package com.mycompany.practice;
import java.util.*;

class Course {

    String courseName;
    String courseCode;
    int creditHours;

    Course(String courseName, String courseCode, int creditHours) {
        this.courseName = courseName;
        this.courseCode = courseCode;
        this.creditHours = creditHours;
    }

    void calculateDifficulty() {
        System.out.println("Course " + courseCode + " is of medium difficulty.");
    }
}

class UnderGraduateCourse extends Course {

    boolean generalEducationRequirement;

    UnderGraduateCourse(String courseName, String courseCode, int creditHours, boolean generalEducationRequirement) {
        super(courseName, courseCode, creditHours);
        this.generalEducationRequirement = generalEducationRequirement;
    }

    @Override
    void calculateDifficulty() {
        if (generalEducationRequirement) {
            System.out.println("Course " + courseCode + " is rated as Medium difficulty.");
        } else {
            System.out.println("Course " + courseCode + " is rated as Hard difficulty.");
        }
    }
}

class PostGraduateCourse extends Course {

    boolean researchComponent;

    PostGraduateCourse(String courseName, String courseCode, int creditHours, boolean researchComponent) {
        super(courseName, courseCode, creditHours);
        this.researchComponent = researchComponent;
    }

    @Override
    void calculateDifficulty() {
        if (researchComponent) {
            System.out.println("Course " + courseCode + " is considered Hard.");
        } else {
            System.out.println("Course " + courseCode + " is considered Medium.");
        }
    }
}

class Student {

    String studentID;
    String name;
    ArrayList<Course> enrolledCourses;

    Student(String studentID, String name) {
        this.studentID = studentID;
        this.name = name;
        this.enrolledCourses = new ArrayList<>();
    }

    void enrollInCourse(Course course) {
        enrolledCourses.add(course);
    }

    void dropCourse(Course course) {
        enrolledCourses.remove(course);
    }

    void courseList() {
        System.out.println(name + " has registered for the following courses:");
        for (Course course : enrolledCourses) {
            System.out.println(course.courseName);
        }
    }
}

class UnderGraduateStudent extends Student {
    int maxCourse = 6;
    String advisorName;

    UnderGraduateStudent(String studentID, String name, String advisorName) {
        super(studentID, name);
        this.advisorName = advisorName;
    }

    @Override
    void enrollInCourse(Course course) {
        if (!(course instanceof UnderGraduateCourse)) {
            System.out.println("Student " + name + " is not allowed to take postgraduate course " + course.courseName);
        } else {
            if (enrolledCourses.size() < maxCourse) {
                enrolledCourses.add(course);
            } else {
                System.out.println("Student " + name + " has already reached the enrollment limit for undergraduate courses.");
            }
        }
    }
}

class PostGraduateStudent extends Student {
    int maxCourse = 4;
    String thesisTopic;

    PostGraduateStudent(String studentID, String name, String thesisTopic) {
        super(studentID, name);
        this.thesisTopic = thesisTopic;
    }

    @Override
    void enrollInCourse(Course course) {
        if (enrolledCourses.size() < maxCourse) {
            enrolledCourses.add(course);
        } else {
            System.out.println("Student " + name + " has exceeded the maximum allowed courses for postgraduates.");
        }
    }
}

public class Practice {

    public static void main(String[] args) {
        Course ugCourse1 = new UnderGraduateCourse("Intro to Math", "MATH101", 3, true);
        Course ugCourse2 = new UnderGraduateCourse("Physics I", "PHYS105", 3, false);
        Course pgCourse1 = new PostGraduateCourse("Advanced AI", "CS701", 4, true);
        Course pgCourse2 = new PostGraduateCourse("Quantum Computing", "CS702", 4, false);

        ugCourse1.calculateDifficulty(); // UG course with gen ed
        ugCourse2.calculateDifficulty(); // UG course without gen ed
        pgCourse1.calculateDifficulty(); // PG course with research
        pgCourse2.calculateDifficulty(); // PG course without research

        UnderGraduateStudent ugStudent = new UnderGraduateStudent("UG123", "Alice", "Dr. Brown");
        PostGraduateStudent pgStudent = new PostGraduateStudent("PG456", "Bob", "AI in Education");

        // Undergraduate student enrolling in UG and PG courses
        ugStudent.enrollInCourse(ugCourse1); // Should succeed
        ugStudent.enrollInCourse(pgCourse1); // Should be rejected
        ugStudent.courseList();

        // Postgraduate student enrolling in PG and UG courses
        pgStudent.enrollInCourse(pgCourse1); // Should succeed
        pgStudent.enrollInCourse(ugCourse2); // Allowed (based on original logic)
        pgStudent.courseList();

        // Test enrollment limit for UG student
        ugStudent.enrollInCourse(new UnderGraduateCourse("Chemistry", "CHEM101", 3, true));
        ugStudent.enrollInCourse(new UnderGraduateCourse("Biology", "BIO102", 3, false));
        ugStudent.enrollInCourse(new UnderGraduateCourse("Literature", "ENG103", 2, true));
        ugStudent.enrollInCourse(new UnderGraduateCourse("Computer Science", "CS104", 3, false));
        ugStudent.enrollInCourse(new UnderGraduateCourse("Economics", "ECON105", 3, true)); // Should hit the limit
        ugStudent.courseList();
    }
}
