# Inter-Thread Communication Quiz

For clickable questions with instant feedback, open the
[interactive browser quiz](./IPC_Quiz.html). This Markdown version is useful
for notes or printing.

Use this with [A_BasicIPC.java](./A_BasicIPC.java),
[B_DeadlockDemo3.java](./B_DeadlockDemo3.java), and
[B_DeadlockDemo2.java](./B_DeadlockDemo2.java).

## 1. Choose the correct answer

### Q1. What is the purpose of this line?

```java
Object lock = new Object();
```

- [ ] It creates a new thread.
- [ ] It creates an object that can be used as a lock.
- [ ] It starts inter-thread communication automatically.
- [ ] It makes every object in the program synchronized.

### Q2. Which object does `synchronized (this)` lock inside `Q.put()`?

- [ ] The `Producer` object.
- [ ] The current `Thread` object.
- [ ] The current `Q` object.
- [ ] The `main` method.

### Q3. Why do Producer and Consumer need the same `Q` object?

- [ ] So they use the same shared value.
- [ ] So they have the same thread name.
- [ ] So both loops run at the same speed.
- [ ] So `main()` does not need to call `start()`.

### Q4. What does `start()` do?

- [ ] Calls `run()` on the current thread.
- [ ] Schedules a new thread and eventually calls its `run()` method.
- [ ] Locks every object used by the thread.
- [ ] Waits for another thread to finish.

### Q5. Which two objects are different locks?

```java
Object lockA = new Object();
Object lockB = new Object();
```

- [ ] `lockA` and `lockB` are the same lock.
- [ ] `lockA` and `lockB` are different locks.
- [ ] They are not objects.
- [ ] They are automatically connected by Java.

## 2. True or false

Write `T` or `F` beside each statement.

1. `synchronized` allows only one thread at a time to enter a block protected by the same lock. `____`
2. `private static final Object LOCK_A` is a globally accessible variable. `____`
3. `final` prevents the lock reference from being replaced, but it does not make the object immutable. `____`
4. Calling `sleep()` releases the monitor held by the current thread. `____`
5. Calling `join()` makes the current thread wait for another thread to finish. `____`
6. Two separately created `new Object()` values represent the same monitor. `____`

## 3. Fill in the blanks

### Q6. Shared communication object

```java
Q q = new ________();
Producer p = new Producer(______);
Consumer c = new Consumer(______);
```

Both constructors must receive the same `________` reference.

### Q7. Thread construction

```java
class Producer implements Runnable {
    Thread t;

    Producer(Q q) {
        this.q = q;
        t = new Thread(______, "Producer");
    }
}
```

The blank should refer to the current `Producer` object.

### Q8. Locking the shared counter

```java
class CounterThread extends Thread {
    Counter counter;

    public void run() {
        synchronized (________) {
            counter.increment();
        }
    }
}
```

Which expression should be used if both threads share the same `counter` object?

### Q9. Locking the current object

```java
class Q {
    synchronized void put(int value) {
        synchronized (________) {
            // protected work
        }
    }
}
```

Inside this `Q` method, the blank can be filled with `________`.

## 4. Find the problem

### Q10. Does this protect both threads from each other?

```java
class Worker extends Thread {
    SharedCounter counter;

    public void run() {
        synchronized (this) {
            counter.increment();
        }
    }
}
```

- [ ] Yes, because both workers extend `Thread`.
- [ ] Yes, because `this` always means the shared counter.
- [ ] No, because `this` refers to a different Worker object in each thread.
- [ ] No, because synchronized blocks cannot be used in `run()`.

Correct the lock expression:

```java
synchronized (________) {
    counter.increment();
}
```

### Q11. Identify the deadlock

```java
Thread t1 = new Thread(() -> {
    synchronized (LOCK_A) {
        synchronized (LOCK_B) {
            System.out.println("T1 finished");
        }
    }
});

Thread t2 = new Thread(() -> {
    synchronized (LOCK_B) {
        synchronized (LOCK_A) {
            System.out.println("T2 finished");
        }
    }
});
```

Complete the explanation:

`t1` holds `________` and waits for `________`, while `t2` holds
`________` and waits for `________`.

## 5. Predict the result

### Q12. What can happen in this basic producer-consumer version?

```java
q.put(0);
q.put(1);
q.get();
```

- [ ] `get()` must return `0`.
- [ ] `get()` must return `1`.
- [ ] The value `0` may be overwritten before it is read.
- [ ] The program cannot compile.

### Q13. What states are likely in `B_DeadlockDemo3` after the deadlock forms?

- [ ] Both threads are `NEW`.
- [ ] Both threads are `RUNNABLE` forever.
- [ ] Both threads are `BLOCKED`.
- [ ] Both threads are `TERMINATED`.

## 6. Short answers

### Q14.

In one sentence, explain the difference between a lock and a shared data object.

`__________________________________________________________________________`

### Q15.

Why is `Object` commonly used as a lock?

`__________________________________________________________________________`

### Q16.

What lock-order rule prevents the deadlock in Q11?

`__________________________________________________________________________`

<details>
<summary>Answer key</summary>

### Multiple choice

- Q1: second option.
- Q2: third option.
- Q3: first option.
- Q4: second option.
- Q5: second option.
- Q10: third option; the correction is `synchronized (counter)`.
- Q12: third option.
- Q13: third option.

### Fill-ins and true/false

- Q6: `Q`, `q`, `q`, `Q`.
- Q7: `this`.
- Q8: `counter`.
- Q9: `this`.
- Q11: `LOCK_A`, `LOCK_B`, `LOCK_B`, `LOCK_A`.
- Q14: A lock controls access while a shared data object stores the value being accessed.
- Q15: Every Java object has a monitor, and `Object` is a simple object with no application state required for locking.
- Q16: Every thread must acquire multiple locks in the same global order.
- Q1–Q6 true/false: `T`, `F`, `T`, `F`, `T`, `F`.

</details>
