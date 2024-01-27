#include <iostream>
#include <string>
#include <Windows.h>
#include <vector>

using namespace std;

struct user_information {
    string user_name;
    string name;
    string password;
    string current_Year;
    string year_of_birth;
};

struct user_detail {
    string comments;
    int likecounter;
    int commentcounter;
};

int displayMenue() {
    cout << "1.Post statuses.\n2.Interact People.\n3.Display activity details.\n4.Log out";
    int option;
    cin >> option;
    cout << "Enter your option: ";
    cin.ignore(); // Clear the newline character from the input buffer
    while (option != 1 && option != 2 && option != 3 && option != 4) {
        cout << "Incorrect input.\n ";
        cin >> option;
    }
    return option;
}

void createProfile(user_information& profilecreation) {
    cout << "Enter your name: ";
    getline(cin, profilecreation.name);
    cout << "\nEnter your user name: ";
    getline(cin, profilecreation.user_name);
    cout << "\nEnter your password: ";
    cout << "\nYour password must have at least 2 digits, 2 alphabets, 0 spaces, and 1 special symbol\n";

    do {
        bool verification;
        int alphacounter = 0;
        int digitcounter = 0;
        int spacecounter = 0, symbolcounter = 0;
        getline(cin, profilecreation.password);

        if (profilecreation.password.size() >= 3 && profilecreation.password.size() <= 16) {
            for (int i = 0; i < profilecreation.password.size(); i++) {
                if (profilecreation.password[i] == ' ') {
                    spacecounter++;
                }
                else if (isalpha(profilecreation.password[i])) {
                    alphacounter++;
                }
                else if (isdigit(profilecreation.password[i])) {
                    digitcounter++;
                }
                else {
                    symbolcounter++;
                }
            }
        }
        else {
            cout << "Your password must be between 3 and 16.\n";
            continue;
        }

        if (digitcounter >= 2 && alphacounter >= 2 && spacecounter == 0 && symbolcounter >= 1) {
            verification = true;
        }
        else {
            verification = false;
        }

        if (verification == true) {
            break;
        }
        else if (verification == false) {
            cout << "\nEnter your password again. Requirements didn't meet.\n";
            cout << "Your password must have at least 2 digits, 2 alphabets, 0 spaces, and 1 special symbol\n";
            continue;
        }

    } while (true);
    bool digit; // Initialize to false

    do{
        cout << "Enter your year of birth: ";
        cin >> profilecreation.year_of_birth;
        cout << "\nEnter current year: ";
        cin >> profilecreation.current_Year;

        while (profilecreation.current_Year.size() != 4 || profilecreation.year_of_birth.size() != 4) {
            cout << "\nIncorrect Input. Your year should contain 4 digits.";
            cout << "\nEnter your year of birth: ";
            cin >> profilecreation.year_of_birth;
            cout << "\nEnter current year: ";
            cin >> profilecreation.current_Year;
        }

        digit = false; // Initialize to false before the for loop

        // Check each string separately in the for loop
        for (int i = 0; i < profilecreation.current_Year.size(); i++) {
            if (!isdigit(profilecreation.current_Year[i])) {
                digit = true;
                break;  // exit the loop once a non-digit character is found
            }
        }

        for (int i = 0; i < profilecreation.year_of_birth.size(); i++) {
            if (!isdigit(profilecreation.year_of_birth[i])) {
                digit = true;
                break;  // exit the loop once a non-digit character is found
            }
        }

        if (digit == true) {
            cout << "Invalid input. Please enter digits only.";
            continue;
        }
        int birth = stoi(profilecreation.year_of_birth);
        int year = stoi(profilecreation.current_Year);
        if (year - birth < 18) {
            cout << "\nYou must be atleast 18 years old to create this account. ";
            continue;
        }
        else {
            cout << "\nAge veified.";
            break;
        }

    } while (true);
}

