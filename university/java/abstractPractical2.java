public class DevelopmentTeam {
    public static void main(String[] args) {
        JuniorDeveloper junior = new JuniorDeveloper("Alice", "Java");
        SeniorDeveloper senior = new SeniorDeveloper("Bob");
        
        junior.completeTask();  // Junior implements abstract method
        junior.submitCode();    // Junior implements abstract method
        senior.reviewCode(junior); // Senior's concrete method
        
        // Testing final restrictions
        // Developer.COMPANY_RULES = "New Rules"; // Error - final variable
        // junior.overrideSecurityCheck();       // Error - final method
    }
}

abstract class SeniorDeveloper {
    protected final String COMPANY_RULES = "Secure coding practices mandatory";
    protected String name;
    
    public SeniorDeveloper(String name) {
        this.name = name;
    }
    
    // Final method - cannot be changed by juniors
    public final void securityCheck() {
        System.out.println("Running mandatory security validation...");
    }
    
    // Concrete method seniors can use
    public void reviewCode(JuniorDeveloper junior) {
        System.out.println(name + " is reviewing code by " + junior.getName());
        securityCheck(); // Calling final method
    }
    
    // Abstract methods - juniors must implement
    public abstract void completeTask();
    public abstract void submitCode();
}

class JuniorDeveloper extends SeniorDeveloper {
    private String currentLanguage;
    
    public JuniorDeveloper(String name, String language) {
        super(name);
        this.currentLanguage = language;
    }
    
    @Override
    public void completeTask() {
        System.out.println(name + " is completing task in " + currentLanguage);
        System.out.println("(This implementation was required by SeniorDeveloper)");
    }
    
    @Override
    public void submitCode() {
        System.out.println(name + " is submitting code for review");
        System.out.println("Following company rules: " + COMPANY_RULES);
    }
    
    public String getName() {
        return name;
    }
    
    // Can't override final methods
    // public void securityCheck() { } // Compiler error
}