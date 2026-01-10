**Student Management System**
==============================
(Programming Fundamentals – C Language Project) 

##### Project Information

Project Title: Student Management System

Course: Programming Fundamentals

Programming Language: C

Project Type: Console Based Application

Project Nature: Group Project

##### Group Members

Haroon Ahmad	25011519-033	Group Leader

Ameer Aqsam	25011519-009	Group Member

Ayesha Noor	25011519-058	Group Member

# Introduction

Student Management System ek console based project hai jo C programming language me develop kiya gaya hai. Is project ka main objective yeh hai ke students aur academic records ko efficiently manage kiya ja sake. System me Admin aur Student dono ke liye alag alag functionalities provide ki gayi hain.

Is project ke zariye humein file handling, structures, functions aur modular programming ka practical experience mila. Data ko permanently store karne ke liye text files ka use kiya gaya hai.

Tools & Technologies Used

1. Programming Language: C
2. Compiler: GCC / Turbo C
3. Concepts Used:
4. Structures
5. Functions
6. File Handling
7. Header Files
8. Loops
9. Conditional Statements
10. Data Storage: Text Files (.txt)

# Project Structure

Project ko different modules me divide kiya gaya hai taake code understandable aur manageable rahe.

#### main.c
Program ka main control file jo user se choice leta hai (Admin / Student)

#### admin.c / admin.h
Admin related functionalities ke liye

#### student.c / student.h
Student related functionalities ke liye

#### Text Files (Data Storage):

1. students.txt
2. admin_login.txt
3. courses.txt
4. enrollments.txt
5. assignments.txt
6. submissions.txt
7. grades.txt
8. Admin Module

**Admin ke paas system ka complete control hota hai. Admin login ke baad following operations perform kar sakta hai:
**
## Admin Module
### Student Management
- New student add karna
- Existing student delete karna
- Student ka data update karna
- Student records view karna

### Course Management
- New course add karna
- Course delete karna
- Course update karna
- All courses view karna

### Enrollment Management
- Student ko course me enroll karna
- Enrollment remove karna
- Enrollment details view karna

### Assignment Management
- Assignment add karna
- Assignment delete karna
- Assignments view karna
- Student submissions check karna

### Grades Management
- Student ke grades add karna
- Grades delete karna
- Grades view karna

**Admin ke login credentials aur data files ke zariye manage kiye jate hain.**

## Student Module

Student apni ID aur password ke zariye system me login karta hai. Student ke options limited hote hain:
- Apna profile view karna
- Enrolled courses dekhna
- Courses me enroll hona
- Assignments submit karna
- Apne grades check karna
- Student sirf apna hi data access kar sakta hai.

## Main Module

Main module program ka starting point hota hai. Program start hone par user ko following options milte hain:

1. Admin Login
2. Student Login
3. Exit

User ki choice ke mutabiq relevant module ke functions call hote hain.
Data Storage

- Is project me database ki jagah text files ka use kiya gaya hai. Har file specific type ka data store karti hai. 
- File handling ke zariye data read aur write kiya jata hai, jis se data program close hone ke baad bhi safe rehta hai.

## Conclusion

Student Management System ek simple lekin effective project hai jo C programming ke core concepts ko clearly demonstrate karta hai. Is project ke zariye humein teamwork, problem solving aur programming logic ko improve karne ka moka mila. Future me is project ko GUI ya database ke sath aur enhance kiya ja sakta hai.
