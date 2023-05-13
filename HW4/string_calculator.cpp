#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout, std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement
    
    unsigned int decimal = int(digit) - 48;
    //cout<<"decimalll: "<<decimal<<endl;
    if (decimal > 9){
        //cout<<"decimalll?????"<<endl;
        throw std::invalid_argument("Not a digit");
    }
    
    return decimal;
}

char decimal_to_digit(unsigned int decimal) {
    // TODO(student): implement
    if (decimal > 9){
        throw std::invalid_argument("Not a digit2");
    } else {
        char digit = char(decimal+48);
        return digit;
    }
    return '\0';
}

string char_to_string(char ch){
    string poop = "";
    poop.push_back(ch);
    return poop;
}

string trim_leading_zeros(string num) {
    // TODO(student): implement
    unsigned int firstDigPos = num.size()-1;
    if (num.find("1")<=firstDigPos){
        firstDigPos = num.find("1");
    }
    if (num.find("2")<=firstDigPos){
        firstDigPos = num.find("2");
    }
    if (num.find("3")<=firstDigPos){
        firstDigPos = num.find("3");
    }
    if (num.find("4")<=firstDigPos){
        firstDigPos = num.find("4");
    }
    if (num.find("5")<=firstDigPos){
        firstDigPos = num.find("5");
    }
    if (num.find("6")<=firstDigPos){
        firstDigPos = num.find("6");
    }
    if (num.find("7")<=firstDigPos){
        firstDigPos = num.find("7");
    }
    if (num.find("8")<=firstDigPos){
        firstDigPos = num.find("8");
    }
    if (num.find("9")<=firstDigPos){
        firstDigPos = num.find("9");
    }    

    while (num.find("0") != string::npos 
            && num.find("0")<firstDigPos 
            && num.find("0")<num.size()){
        //cout<<"POOOOP"<<endl;
        
        num.replace(num.find("0"),1,"");
        firstDigPos--;
        //cout<<a<<": "<<num<<endl;
    }
    //cout<<"KK's NUM: "<<num<<endl;
    if (num == "-0" || num == ""){
        num = "0";
    }
    //cout<<"KK's NUM NUM: "<<num<<endl;

    return num;
}

string add(string lhs, string rhs) {
    // TODO(student): implement
    
    bool negative = false; 
    string result = "";
    int carry = 0;


    
    if (lhs.at(0)=='-' && rhs.at(0)=='-'){
        negative = true;
        lhs.replace(0,1,"");
        rhs.replace(0,1,"");
    }
    
    if (lhs.size()>rhs.size()){        
        while(lhs.size() != rhs.size()) {
            rhs.insert(0,"0");
        }
        //cout<<"rhs: "<<rhs<<endl;
        //cout<<"lhs: "<<lhs<<endl;
        
        
    } else if (lhs.size()<rhs.size()){
        while(lhs.size() != rhs.size()) {
            lhs.insert(0,"0");
        }
    } 
    if (lhs.size() == rhs.size()){
        for (int i = int(rhs.length()) - 1; i >= 0; i--){
            int c = digit_to_decimal(rhs.at(i));
            int d = digit_to_decimal(lhs.at(i));
            int addedDig = c + d + carry;
            carry = 0;
            if (addedDig > 9){
                carry = 1;
                addedDig -= 10;
                string something = char_to_string(decimal_to_digit(addedDig));
                result.insert(0, something);
            } else {
                string somethingElse = char_to_string(decimal_to_digit(addedDig));
                result.insert(0, somethingElse);
            }
        }
        if (carry == 1){
            result.insert(0, "1");
        }
    }

    if(negative){
        result.insert(0,"-");
    }
    result = trim_leading_zeros(result);
    return result;

    if(negative){
        result.insert(0,"-");
    }
    return result;
}

string multiply(string lhs, string rhs) {
    //cout<<"\tLine "<<__LINE__<<endl;
    // TODO(student): implement
    bool negative = false;
    string intermediate = "0"; //holder
    string result = ""; //finals
    int carry = 0;
    string shorter;
    string longer;
    int count = 0;
    //int numDigits;

    if ((lhs.at(0)=='-') && (rhs.at(0)!='-')){ //ONLY LEFT IS NEG
        negative = true;
        lhs.replace(0,1,"");
    } else if ((lhs.at(0)!='-') && (rhs.at(0)=='-')){ //ONLY RIGHT IS NEG
        negative = true;
        rhs.replace(0,1,"");
    } else if (lhs.at(0)=='-' && rhs.at(0)=='-'){ //BOTH ARE NEG
        lhs.replace(0,1,"");
        rhs.replace(0,1,"");
    }

    if (lhs.size()>rhs.size()){ //LEFT IS LONGER
        shorter = rhs;
        longer = lhs;
    } else if (lhs.size()<rhs.size()){ //RIGHT IS LONGER
        shorter = lhs;
        longer = rhs;
    }else if (lhs.size()==rhs.size()){ //BOTH ARE SAME LENGTH
        shorter = lhs;
        longer = rhs;
    }
    
    for (int i = shorter.size() - 1; i >= 0; i--){
        result = "";
        for (int j = longer.size() - 1; j >= 0; j--){
            int a = digit_to_decimal(shorter.at(i));
            int b = digit_to_decimal(longer.at(j));
            int multDig = (a * b) + carry;
            carry = 0;
            //cout<<"\t\tLine "<<__LINE__<<endl<<"a= "<<a<<endl<<"b= "<<b<<endl<<"multDig= "<<multDig<<endl;
            if (multDig > 9){
                carry = (multDig / 10) % 10;
                multDig = multDig % 10;
                string something = char_to_string(decimal_to_digit(multDig));
                result.insert(0, something);
                //cout<<"\t\tLine "<<__LINE__<<endl<<"carry1= "<<carry<<endl<<"multDig1= "<<multDig<<endl<<"INTERMEDIATE1= "<<intermediate<<endl;
            } else {
                string somethingElse = char_to_string(decimal_to_digit(multDig));
                result.insert(0, somethingElse);
                //cout<<"\t\tLine "<<__LINE__<<endl<<"carry2= "<<carry<<endl<<"multDig2= "<<multDig<<endl<<"INTERMEDIATE2= "<<intermediate<<endl;
            }

        }
        if (count != 0){
            int temp = count;
            while (temp > 0){
                result.insert(int(result.size()),"0");
                temp -= 1;
            }
        }

        count += 1;

        if (carry != 0){
            result.insert(0,char_to_string(decimal_to_digit(carry)));
            carry = 0;
        }

        intermediate = add(intermediate, result);
    }
    result = intermediate;

    if(negative){
        result.insert(0,"-");
    }

    return result;
}
