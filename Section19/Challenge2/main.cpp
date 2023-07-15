// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int output_width{20};
    cout << setw(output_width - 10) << left << setfill(' ') << "Student";
    cout << setw(10) << right << setfill(' ') << "Score";
    cout << endl;
    cout << setw(output_width) << setfill('-') << "" << endl;

    ifstream responses_file;
    responses_file.open("Section19/Challenge2/responses.txt");

    if (!responses_file.is_open())
    {
        cerr << "Error opening file, aborting program" << endl;
        return 1;
    }

    string correct_answers{};
    getline(responses_file, correct_answers);

    string name{};
    string student_answers{};
    int score{0};
    double avg_score{0.0};
    int total_students{0};
    while (!responses_file.eof())
    {
        total_students++;
        score = 0;

        responses_file >> name >> student_answers;

        for (int i{0}; i < 5; i++)
        {
            if (correct_answers[i] == student_answers[i])
                score++;
        }
        cout << name << setw(output_width - name.size()) << right << setfill(' ') << score << endl;
        avg_score += score;
    }
    avg_score = avg_score / total_students;
    cout << setw(output_width) << setfill('-') << "" << endl;
    cout << setprecision(1) << fixed;
    cout << setw(output_width - 5) << left << setfill(' ') << "Average score";
    cout << setw(5) << right << setfill(' ') << avg_score << endl;

    responses_file.close();
    return 0;
}

// Student                     Score
// ----------------------------
// Frank                             5
// Larry                              3
// Moe                              4
// Curly                             2
// Michael                         4
// ---------------------------
// Average score            3.6

// std::fstream ifile; //{"file1", std::ios::in};
// ifile.open("Section19/file1");

// std::cout << ifile.is_open() << std::endl;
// int c;
// ifile >> c;
// std::cout << c;

// ifile.close();