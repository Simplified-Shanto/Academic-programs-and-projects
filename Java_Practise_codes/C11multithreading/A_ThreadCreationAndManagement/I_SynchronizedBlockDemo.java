///////////////////////// Variant 1 synchronized block ///////////////////////////
/// 
// In this variant, the lock is taken inside the object that owns count.
// Both threads share one Counter object, so synchronized(this) refers to the
// same Counter lock for both threads.
// class Counter {   // A simple counter class which has a synchronized block inside its increment() method
//     int count = 0;

//     public void increment() {
//         synchronized(this) { // Here, this is the shared Counter object.
//             count++;
//         }
//     }
// }

// class CounterThread extends Thread {
//     Counter counter;

//     public CounterThread(Counter counter) {  // Constructor receiving a counter object
//         this.counter = counter;
//     }
//     public void run() {   // Overridden run() method of the generic Thread class 
//         for (int i = 0; i < 1000; i++) {
//             counter.increment();
//         }
//     }
// }


//////////////////////////// Variant 2 Synchronized block ///////////////////////////////
/// 
// In this variant, Counter.increment() is not synchronized. Each thread locks
// the shared counter before calling increment().
class Counter {   // A simple counter; Variant 2 synchronizes from CounterThread.
    int count = 0;

    public void increment() {
            count++;
    }
}

class CounterThread extends Thread {
    Counter counter;

    public CounterThread(Counter counter) {  // Constructor receiving a counter object
        this.counter = counter;
    }
    public void run() {   // Overridden run() method of the generic Thread class 
        for (int i = 0; i < 1000; i++) {
              synchronized(counter) { // Both threads lock this same shared Counter.
            counter.increment();
              }
        }
    }
}

public class I_SynchronizedBlockDemo {
    public static void main(String[] args) throws InterruptedException {
        Counter demoCounter = new Counter(); 
        Thread t1 = new CounterThread(demoCounter); 
        Thread t2 = new CounterThread(demoCounter); 

        t1.start();
        t2.start();

        t1.join();
        t2.join();


        System.out.println("Final count: " + demoCounter.count);
    }
}

/*
 * Subtle but important difference:
 *
 * synchronized(this) inside Counter.increment() is correct because this is
 * the one shared Counter object.
 *
 * synchronized(counter) inside CounterThread.run() is also correct because
 * counter refers to that same shared Counter object in both threads.
 *
 * synchronized(this) inside CounterThread.run() would be wrong: there, this
 * refers to the current CounterThread. t1 and t2 are different objects, so
 * they would acquire different locks and could still lose updates.
 */
