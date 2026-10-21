package prepsmith.learning;

public interface Learner {

    // Interface methods are implicitly public; every concrete Student subclass must implement both.
    void learn();
    String getProgressSummary(); 
}



// An interface specifies what a learner can do, but not how each learner does it.
