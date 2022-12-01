#ifndef THREADS_SYNCH_H
#define THREADS_SYNCH_H

#include <list.h>
#include <stdbool.h>

/* A counting semaphore. */
struct semaphore 
  {
    unsigned value;             /* Current value. */
    struct list waiters;        /* List of waiting threads. */
    struct list_elem holder_elem;
    int sema_priority;
  };

void sema_init (struct semaphore *, unsigned value);
void sema_down (struct semaphore *);
bool sema_try_down (struct semaphore *);
void sema_up (struct semaphore *);
void sema_self_test (void);

/* Lock. */
struct lock 
  {
    struct thread *holder;      /* Thread holding lock (for debugging). */
    struct semaphore semaphore; /* Binary semaphore controlling access. */
    /*Added by moon*/
    struct list_elem holder_elem;/*用于加入到某个获得当前信号量的线程的locks队列中*/
    int lock_priority;           /*当前获得锁的线程的优先级*/
    /*Added by moon*/
  };

void lock_init (struct lock *);
void lock_acquire (struct lock *);
bool lock_try_acquire (struct lock *);
void lock_release (struct lock *);
bool lock_held_by_current_thread (const struct lock *);

/* Condition variable. */
struct condition 
  {
    struct list waiters;        /* List of waiting threads. */
  };

void cond_init (struct condition *);
void cond_wait (struct condition *, struct lock *);
void cond_signal (struct condition *, struct lock *);
void cond_broadcast (struct condition *, struct lock *);

/* Optimization barrier.

   The compiler will not reorder operations across an
   optimization barrier.  See "Optimization Barriers" in the
   reference guide for more information.*/
#define barrier() asm volatile ("" : : : "memory")

/*Added by moon*/
/*比较两个list_elem对应的锁的优先级*/
bool lock_priority_higher (const struct list_elem *, const struct list_elem *, void *aux);

/*比较两个list_elem对应的semaphore_elem所对应的semaphore的优先级*/
bool sema_priority_higher (const struct list_elem *, const struct list_elem *, void *aux);
/*Added by moon*/

#endif /* threads/synch.h */
