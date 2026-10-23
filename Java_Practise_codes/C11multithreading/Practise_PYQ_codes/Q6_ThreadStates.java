/*
 * PYQ Exercise 6: Observe thread state transitions
 *
 * Create a worker that starts in NEW, sleeps long enough to observe
 * TIMED_WAITING, and then finishes. From main, print the worker's state before
 * start(), after start(), while it sleeps, and after join() returns. Explain
 * why an exact state can be difficult to observe without coordination.
 *
 * Draw the state flow represented by the program: NEW, RUNNABLE,
 * TIMED_WAITING, and TERMINATED.
 *
 * Write your solution below this comment.
 */
