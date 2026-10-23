/*
 * PYQ Exercise 4: Produce a deadlock deliberately, then remove it
 *
 * Create two shared lock objects. Thread 1 must lock A and then wait for B;
 * Thread 2 must lock B and then wait for A. Add messages before and after each
 * lock so the deadlock can be identified. Then remove the deadlock by making
 * both threads acquire the locks in the same order. Explain the four conditions
 * that make the deadlock possible.
 *
 * Do not rely on sleep() to create the deadlock; use it only to make the trace
 * easy to observe.
 *
 * Write your solution below this comment.
 */
