#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a structure to represent a user
struct User {
    string username;
    string password;
};

int main() {
    vector<User> users; // Store user accounts

    cout << "Are you a USF student? (yes/no): ";
    string answer;
    cin >> answer;

    if (answer == "yes" || answer == "Yes" || answer == "YES") {
        while (true) {
            cout << "\n------Go Bulls-----\n";
            cout << "1. Log In\n";
            cout << "2. Sign Up\n";
            cout << "3. Exit\n";

            int choice;
            cin >> choice;

            switch (choice) {
                case 1: {
                    string username, password;
                    cout << "Enter your username: ";
                    cin >> username;
                    cout << "Enter your password: ";
                    cin >> password;
                    
                    // Check if the user exists in the vector (simplified for this example)
                    bool userFound = false;
                    for (const User& user : users) {
                        if (user.username == username && user.password == password) {
                            cout << "Logged in successfully!\n";
                            userFound = true;
                            break;
                        }
                    }
                    if (!userFound) {
                        cout << "Invalid username or password. Please try again.\n";
                    }
                    break;
                }
                case 2: {
                    string username, password;
                    cout << "Enter a new username: ";
                    cin >> username;
                    cout << "Enter a new password: ";
                    cin >> password;
                    
                    // Check if the username already exists (simplified for this example)
                    bool usernameExists = false;
                    for (const User& user : users) {
                        if (user.username == username) {
                            usernameExists = true;
                            break;
                        }
                    }
                    if (usernameExists) {
                        cout << "Username already exists. Please choose a different username.\n";
                    } else {
                        User newUser = {username, password};
                        users.push_back(newUser);
                        cout << "Sign up successful! You can now log in.\n";
                    }
                    break;
                }
                case 3:
                    cout << "Exiting the program.\n";
                    return 0;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        }
    } else {
        cout << "You are not a USF student. This program is for USF students only.\n";
    }

    return 0;
}
