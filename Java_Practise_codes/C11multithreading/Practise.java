class counter {
    int count = 0; 
    void increment()
    {
        count++; 
    }
}



class demoThread extends Thread {
counter ctr; 
 public demoThread(counter counter) // constructor for demoThread 
 {
    ctr = counter; 
 }

 public void run()
 {
    for(int i = 1; i<=5; i++)
    {
        ctr.increment();
        System.out.println("Printing " + ctr.count + " from demoThread"); 
    }
 }
}


class demoThread2 implements Runnable{
    counter ctr; 
 public demoThread2(counter counter) // constructor for demoThread 
 {
    ctr = counter; 
 }

 public void run()
 {
    for(int i = 1; i<=5; i++)
    {
        ctr.increment();
        System.out.println("Printing " + ctr.count + " from demoThread"); 
    }
 }
}


public class Practise {
    public static void main(String args[]) throws InterruptedException{
        counter counterObject = new counter(); 
        counter counterObject2 = new counter(); 

        demoThread2 runnable = new demoThread2(counterObject2); 
        Thread t1 = new demoThread(counterObject);
        Thread t2 = new Thread(runnable, "A runnable thread"); 

        t1.start(); 
        t2.start(); 
        t1.join(); // main thread will wait until t1 finishes. 
        t2.join(); 
        System.out.println("Finished Printing"); 
    }
}
