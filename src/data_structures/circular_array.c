#include <stdio.h>

#define SIZE 10
#define ARRAY_SIZE(arr)  (sizeof(arr) / sizeof((arr)[0]))

typedef struct Queues {
  int queue[SIZE];
  int front;
  int back;
  int count;
} Queue;

Queue initQueue() {
  Queue queue;
  queue.front = 0;
  queue.back  = 0;
  queue.count = 0;

  return queue;
}

void print(Queue *queue) {
  printf("Front of queue: %d, at position: %d\n", queue->queue[queue->front], queue->front);
  printf("Back of queue: %d, at position: %d\n", queue->queue[queue->back], queue->back);
  printf("Current openings in queue: %d\n", SIZE - queue->count);
}

void insert(Queue *queue, int value) {
  if(queue->count == SIZE) {
    printf("Queue is full!\n");
    return;
  }

  if(queue->count == 0) {
    queue->queue[queue->back] = value;
  } else {
    queue->back = (queue->back + 1) % SIZE;
    queue->queue[queue->back] = value;
  }

  queue->count++;

  return;
}

void read(Queue *queue) {
  if(queue->count == 0) {
    printf("Queue is empty!\n");
    return;
  }

  int value = queue->queue[queue->front];
  queue->queue[queue->front] = 0;
  queue->count--;

  if(queue->count != 0) {
    queue->front = (queue->front + 1) % SIZE;
  }

  printf("Next in line is: %d\n", value);

  return;
}

int main() {
  Queue queue  = initQueue();
  int value;

  printf("You have a queue size of 10.\nPlease select an option:\n\n");
  printf("\tEnter 'i' to insert new value.\n\tEnter 'r' to read/remove next value in queue\n");
  printf("\tEnter 'e' to empty the queue.\n\tEnter 'p' to print the queue\n\tEnter 'x' to exit\n");

  char select;
  scanf("%c", &select);
  while(select != 'x') {
    switch(select) {
      case 'i':
        printf("Enter value to insert: ");
        scanf("%d", &value);
        insert(&queue, value);
        print(&queue);
        break;
      case 'r':
        read(&queue);
        print(&queue);
        break;
      case 'p':
        print(&queue);
        break;
      case '\n':
        break;
      default:
        printf("\nInvalid selection %s, please review the selections\n", &select);
        break;
    }

    printf("\nPlease make another selection: ");
    scanf("%c", &select);
  }

  return 0;
}
