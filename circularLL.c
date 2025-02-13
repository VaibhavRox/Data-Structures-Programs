#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a dummy head node
Node* createDummyNode() {
    Node* dummy = (Node*)malloc(sizeof(Node));
    if (!dummy) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    dummy->data = -1; // Dummy node can have any value; it's not part of the actual data
    dummy->next = dummy; // Pointing to itself to create the circular property
    return dummy;
}

// Function to insert a node at the end of the circular linked list
void insertEnd(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;

    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head; // Maintain circular property
}

// Function to insert a node at the front of the circular linked list
void insertFront(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;

    newNode->next = head->next;
    head->next = newNode;
}

// Function to delete a node from the front of the circular linked list
void deleteFront(Node* head) {
    if (head->next == head) { // List is empty
        printf("List is empty. Cannot delete.\n");
        return;
    }

    Node* temp = head->next;
    head->next = temp->next;
    free(temp);
    printf("Front node deleted.\n");
}

// Function to delete a node from the end of the circular linked list
void deleteEnd(Node* head) {
    if (head->next == head) { // List is empty
        printf("List is empty. Cannot delete.\n");
        return;
    }

    Node* temp = head;
    Node* prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head; // Update the second last node to point to the dummy node
    free(temp);
    printf("End node deleted.\n");
}

// Function to display the circular linked list
void display(Node* head) {
    if (head->next == head) { // List is empty
        printf("List is empty\n");
        return;
    }

    Node* temp = head->next; // Skip the dummy node
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Back to head)\n");
}

// Main function to test the circular linked list
int main() {
    Node* head = createDummyNode();

    // Insert elements at the end
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    printf("After inserting at the end:\n");
    display(head);

    // Insert elements at the front
    insertFront(head, 5);
    insertFront(head, 1);
    printf("After inserting at the front:\n");
    display(head);

    // Delete from the front
    deleteFront(head);
    printf("After deleting from the front:\n");
    display(head);

    // Delete from the end
    deleteEnd(head);
    printf("After deleting from the end:\n");
    display(head);

    return 0;
}
