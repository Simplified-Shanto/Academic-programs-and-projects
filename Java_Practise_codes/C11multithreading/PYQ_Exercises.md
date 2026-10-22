# PYQ-based multithreading exercises

These are original practice problems inspired by section 9, “Multithreaded
Programming,” of the local [Java PYQ Bank](../reference/README.md). They are
designed to extend the examples in this folder rather than reproduce the bank's
questions word for word.

## 1. Two ways to create the same worker

Build a small program that starts two workers which print the numbers 1 through
5. Implement one worker by extending `Thread` and the other by implementing
`Runnable`. Give both threads names and print the name beside every number.

Use [B_RunnableDemo.java](./B_RunnableDemo.java) and
[C_ExtendedThreadClassDemo.java](./C_ExtendedThreadClassDemo.java) as starting
points. Explain when the `run()` method is selected in each design.

PYQ connection: thread creation and the advantages of multithreading.

## 2. Predict the output around `start()` and `join()`

Write a program that prints messages from `main` and a worker. The worker prints
`worker started`, sleeps for 500 ms, and prints `worker finished`. Predict all
ordering constraints before running it. Then add `join()` and explain exactly
which message the main thread can no longer print early.

Use [E_JoinDemo.java](./E_JoinDemo.java) as a reference. Separate guaranteed
ordering from output whose order is scheduler-dependent.

PYQ connection: `join()`, `sleep()`, and output tracing.

## 3. Diagnose and repair a lost update

Start with [F_RaceConditionDemo.java](./F_RaceConditionDemo.java). Run two
threads that each increment a shared counter 10,000 times. Record several final
counts. Repair the program twice:

1. with a synchronized method; and
2. with a synchronized block using the shared counter as the lock.

For each repair, state which object owns the lock and why `synchronized(this)`
inside a `Thread` subclass would use the wrong lock.

Compare your solutions with [G_SynchronizedCounterDemo.java](./G_SynchronizedCounterDemo.java)
and [I_SynchronizedBlockDemo.java](./I_SynchronizedBlockDemo.java).

PYQ connection: thread safety and synchronization.

## 4. Produce a deadlock deliberately, then remove it

Create two shared lock objects. Thread 1 must lock A and then wait for B;
thread 2 must lock B and then wait for A. Add short messages before and after
each lock so the deadlock can be identified. Then remove the deadlock by making
both threads acquire the locks in the same order.

Do not rely on `sleep()` to create the deadlock; use it only to make the trace
easy to observe. Explain the four conditions that make the deadlock possible.

PYQ connection: deadlock and thread coordination.

## 5. Build a one-slot producer-consumer queue

Implement a `OneSlotQueue` containing one integer and a flag indicating whether
the slot is full. A producer must wait while the slot is full, put a value, and
notify the consumer. The consumer must wait while the slot is empty, read the
value, and notify the producer.

Use `wait()` and `notifyAll()` inside synchronized methods or blocks. Produce and
consume 10 values, then terminate both threads cleanly. Explain why calling
`wait()` releases the monitor while calling `sleep()` does not.

PYQ connection: inter-thread communication and producer-consumer coordination.

## 6. Observe the thread state transitions

Create a worker that starts in `NEW`, sleeps long enough to observe `TIMED_WAITING`,
and then finishes. From `main`, print the worker's state before `start()`, after
`start()`, while it sleeps, and after `join()` returns. Explain why an exact
state may be difficult to observe without coordination.

Draw the state flow represented by your program: `NEW`, `RUNNABLE`,
`TIMED_WAITING`, and `TERMINATED`.

PYQ connection: thread states and their relationships.

## 7. Five-round goalkeeper and shooter simulation

Create a goalkeeper thread and a shooter thread for five penalty rounds. Each
round, both choose left or right using a shared, thread-safe coordination design.
Print whether the goalkeeper saves the shot or the shooter scores. Ensure the
main thread prints the final summary only after all five rounds finish.

Choose and justify one design: a shared synchronized round object, a blocking
queue, or `wait()`/`notifyAll()`.

PYQ connection: a multithreaded penalty-shootout simulation.

## 8. Same message, different thread designs

Implement two classes that each print `Happy Threading`, one character at a
time with a 500 ms delay. The first class must extend `Thread`; the second must
implement `Runnable`. Assign different priorities, start both, and make `main`
finish last with `join()`.

Observe whether priority guarantees a particular output order. Explain why it
does not provide strict scheduling control.

PYQ connection: `Thread`, `Runnable`, priorities, delays, and `join()`.

## Suggested order

Work through exercises 1–3 first, then 6, 4, 5, 8, and 7. The order moves from
thread construction and waiting to shared-state safety, then to coordination
and more involved simulations.
