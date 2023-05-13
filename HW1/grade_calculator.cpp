// These headers define some of the classes and functions we need
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

// ONLY MAKE CHANGES WHERE THERE IS A TODO

// These using declarations let us refer to things more simply
// e.g. instead of "std::cin" we can just write "cin"
using std::cin, std::cout, std::endl;
using std::string, std::getline;

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

// pretty print a summary of the grades
void print_results(double exam_average,
                   double hw_average,
                   double lw_average,
                   double reading,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade);

// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string& line,
                            string* category,
                            double* score);

int main() {
    print_instructions();

    // ONLY MAKE CHANGES WHERE THERE IS A TODO

    // TODO(student): declare and initialize variables that you want
    double totExamS = 0;
    double numExams = 0;
    double finExamS = 0;
    double totHwS = 0;
    double numHw = 0;
    double totLwS = 0;
    double numLw = 0;
    double totReadS = 0;
    double numRead = 0;
    double totEngS = 0;
    double numEng = 0;

    string line;
    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    // read lines until an empty line is read
    while (!line.empty()) {
        string category;
        double score;
        get_category_and_score(line, &category, &score);

        // process the grade entry
        if (category == "exam") {
            // TODO(student): process exam score
            totExamS += score;
            numExams++;
        } else if (category == "final-exam") {
            // TODO(student): process final score
            finExamS += score;
            totExamS += score;
            numExams++;
        } else if (category == "hw") {
            // TODO(student): process hw score
            totHwS += score;
            numHw++;
        } else if (category == "lw") {
            // TODO(student): process lw score
            if (score != 0){
                totLwS += 100;
                numLw++;
            } else {
                //totLwS += 0;
                numLw++;
            }
        } else if (category == "reading") {
            // TODO(student): process reading score
            totReadS += score;
            numRead++;
        } else if (category == "engagement") {
            // TODO(student): process engagement score
            totEngS += score;
            numEng++;
        } else {
            cout << "ignored invalid input" << endl;
        }

        // get the next line from standard input
        getline(cin, line);
    }

    // TODO(student): compute component averages
    double exam_average = totExamS / 3;
    if (finExamS > exam_average){
        exam_average = finExamS;
    }
    double hw_average = totHwS / numHw;
    double lw_average = totLwS / numLw;
    double reading = totReadS / numRead;
    double engagement = totEngS / numEng;
    if (numHw == 0){
        hw_average = 0;
    }
    if (numLw == 0){
        lw_average = 0;
    }
    if (numRead == 0){
        reading = 0;
    } 
    if (numEng == 0){
        engagement = 0;
    }

    // TODO(student): compute weighted total of components
    double weighted_total = (exam_average * 0.4)
                          + (hw_average * 0.4) 
                          + (lw_average * 0.1);
    reading += 15;
    if (reading >= 100.0){
        reading = 100;
    }
    engagement += 15;
    if (engagement >= 100.0){
        engagement = 100;
    }
    weighted_total += (reading * 0.05)
                    + (engagement * 0.05);


    // TODO(student): compute final letter grade
    char final_letter_grade;
    if (weighted_total >= 90.0){
        final_letter_grade = 'A';
    } else if (weighted_total >= 80.0){
        final_letter_grade = 'B';
    } else if (weighted_total >= 70.0){
        final_letter_grade = 'C';
    } else if (weighted_total >= 60.0){
        final_letter_grade = 'D';
    } else if (weighted_total < 60.0){
        final_letter_grade = 'F';
    }

    print_results(
        exam_average, hw_average, lw_average, reading, engagement,
        weighted_total, final_letter_grade);
}

// These methods are already implemented for you
// You should not need to modify them

void print_instructions() {
    cout << "enter grades as <category> <score>" << endl;
    cout << "  <category> := exam | final-exam | hw | lw | reading | engagement" << endl;
    cout << "     <score> := numeric value" << endl;
    cout << "enter an empty line to end input" << endl;
}

void get_category_and_score(
    const string& line,
    string* category,
    double* score) {
    // turn the string into an input stream
    std::istringstream sin(line);

    // read the category (as string) and score (as double) from the stream
    sin >> *category;
    sin >> *score;

    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *category = "ignore";
    }
}

void print_results(
    double exam_average,
    double hw_average,
    double lw_average,
    double reading,
    double engagement,
    double weighted_total,
    char final_letter_grade) {
    cout << "summary:" << endl;
    cout << "      exam average: " << exam_average << endl;
    cout << "        hw average: " << hw_average << endl;
    cout << "        lw average: " << lw_average << endl;
    cout << "           reading: " << reading << endl;
    cout << "        engagement: " << engagement << endl;
    cout << "    ---------------" << endl;

    cout << "    weighted total: " << weighted_total << endl;

    cout << "final letter grade: " << final_letter_grade << endl;
}
