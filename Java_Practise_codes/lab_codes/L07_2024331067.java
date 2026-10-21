package A;
/**
 *@LabID:07
 *@Date:2026-09-08
 *@RegNo:2024331067
 *@Section:A
 */
public class L07_2024331067{
    public static void main(String[] args) {
IO.println("A.L07.main()");
// new A.p1.C();new A.p2.B();
P p=new Q();p.m();p.m2();
IO.println(P.i + P.j);
    }
}

interface P{
// {}//error: initializers not allowed in interfaces
// static {}//error: initializers not allowed in interfaces
// int i;//error: = expected
int i=10;
final static int j=20;
// void m(){}//error: interface abstract methods cannot have body
void m();
public abstract void m2();
// final void m3();//error: modifier final not allowed here
interface M{}
// private interface N{}//error: illegal combination of modifiers: public and private
}
interface G extends P{
    void m4();
    default void m3(){m6();}
    static void m5(){}
    private void m6(){}

}
class T implements G{
    public void m(){}
    public void m2(){}
    public void m4(){}
    public static void main(String[] args) {
        T t=new T();
        // t.m5();
        // T.m5();
        G.m5();
        // G.m6();//error: m6() has private access in G
        P p=new P(){
            public void m(){}
            public void m2(){}

        };
    p.m();p.m2();
    }
}
class Q implements P,P.M{
    private interface Z{}
  public  void m(){ IO.println("Q.m()"+i);}
 public void m2(){ IO.println("Q.m2()"+j);}
}

abstract class R implements P{
    public void m(){IO.println("R.m()");}
}
class X implements P.M{

}