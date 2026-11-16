import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.reflect.Method;

@Retention(RetentionPolicy.RUNTIME)
// A custom annotation lets us define application-specific metadata.
// Here, MyAnno stores a text description and an integer value.
// RUNTIME retention is important because the program reads this annotation
// while it is running through reflection. Without RUNTIME, getAnnotation()
// would not be able to find MyAnno.
@interface MyAnno {
    String str();
    int val();
}

class Test {
    // The annotation attaches structured information to login() without
    // changing the method's implementation.
    // A framework could interpret this as "Admin only" permission with
    // permission level 5 and then apply security, logging, or validation rules.
    // The annotation itself does not enforce those rules; another program or
    // framework must read the metadata and decide what action to take.
    @MyAnno(str = "Admin only", val = 5)
    public void login() { }
}


public class CustomAnnotation {
    public static void main(String[] args) throws NoSuchMethodException {
        // Reflection locates the login() method at runtime.
        Method m = Test.class.getMethod("login");

        // Read the custom annotation attached to login().
        MyAnno a = m.getAnnotation(MyAnno.class);

        // The annotation values can now be used by the program or a framework.
        // Output: Admin only, followed by 5.
        System.out.println(a.str());
        System.out.println(a.val());
    }
}
