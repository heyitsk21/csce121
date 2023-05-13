//02-11-22

/* agenda
stream states - https://en.cppreference.com/w/cpp/io/ios_base/iostate
    see also: table at bottom of page
i/o stream input validation
how to recover a failed stream
file i/o
    RAII
    is_open()
*/

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using std::cin, std::cout, std::endl;
using std::string;

//////////////////////////////////////////
#define EVERYTHING std::numeric_limits<std::streamsize>::max() //pre-processor macro
//////////////////////////////////////////

std::string input(const std::string& prompt = "") {
    cout << prompt;
    string line;
    getline(cin >> std::ws, line);
    return line;
}

void io_stream_input_validation() {
    int a;
    cout << "int> ";
    cin >> a;
    while (cin.fail()) {
        cout << "invalid" << endl;

        //clean up
        cin.clear(); //clear the BITS, not the stream itself //put stream back to "good" state (the failed input is still in the stream)
        cin.ignore(EVERYTHING, '\n'); //tell the stream to ignore everything that was inputted until that newline
        
        //reprompt
        cout << "int> ";
        cin >> a;
    }
    cout << "int: " << a << endl;
}

void another_validation_example() {
    // not stream states
    string str = input("another int> ");
    int a;
    try {
        a = stoi(str); //stoi is a string function. converts strings to an int
        cout << "int: " << a << endl;
    } catch (const std::invalid_argument& err) {
        cout << err.what() << endl;
        cout << "no conversion could be performed (not an int)" << endl;
    } catch (const std::out_of_range& err) {
        cout << err.what() << endl;
        cout << "out of range (int, but too big)" << endl;
    }
}

void yet_another_validation_example() { //same as the 1st example, but using ss (stream strings)
//reads the whole inputted line
    string str = input("yet another int> ");
    cout << "got: " << str << endl; //proves that it read the whole line
    /*
    try {
        cout << stoi(str) << endl;
    } catch (const std::invalid_argument& err){
        cout << err.what()
        ///////////didn't finish
    }
    */
    std::istringstream ss(str);
    int a;
    ss >> a;
    if (ss.fail()) {
        cout << "failed to extract an int" << endl;
    } else {
        cout << "int: " << a << endl;
    }
}

void file_io() {
    string filename = "file";

    // write to file
    {
        // RAII - resource allocation is initialization
        std::ofstream fout(filename); //output file stream
        if (!fout.is_open()) {
            cout << "could not open \""<<filename<<"\"" << endl;
        } else {
            fout << "stuff" << " and things" << endl;
        }
    } //this block automatically opens/closes the file for me

    // read from file
    {
        // RAII
        std::ifstream fin(filename); //input file stream
        if (!fin.is_open()) {
            cout << "could not open \""<<filename<<"\"" << endl;
        } else {
            while(fin.good()) {
                string line;
                getline(fin, line);
                cout << line << endl;
            }
        }
    }

}

int main() {
    //io_stream_input_validation();
    
    //another_validation_example();
    
    //yet_another_validation_example();
    
    //file_io();

    return 0;
}
