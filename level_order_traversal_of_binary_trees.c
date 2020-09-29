#include <stdio.h>
#include "queue.c"

int main() {
  struct Queue* queue = create_queue(50);
  enqueue(queue, 5);
  enqueue(queue, 3);
  printQueueElements(queue);
}