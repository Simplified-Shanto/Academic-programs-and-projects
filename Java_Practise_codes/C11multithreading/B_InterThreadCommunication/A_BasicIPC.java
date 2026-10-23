class Q {
    int n; 
    synchronized int get() {
        System.out.println("Got: " + n); 
        return n; 
    }

    synchronized void put(int n) {
        this.n = n; 
        System.out.println("Put: " + n); 
    }
}


class Producer implements Runnable {
    Q q; 
    Thread t; 
    Producer(Q q) {
        this.q = q; 
        t = new Thread(this, "Producer"); 
    }

    public void run() {
        int i = 0; 
        while(true) {
            q.put(i++); 
        }
    }
}


class Consumer implements Runnable {
    Q q; 
    Thread t; 
    Consumer(Q q) {
        this.q = q; 
        t = new Thread(this, "Consumer")
    }
}




public class A_BasicIPC {
    
}
