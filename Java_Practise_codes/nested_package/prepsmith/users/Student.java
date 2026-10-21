package prepsmith.users;
import prepsmith.learning.Learner; 



// FUTURE REVIEW: Student promises the Learner methods but does not define them itself.
// Therefore it must be abstract; only concrete subclasses can be created.
public abstract class Student implements Learner {

    private String name;
    private String email; // Accessible only inside Student.
    String studentId; // Package-private: accessible only inside exactly prepsmith.users.
    protected int weeklyGoal; // Accessible in Student, same-package classes, and subclasses.
    private int sessionsCompleted = 0; 

    public Student(String name, String email, String studentId, int weeklyGoal) { // Constructor of the public class Student
        this.name = name;
        this.email = email; 
        this.studentId = studentId; 
        this.weeklyGoal = weeklyGoal; 
    }

    public String getName() {
        return name;
    }

    public String getMaskedEmail() {
        return "***@email.com"; 
    }

    // Protected: child classes record a session, while unrelated classes cannot change the count.
    protected void completeLearningSession() {
        sessionsCompleted++; 
    }

    // Public getter exposes the private value without allowing outside code to modify it directly.
    public int getSessionCompleted() {
        return sessionsCompleted; 
    }
}
