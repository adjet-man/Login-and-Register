#include <iostream>
#include <fstream>
#include <string>

// Struct to hold user information
struct User {
    std::string username;
    std::string password;
};

// Function to register a new user
void registerUser() {
    User user;

    std::cout << "Enter username: ";
    std::cin >> user.username;

    // Check if username already exists in file
    std::ifstream usersFile("users.txt");
    std::string line;
    bool usernameTaken = false;
    while (std::getline(usersFile, line)) {
        size_t pos = line.find(",");
        std::string storedUsername = line.substr(0, pos);
        if (user.username == storedUsername) {
            usernameTaken = true;
            break;
        }
    }
    
    if (usernameTaken) {
        std::cout << "Username already taken. Please choose another one." << std::endl;
        return;
    }

    std::cout << "Enter password: ";
    std::cin >> user.password;

    // Open users file in append mode
    std::ofstream usersFileAppend("users.txt", std::ios_base::app);

    // Write new user info to file
    usersFileAppend << user.username << "," << user.password << std::endl;

    std::cout << "User registered successfully!" << std::endl;
}

// Function to check if user exists and login
void loginUser() {
    std::string username, password;

    std::cout << "Enter username: ";
    std::cin >> username;

	std::cout << "Enter password: ";
	std::cin >> password;

	// Open users file in read mode
	std::ifstream usersFileRead("users.txt");

	std::string line;
	bool userFound = false;

	// Check each line of the file for the entered username and password
	while (std::getline(usersFileRead, line)) {
	    size_t pos = line.find(",");
	    std::string storedUsername = line.substr(0, pos);
	    std::string storedPassword = line.substr(pos+1);

	    if (username == storedUsername && password == storedPassword) {
	        userFound = true;
	        break;
	    }
	}

	if (userFound) {
	    std::cout << "Login successful!" << std::endl;
	} else {
	    std::cout << "Incorrect username or password." << std::endl;
	}
}

int main() {
    int choice;

    do {
        std::cout << "1. Register\n2. Login\n3. Quit\n\nEnter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                std::cout << "Goodbye!" << std::endl;

				// Clear console before exiting
#ifdef _WIN32
				system("cls");
#else
				system("clear");
#endif

                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }

    } while (choice != 3);

    return 0;
}