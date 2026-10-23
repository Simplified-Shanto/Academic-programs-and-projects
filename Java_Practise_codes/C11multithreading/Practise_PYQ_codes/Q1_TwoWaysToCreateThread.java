/*
 * PYQ Exercise 1: Two ways to create the same worker
 *
 * Build a program that starts two workers which print the numbers 1 through 5.
 * Implement one worker by extending Thread and the other by implementing
 * Runnable. Give both threads names and print the name beside every number.
 * Explain when the run() method is selected in each design.
 *
 * Solution adapted from Practise.java.
 */
class Q1Counter {
    int count = 0;

    void increment() {
        count++;
    }
}

class Q1DemoThread extends Thread {
    private final Q1Counter counter;

    Q1DemoThread(Q1Counter counter, String name) {
        super(name);
        this.counter = counter;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            counter.increment();
            System.out.println("Printing " + counter.count + " from "
                    + getName());
        }
    }
}

class Q1DemoRunnable implements Runnable {
    private final Q1Counter counter;

    Q1DemoRunnable(Q1Counter counter) {
        this.counter = counter;
    }

    @Override
    public void run() {
        for (int i = 1; i <= 5; i++) {
            counter.increment();
            System.out.println("Printing " + counter.count + " from "
                    + Thread.currentThread().getName());
        }
    }
}

public class Q1_TwoWaysToCreateThread {
    public static void main(String[] args) throws InterruptedException {
        Q1Counter counterForThread = new Q1Counter();
        Q1Counter counterForRunnable = new Q1Counter();

        Thread t1 = new Q1DemoThread(counterForThread, "Thread subclass");
        Thread t2 = new Thread(
                new Q1DemoRunnable(counterForRunnable),
                "Runnable task"
        );

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        System.out.println("Finished printing");
    }
}
