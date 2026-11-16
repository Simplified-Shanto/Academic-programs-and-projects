class A {
    synchronized void foo(B b){
        String threadName = Thread.currentThread().getName(); 
        System.out.println(threadName + " entered A.foo"); 
        try{
            Thread.sleep(100); 
        }
        catch (InterruptedException e){
            System.out.println("A interrupted"); 
        }

        System.out.println(threadName + " trying to call B.last()"); 
        b.last(); 
    }


    synchronized void last() {
        System.out.println("Inside A.last"); 
    }
}

class B {
     synchronized void bar(A a) {
        String threadName = Thread.currentThread().getName(); 
        System.out.println(threadName + " entered B.bar"); 
        try {
            Thread.sleep(100); 
        } catch(InterruptedException e) {
            System.out.println("B interrupted"); 
        }
        System.out.println(threadName + " trying to call A.last()"); 
        a.last(); 
    }

    synchronized void last() {
        System.out.println("Inside B.last"); 
    }
}

class B_DeadlockDemo {
   
}
