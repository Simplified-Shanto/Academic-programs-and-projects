/*
 * PYQ Exercise 5: Build a one-slot producer-consumer queue
 *
 * Implement a OneSlotQueue containing one integer and a flag indicating whether
 * the slot is full. A producer must wait while the slot is full, put a value,
 * and notify the consumer. A consumer must wait while the slot is empty, read
 * the value, and notify the producer. Produce and consume 10 values, then end
 * both threads cleanly. Explain why wait() releases the monitor while sleep()
 * does not.
 *
 * Write your solution below this comment.
 */
