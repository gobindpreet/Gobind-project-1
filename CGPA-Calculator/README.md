# CGPA Calculator

This is a simple C++ program that calculates a student's CGPA (Cumulative Grade Point Average) based on the courses taken in the current semester and the previous CGPA. It allows the user to input course details, such as course name, total marks, and obtained marks, and calculates both the GPA for the current semester and the overall CGPA.

## Features

- Allows the user to enter previous CGPA and details for each course in the current semester.
- Calculates the GPA for the current semester and the cumulative CGPA.
- Displays a detailed list of courses with total and obtained marks.

## Table of Contents
1. [Formulae](#formulae)
2. [Code Explanation](#code-explanation)
    - [Course Class](#course-class)
    - [Student Class](#student-class)
    - [Main Function](#main-function)
3. [Sample Output](#sample-output)
4. [About Me](#about-me)

## Formulae

The **GPA (Grade Point Average)** is calculated using the formula:

![gpa](https://github.com/user-attachments/assets/4f13c2c6-e64d-4fd9-917c-039483df070b)

Where **Grade Points** for a course are calculated as:

![gradePoints](https://github.com/user-attachments/assets/6e379a86-3309-44ee-a01f-106143d2ed75)

**Course Credits** represent the weight or importance of the course, often derived from the total marks.

BROCODE: https://www.youtube.com/@BroCodez

## Code Explanation

### Course Class

The `Course` class represents a single course with the following attributes:

- **courseName**: The name of the course.
- **totalMarks**: The total marks for the course.
- **obtainedMarks**: The marks obtained by the student.

The `Course` class contains the following methods:

- **Constructor**: Initializes the course name, total marks, and obtained marks.
- **getCredits()**: Returns the number of credits for the course. 
- **getGradePoints()**: Calculates the grade points based on the obtained marks and credits. 
- **getCourseName()**: Returns the course name.
- **getTotalMarks()**: Returns the total marks of the course.
- **getObtainedMarks()**: Returns the obtained marks for the course.

### Student Class

The `Student` class represents a student with the following attributes:

- **courses**: A vector of `Course` objects representing the courses taken by the student.
- **previousCGPA**: The student's previous CGPA.

The `Student` class contains the following methods:

- **Constructor**: Initializes the student's previous CGPA.
- **addCourse()**: Adds a course to the student's list of courses.
- **calculateGPA()**: Calculates the GPA for the current semester based on the grade points and credits of all the courses taken. It uses the formula:
  

  GPA = `Total Grade Points\Total Credits`
  
- **calculateCGPA()**: Calculates the cumulative CGPA by averaging the previous CGPA and the current GPA:
  
 
  CGPA = `(Previous CGPA +Current GPA) / 2.0`

- **displayCourses()**: Displays the details of all the courses, including course name, total marks, and obtained marks.

### Main Function

The main function is responsible for the following:

1. **Input Previous CGPA**: The program first prompts the user to enter their previous CGPA. It checks that the CGPA is between 0.0 and 4.0.
2. **Input Number of Courses**: The program prompts the user to enter the number of courses taken in the current semester. The user can enter a number between 1 and 10.
3. **Input Course Details**: For each course, the user is asked to input the course name, total marks, and obtained marks. The program ensures that the obtained marks are valid (i.e., between 0 and the total marks).
4. **Add Courses to Student**: After the user inputs the course details, each course is added to the student's record.
5. **Display Courses**: The program displays a list of all the courses, showing their names, total marks, and obtained marks.
6. **Calculate and Display GPA and CGPA**: The program calculates the GPA for the current semester and the cumulative CGPA, displaying them in the format with 2 decimal places.

