package prepsmith.learning; 
import prepsmith.users.Student; 

// Learner needs no import because it is in the same package as MathStudent.

// Student already implements Learner, so this class inherits the Learner contract.
public class MathStudent extends Student {
    private int problemSolved; 

    public MathStudent(String name, String email, String studentId, int weeklyGoal, int probSolved) {
        // super(...) initializes the Student part of this MathStudent, including private Student fields.
        super( name, email,  studentId,  weeklyGoal); 
        this.problemSolved = probSolved; 
    }
    @Override
    public void learn() {
        // This protected Student method updates shared state; Main cannot call it directly.
        completeLearningSession();
        System.out.println(getName() + " solved " + problemSolved + " math problems having a weekly goal of " + weeklyGoal);    
    }

    // FUTURE REVIEW: This exact method signature implements the inherited Learner contract.
    // It is overriding/implementing, not overloading: no different parameter list is used.
    public String getProgressSummary(){
           String progressSummary = (getName() + " solved " + problemSolved + " problems against the weekly goal of " + weeklyGoal); 
           return progressSummary; 
    }

}
