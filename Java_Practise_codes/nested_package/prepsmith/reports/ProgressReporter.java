package prepsmith.reports; 
import prepsmith.users.Student; 

public class ProgressReporter {
    public void report(Student student) {
        // This unrelated class in another package may use Student's public methods only.
        System.out.println(student.getName()); 
        System.out.println(student.getMaskedEmail()); 

        System.out.println("Sessions completed: " + student.getSessionCompleted()); 
        // student.studentId;  // Not allowed: this class is outside prepsmith.users.
        // student.weeklyGoal; // Not allowed: this class is not a Student subclass.
        // student.email;      // Not allowed: email is accessible only inside Student.
    }
}
