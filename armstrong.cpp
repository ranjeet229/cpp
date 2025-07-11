// class Solution {
// public:
//     string convert(string s, int numRows) {
//         if (numRows == 1 || s.size() <= numRows) return s;

//         vector<string> matrix(numRows);
//         int i = 0, n = s.size(), index = 0;
//         bool direction = true;

//         while (i < n) {
//             matrix[index].push_back(s[i]);

//             if (index == numRows - 1) direction = false;
//             if (index == 0) direction = true;

//             if (direction) index++;
//             else index--;

//             i++;
//         }

//         string result;
//         for(auto &x:matrix)
//         {
//             result+=x;
//         }

//         return result;
//     }
// };

//Lms .......>>>


// #include <iostream>
// #include <vector>
// #include <string>
// using namespace std;

// class Course {
// public:
//     string courseName;
//     string courseCode;

//     Course(string name, string code) {
//         courseName = name;
//         courseCode = code;
//     }

//     void displayCourse() {
//         cout << "Course: " << courseName << " (" << courseCode << ")" << endl;
//     }
// };

// class User {
// public:
//     string name;
//     string role;

//     User(string n, string r) {
//         name = n;
//         role = r;
//     }

//     virtual void showMenu() = 0;
// };

// class Admin : public User {
// private:
//     vector<Course>& courses;

// public:
//     Admin(string n, vector<Course>& courseList) : User(n, "Admin"), courses(courseList) {}

//     void addCourse() {
//         string name, code;
//         cout << "Enter course name: ";
//         cin.ignore();
//         getline(cin, name);
//         cout << "Enter course code: ";
//         getline(cin, code);
//         courses.push_back(Course(name, code));
//         cout << "Course added successfully!\n";
//     }

//     void viewCourses() {
//         cout << "Available Courses:\n";
//         for (auto& c : courses) {
//             c.displayCourse();
//         }
//     }

//     void showMenu() override {
//         int choice;
//         do {
//             cout << "\n--- Admin Menu ---\n";
//             cout << "1. Add Course\n";
//             cout << "2. View Courses\n";
//             cout << "3. Logout\n";
//             cout << "Enter choice: ";
//             cin >> choice;

//             switch (choice) {
//                 case 1: addCourse(); break;
//                 case 2: viewCourses(); break;
//                 case 3: cout << "Logging out...\n"; break;
//                 default: cout << "Invalid choice.\n"; break;
//             }
//         } while (choice != 3);
//     }
// };

// class Student : public User {
// private:
//     vector<Course>& courses;

// public:
//     Student(string n, vector<Course>& courseList) : User(n, "Student"), courses(courseList) {}

//     void viewCourses() {
//         cout << "Available Courses:\n";
//         for (auto& c : courses) {
//             c.displayCourse();
//         }
//     }

//     void showMenu() override {
//         int choice;
//         do {
//             cout << "\n--- Student Menu ---\n";
//             cout << "1. View Courses\n";
//             cout << "2. Logout\n";
//             cout << "Enter choice: ";
//             cin >> choice;

//             switch (choice) {
//                 case 1: viewCourses(); break;
//                 case 2: cout << "Logging out...\n"; break;
//                 default: cout << "Invalid choice.\n"; break;
//             }
//         } while (choice != 2);
//     }
// };

// int main() {
//     vector<Course> courses;
//     int userType;

//     cout << "Welcome to LMS (Learning Management System)\n";
//     do {
//         cout << "\nLogin as:\n1. Admin\n2. Student\n3. Exit\nEnter choice: ";
//         cin >> userType;

//         if (userType == 1) {
//             Admin admin("AdminUser", courses);
//             admin.showMenu();
//         } else if (userType == 2) {
//             Student student("StudentUser", courses);
//             student.showMenu();
//         } else if (userType == 3) {
//             cout << "Exiting LMS...\n";
//         } else {
//             cout << "Invalid option. Try again.\n";
//         }
//     } while (userType != 3);

//     return 0;
// }

//tic-tak-toe

#include <iostream>
using namespace std;

char board[3][3];
char currentMarker;
int currentPlayer;

void initializeBoard() {
    char num = '1';
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = num++;
}

void printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n-----------\n";
    }
    cout << "\n\n";
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == currentMarker && board[i][1] == currentMarker && board[i][2] == currentMarker) ||
            (board[0][i] == currentMarker && board[1][i] == currentMarker && board[2][i] == currentMarker))
            return true;
    }

    if ((board[0][0] == currentMarker && board[1][1] == currentMarker && board[2][2] == currentMarker) ||
        (board[0][2] == currentMarker && board[1][1] == currentMarker && board[2][0] == currentMarker))
        return true;

    return false;
}

void swapPlayerAndMarker() {
    if (currentMarker == 'X') {
        currentMarker = 'O';
        currentPlayer = 2;
    } else {
        currentMarker = 'X';
        currentPlayer = 1;
    }
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!\n";
    initializeBoard();
    currentMarker = 'X';
    currentPlayer = 1;
    int moveCount = 0;

    printBoard();

    while (true) {
        int slot;
        cout << "Player " << currentPlayer << " (" << currentMarker << "), enter your move (1-9): ";
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot. Try again.\n";
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot already taken. Try again.\n";
            continue;
        }

        printBoard();
        moveCount++;

        if (checkWin()) {
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (moveCount == 9) {
            cout << "It's a draw!\n";
            break;
        }
        swapPlayerAndMarker();
    }

    return 0;
}

