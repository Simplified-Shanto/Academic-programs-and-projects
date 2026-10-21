import java.io.IOException;
/**
 *@LabID:08
 *@Date:2026-09-15
 *@RegNo:2024331067
 *@Section:A
 */
public class L08_2024331067 {
    static void m(){ int i=1/0;}
    public static void main(String[] args) {
        IO.println("L08.main start");
        try{
            if(args.length==0) m();
            else {int j[]={1};
            try{j[2]=0;} catch(ArithmeticException e){}
        }
    }


        catch(ArithmeticException e){
            IO.println(e);try{int k=1/0;}
            catch(ArrayIndexOutOfBoundsException e1 ){}
        }
        catch(RuntimeException e){  
            IO.println("Re"+e);}
        IO.println("L08.main end");
    }
}



class A{
public static void main(String[] args) {
                IO.println("A.main start");
                if(true) return;
               try{ if(false) return;
                System.exit(0);
                if(true) throw new ArithmeticException("AR");}
               catch(ArithmeticException e) {IO.println("CT");throw e;}
               finally{IO.println("F");  }
                IO.println("A.main end");
    
}
}





class B{
    public static void main(String[] args)throws IOException,ArithmeticException {
        // throw new ArithmeticException("AR");
        throw new IOException();//error: unreported exception IOException; must be caught or declared to be thrown
    }
}



class P{}class Q extends Exception{
    Q(){super("MSG");}
    public String toString(){
        return "DiffMSG";
    }
}




class C{
    public static void main(String[] args) throws Q{
    //   throw new P();   //error: incompatible types: P cannot be converted to Throwable
    try{throw new Q();}
    catch(Q q){            IO.println(q);
    }    
}
}




class D{
    public static void main(String[] args) {
         try{var n=new NullPointerException("NPE");
            var a= new ArithmeticException("AE");
            a.initCause(n);throw a;
         }
         catch(NullPointerException n){
                      IO.println(n);}
                      catch(ArithmeticException e){
                                  IO.println(e);
                                  IO.println(e.getCause());
                      }
                                IO.println("D.main End");
                      
    }
}



class E{
    public static void main(String[] args)throws InterruptedException {
Thread t=Thread.currentThread() ;
IO.println(t);
t.setName("E.main");
        t.setPriority(Thread.MAX_PRIORITY);
        new Thread(new T1(),"CT1").start();
        new T2("CT2").start();
        t.sleep(1000);
        IO.println(t.getName());
        IO.println(t.threadId());
        IO.println(t.getPriority());

        
    }
}




class T1 implements Runnable{
    public void run () {
        for(int i=0;i<10000;i++);
            IO.println(this);
            IO.println(Thread.currentThread());
            
        
    }
}



class T2 extends Thread{
    T2(String s) {super (s);}
    public void run () {
        for(int i=0;i<10000;i++);
            IO.println(this);
            
        
    }
}




class Counter{int c=0;
    // public synchronized void m() {c++; }
    public  void m() {c++; }
}



class T3 implements Runnable{
    Counter c;
    T3 (Counter c){this.c=c;}
    public void run(){
        for(int i=0;i<10000;i++) 
            synchronized(c){c.m();}
    }
}



class F{
    public static void main(String[] args)throws InterruptedException {
        Counter c=new Counter();
        Thread t1=new Thread(new T3(c),"T1") ;
        Thread t2=new Thread(new T3(c),"T2") ;
        t1.start();t2.start();
        t1.join();t2.join();
        IO.println(c.c);
    }        
}