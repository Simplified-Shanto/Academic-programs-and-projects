class MyThread implements Runnable{ // Mythread is a class that implements the Runnable interface. 
    public void run() {  // Intended executable code should stay here 
        for(int i = 0; i < 5; i++){
            System.out.println("From MyThread: " + i); 
        }
     }
}

public class B_RunnableDemo {
    public static void main(String[] args) {
        /*
         * In RunnableDemo.java, myRunnable contains the work to do in its run()
         * method. It is a Runnable, but creating it does not start a thread.
         *
         * new Thread(myRunnable, "My Runnable Thread") creates the thread and
         * tells it which work to run. Then thread.start() starts that thread,
         * which calls myRunnable.run().
         *
         * So you are not creating MyThread twice. You create one MyThread
         * object, then pass that same object to a new Thread object.
         */
        MyThread myRunnable  = new MyThread();  // Created an object of the MyThreadClass that implements runnable 
        Thread thread = new Thread(myRunnable, "My Runnable Thread"); 
        thread.start(); 
        for(int i = 0; i< 5; i++) {
            System.out.println("From main thread: " + i); 
        }
    }
    
}
