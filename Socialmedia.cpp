#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct user_information {
    string user_name;
    string name;
    string password;
    string date_of_birth;
};

struct user_detail {
    vector<string> comments;
    vector<int> likecounter;
    vector<int> commentcounter;
};

void create_profile(user_information& profilecreation) {
    string message;
    cout << "Enter your name: ";
    getline(cin, profilecreation.name);
    cout << "\nEnter your user name: ";
    getline(cin, profilecreation.user_name);
    cout << "\nEnter your password: ";
    cout << "\nYour password must have at least 2 digits, 2 alphabets, 0 spaces and 1 special symbol\n";
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
            cout << "Your password must have at least 2 digits, 2 alphabets, 0 spaces and 1 special symbol\n";
            continue;
        }

    } while (true);
    cout << "Enter your date of birth: ";
    getline(cin, profilecreation.date_of_birth);
}

void verification(user_information& profilecreation) {
    bool check;
    string password;
    string username;
    do {
        cout << "Enter your user name to login to your account: ";
        getline(cin, username);
        cout << "\nEnter your password to login to your account: ";
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
    } while (true);
}

void poststatus(vector<user_detail>& status) {
    string choice = "Yes";
    int i = 0;

    cout << "Write any text message.\n";
    do {
        string commentsss;
        int likecount = 0, commentcount = 0;

        getline(cin, commentsss);
        likecount = rand() % 100;
        status[i].likecounter.push_back(likecount);
        commentcount = rand() % 100 + 1;
        status[i].commentcounter.push_back(commentcount);
        status[i].comments.push_back(commentsss);

        cout << "\nYou got " << likecount << " likes on your text message.\n";
        cout << "You got " << commentcount << " comments on your text message.\n";
        cout << "Do you want to post further? (Yes/No): ";
        cin >> choice;

        // Clear the newline character from the input buffer
        cin.ignore();

        if (choice == "Yes" || choice == "yes") {
            i++;
            cout << "Write your comment: ";
            continue;
        }
        else if (choice == "No" || choice == "no") {
            break;
        }
        else {
            cout << "Incorrect input. Please select Yes/No.\n";
            continue;
        }
    } while (true);
}


int main() {
    srand(time(0));
    vector<user_detail> status;
    user_information profilecreation;
    create_profile(profilecreation);
    // Clear screen (cross-platform approach needed)
    // system("cls");
    verification(profilecreation);
    // Clear screen (cross-platform approach needed)
    // system("cls");
    poststatus(status);
    // Clear screen (cross-platform approach needed)
    // system("cls");

    return 0;
}