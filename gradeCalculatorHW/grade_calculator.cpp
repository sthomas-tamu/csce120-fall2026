// These headers define some of the classes and functions we need
#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <sstream>

// ONLY MAKE CHANGES WHERE THERE IS A TODO(student)

// These using declarations let us refer to things more simply
// e.g. instead of "std::cout" we can just write "cout"
using std::cout, std::endl, std::cin, std::string, std::getline;

// Some methods are already implemented for you
// You should not modify them
// Even minor changes might cause you to fail test cases for the wrong reasons

void println(const string& str, double value) {
    cout << str << std::setw(6) << value << endl;
}
void println(const string& str, char value) {
    cout << str << value << endl;
}
void println(const string& str) {
    cout << str << endl;
}

// pretty-print a summary of the grades
void print_results(double homework,
                   double labwork,
                   double midterm_exams,
                   double final_exam,
                   double quizzes,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade) {
    cout << std::fixed << std::setprecision(2);
    println("summary:");
    println("      homework: ", homework);
    println("       labwork: ", labwork);
    println(" midterm exams: ", midterm_exams);
    println("    final exam: ", final_exam);
    println("       quizzes: ", quizzes);
    println("    engagement: ", engagement);
    println("----------------------");
    println("weighted total: ", weighted_total);
    println("final letter grade: ", final_letter_grade);
}

// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
void get_category_and_score(const string& line,
                            string* category,
                            double* score) {
    // turn the string into an input stream
    std::istringstream sin(line);

    // read the category (as string) and score (as double) from the stream
    sin >> *category >> *score;

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

int main() {
    // TODO(student): add more variables, as needed
    double homework_sum = 0;
    int homework_count = 0;
    double homework_score = 0;

    double labwork_sum = 0;
    int labwork_count = 0;
    double labwork_score = 0;

    double exam_sum = 0;
    double exam_min = std::numeric_limits<double>::max();
    int exam_count = 0;
    double midterm_exams_score = 0;

    double final_exam_score = 0;

    double quiz_sum = 0;
    int quiz_count = 0;
    double quizzes_score = 0;

    double engagement_raw = 0;
    double engagement_score = 0;

    string line;
    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    // read lines until an empty line is read
    while (!line.empty()) {
        string category;
        double score;
        get_category_and_score(line, &category, &score);

        // process the grade entry
        if (category == "hw") {
            // TODO(student): process a homework score
            homework_sum += score;
            homework_count++;
        } else if (category == "lw") {
            // TODO(student): process a labwork score
            labwork_sum += score;
            labwork_count++;
        } else if (category == "exam") {
            // TODO(student): process a midterm exam score
            exam_sum += score;
            if (score < exam_min) {
                exam_min = score;
            }
            exam_count++;
        } else if (category == "final-exam") {
            // TODO(student): process the final exam score
            final_exam_score = score;
        } else if (category == "quiz") {
            // TODO(student): process a reading score
            quiz_sum += score;
            quiz_count++;
        } else if (category == "engagement") {
            // TODO(student): process the engagement score
            engagement_raw = score;
        } else {
            println("ignored invalid input");
        }

        // get the next line from standard input
        getline(cin, line);
    }

    // TODO(student): finalize computation of component scores
    if (homework_count > 0) {
        homework_score = homework_sum / homework_count;
        if (homework_score > 100) {
            homework_score = 100;
        }
    }

    if (labwork_count > 0) {
        labwork_score = (labwork_sum / labwork_count) * 100;
    }

    if (exam_count > 0) {
        midterm_exams_score = (exam_sum - exam_min / 2) / (exam_count - 0.5);
    }

    if (quiz_count > 0) {
        quizzes_score = (quiz_sum / quiz_count) * 10;
    }

    engagement_score = engagement_raw + 15;
    if (engagement_score > 100) {
        engagement_score = 100;
    }

    // TODO(student): compute weighted total of components
    double weighted_total = homework_score * 0.10
                           + labwork_score * 0.05
                           + midterm_exams_score * 0.35
                           + final_exam_score * 0.25
                           + quizzes_score * 0.20
                           + engagement_score * 0.05;

    // TODO(student): compute final letter grade
    int rounded_total = static_cast<int>(weighted_total + 0.5);
    char final_letter_grade = 'X';
    if (rounded_total >= 90) {
        final_letter_grade = 'A';
    } else if (rounded_total >= 80) {
        final_letter_grade = 'B';
    } else if (rounded_total >= 70) {
        final_letter_grade = 'C';
    } else if (rounded_total >= 60) {
        final_letter_grade = 'D';
    } else {
        final_letter_grade = 'F';
    }

    print_results(
        homework_score,
        labwork_score,
        midterm_exams_score,
        final_exam_score,
        quizzes_score,
        engagement_score,
        weighted_total,
        final_letter_grade);
}

/*
Used AI to define maximum value for initial lowest test score value
I forgot the syntax for the minimum value for int, double, etc. and Claude suggested
I use max value instead so the very first value that is inputted for a test score is
now the new comparison for the rest of the tests because it's guaranteed to be less
than the std numerical max() value (if all that made sense, idk how else to explain it)

Also used AI to help with rounding logic with the weighted total (line 188)
Apparently, this line adds 0.5 to the weighted total, then truncates the decimal
If the value has a decimal under 0.5, that counts as a round down.
If the value has a decimal over 0.5, adding 0,5 will bring the value past the rounded
number and truncating the spillover decimal will result in the correct rounded value.
*/
