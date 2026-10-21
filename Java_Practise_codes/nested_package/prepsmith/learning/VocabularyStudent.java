package prepsmith.learning; 
import prepsmith.users.Student; 

// Learner needs no import because it is in the same package as VocabularyStudent.

// Student already implements Learner, so this class inherits the Learner contract.
public class VocabularyStudent extends Student {
    private int wordsLearned; 

    public VocabularyStudent(String name, String email, String studentId, int weeklyGoal, int wordsLearned) {
        // Calls the Student constructor to initialize the inherited student state.
        super(name, email,  studentId,  weeklyGoal);
        this.wordsLearned = wordsLearned; 
    }
    @Override
    public void learn() {
        // This protected Student method records one completed learning session.
        completeLearningSession();
        System.out.println(getName() + " learned " + wordsLearned + " vocabulary words having a weekly goal of learning " + weeklyGoal + " words"); 
    }

    // Implements the progress-summary requirement inherited from Learner through Student.
    public String getProgressSummary(){
        String progressSummary = (getName() + " learned " + wordsLearned + " words against the weekly goal of " + weeklyGoal); 
        return progressSummary; 
    }
}
