class SynchronizedCounter {
    int count = 0; 

    /*
     * count++ reads count, adds one, and writes the result. Without protection,
     * two threads can read the same old value and overwrite each other's work.
     *
     * A synchronized instance method locks this SynchronizedCounter object.
     * Only one thread at a time can execute increment() on this same object;
     * the other waits for the lock. This keeps each increment together and
     * prevents lost updates.
     */
    public synchronized void increment() {
        count++; 
    }
}


class SynchronizedCounterThread extends Thread {
    // Hold a reference to the shared counter, not a separate copy of it.
    SynchronizedCounter counter; 
    public SynchronizedCounterThread(SynchronizedCounter counter)
    {
        this.counter = counter; 
    }

    public void run() {
        // Each thread performs 1000 increments on that same counter.
        for(int i = 0; i < 1000; i++) {
            counter.increment(); 
        }
    }
}

public class G_SynchronizedCounterDemo {
    public static void main(String[] args) throws InterruptedException {
        // Create one counter so both threads synchronize on the same object.
        SynchronizedCounter counter = new SynchronizedCounter(); 
        Thread t1 = new SynchronizedCounterThread(counter); 
        Thread t2 = new SynchronizedCounterThread(counter); 

        // start() runs each thread's run() method; their execution can overlap.
        t1.start(); t2.start(); 

        /*
         * Main waits for t1 first, then t2. t2 continues working while main
         * waits for t1 and may finish first. If t2 has already finished, its
         * join() returns immediately. After both joins, all 2000 increment()
         * calls are complete and main can read the final count.
         *
         * join() waits for completion; synchronized prevents lost increments.
         * Both are needed here to print the reliable final result.
         */
        t1.join();  t2.join();

        System.out.println("Final count: " + counter.count); 
    }
}

/*
 * Example output from one run:
 * Final count: 2000
 *
 * Example output from another run:
 * Final count: 2000
 *
 * The threads may finish in either order, but both increment the same counter
 * 1000 times. Synchronization prevents lost updates, and join() makes main
 * wait before printing. Therefore, a completed run prints 2000 each time.
 *
 * This file uses SynchronizedCounter and SynchronizedCounterThread throughout.
 * Using the unsynchronized Counter from F_RaceConditionDemo instead would
 * bring back the race. The distinct thread class name also lets both demo
 * source files compile together without a duplicate-class error.
 */

