package prepsmith.learning; 

import prepsmith.users.Student; 

// Student already implements Learner, so this class inherits the Learner contract.
public class ScienceStudent extends Student {
    private int experimentsCompleted; 
    //Custom constructor 
    public ScienceStudent(String name, String email, String studentId, int weeklyGoal, int experimentsCompleted){
        // Calls the Student constructor to initialize the inherited student state.
        super(name, email, studentId, weeklyGoal);
        this.experimentsCompleted = experimentsCompleted;
    }

    @Override  // learn() implements the method required by the Learner interface.
    public void learn() {
        // This protected Student method records one completed learning session.
        completeLearningSession();
        System.out.println(getName() + " completed " + experimentsCompleted + " experiments. "); 
    }

    // Implements the progress-summary requirement inherited from Learner through Student.
    public String getProgressSummary(){
          String progressSummary = (getName() + " completed " + experimentsCompleted + " experiments against the weekly goal of " + weeklyGoal); 
          return progressSummary; 
    }
}
