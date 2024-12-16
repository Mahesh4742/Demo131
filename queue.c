#include <stdio.h>
#define MAX_SIZE 5  // Maximum size of the queue

// Declare the queue variables
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Check if the queue is empty
int isQEmpty() {
    return front == -1 || front > rear;
}

// Check if the queue is full
int isQFull() {
    return rear == MAX_SIZE - 1;
}

// Add an item to the queue
void EnQueue(int item) {
    if (isQFull()) {
        printf("Queue is full! Cannot enqueue %d.\n", item);
        return;
    }
    if (isQEmpty()) {
        front = 0;  // Set front to 0 if the queue was empty
    }
    rear++;
    queue[rear] = item;
    printf("Enqueued: %d\n", item);
}

// Remove an item from the queue
int DeQueue() {
    if (isQEmpty()) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;  // Return -1 to indicate an error
    }
    int item = queue[front];
    front++;
    if (front > rear) {
        // Reset the queue when it becomes empty
        front = -1;
        rear = -1;
    }
    printf("Dequeued: %d\n", item);
    return item;
}

// Display the current state of the queue
void display() {
    if (isQEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

// Main function to demonstrate queue operations
int main() {
    int choice,item;
    while (1) {
        printf("\nQueue Operations\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter an element: ");
                scanf("%d", &item);
                EnQueue(item);
                break;
            case 2:
                DeQueue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Thank you for choosing the queue.\n");
                return 0;
            default:
                printf("Invalid choice.... Please enter a valid choice.\n");
        }
    }
    return 0;
}
