#include <stdio.h>
#define MAX_SIZE 5 

int deque[MAX_SIZE];
int front = -1;
int rear = -1;


int isDEEmpty() {
    return front == -1;
}

int isDEFull() {
    return (rear + 1) % MAX_SIZE == front;
}

void EnQueueFront(int item) {
    if (isDEFull()) {
        printf("Deque is full! Cannot enqueue %d at front.\n", item);
        return;
    }
    if (isDEEmpty()) {
        front = 0;  
        rear = 0;   
    } else {
        front = (front - 1 + MAX_SIZE) % MAX_SIZE;  
    }
    deque[front] = item;
    printf("Enqueued at front: %d\n", item);
}


void EnQueueRear(int item) {
    if (isDEFull()) {
        printf("Deque is full! Cannot enqueue %d at rear.\n", item);
        return;
    }
    if (isDEEmpty()) {
        front = 0;  
        rear = 0;   
    } else {
        rear = (rear + 1) % MAX_SIZE; 
    }
    deque[rear] = item;
    printf("Enqueued at rear: %d\n", item);
}


int DeQueueFront() {
    if (isDEEmpty()) {
        printf("Deque is empty! Cannot dequeue from front.\n");
        return -1;  
    }
    int item = deque[front];
    if (front == rear) {
    
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;  
    }
    printf("Dequeued from front: %d\n", item);
    return item;
}


int DeQueueRear() {
    if (isDEEmpty()) {
        printf("Deque is empty! Cannot dequeue from rear.\n");
        return -1;  
    }
    int item = deque[rear];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;  
    }
    printf("Dequeued from rear: %d\n", item);
    return item;
}


void display() {
    if (isDEEmpty()) {
        printf("Deque is empty!\n");
        return;
    }
    printf("Deque: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;  
        i = (i + 1) % MAX_SIZE;  
    }
    printf("\n");
}

int main() {
    int choice, item;
    while (1) {
        printf("\nDeque Operations\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter an element: ");
                scanf("%d", &item);
                EnQueueFront(item);
                break;
            case 2:
                printf("\nEnter an element: ");
                scanf("%d", &item);
                EnQueueRear(item);
                break;
            case 3:
                DeQueueFront();
                break;
            case 4:
                DeQueueRear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Thank you for choosing the deque.\n");
                return 0;
            default:
                printf("Invalid choice.... Please enter a valid choice.\n");
        }
    }
    return 0;
}