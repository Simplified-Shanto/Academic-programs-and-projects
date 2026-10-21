package university;

public class Student {

    String name;

    public Student(String name) {
        this.name = name;
    }

    public void introduce() {
        System.out.println("Hello, I am " + name);
    }
}