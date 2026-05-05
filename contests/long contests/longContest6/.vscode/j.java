class Course {
    protected String courseName;
    protected String courseCode;
    protected int creditHours;

    public Course(String courseName, String courseCode, int creditHours) {
        this.courseName = courseName;
        this.courseCode = courseCode;
        this.creditHours = creditHours;
    }

    public String getCourseName() {
        return courseName;
    }

    public String getCourseCode() {
        return courseCode;
    }

    public int getCreditHours() {
        return creditHours;
    }

    public String calculateDifficulty() {
        return "Standard difficulty";
    }
}

class UndergraduateCourse extends Course {
    private boolean generalEducationRequirement;

    public UndergraduateCourse(String courseName, String courseCode, int creditHours, boolean generalEducationRequirement) {
        super(courseName, courseCode, creditHours);
        this.generalEducationRequirement = generalEducationRequirement;
    }

    public boolean isGeneralEducationRequirement() {
        return generalEducationRequirement;
    }

    @Override
    public String calculateDifficulty() {
        return "Undergraduate difficulty level: " + (generalEducationRequirement ? "Easier" : "Standard");
    }
}

class PostgraduateCourse extends Course {
    private boolean researchComponent;

    public PostgraduateCourse(String courseName, String courseCode, int creditHours, boolean researchComponent) {
        super(courseName, courseCode, creditHours);
        this.researchComponent = researchComponent;
    }

    public boolean hasResearchComponent() {
        return researchComponent;
    }

    @Override
    public String calculateDifficulty() {
        return "Postgraduate difficulty level: " + (researchComponent ? "Advanced" : "Standard");
    }
}





import java.util.ArrayList;
import java.util.List;

class Student {
    protected String studentID;
    protected String name;
    protected List<Course> enrolledCourses;

    public Student(String studentID, String name) {
        this.studentID = studentID;
        this.name = name;
        this.enrolledCourses = new ArrayList<>();
    }

    public String getStudentID() {
        return studentID;
    }

    public String getName() {
        return name;
    }

    public List<Course> getEnrolledCourses() {
        return enrolledCourses;
    }

    public int getMaxEnrollment() {
        return 0;
    }

    public void enrollInCourse(Course course) {
        if (enrolledCourses.size() >= getMaxEnrollment()) {
            System.out.println("Enrollment failed: " + name + " has reached the maximum of " 
                + getMaxEnrollment() + " courses.");
            return;
        }
        enrolledCourses.add(course);
        System.out.println(name + " enrolled in " + course.getCourseName());
    }

    public void dropCourse(Course course) {
        if (enrolledCourses.remove(course)) {
            System.out.println(name + " dropped " + course.getCourseName());
        } else {
            System.out.println(name + " is not enrolled in " + course.getCourseName());
        }
    }
}

class UndergraduateStudent extends Student {
    private String advisorName;

    public UndergraduateStudent(String studentID, String name, String advisorName) {
        super(studentID, name);
        this.advisorName = advisorName;
    }

    public String getAdvisorName() {
        return advisorName;
    }

    @Override
    public int getMaxEnrollment() {
        return 6;
    }

    @Override
    public void enrollInCourse(Course course) {
        super.enrollInCourse(course);
        if (enrolledCourses.size() <= getMaxEnrollment()) {
            System.out.println("Undergraduate advisor " + advisorName + " has been notified.");
        }
    }
}

class PostgraduateStudent extends Student {
    private String thesisTopic;

    public PostgraduateStudent(String studentID, String name, String thesisTopic) {
        super(studentID, name);
        this.thesisTopic = thesisTopic;
    }

    public String getThesisTopic() {
        return thesisTopic;
    }

    @Override
    public int getMaxEnrollment() {
        return 4;
    }

    @Override
    public void enrollInCourse(Course course) {
        super.enrollInCourse(course);
        if (enrolledCourses.size() <= getMaxEnrollment()) {
            System.out.println("Thesis topic: " + thesisTopic + ". Course enrollment may affect research progress.");
        }
    }
}




