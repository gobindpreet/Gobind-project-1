#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <iomanip>
#include <map>

// Function to calculate GPA for a given grade point
double calculate_gpa(int grade_points) {
    if (grade_points == 10) return 10.0; // A+
    if (grade_points >= 9) return 9.0;
    if (grade_points >= 8) return 8.0;
    if (grade_points >= 7) return 7.0;
    if (grade_points >= 6) return 6.0;
    if (grade_points >= 5) return 5.0;
    if (grade_points >= 4) return 4.0; // D
    return 0.0; // F
}

// Function to get the grade letter for a given grade point
std::string get_grade_letter(int grade_points) {
    if (grade_points == 10) return "A+";
    if (grade_points == 9) return "A";
    if (grade_points == 8) return "B+";
    if (grade_points == 7) return "B";
    if (grade_points == 6) return "C+";
    if (grade_points == 5) return "C";
    if (grade_points == 4) return "D";
    return "F";
}

int main() {
    int num_semesters;
    std::cout << "Enter the total number of semesters (e.g., 8): ";
    std::cin >> num_semesters;

    if (num_semesters <= 0) {
        std::cout << "Number of semesters must be positive.\n";
        return 1;
    }

    double overall_total_grade_points_product_credits = 0.0;
    int overall_total_credits = 0;

    for (int s = 1; s <= num_semesters; ++s) {
        std::cout << "\n--- Semester " << s << " ---" << std::endl;
        int num_courses;
        std::cout << "Enter the number of courses for Semester " << s << ": ";
        std::cin >> num_courses;

        if (num_courses <= 0) {
            std::cout << "Number of courses must be positive for this semester. Skipping.\n";
            continue; // Skip to next semester if no courses
        }

        double semester_total_grade_points_product_credits = 0.0;
        int semester_total_credits = 0;

        for (int c = 1; c <= num_courses; ++c) {
            int grade_points;
            int credits;

            std::cout << "  Enter grade points (0-10) for Course " << c << " in Semester " << s << ": ";
            std::cin >> grade_points;
            while (grade_points < 0 || grade_points > 10) {
                std::cout << "  Invalid grade points. Please enter between 0 and 10: ";
                std::cin >> grade_points;
            }

            std::cout << "  Enter credits for Course " << c << " in Semester " << s << ": ";
            std::cin >> credits;
            while (credits <= 0) {
                std::cout << "  Credits must be positive. Please enter again: ";
                std::cin >> credits;
            }

            double course_gpa = calculate_gpa(grade_points);
            semester_total_grade_points_product_credits += course_gpa * credits;
            semester_total_credits += credits;
        }

        if (semester_total_credits == 0) {
            std::cout << "  No credits earned in Semester " << s << ". Semester GPA not calculable.\n";
        } else {
            double semester_gpa = semester_total_grade_points_product_credits / semester_total_credits;
            std::cout << "  Semester " << s << " GPA: " << std::fixed << std::setprecision(2) << semester_gpa << std::endl;
        }
        
        overall_total_grade_points_product_credits += semester_total_grade_points_product_credits;
        overall_total_credits += semester_total_credits;
    }

    std::cout << "\n--- Overall CGPA Calculation ---" << std::endl;
    if (overall_total_credits == 0) {
        std::cout << "Cannot calculate Overall CGPA: Total credits across all semesters are zero.\n";
    } else {
        double overall_cgpa = overall_total_grade_points_product_credits / overall_total_credits;
        std::cout << "Total Credits across all semesters: " << overall_total_credits << std::endl;
        std::cout << "Overall CGPA: " << std::fixed << std::setprecision(2) << overall_cgpa << std::endl;
    }

    return 0;
}
