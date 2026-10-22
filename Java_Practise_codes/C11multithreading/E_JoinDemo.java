class MyThread extends Thread {  // Mythread inherits the Thread class and overrides its run() method 
    MyThread(String name) {
        super(name); 
    }

    public void run() {
        for(int i = 0; i < 5; i++) {
            System.out.println("From MyThread: " + i); 
        }
    }
}





public class E_JoinDemo {
    public static void main(String[] args) {
        Thread thread  = new Thread(new MyThread("Thread"), "My Thread"); 
        thread.start(); 
        try {
            thread.join(); // Waits for My Thread to finish 
        }
        catch(InterruptedException e) {
            System.out.println("Main thread interrupted"); 
        }

        // This line is executed after thread finishes execution 
        System.out.println("My Thread has finished."); 
    }
}
