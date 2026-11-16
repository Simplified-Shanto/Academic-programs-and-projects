class MyException extends Exception {
    int value; 

    MyException(int v) {
        value = v; 
    }

    public String toString(){  // overriding the toString() method of the superclass Exception to control printed output
        return "Bad value: " + value; 
    }
}


public class D_OverridingtoStringDemo {
    public static void main(String[] args) {
        System.out.println(new MyException(20)); 
    }
}


/* Example of not overriding toString(): 

class E extends Exception {
    E() { super("Problem"); }
}

try {
    throw new E();
} catch(E e) {
    System.out.println(e);
}


Output: Something like  E:Problem 
The default Throwable toString from includes the exception class name followed by the message passed to super. 

*/ 