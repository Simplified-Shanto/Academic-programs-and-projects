package prepsmith.users; 

public class StudentIdLookup { 
    public boolean matches(Student student, String id) {
        // This works because StudentIdLookup and Student are both in prepsmith.users.
        return student.studentId.equals(id); 
    }
}
