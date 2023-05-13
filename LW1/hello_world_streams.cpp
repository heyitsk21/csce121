#include <iostream> //has cout, cin, endl
/*
int main() {

    // << is the [ostream] insertion operator
    std::cout << "howdy, world!" << std::endl;
    //cout is the standard output stream
    //things flow from R to L.
    //endl is the end of line (\n) character + flushes the output to the console

    return 0; // 0 means success for the calling process

}*/

#include <fstream> //has ifstream and ofstream
#include <string>
using std::cout, std::endl; //only available with -std=c++17

int main() {

        // << is the [ostream] insertion operator
    cout << "howdy, world!" << endl;
        //cout is the standard output stream
        //things flow from R to L.
        //endl is the end of line (\n) character + flushes the output to the console

    std::string response;
    cout << "say something: ";
    //cin is the standard input stream
    //>> is the [istream] extraction operator
    cin >> response;
    cout << "got: " << response << endl;





    /*

    //now, with files
    std::ofstream fout("output_file.txt");
    std::ifstream fin("input_file.txt");
    fout << "howdy, world!" << endl;

    std::string response;
    fout << "i'm reading from a file... ";

    */



    
    return 0; // 0 means success for the calling process

}