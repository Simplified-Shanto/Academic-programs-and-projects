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


public class C_ExtendedThreadClassDemo {
    public static void main(String[] args){
        MyThread thread = new MyThread("My Extended Thread"); 
        System.out.println("MyThread object's thread name: " + thread.getName()); 
        thread.start(); // This thread will be concurrently running with the main thread. 
        for(int i = 0; i< 5; i++) {
            System.out.println("From main thread: " + i); 
        }
    }
    
}
