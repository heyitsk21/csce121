#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main() {
    string startingStr = "";
    string numLetters = "";

    cout<<"Please enter obfuscated sentence: ";
    cin>>startingStr;

    cout<<"Please enter deobfuscation details: ";
    cin>>numLetters;

    string resultant = "";

    int numNum = 0;
    int index = 0;
    string temp = "";
    cout<<"Deobfuscated sentence: ";
    
    for (size_t i = 0; i < numLetters.size(); i++){
        numNum = int(numLetters.at(i)) - '0';
        
        //cout<<index<<endl;
        //cout << numNum << endl;

        resultant+=startingStr.substr(index, numNum) + " ";
        index+=numNum;
    }
    cout<<resultant<<endl;
    return 0;
}




/*
try {
    cout<<"0: "<<str1.at(0)<<'\n';
    cout<<"1: "<<str1.at(1)<<'\n';
    cout<<"2: "<<str1.at(2)<<'\n';
    cout<<"3: "<<str1.at(3)<<'\n';

}catch (std::out_of_range) {
    cout<<"Out of range\n";
}
*/