#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
  int value;
  struct Node* left;
  struct Node* right;
};

struct Queue {
  struct Node** queue;
  int front, rear, size, capacity;
};

struct Node* create_node(int);
struct Queue* create_queue(int);
void enqueue(struct Queue*, struct Node*);
struct Node* dequeue(struct Queue*);
void printQueueElements(struct Queue*);

// int main() {
//   struct Queue *queue = create_queue(50);

//   char operation[20]; // ENQUEUE, DEQUEUE, EXIT
//   int value;

//   scanf("%s %d", &operation, &value);
//   while(strcmp(operation, "EXIT")) {
//     if (strcmp(operation, "ENQUEUE") == 0) {
//       enqueue(queue, value);
//     } else if (strcmp(operation, "DEQUEUE") == 0) {
//       dequeue(queue);
//     }

//     scanf("%s %d", &operation, &value);
//   }
// }

struct Node* create_node(int value) {
  // struct Node (5, 0x342342, 0x1987492)
  // struct Node* 0x312312
  // struct Node** [0x312312, 0x93492734]

  struct Node* node = (struct Node*) malloc(sizeof(struct Node)); //0x22b2cf21
  node->value = value; // (5, 0x2342, 0x342342) = (value, 0x2342, 0x342342)
  return node;
}

struct Queue* create_queue(int capacity) {
  struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
  queue->front = -1;
  queue->rear = -1;
  queue->size = 0;
  queue->capacity = capacity;
  queue->queue = (struct Node**)malloc(capacity * sizeof(struct Node*));

  return queue;
}

void enqueue(struct Queue* queue, struct Node* node) {
  if (queue->size == queue->capacity) {
    return;
  }

  queue->rear = (queue->rear + 1) % queue->capacity;
  queue->queue[queue->rear] = node;
  queue->size = queue->size + 1;

  if (queue->front == -1) {
    queue->front = 0;
    fflush(stdout);
  }

  // printQueueElements(queue);
}

struct Node* dequeue(struct Queue* queue) {
  if (queue->size == 0) {
    return NULL;
  }

  struct Node* node = queue->queue[queue->front];
  queue->front = (queue->front + 1) % queue->capacity;
  queue->size = queue->size - 1;

  if (queue->size == 0) {
    queue->front = -1;
    queue->rear = -1;
  }

  // printQueueElements(queue);
  return node;
}

void printQueueElements(struct Queue* queue) {
  int counter = 0;
  for (int i = queue->front; counter++ < queue->size;
       i = (i + 1) % queue->capacity) {
    printf("%d ", (queue->queue[i])->value);
    fflush(stdout);
  }
  printf("\n");
  fflush(stdout);
}
