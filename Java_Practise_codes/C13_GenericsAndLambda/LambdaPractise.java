interface I<T> { T f(T x); }


class A {
    static String echo(String s) {
        return s + s; 
    }
}




class LambdaPractise {
     static <T> T run(I<T> op, T v) {
        return op.f(v); 
    }
    public static void main(String args[])
    {
        System.out.println(run(A::echo, "Go")); 
    }
}