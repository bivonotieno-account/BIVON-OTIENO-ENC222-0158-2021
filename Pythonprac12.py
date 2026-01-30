# =======================
# Student Class
# =======================
class Student:
    def __init__(self, student_id, name):
        self._student_id = student_id
        self._name = name

    def get_id(self):
        return self._student_id

    def get_name(self):
        return self._name


# =======================
# Course Class
# =======================
class Course:
    def __init__(self, course_code, course_name):
        self._course_code = course_code
        self._course_name = course_name

    def get_course_code(self):
        return self._course_code

    def get_course_name(self):
        return self._course_name


# =======================
# Registration Class
# (Association)
# =======================
class Registration:
    def __init__(self, student, course, registration_date):
        self.student = student    # associated Student
        self.course = course      # associated Course
        self.registration_date = registration_date

    def display(self):
        print(f"Student: {self.student.get_name()} "
              f"(ID: {self.student.get_id()})")
        print(f"Course: {self.course.get_course_name()} "
              f"({self.course.get_course_code()})")
        print(f"Date: {self.registration_date}")


# =======================
# Registrar Class
# (Dependency)
# =======================
class Registrar:
    # Registrar DEPENDS on Registration to register students
    def register_student(self, student, course):
        return Registration(student, course, "10-Feb-2026")


# =======================
# Main Program
# =======================
if __name__ == "__main__":
    # Create students
    student1 = Student(101, "Alice")
    student2 = Student(102, "Bob")

    # Create courses
    course1 = Course("CS101", "Introduction to Programming")
    course2 = Course("MATH201", "Calculus II")

    # Registrar object
    registrar = Registrar()

    # Perform registrations
    reg1 = registrar.register_student(student1, course1)
    reg2 = registrar.register_student(student2, course2)

    # Display registration details
    print("=== Registration Details ===\n")
    reg1.display()
    print()
    reg2.display()
