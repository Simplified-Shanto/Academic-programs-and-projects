package prepsmith.app; // This file belongs to prepsmith.app, not the default package.
import prepsmith.learning.VocabularyStudent; 
import prepsmith.learning.MathStudent; 
import prepsmith.learning.ScienceStudent; 
import prepsmith.users.StudentIdLookup; 
import prepsmith.learning.Learner; 
import prepsmith.learning.LearningSession; 

import prepsmith.reports.ProgressReporter; 



public class Main {
    public static void main(String[] args) {
        VocabularyStudent studentV = new VocabularyStudent("Shanto", "islamnayeem386@gmial.com", "2024331067",  50, 30 ); 
        MathStudent studentM = new MathStudent("Muaj","muajislam@gmail.com", "2024331011", 70, 50); 
        ScienceStudent studentS = new ScienceStudent("Koushik", "koushik.sust@gmail.com", "2024331009", 5, 4 ); 


        // FUTURE REVIEW: This array stores Learner references, not interface objects.
        // Each object was created as a concrete student type and is usable here through Learner.
        Learner[] learners = { studentV, studentM, studentS}; 

        LearningSession session = new LearningSession(); 
        // The session calls the correct learn() method for each concrete learner at runtime.
        session.start(learners); 
       

    //     session.showProgress(learners); 

    //     // This fails because studentId is package-private and Main is outside prepsmith.users.
    //     //System.out.println(studentM.studentId); 

    //     StudentIdLookup  lookup = new StudentIdLookup(); 
    //     System.out.println(lookup.matches(student, "2024331067")); // true 
    //     System.out.println(lookup.matches(student, "wrong-id")); // false 


    //   // System.out.println(studentM.weeklyGoal); 
    //     // A fully qualified class name includes the package and class name, so no import is needed.

    // FUTURE REVIEW: A fully qualified name avoids an import. Usually prefer the import above
    // when the class is used repeatedly; use a fully qualified name to resolve name conflicts.
    ProgressReporter reporter = new prepsmith.reports.ProgressReporter();


    reporter.report(studentV); 
    reporter.report(studentM); 
    reporter.report(studentS); 
    }
}
