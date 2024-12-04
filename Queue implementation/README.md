# Queue Implementation in C

File simple_queue and circular_queue.c contains a simple implementation of a queue data structures. They have such commands:
## simple_queue.c
1. initQueue() - It initializes the queue by setting head and tail pointer to the -1 that means queue is empty.
2. isQueueEmpty() - It checks if queue is empty or not by comparing the head with -1.
3. isQueueFull() - It checks is queue is full or not by comparing tail (last element) with queue size.
4. enQueue() - Adds a new element to the queue if the queue is not full.
5. deQueue() - Deletes the first element from the queue (FIFO) up to the tail (last element) if the queue is not empty yet.
6. printQueue() - Prints all elements in the queue.

## circular_queue.c
1. initQueue() - It initializes the queue by setting head and tail pointer to the -1 that means queue is empty.
2. isQueueEmpty() - It checks if queue is empty or not by comparing the head with -1.
3. isQueueFull() - It checks is queue is full or not by comparing head with the position of the tail (last element).
4. enQueue() - Adds a new element to the queue if the queue is not full. After deleting elements you can add a new elements (the circular_queue diversity). 
5. deQueue() - Deletes the first element from the queue (FIFO) up to the tail (last element) if the queue is not empty yet.
6. printQueue() - Prints all elements in the queue. P.S. In this function if you print all elements before you filled the queue you will get garbage values
that is not really good, but I did it on purpose to see it works. (* ´ ▽ ` *) 
