#include <stdio.h>
#include <stdlib.h>  // For exit()
#define N 20

// Declaring two queues and their front and rear variables
int queue1[N], queue2[N];
int f1 = -1, r1 = -1;
int f2 = -1, r2 = -1;
int count = 0; // To keep track of the stack size

// Function prototypes
void enqueue1(int x);
int dequeue1();
void enqueue2(int x);
int dequeue2();
void push(int x);
int pop();
void display();

// Main function
int main() {
    int ch, num;

    while (1) { // Infinite loop, broken only on exit choice
        printf("\n1. Push Item\n2. Pop Item\n3. Display Items\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter item to be inserted: ");
                scanf("%d", &num);
                push(num); // Push function call
                break;
            case 2:
                printf("Item popped: %d\n", pop()); // Pop function call
                break;
            case 3:
                display(); // Display stack items
                break;
            case 4:
                exit(0); // Exit the program
                break;
            default:
                printf("\nInvalid Choice!\n"); // Invalid input
        }
    }

    return 0; // Return 0 if main terminates correctly (should not reach here)
}

// Enqueue operation for queue1
void enqueue1(int x) {
    if (r1 == N - 1) {
        printf("Queue1 Overflow\n");
    } else {
        if (f1 == -1) {
            f1 = 0; // Initialize front if it's the first element
        }
        r1++;
        queue1[r1] = x;
    }
}

// Dequeue operation for queue1
int dequeue1() {
    int temp;
    if (f1 == -1 || f1 > r1) {
        printf("Queue1 Underflow\n");
        return -1; // Return -1 in case of underflow
    } else {
        temp = queue1[f1];
        f1++;
        return temp;
    }
}

// Enqueue operation for queue2
void enqueue2(int x) {
    if (r2 == N - 1) {
        printf("Queue2 Overflow\n");
    } else {
        if (f2 == -1) {
            f2 = 0; // Initialize front if it's the first element
        }
        r2++;
        queue2[r2] = x;
    }
}

// Dequeue operation for queue2
int dequeue2() {
    int temp;
    if (f2 == -1 || f2 > r2) {
        printf("Queue2 Underflow\n");
        return -1; // Return -1 in case of underflow
    } else {
        temp = queue2[f2];
        f2++;
        return temp;
    }
}

// Push function to insert data into the stack using two queues
void push(int x) {
    enqueue1(x); // Add the item to queue1
    for (int i = 0; i < count; i++) {
        enqueue1(dequeue2()); // Transfer items from queue2 to queue1
    }
    count++; // Increment stack size
    for (int i = 0; i < count; i++) {
        enqueue2(dequeue1()); // Transfer items back to queue2 to maintain stack order
    }
}

// Pop function to delete data from the stack using two queues
int pop() {
    if (count == 0) {
        printf("Stack Underflow\n");
        return -1; // Return -1 if the stack is empty
    }
    count--; // Decrement stack size
    return dequeue2(); // Dequeue from queue2 (stack top)
}

// Display the items in the stack (queue2 holds the stack elements)
void display() {
    if (f2 == -1 || f2 > r2) {
        printf("Stack is empty!\n");
        return;
    }

    printf("\nElements in Stack: ");
    for (int i = f2; i <= r2; i++) {
        printf("%d ", queue2[i]);
    }
    printf("\n");
}
