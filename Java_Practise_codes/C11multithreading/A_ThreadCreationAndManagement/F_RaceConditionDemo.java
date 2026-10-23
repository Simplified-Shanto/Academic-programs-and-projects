class Counter {
    int count = 0; 
    public void increment() {
        /*
         * Both threads call this method on the same Counter object. count++ is
         * a read, an addition, and a write; those steps are not atomic. For
         * example, if both threads read 10, both can calculate 11 and write
         * 11. Two increments happened, but the count increased by only one.
         * This lost update is the race condition. Because each thread calls
         * increment() 1000 times, the expected final count is 2000. A lower
         * result demonstrates the race, although the result can sometimes be
         * 2000 when the threads happen not to overlap in this way.
         */
        count++; 
    }
}


class CounterThread extends Thread {
    Counter counter; 
    public CounterThread(Counter counter) // Public constructor of the CounterThreadClass
    {
        this.counter = counter; 
    }

    public void run() {
        for(int i = 0; i < 1000; i++) {
            counter.increment(); 
        }
    }
}

public class F_RaceConditionDemo {
    public static void main(String[] args) throws InterruptedException {
        Counter counter = new Counter(); 
        // Both threads receive the same Counter object and increment it 1000 times.
        Thread t1 = new CounterThread(counter); 
        Thread t2 = new CounterThread(counter); 
        t1.start(); t2.start(); 
        /*
         * After starting both threads, the main thread waits at t1.join()
         * until t1 finishes. t2 keeps running during this wait and may even
         * finish before t1. Main then reaches t2.join(): it waits if t2 is
         * still running, or continues immediately if t2 has already finished.
         * The sequence for main is: start t1, start t2, wait for t1, wait for
         * t2 if needed, then print. The join order does not decide which
         * worker finishes first. join() ensures both workers finish before
         * printing, but it does not prevent the race in count++.
         */
        t1.join();  t2.join(); 
        System.out.println("Final count: " + counter.count); 
    }
  
}

/*
 * Possible output from separate runs (the exact result depends on timing):
 *
 * Final count: 2000
 *   All 2000 increments affected the final count. This can happen even though
 *   count++ is unsafe; one successful run does not prove there is no race.
 *
 * Final count: 1999
 *   At least one update was lost. For example, both threads may have read the
 *   same value and then both written the same incremented value.
 *
 * Final count: 1874
 *   More updates were lost as the threads overlapped repeatedly while reading
 *   and writing count. The exact number varies between runs and machines.
 *
 * Both join() calls finish before any of these lines are printed, so a lower
 * count is caused by racing updates, not by printing before a thread ends.
 */