void verification(user_information& profilecreation) {
    bool check;
    string password;
    string username;

    do {
        cin.ignore();
        cout << "Enter your user name to log in to your account: ";
        getline(cin, username);
        cout << "\nEnter your password to log in to your account: ";
        getline(cin, password);

        if (username == profilecreation.user_name) {
            if (password == profilecreation.password) {
                cout << "Login verified.\n";
                check = true;
            }
            else {
                cout << "Incorrect Password.";
                continue;
            }
        }
        else {
            cout << "\nIncorrect username.\n";
            continue;
        }
    } while (username.compare(profilecreation.user_name) != 0 || password.compare(profilecreation.password) != 0);
}

void postStatus(vector<user_detail>& status) {
    string choice = "Yes";

    do {
        status.push_back(user_detail());  // Add a new element to the vector
        int i = status.size() - 1;  // Get the index of the last element

        cout << "Write any text message.\n";
        getline(cin, status[i].comments);
        status[i].likecounter = rand() % 100 + 1;
        status[i].commentcounter = rand() % 100 + 1;

        cout << "\nYou got " << status[i].likecounter << " likes on your post.\n";
        cout << "Press enter to continue. ";
        cin.ignore(); // Clear the newline character from the input buffer
        cin.get();

        cout << "\nYou got " << status[i].commentcounter << " comments on your post.\n";
        cout << "Press enter to continue. ";
        cin.ignore(); // Clear the newline character from the input buffer
        cin.get();

        cout << "Do you want to continue posting further? (Yes/No): ";
        getline(cin, choice);

        while (!(choice == "No" || choice == "no" || choice == "Yes" || choice == "yes")) {
            cout << "\nIncorrect option\n";
            getline(cin, choice);
        }

    } while (choice == "Yes" || choice == "yes");
}

void displayDetails(const vector<user_detail>& status, int likecounter, int commentcounter) {
    cout << "\nYou have done the following comments till now:\n";
    for (int i = 0; i < status.size(); i++) {
        cout << status[i].comments << "\n";
    }

    cout << "Press enter to continue.\n";
    cin.get();

    cout << "You have liked " << likecounter << " posts so far.\n";
    cout << "You have commented " << commentcounter << " times on posts.";
}

void interactPeople(int& likecounter, int& commentcounter) {
    int option;
    string verify;

    do {
        cout << "\nEnter 1 if you want to like a post.\nEnter 2 if you want to comment on a post.\n";
        cin >> option;

        if (option == 1) {
            cout << "\nYou liked a post!";
            likecounter++;
        }
        else if (option == 2) {
            cout << "\nYou commented on a post.";
            commentcounter++;
        }
        else {
            cout << "\nIncorrect input. Please try again.";
            continue;
        }

        cout << "\nPress Enter to continue. ";
        cin.ignore(); // Clear the newline character from the input buffer
        cin.get();

        do {
            cout << "\nDo you want to continue further interacting with people? (Yes/No): ";
            getline(cin, verify);

            if (!(verify == "No" || verify == "no" || verify == "Yes" || verify == "yes")) {
                cout << "Incorrect option. Please enter Yes or No: ";
            }
        } while (!(verify == "No" || verify == "no" || verify == "Yes" || verify == "yes"));

    } while (verify == "Yes" || verify == "yes");

    cout << ":)";
}

int main() {
    srand(time(0));
    int likecounter = 0, commentcounter = 0;
    vector<user_detail> status;
    user_information profilecreation;
    createProfile(profilecreation);
    system("cls");
    system("pause");
    verification(profilecreation);
    system("cls");
    system("pause");
    do {
        int number = displayMenue();
        if (number == 1) {
            postStatus(status);
            system("cls");
        }
        else if (number == 2) {
            interactPeople(likecounter, commentcounter);
            system("cls");
        }
        else if (number == 3) {
            displayDetails(status, likecounter, commentcounter);
            system("pause");
            system("cls");
        }
        else if (number == 4) {
            cout << "Logging out!!\n";
            break;
        }
        else if (isalpha(number)) {
            cout << "Invalid input.\n";
            continue;
        }
        else {
            cout << "Invalid input.\n";
            continue;
        }

    } while (true);

    verification(profilecreation);

    return 0;
}
