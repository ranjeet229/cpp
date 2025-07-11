// #include<iostream>
// #include<string.h>
// using namespace std;

// int main(){
//     char c;
//     cin>>c;
//     cout << (int)c <<endl;
//     return 0;
// }

//write the program in cpp to overload the area function 
//palindrome

// #include <iostream>
// using namespace std;

// int main() {
//     string str;
//     cout << "Enter a string: ";
//     cin >> str;

//     bool isPalindrome = true;
//     int n = str.length();

//     for (int i = 0; i < n / 2; i++) {
//         if (str[i] != str[n - 1 - i]) {
//             isPalindrome = false;
//             break;
//         }
//     }

//     if (isPalindrome) {
//         cout << "palindrome" << endl;
//     } else {
//         cout << "not" << endl;
//     }

//     return 0;
// }

//function
//declaring, defining and calling function 
// #include<iostream>
// using namespace std;

// int sum(int x, int y){ //delecaring function 
//     return x+y;
// }
// int main(){
//     cout<<"hello world";
// }

//average of two number
// #include<iostream>
// using namespace std;

// int main(){
//     float n1, n2, n3;
//     cin>>n1;
//     cin>>n2;
//     n3=n1+n2;
//     float avg = n3/2;
    
//     //cascading i/o operator
//     cout<<"Sum: "<<n3<<endl;
//     cout<<"Average: "<<avg<<endl;
// }

//complie time polymorphism..
//function overrloading...
// #include<iostream>
// using namespace std;

// class Add{
//     public:
//     int sum(int num1, int num2){
//         return num1+num2;
//     }
//     int sum(int num1, int num2, int num3){
//         return num1+num2+num3;
//     }

// };

// int main(){
//     Add obj;
//     //this will print first function
//     cout<<"output: "<<obj.sum(20,10)<<endl;
//     //this will print second funciton 
//     cout<<"output: "<<obj.sum(20,40,30)<<endl;

//     return 0;
// }
//

//2:- function overriding
// #include <iostream>
// using namespace std;

// class A {
// public:
//     void disp() {
//         cout << "Base class function" << endl;
//     }
// };

// class B : public A {
// public:
//     void disp() {
//         cout << "Sub class function" << endl;
//     }
// };

// int main() {
//     A obj1; // parent class object
//     obj1.disp(); // calls A::disp()

//     B obj2; // child class object
//     obj2.disp(); // calls B::disp()

//     return 0;
// }

//Template in cpp....>>>
// #include <iostream>
// using namespace std;

// // Template class
// template <class T>
// class Box {
// private:
//     T value;

// public:
//     void setValue(T val) {
//         value = val;
//     }

//     T getValue() {
//         return value;
//     }
// };

// int main() {
//     Box<int> intBox;
//     Box<string> strBox;
//     Box<float> floatBox;

//     intBox.setValue(42);
//     strBox.setValue("Hello, Templates!");
//     floatBox.setValue(3.14);

//     cout << "Integer Box: " << intBox.getValue() << endl;
//     cout << "String Box: " << strBox.getValue() << endl;
//     cout << "Float Box: " << floatBox.getValue() << endl;

//     return 0;
// }

// project:- Build a "Student Grade Calculator" using functions, arrays and classes
// #include<iostream>
// #include<string>
// using namespace std;

// class Student {
//     private:
//     string name;
//     int rollno;
//     float marks[5];
//     float total;
//     float avg;
//     char grade;

//     public:
// void Details(){
//         cout<<"enter name: ";
//         getline(cin, name);
//         cout<<"enter rollno: ";
//         cin>>rollno;

//         cout <<"enter marks ";
//         for(int i=0; i<5;i++){
//             cout<<"subject "<<i+1<<": ";
//             cin>>marks[i];
//         }
//     }

//     void calculate(){
//         total=0;
//         for(int i=0;i<5;i++){
//             total+=marks[i];
//         }
//         avg = total/5;

//         if(avg >=90){
//             grade ='A';
//         }else if (avg >=75){
//             grade ='B';
//         }else if(avg>=60){
//             grade='C';
//         }else if(avg >=40){
//             grade='D';
//         }else{
//             grade='F';
//         }
//     }
//     void display(){
//         cout<<"name: "<<name<<endl;
//         cout<<"rollno: "<<rollno<<endl;
//         cout<<"marks: ";
//         for(int i=0;i<5;i++){
//             cout<<marks[i]<<" ";
//         }
//         cout<<"\ntotal: "<<total<<endl;
//         cout<<"avg: "<<avg<<endl;
//         cout<<"grade: "<<grade<<endl;
//     }

// };

// int main(){
//     Student student;
//     student.Details();
//     student.calculate();
//     student.display();

//     return 0;
// }

//Lms using filehandling.........>>>>>
// #include<iostream>
// #include<vector>
// #include<string>
// using namespace std;

// class Course{
//     public:
//     string courseName;
//     string courseCode;

//     Course(string name, string code){
//         courseName = name;
//         courseCode = code;
//     }
//     void display(){
//         cout<<"course: "<<courseName<<" ("<<courseCode<<")"<<endl;
//     }
// };

// class
// int main(){
// }

//TIck tak toe ....>>>
#include<isotream>
using namespace std;

char board[3][3];
char currMark;
int currPlayer;

char inital(){
    char num = '1';
    for(int i=0; i<3i++){
        for(int j =0;j<3;j++){
            board[i][j] = num++;
        }
    }
}
void Board() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n-----------\n";
    }
    cout << "\n\n\n";
}