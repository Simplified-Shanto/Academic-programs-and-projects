/*
 * PYQ Exercise 3: Diagnose and repair a lost update
 *
 * Start with F_RaceConditionDemo.java. Run two threads that each increment a
 * shared counter 10,000 times and record several final counts. Repair the
 * program twice: first with a synchronized method, and then with a synchronized
 * block using the shared counter as the lock. Explain which object owns the
 * lock and why synchronized(this) inside a Thread subclass uses the wrong lock.
 *
 * Write your solution below this comment.
 */



//------------------------------Attempt1: Synchronized method ---------------------

// class counter{
//     int count = 0; 
//     public synchronized void increment(){
//         count++; 
//     }
// }


// // Multithreading by extending the Thread class 
// class customThread extends Thread{
//     counter ctr; 
//     public customThread(counter counterObject)
//     {
//         ctr = counterObject; // Instantiating the ctr with the argument
//     }

//     public void run()
//     {
//         for(int i = 1; i<=10000; i++){
//             ctr.increment(); 
//         }
//     }
// }



//------------------------------Attempt2: Synchronized block ---------------------

class counter{
    int count = 0; 
    public void increment(){
        synchronized(this){
            count++; 
        }
    }
}


// Multithreading by extending the Thread class 
class customThread extends Thread{
    counter ctr; 
    public customThread(counter counterObject)
    {
        ctr = counterObject; // Instantiating the ctr with the argument
    }

    public void run()
    {
        for(int i = 1; i<=10000; i++){
            ctr.increment(); 
        }
    }
}


class Q3_RaceConditionRepair{
public static void main(String[] args) throws InterruptedException{
    counter sharedCounter = new counter(); 
    Thread t1 = new customThread(sharedCounter); 
    Thread t2 = new customThread(sharedCounter); 
    t1.start(); 
    t2.start(); 
    t1.join(); t2.join(); 

    System.out.println("Both of the thread finished executing. Count = " + sharedCounter.count); 
}
}