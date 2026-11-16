// Shared object of the following class will be used as the buffer of the interthread communication 
class BufferClass {
    int n; // This is the variable we'll use to send data from one thread to another thread. 

    synchronized void get()
    {
        System.out.println("Got: " + this.n); 
    }

    synchronized void put(int i) 
    {
        this.n = i; 
        System.out.println("Put: " + this.n); 
    }
}



// The following two calsses will have a separete thread of its own, which will access the variable n of the same BufferClass object, demonstrating interthread communication 

class producer implements Runnable
{
    BufferClass b; 
    int i = 0; 
    producer(BufferClass BC)
    {
        this.b = BC; 
    }
    // we pass this as the runnable argument because, this class is itself runnable
    Thread t = new Thread(this, "producer's thread"); 

    //Runnable will run this function 
    public void run()
    {
        while(true)
        {
            b.put(i++);
        }
 
    }
}


class consumer implements Runnable 
{
    BufferClass b; 
    consumer(BufferClass BC)
    {
        this.b = BC; 
    }

    Thread t = new Thread(this, "consumer's thread"); 

    public void run()
    {
        while(true)
        {
        b.get(); 
        }
    }
}



class A_BasicIPC{
    public static void main(String[] args)
    {
        BufferClass bc = new BufferClass(); 

        producer p = new producer(bc); 
        consumer c = new consumer(bc); 

        p.t.start(); 
        c.t.start(); 


        System.out.println("Press ctrl+c to stop !"); 
    }

}
































// /*
//  * Basic inter-thread communication example
//  *
//  * The Producer and Consumer threads communicate through one shared Q object.
//  * Q acts as a small shared data container: the producer writes a value using
//  * put(), and the consumer reads a value using get().
//  *
//  * This version demonstrates synchronized access only. It does not yet use
//  * wait() or notifyAll(). Therefore, it prevents get() and put() from running
//  * at the same time, but it does not make the producer wait when the value has
//  * not been consumed, and it does not make the consumer wait for a new value.
//  */
// class Q {
//     // This is the single value shared by the producer and consumer.
//     int n;

//     /*
//      * synchronized means that the current Q object is used as the lock.
//      * Because Producer and Consumer share the same Q object, only one of these
//      * methods can execute at a time for that object.
//      *
//      * The method returns the current value of n. In this basic version, it can
//      * return the same value more than once because no consumed/not-consumed
//      * status is being stored yet.
//      */
//     synchronized int get() {
//         System.out.println("Got: " + n);
//         return n;
//     }

//     /*
//      * This method writes a value into the shared Q object. The parameter n and
//      * the field n have the same name, so this.n means "the field belonging to
//      * this Q object", while n by itself means "the parameter".
//      */
//     synchronized void put(int n) {
//         this.n = n;
//         System.out.println("Put: " + n);
//     }
// }

// /*
//  * Producer creates values and puts them into the shared Q object.
//  *
//  * Producer implements Runnable, so it describes a task. The actual Thread
//  * object is created in the constructor and receives this Producer as its task.
//  */
// class Producer implements Runnable {
//     // q refers to the same Q object that will also be used by Consumer.
//     Q q;
//     Thread t;

//     Producer(Q q) {
//         this.q = q;

//         /*
//          * Here, this is the current Producer object. The Producer object is a
//          * Runnable, so the new Thread will call this object's run() method.
//          * "Producer" is the name assigned to the new thread.
//          */
//         t = new Thread(this, "Producer");
//     }

//     // The new Producer thread starts executing here after t.start().
//     public void run() {
//         int i = 0;

//         // Continuously produce 0, 1, 2, 3, ... and put each value into Q.
//         while (true) {
//             q.put(i++);
//         }
//     }
// }

// /*
//  * Consumer reads values from the same Q object used by Producer.
//  */
// class Consumer implements Runnable {
//     // This reference must point to the same Q instance shared with Producer.
//     Q q;
//     Thread t;

//     Consumer(Q q) {
//         this.q = q;

//         // The Consumer object supplies the Runnable task for this Thread.
//         t = new Thread(this, "Consumer");
//     }

//     // The new Consumer thread starts executing here after t.start().
//     public void run() {
//         // Continuously read the current value from Q.
//         while (true) {
//             q.get();
//         }
//     }
// }

// public class A_BasicIPC {
//     public static void main(String[] args) {
//         /*
//          * Create exactly one Q object. Passing this same object to both
//          * constructors is what allows the producer and consumer to share data.
//          * If two separate Q objects were created, the threads would not
//          * communicate with each other.
//          */
//         Q q = new Q();

//         Producer p = new Producer(q);  // These are not threads by themeselves, they have a thread attribute
//         Consumer c = new Consumer(q);

//         /*
//          * start() creates/schedules the new threads and eventually calls each
//          * Runnable object's run() method. Calling p.run() or c.run() directly
//          * would execute on the main thread instead of creating new threads.
//          */
//         p.t.start();
//         c.t.start();

//         // Both worker threads run forever, so Ctrl+C is used to stop the demo.
//         System.out.println("Press ctrl-c to stop.");
//     }
// }

// /*
//  * What synchronization guarantees here:
//  *
//  * 1. Producer enters q.put() and locks the shared Q object.
//  * 2. Consumer cannot enter q.get() until put() releases that lock.
//  * 3. Consumer then enters q.get() and locks the same Q object.
//  * 4. Producer waits briefly if it tries to enter put() at the same time.
//  *
//  * What this version does not guarantee:
//  *
//  * The producer can overwrite a value before the consumer reads it. For
//  * example, it may put 0, 1, and 2 before the consumer gets the value; the
//  * consumer might then read only 2. The consumer can also read the same value
//  * repeatedly if the producer has not written a new value yet.
//  *
//  * So synchronized provides mutual exclusion here, but not full producer-
//  * consumer coordination. A later version can add wait() and notifyAll() to
//  * make the producer wait when the slot is full and the consumer wait when the
//  * slot is empty.
//  */
