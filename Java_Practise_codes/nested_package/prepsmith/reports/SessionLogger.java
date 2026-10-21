package prepsmith.reports; // This class belongs to the prepsmith.reports package.

import prepsmith.learning.LearningSession; // LearningSession is public, so another package can import it.


// FUTURE REVIEW: SessionObserver is a public nested interface of LearningSession.
// A class outside prepsmith.learning refers to it as LearningSession.SessionObserver.
public class SessionLogger implements LearningSession.SessionObserver {
    @Override 
    public void onSessionStarted() {
        System.out.println("Learning session started."); 
    }
}                    
