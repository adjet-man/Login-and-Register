# User Authentication Program
This is a simple user authentication program that allows users to register and login using a username and password. The program stores user information in a text file called "users.txt".
Dependencies
This program requires the following standard C++ libraries:
    -  iostream 
    -  fstream 
    -  string 
# Usage
To use this program, compile the source code using your preferred C++ compiler. Then, run the compiled executable.
When you run the program, you will be presented with a menu that allows you to choose between registering a new user, logging in as an existing user, or quitting the program.
# Registering a New User
To register a new user, choose option 1 from the menu. You will be prompted to enter a username and password. The program will check if the username is already taken. If it is not taken, it will add the new user information to "users.txt".
# Logging In as an Existing User
To log in as an existing user, choose option 2 from the menu. You will be prompted to enter your username and password. The program will check if the entered username and password match any of the users in "users.txt". If there is a match, you will be logged in successfully. Otherwise, you will receive an error message.
# Quitting the Program
To quit the program, choose option 3 from the menu.
# Code Explanation
The code consists of two main functions: registerUser() and loginUser().
- registerUser() prompts the user for their desired username and password. It then checks if there are any existing users with that username. If there are no existing users with that username, it adds their information to "users.txt".
- loginUser() prompts the user for their existing username and password. It then checks if there are any existing users with that username and password. If there is a match, it logs the user in successfully.
- The program uses std::ofstream and std::ifstream to read and write data to "users.txt". It also uses the std::string class to store user information.
# Conclusion
This program is a simple example of how user authentication can be implemented in C++. While it is not secure enough for production use, it provides a good starting point for learning about file I/O, string manipulation, and basic control flow structures in C++.
