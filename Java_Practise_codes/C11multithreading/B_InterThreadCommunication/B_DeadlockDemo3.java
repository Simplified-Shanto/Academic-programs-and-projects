/*
 * A very small deadlock example
 *
 * Thread 1 locks LOCK_A and then asks for LOCK_B.
 * Thread 2 locks LOCK_B and then asks for LOCK_A.
 *
 * Each thread holds one lock while waiting for the other, so neither can
 * continue. The short sleeps give the other thread time to acquire its first
 * lock. The threads are daemon threads so the program can finish after main
 * reports the deadlock.
 */
public class B_DeadlockDemo3 {
    private static final Object LOCK_A = new Object();
    private static final Object LOCK_B = new Object();

    public static void main(String[] args) throws InterruptedException {
        Thread t1 = new Thread(() -> {
            synchronized (LOCK_A) {
                System.out.println("Thread 1 locked A");

                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }

                System.out.println("Thread 1 is waiting for B");
                synchronized (LOCK_B) {
                    System.out.println("Thread 1 locked B");
                }
            }
        });

        Thread t2 = new Thread(() -> {
            synchronized (LOCK_B) {
                System.out.println("Thread 2 locked B");

                try {
                    Thread.sleep(500);
                } catch (InterruptedException e) {
                    Thread.currentThread().interrupt();
                }

                System.out.println("Thread 2 is waiting for A");
                synchronized (LOCK_A) {
                    System.out.println("Thread 2 locked A");
                }
            }
        });

        t1.setDaemon(true);
        t2.setDaemon(true);

        t1.start();
        t2.start();

        Thread.sleep(700);

        System.out.println("Thread 1 state: " + t1.getState());
        System.out.println("Thread 2 state: " + t2.getState());
        System.out.println("Both threads are waiting for each other's lock.");
    }
}
