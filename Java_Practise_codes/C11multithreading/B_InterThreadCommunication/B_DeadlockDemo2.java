import java.util.concurrent.CountDownLatch;

/*
 * Deadlock demonstration in the producer-consumer context
 *
 * A deadlock occurs when two threads wait forever for locks held by each other.
 * This example uses two shared resources:
 *
 *     BUFFER_LOCK       represents access to a shared communication buffer.
 *     STATISTICS_LOCK   represents access to shared communication statistics.
 *
 * The Producer acquires BUFFER_LOCK first and then asks for STATISTICS_LOCK.
 * The Consumer acquires STATISTICS_LOCK first and then asks for BUFFER_LOCK.
 * If both threads hold their first lock, each waits for the second lock and
 * neither can continue.
 *
 * CountDownLatch is used only to make the demonstration reliable. It ensures
 * that both threads have acquired their first lock before they request their
 * second lock. It is not the cause of the deadlock.
 */
public class B_DeadlockDemo2 {
    private static final Object BUFFER_LOCK = new Object();
    private static final Object STATISTICS_LOCK = new Object();

    // Both threads count down after acquiring their first lock.
    private static final CountDownLatch FIRST_LOCKS_READY =
            new CountDownLatch(2);

    private static void waitUntilBothThreadsHaveTheirFirstLock() {
        try {
            FIRST_LOCKS_READY.await();
        } catch (InterruptedException e) {
            Thread.currentThread().interrupt();
        }
    }

    private static void runProducer() {
        synchronized (BUFFER_LOCK) {
            System.out.println("Producer acquired BUFFER_LOCK");
            FIRST_LOCKS_READY.countDown();
            waitUntilBothThreadsHaveTheirFirstLock();

            System.out.println("Producer is waiting for STATISTICS_LOCK");
            synchronized (STATISTICS_LOCK) {
                System.out.println("Producer acquired both locks");
            }
        }
    }

    private static void runConsumer() {
        synchronized (STATISTICS_LOCK) {
            System.out.println("Consumer acquired STATISTICS_LOCK");
            FIRST_LOCKS_READY.countDown();
            waitUntilBothThreadsHaveTheirFirstLock();

            System.out.println("Consumer is waiting for BUFFER_LOCK");
            synchronized (BUFFER_LOCK) {
                System.out.println("Consumer acquired both locks");
            }
        }
    }

    public static void main(String[] args) throws InterruptedException {
        Thread producer = new Thread(
                B_DeadlockDemo2::runProducer,
                "Producer"
        );
        Thread consumer = new Thread(
                B_DeadlockDemo2::runConsumer,
                "Consumer"
        );

        /*
         * The threads are daemon threads so that the JVM can exit after main
         * reports the deadlock. Calling join() without a timeout here would
         * also wait forever, because the two worker threads are deadlocked.
         */
        producer.setDaemon(true);
        consumer.setDaemon(true);

        producer.start();
        consumer.start();

        // Wait until both threads hold their first lock.
        FIRST_LOCKS_READY.await();
        Thread.sleep(100);

        System.out.println("Producer state: " + producer.getState());
        System.out.println("Consumer state: " + consumer.getState());
        System.out.println("Deadlock detected: each thread is waiting for the other's lock.");
    }
}

/*
 * Typical output:
 *
 * Producer acquired BUFFER_LOCK
 * Consumer acquired STATISTICS_LOCK
 * Producer is waiting for STATISTICS_LOCK
 * Consumer is waiting for BUFFER_LOCK
 * Producer state: BLOCKED
 * Consumer state: BLOCKED
 * Deadlock detected: each thread is waiting for the other's lock.
 *
 * The first two lines may appear in either order. The important sequence is:
 *
 *     Producer holds BUFFER_LOCK and wants STATISTICS_LOCK.
 *     Consumer holds STATISTICS_LOCK and wants BUFFER_LOCK.
 *
 * To prevent this deadlock, every thread must acquire the locks in the same
 * order, for example BUFFER_LOCK first and STATISTICS_LOCK second.
 */
