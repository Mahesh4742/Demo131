#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

typedef struct Queue *Queue;

Queue createQueue() {
    Queue q = (Queue)malloc(sizeof( Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isQEmpty(Queue q) {
    return q->front == NULL;
}


void EnQueue(Queue q, int item) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;

    if (isQEmpty(q)) {
        q->front = newNode;  
    } else {
        q->rear->next = newNode;  
    }
    q->rear = newNode;  
    printf("Enqueued: %d\n", item);
}

int DeQueue(struct Queue* q) {
    if (isQEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;  
    }
    struct Node* temp = q->front;
    int item = temp->data;
    q->front = q->front->next;  
    if (q->front == NULL) {
        q->rear = NULL;  
    }
    free(temp);
    printf("Dequeued: %d\n", item);
    return item;
}


void display(Queue q) {
    if (isQEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function 
int main() {
    Queue q = createQueue();
    int choice, item;

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
                EnQueue(q, item);
                break;
            case 2:
                DeQueue(q);
                break;
            case 3:
                display(q);
                break;
            case 4:
                printf("Thank you for using the queue.\n");
                free(q);  
                exit(0);
            default:
                printf("Invalid choice.... Please enter a valid choice.\n");
        }
    }
    return 0;
}