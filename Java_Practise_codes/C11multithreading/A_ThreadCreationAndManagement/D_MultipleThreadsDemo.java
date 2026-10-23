class MyThread implements Runnable {
    public void run() {
        for(int i = 0; i< 5; i++) {
            System.out.println("From " + Thread.currentThread().getName() + ": " + i); 
        }
    }
}


public class D_MultipleThreadsDemo {
    public static void main(String[] args) {
        Thread thread1   = new Thread(new MyThread(), "Thread 1"); 
        Thread thread2   = new Thread(new MyThread(), "Thread 2"); // The argumetns are the runnable task, string name 
        thread1.start(); thread2.start(); 
        for(int i = 0; i < 5; i++){
            System.out.println("From main thread: " + i); 
        }
    }
}
