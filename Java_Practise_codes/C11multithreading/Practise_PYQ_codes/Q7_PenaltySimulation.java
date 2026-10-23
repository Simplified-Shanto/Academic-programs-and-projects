/*
 * PYQ Exercise 7: Five-round goalkeeper and shooter simulation
 *
 * Create a goalkeeper thread and a shooter thread for five penalty rounds. In
 * each round, both choose left or right using a shared, thread-safe design.
 * Print whether the goalkeeper saves the shot or the shooter scores. Main must
 * print the final summary only after all five rounds finish.
 *
 * Choose and justify one design: a shared synchronized round object, a blocking
 * queue, or wait()/notifyAll().
 *
 * Write your solution below this comment.
 */
