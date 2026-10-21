package prepsmith.learning; 



public class LearningSession {
    // FUTURE REVIEW: This is a nested interface, referred to as LearningSession.SessionObserver.
    // It is useful later for events such as logging or notifications when a session starts.
    public interface SessionObserver {
        void onSessionStarted(); 
    }
    // This method receives an array of Learner references and calls learn() on each one.
    // Each class that implements Learner, such as MathStudent or VocabularyStudent,
    // provides its own learn() implementation.
    public void start(Learner[] learners) {
        for (Learner learner: learners) {
            learner.learn();
        }
    }

    public void showProgress(Learner[] learners) {
        for(Learner learner: learners){
                System.out.println(learner.getProgressSummary()); 
        }
    }


   }
