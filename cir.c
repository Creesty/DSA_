#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10 // Adjust the maximum size as needed

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
    int count;
} CircularQueue;

void initializeQueue(CircularQueue* queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->count = 0;
}

bool isFull(CircularQueue* queue) {
    return queue->count == MAX_SIZE;
}

bool isEmpty(CircularQueue* queue) {
    return queue->count == 0;
}

void enqueue(CircularQueue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->data[queue->rear] = value;
    queue->count++;
}

int dequeue(CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Assuming -1 is not a valid element in the queue
    }

    int dequeuedValue = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->count--;

    return dequeuedValue;
}

int main() {
    CircularQueue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));

    enqueue(&queue, 40);
    enqueue(&queue, 50);

    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue));
    printf("Dequeued: %d\n", dequeue(&queue)); // Attempt to dequeue from an empty queue

    return 0;
}
