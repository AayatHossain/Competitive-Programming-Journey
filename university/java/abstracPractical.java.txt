// Main class to run our example
public class DevelopmentTeam {
    public static void main(String[] args) {
        JuniorDeveloper junior = new JuniorDeveloper("Alice", "Java");
        SeniorDeveloper senior = new SeniorDeveloper("Bob", 10);
        
        junior.workOnTask();  // Junior implements abstract method
        senior.reviewCode();  // Senior uses final method
        
        // Testing final variables
        System.out.println("Company Policy: " + Developer.COMPANY_POLICY);
        
        // Testing final method restrictions
        // junior.COMPANY_POLICY = "New Policy"; // Error - final variable
        // junior.changeCompanyPolicy();         // Error - final method
    }
}

// Abstract class defining developer requirements
abstract class Developer {
    // Final constant - cannot be changed by any subclass
    public static final String COMPANY_POLICY = "Always document your code!";
    
    protected String name;
    protected String specialization;
    
    public Developer(String name, String specialization) {
        this.name = name;
        this.specialization = specialization;
    }
    
    // Abstract method - must be implemented by subclasses
    public abstract void workOnTask();
    
    // Final method - cannot be overridden by subclasses
    public final void attendMeeting() {
        System.out.println(name + " is attending the daily standup meeting.");
    }
    
    // Final method demonstrating company policy
    public final void followCompanyPolicy() {
        System.out.println(name + " follows: " + COMPANY_POLICY);
    }
}

// Junior Developer class - must implement abstract methods
class JuniorDeveloper extends Developer {
    public JuniorDeveloper(String name, String specialization) {
        super(name, specialization);
    }
    
    @Override
    public void workOnTask() {
        System.out.println(name + " is implementing a feature in " + specialization);
        System.out.println("(This implementation was required by the Senior Developer)");
    }
    
    // Cannot override final methods
    // public void attendMeeting() { } // Error!
}

// Senior Developer class - can add additional functionality
class SeniorDeveloper extends Developer {
    private int yearsOfExperience;
    
    public SeniorDeveloper(String name, int yearsOfExperience) {
        super(name, "Architecture");
        this.yearsOfExperience = yearsOfExperience;
    }
    
    @Override
    public void workOnTask() {
        System.out.println(name + " is designing the system architecture");
    }
    
    // Additional method only for seniors
    public void reviewCode() {
        System.out.println(name + " is reviewing junior developers' code");
        followCompanyPolicy();  // Calling final method
    }
    
    // Can access final variable but not modify it
    public void showPolicy() {
        System.out.println("Current policy: " + COMPANY_POLICY);
    }
}