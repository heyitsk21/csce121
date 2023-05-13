#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"

using std::cout, std::endl, std::cin;
using std::string;

void print_quit(){
    cout<<endl<<"farvel!"<<endl<<endl;
}

int main() {
    //cout<<"POOPIE: "<<trim_leading_zeros(add("023482358374943","23423434"))<<endl;
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    
    // TODO(student): implement the UI
    
    cout << ">> ";

    //bool quit = false;

    string num1;
    char sign;
    string num2;
    
    cin >> num1;
    if (num1 == "q" || num1 == "quit"){
        print_quit();
        return 0;
    }
    cin >> sign;
    cin >> num2;
    if (num2 == "q" || num2 == "quit"){
        print_quit();
        return 0;
    }

    //cout<<add(num1,num2);

    /*
    cout<<"num1: "<<num1<<endl;
    cout<<"sign: "<<sign<<endl;
    cout<<"num2: "<<num2<<endl;
    */

    num1 = trim_leading_zeros(num1);
    num2 = trim_leading_zeros(num2);

    if (sign == '+'){
        cout<<endl<<"ans ="<<endl<<endl<<"    "<<trim_leading_zeros(add(num1,num2))<<endl<<endl;
    } else if (sign == '*'){
        cout<<endl<<"ans ="<<endl<<endl<<"    "<<trim_leading_zeros(multiply(num1,num2))<<endl<<endl;
    }
    
    while (num1 != "q" || num1 != "quit" || num2 != "q" || num2 != "quit"){
        cout << ">> ";
        cin >> num1;
        if(num1 == "q" || num1 == "quit"){
            break;
        }
        cin >> sign;
        cin >> num2;
        if(num2 == "q" || num2 == "quit"){
            break;
        }
        

        num1 = trim_leading_zeros(num1);
        num2 = trim_leading_zeros(num2);

        if (sign == '+'){
            cout<<endl<<"ans ="<<endl<<endl<<"    "<<trim_leading_zeros(add(num1,num2))<<endl<<endl;
        } else if (sign == '*'){
            cout<<endl<<"ans ="<<endl<<endl<<"    "<<trim_leading_zeros(multiply(num1,num2))<<endl<<endl;
        }
    }
    print_quit();
    return 0;
}

