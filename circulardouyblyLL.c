#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a dummy head node
Node* createDummyNode() {
    Node* dummy = (Node*)malloc(sizeof(Node));
    if (!dummy) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    dummy->data = -1; // Dummy node placeholder value
    dummy->next = dummy; // Points to itself
    dummy->prev = dummy; // Points to itself
    return dummy;
}

// Function to insert a node at the end of the doubly circular linked list
void insertEnd(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;

    Node* last = head->prev; // Last node (head->prev points to the last node)
    newNode->next = head; // New node's next points to the dummy node
    newNode->prev = last; // New node's prev points to the last node
    last->next = newNode; // Last node's next points to the new node
    head->prev = newNode; // Dummy node's prev points to the new node
}

// Function to insert a node at the front of the doubly circular linked list
void insertFront(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;

    Node* first = head->next; // First node (after the dummy node)
    newNode->next = first; // New node's next points to the first node
    newNode->prev = head; // New node's prev points to the dummy node
    head->next = newNode; // Dummy node's next points to the new node
    first->prev = newNode; // First node's prev points to the new node
}

// Function to delete a node from the front of the doubly circular linked list
void deleteFront(Node* head) {
    if (head->next == head) { // List is empty
        printf("List is empty. Cannot delete.\n");
        return;
    }

    Node* first = head->next; // First node
    Node* second = first->next; // Second node

    head->next = second; // Dummy node's next points to the second node
    second->prev = head; // Second node's prev points to the dummy node

    free(first);
    printf("Front node deleted.\n");
}

// Function to delete a node from the end of the doubly circular linked list
void deleteEnd(Node* head) {
    if (head->next == head) { // List is empty
        printf("List is empty. Cannot delete.\n");
        return;
    }

    Node* last = head->prev; // Last node
    Node* secondLast = last->prev; // Second last node

    secondLast->next = head; // Second last node's next points to the dummy node
    head->prev = secondLast; // Dummy node's prev points to the second last node

    free(last);
    printf("End node deleted.\n");
}

// Function to display the doubly circular linked list
void display(Node* head) {
    if (head->next == head) { // List is empty
        printf("List is empty\n");
        return;
    }

    Node* temp = head->next; // Skip the dummy node
    printf("Forward: ");
    while (temp != head) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("(Back to head)\n");
}

// Function to display the doubly circular linked list in reverse
void displayReverse(Node* head) {
    if (head->prev == head) { // List is empty
        printf("List is empty\n");
        return;
    }

    Node* temp = head->prev; // Start from the last node
    printf("Reverse: ");
    while (temp != head) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("(Back to head)\n");
}

// Main function to test the doubly circular linked list
int main() {
    Node* head = createDummyNode();

    // Insert elements at the end
    insertEnd(head, 10);
    insertEnd(head, 20);
    insertEnd(head, 30);
    printf("After inserting at the end:\n");
    display(head);
    displayReverse(head);

    // Insert elements at the front
    insertFront(head, 5);
    insertFront(head, 1);
    printf("After inserting at the front:\n");
    display(head);
    displayReverse(head);

    // Delete from the front
    deleteFront(head);
    printf("After deleting from the front:\n");
    display(head);
    displayReverse(head);

    // Delete from the end
    deleteEnd(head);
    printf("After deleting from the end:\n");
    display(head);
    displayReverse(head);

    return 0;
}
