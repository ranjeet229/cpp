// #include <iostream>
// #include <thread>  

// void fun() {
//     std::cout << "Inside thread" << std::endl;
// }

// int main() {
//     std::thread t(fun); 
//     t.join();           

//     std::cout << "Outside thread" << std::endl;
//     return 0;
// }

//
#include<iostream>
#include<thread>

int main(){
    std::cout<<"Main Thread id = "<<std::this_thread::get_id() <<std::endl;

    return 0;
}
