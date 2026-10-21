package prepsmith.users; 

// FUTURE REVIEW: This class is package-private because it has no access modifier.
// It is an unused experiment until PrepSmith needs real student-ID validation rules.

class InternalStudentValidator {
    boolean isValid(Student student) {
        return student.studentId.startsWith("2024"); 
    }
}
