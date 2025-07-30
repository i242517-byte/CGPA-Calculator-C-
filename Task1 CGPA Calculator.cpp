#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int MAX_COURSES = 20;
const int MAX_SEMESTERS = 10;

// convert grade to grade points
double gradeToPoints(const char* grade) {
    if (strcmp(grade, "A+") == 0 || strcmp(grade, "a+") == 0) return 4.0;
    if (strcmp(grade, "A") == 0 || strcmp(grade, "a") == 0) return 4.0;
    if (strcmp(grade, "A-") == 0 || strcmp(grade, "a-") == 0) return 3.7;
    if (strcmp(grade, "B+") == 0 || strcmp(grade, "b+") == 0) return 3.3;
    if (strcmp(grade, "B") == 0 || strcmp(grade, "b") == 0) return 3.0;
    if (strcmp(grade, "B-") == 0 || strcmp(grade, "b-") == 0) return 2.7;
    if (strcmp(grade, "C+") == 0 || strcmp(grade, "c+") == 0) return 2.3;
    if (strcmp(grade, "C") == 0 || strcmp(grade, "c") == 0) return 2.0;
    if (strcmp(grade, "C-") == 0 || strcmp(grade, "c-") == 0) return 1.7;
    if (strcmp(grade, "D+") == 0 || strcmp(grade, "d+") == 0) return 1.3;
    if (strcmp(grade, "D") == 0 || strcmp(grade, "d") == 0) return 1.0;
    if (strcmp(grade, "F") == 0 || strcmp(grade, "f") == 0) return 0.0;
    return 0.0; 
}

int main() {
    int numSemesters;
    double semesterGPAs[MAX_SEMESTERS];
    int totalCreditsPerSemester[MAX_SEMESTERS];
    
    cout << "CGPA Calculator\n";
    cout << "Enter number of semesters (max " << MAX_SEMESTERS << "): ";
    cin >> numSemesters;
    
    if (numSemesters > MAX_SEMESTERS) {
        cout << "Error: Maximum number of semesters exceeded.\n";
        return 1;
    }
    
    for (int sem = 0; sem < numSemesters; ++sem) {
        int numCourses;
        char grades[MAX_COURSES][3]; // Stores grades like "A", "B+", etc.
        int creditHours[MAX_COURSES];
        double totalGradePoints = 0.0;
        int totalCredits = 0;
        
        cout << "\nSemester " << sem+1 << ":\n";
        cout << "Enter number of courses (max " << MAX_COURSES << "): ";
        cin >> numCourses;
        
        if (numCourses > MAX_COURSES) {
            cout << "Error: Maximum number of courses exceeded.\n";
            return 1;
        }
        
        for (int i = 0; i < numCourses; ++i) {
            char grade[3];
            int credits;
            
            cout << "\nCourse " << i+1 << ":\n";
            cout << "Enter grade (A+, A, A-, B+, B, B-, C+, C, C-, D+, D, F): ";
            cin >> grade;
            cout << "Enter credit hours: ";
            cin >> credits;
            
            strcpy(grades[i], grade);
            creditHours[i] = credits;
            
            double gradePoints = gradeToPoints(grade);
            totalGradePoints += gradePoints * credits;
            totalCredits += credits;
        }
        
        // Calculate SGPA
        double semesterGPA = (totalCredits == 0) ? 0.0 : totalGradePoints / totalCredits;
        semesterGPAs[sem] = semesterGPA;
        totalCreditsPerSemester[sem] = totalCredits;
        
        // Display semester results
        cout << "\nSemester " << sem+1 << " Results:\n";
        cout << "--------------------------------\n";
        cout << left << setw(10) << "Course" << setw(10) << "Grade" << setw(15) << "Credit Hours" << endl;
        cout << "--------------------------------\n";
        
        for (int i = 0; i < numCourses; ++i) {
            cout << left << setw(10) << i+1 
                 << setw(10) << grades[i] 
                 << setw(15) << creditHours[i] << endl;
        }
        
        cout << "--------------------------------\n";
        cout << fixed << setprecision(2);
        cout << "Total Credits: " << totalCredits << endl;
        cout << "Semester GPA: " << semesterGPA << endl;
    }
    
    // Calculate CGPA
    double totalGradePointsAllSemesters = 0.0;
    int totalCreditsAllSemesters = 0;
    
    for (int i = 0; i < numSemesters; ++i) {
        totalGradePointsAllSemesters += semesterGPAs[i] * totalCreditsPerSemester[i];
        totalCreditsAllSemesters += totalCreditsPerSemester[i];
    }
    
    double cgpa = (totalCreditsAllSemesters == 0) ? 0.0 : totalGradePointsAllSemesters / totalCreditsAllSemesters;
    
    // Display CGPA
    cout << "\nFinal Results:\n";
    cout << "================================\n";
    cout << fixed << setprecision(2);
    cout << "Overall CGPA: " << cgpa << endl;
    cout << "Total Credits Across All Semesters: " << totalCreditsAllSemesters << endl;
    cout << "================================\n";
    
    return 0;
}
