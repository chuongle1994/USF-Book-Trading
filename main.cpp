#include <iostream>
#include <fstream>
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
        string filename = "StudentID.txt"; // Replace with your file's name
        ifstream file(filename); // Open the file for reading
    if (!file.is_open()) {
        std::cerr << "Failed to open the file: " << filename << std::endl;
        return 1;
    }

    std::string numID;
    std::cout << "What is your student ID? ";
    std::cin >> numID; // Read the user's input as a string

    std::string line;
    while (std::getline(file, line)) {
        // Convert the line to an integer using std::stoi()
        int number = std::stoi(line);

        // Convert numID to an integer for comparison
        int input_to_check = std::stoi(numID);

        if (number == input_to_check) {
                cout << "Welcome USF Student " << std::endl;
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
                                                    
                            do {
                                cout << "Enter your password: ";
                                std::cin >> password;

                                // Check password length
                                if (password.length() < 8) {
                                    std::cout << "Password is too short. It should be at least 8 characters long.\n";
                                }
                                // Check for at least one letter and one digit
                                else if (!std::any_of(password.begin(), password.end(), ::isdigit) ||
                                        !std::any_of(password.begin(), password.end(), ::isalpha)) {
                                    std::cout << "Password should include both letters and digits.\n";
                                }
                                // If password meets criteria, break out of the loop
                                else {
                                    std::cout << "Password accepted!\n";
                                    break;
                                }
                            } while (true);
                                                    
                            
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
            
            }else {
                    cout << "You are not a USF student. This program is for USF students only.\n";
                    break;
            }
        }
        file.close();
        return 0;

    }else{
        cout << "This program is for USF students only, sorry.\n";

    }

    return 0;
}
