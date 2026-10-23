/*
 * PYQ Exercise 2: Predict the output around start() and join()
 *
 * Write a program that prints messages from main and a worker. The worker must
 * print "Worker started", sleep for 500 ms, and print "Worker finished".
 * Predict the ordering constraints before running the program. Then use join()
 * and explain exactly which message main can no longer print early.
 */
public class Q2_JoinOrdering {
    public static void main(String[] args) throws InterruptedException {
        System.out.println("Main before start");

        Thread worker = new Thread(() -> {
            System.out.println("Worker started");

            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
                System.out.println("Worker interrupted");
                return;
            }

            System.out.println("Worker finished");
        });

        worker.start();
        System.out.println("Main after start");

        worker.join();
        System.out.println("Main after join");
    }
}
