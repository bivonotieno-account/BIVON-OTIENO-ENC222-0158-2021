#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* =======================
   Student Class
   ======================= */
class Student {
private:
    int studentID;
    string name;

public:
    Student(int id, string n) {
        studentID = id;
        name = n;
    }

    int getID() const {
        return studentID;
    }

    string getName() const {
        return name;
    }
};

/* =======================
   Course Class
   ======================= */
class Course {
private:
    string courseCode;
    string courseName;

public:
    Course(string code, string name) {
        courseCode = code;
        courseName = name;
    }

    string getCourseCode() const {
        return courseCode;
    }

    string getCourseName() const {
        return courseName;
    }
};

/* =======================
   Registration Class
   (Association)
   ======================= */
class Registration {
private:
    Student* student;   // associated Student
    Course* course;     // associated Course
    string registrationDate;

public:
    Registration(Student* s, Course* c, string date) {
        student = s;
        course = c;
        registrationDate = date;
    }

    void display() const {
        cout << "Student: " << student->getName()
             << " (ID: " << student->getID() << ")\n";
        cout << "Course: " << course->getCourseName()
             << " (" << course->getCourseCode() << ")\n";
        cout << "Date: " << registrationDate << endl;
    }
};

/* =======================
   Registrar Class
   (Dependency)
   ======================= */
class Registrar {
public:
    // Registrar DEPENDS on Registration to register students
    Registration registerStudent(Student* s, Course* c) {
        return Registration(s, c, "10-Feb-2026");
    }
};

/* =======================
   Main Function
   ======================= */
int main() {
    // Create students
    Student student1(101, "Alice");
    Student student2(102, "Bob");

    // Create courses
    Course course1("CS101", "Introduction to Programming");
    Course course2("MATH201", "Calculus II");

    // Registrar object
    Registrar registrar;

    // Perform registrations
    Registration reg1 = registrar.registerStudent(&student1, &course1);
    Registration reg2 = registrar.registerStudent(&student2, &course2);

    // Display registration details
    cout << "=== Registration Details ===\n\n";
    reg1.display();
    cout << endl;
    reg2.display();

    return 0;
}
