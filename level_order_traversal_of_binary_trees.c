#include <stdio.h>
#include "queue.c"

int main() {
  // Creating our sample binary tree

  struct Node* n1 = create_node(15);
  struct Node* n2 = create_node(11);
  struct Node* n3 = create_node(17);
  struct Node* n4 = create_node(5);
  struct Node* n5 = create_node(13);
  struct Node* n6 = create_node(16);
  struct Node* n7 = create_node(1);
  struct Node* n8 = create_node(12);

  n1->left = n2;
  n1->right = n3;

  n2->left = n4;
  n2->right = n5;

  n3->left = n6;
  n3->right = NULL;

  n4->left = n7;
  n4->right = NULL;

  n5->left = n8;
  n5->right = NULL;

  n6->left = NULL;
  n6->right = NULL;
  
  n7->left = NULL;
  n7->right = NULL;

  n8->left = NULL;
  n8->right = NULL;

  struct Queue* queue = create_queue(50);
  enqueue(queue, n1);

  printf("Binary tree in level order: ");
  while(queue->size != 0) {
    struct Node* node = dequeue(queue);
    if(node->left) enqueue(queue, node->left);
    if(node->right) enqueue(queue, node->right);
    printf("%d ", node->value);
  }
}