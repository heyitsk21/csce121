#include <iostream>
#include <string>
using std::cin, std::cout, std::endl, std::string;

int main() {
    string sentence;
    cout<<"Please enter the sentence: ";
    getline(cin, sentence);

    string filter;
    cout<<"Please enter the filter word: ";
    cin>>filter;
    
    string bleep = "#";
    for (long unsigned int i = 0; i < filter.size()-1; i++){
        bleep += '#';
    }
    
    /*
    cout<<"bleep: "<<bleep<<endl;
    cout<<"sentence: "<<sentence<<endl;
    cout<<"sentence size: "<<sentence.size()<<endl;
    cout<<"filter: "<<filter<<endl;
    */

    while (sentence.find(filter) != string::npos){
        int a = sentence.find(filter);
        if(sentence.find(filter)){
            sentence.replace(a,filter.size(),bleep);
            //cout<<": "<<sentence<<endl;
        }
    }

    cout<<"Filtered sentence: "<<sentence<<endl;
    return 0;
}
