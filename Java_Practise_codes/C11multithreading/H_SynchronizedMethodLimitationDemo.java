/*
 * Limitation of synchronized methods
 * -----------------------------------
 *
 * Sometimes a class was written by someone else and is not designed for
 * multithreading. Its methods are not synchronized, and its source code may
 * not be available because it is a third-party library. In that situation, we
 * cannot add the synchronized keyword directly to the original class.
 *
 * The class below represents that third-party class. Do not modify it in this
 * example. Its count++ operation is unsafe when multiple threads use the same
 * object at the same time.
 */
class ThirdPartyCounter {
    private int count = 0;

    public void increment() {
        // count++ is a read, an addition, and a write; it is not atomic.
        count++;
    }

    public int getCount() {
        return count;
    }
}

/*
 * SafeCounter is a wrapper (also called an adapter) around the third-party
 * object. The wrapper owns the synchronization lock and controls access to the
 * wrapped object.
 *
 * Both methods are synchronized on this same SafeCounter object. Therefore,
 * only one thread at a time can call increment() or getCount() through the
 * wrapper. The original ThirdPartyCounter class remains unchanged.
 */
class SafeCounter {
    /*
     * private means callers cannot access the wrapped object directly. They
     * must use SafeCounter's synchronized methods, so they cannot bypass the
     * protection and call the unsafe third-party methods themselves.
     *
     * final means this reference is assigned once and always points to the
     * same ThirdPartyCounter object. It does not make the object's count
     * immutable: counter.increment() can still change that object's state.
     *
     * final is not strictly required for synchronization, but it preserves the
     * wrapper's design: SafeCounter always protects the same counter object.
     */
    private final ThirdPartyCounter counter = new ThirdPartyCounter();

    public synchronized void increment() {
        counter.increment();
    }

    public synchronized int getCount() {
        return counter.getCount();
    }
}

public class H_SynchronizedMethodLimitationDemo {
    public static void main(String[] args) throws InterruptedException {
        /*
         * Both threads must use the same SafeCounter object. If one thread
         * accesses ThirdPartyCounter directly, that access is outside the
         * wrapper's lock and is not protected.
         */
        SafeCounter counter = new SafeCounter();

        /*
         * A Thread object represents a worker, but it needs to be given the
         * work it should perform. Thread has a constructor that accepts a
         * Runnable, whose single method is run(). The lambda below supplies
         * the implementation of Runnable.run().
         *
         * () means the task takes no parameters, and the block after -> is
         * the task's code. The lambda is not executed while the Thread object
         * is being created. It runs when start() causes the new thread to call
         * run().
         *
         * This short form:
         *
         *     new Thread(() -> { counter.increment(); });
         *
         * is equivalent to:
         *
         *     new Thread(new Runnable() {
         *         @Override
         *         public void run() {
         *             counter.increment();
         *         }
         *     });
         */
        Thread t1 = new Thread(() -> {
            for (int i = 0; i < 1000; i++) {
                counter.increment();
            }
        });

        Thread t2 = new Thread(() -> {
            for (int i = 0; i < 1000; i++) {
                counter.increment();
            }
        });

        // start() begins both threads; their work may run concurrently.
        t1.start();
        t2.start();

        /*
         * join() makes main wait until both worker threads have completed all
         * 1000 increments. It does not provide the synchronization; the
         * synchronized methods in SafeCounter provide that protection.
         */
        t1.join();
        t2.join();

        System.out.println("Final count: " + counter.getCount());
    }
}

/*
 * Example output:
 *
 * Final count: 2000
 *
 * Why the result is 2000:
 * - t1 performs 1000 increments.
 * - t2 performs 1000 increments.
 * - SafeCounter allows only one increment at a time.
 * - join() ensures both threads finish before the count is printed.
 *
 * Important limitation:
 * The wrapper protects only calls made through SafeCounter. If callers can
 * obtain the ThirdPartyCounter object and call its methods directly, those
 * calls can still race with the wrapper. Keeping the wrapped object private,
 * as this example does, prevents that accidental unsafe access.
 */
