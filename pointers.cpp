// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <cstring>
#include <sstream>
#include <math.h>
typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

int promptInt(std::string message, int min, int max);
double promptDouble(std::string message, double min, double max);
void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student student;
    double average = 0.0;
    student.f_name = new char[128];
    student.l_name = new char[128];
    student.grades = new double[10];
    std::string message;
    
    // Sequence of user input -> store in fields of `student`
    student.id = promptInt("Please enter the student's id number: ", 0, 999999999);

    std::cout << "Please enter the student's first name: ";
    std::cin >> student.f_name;

    std::cout << "Please enter the student's last name: ";
    std::cin >> student.l_name;

    student.n_assignments = promptInt("Please enter how many assignments were graded: ", 1, 134217728);

    for (int i = 0; i < student.n_assignments; i++) 
    {
        std::stringstream stream;
        stream << "Please enter grade for assignment " << i << ": "; // otherwise cannot print i in function call
        message = stream.str();
        double grade = promptDouble(message, 0.0, 10000.0);
        student.grades[i] = grade;
    }

     // Call `CalculateStudentAverage(???, ???)`
    calculateStudentAverage(&student, &average);
    
    // Output `average`
    std::cout << "Student: " << student.f_name << " " << student.l_name << " " << "[" << student.id << "]" << "\n";
    std::cout << "  " << "Average Grade: " << average << "\n";

    return 0;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid int
   max: maximum value to accept as a valid int
*/
int promptInt(std::string message, int min, int max)
{
    // Code to prompt user for an int
    int userint;
    std::cout << message;
    std::cin >> userint;
    return userint;
}

/*
   message: text to output as the prompt
   min: minimum value to accept as a valid double
   max: maximum value to accept as a valid double
*/
double promptDouble(std::string message, double min, double max)
{
    // Code to prompt user for a double
    double userdouble;
    std::cout << message;
    std::cin >> userdouble;

    return userdouble;
}

/*
   object: pointer to anything - your choice! (but choose something that will be helpful)
   avg: pointer to a double (can store a value here)
*/
void calculateStudentAverage(void *object, double *avg)
{
    double temp_avg;
    // Code to calculate and store average grade
    Student new_student = *((Student*)object);
    double sum = 0.0;
    for (int i = 0; i < new_student.n_assignments; i++)
    {
        sum = sum + (double)new_student.grades[i];
    }
    temp_avg = (double)sum / (double)new_student.n_assignments;
    *avg = floor(temp_avg * 10 + 0.5) / 10;

}
