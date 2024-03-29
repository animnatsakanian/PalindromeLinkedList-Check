#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Creating nodes of linked lists
struct Node {
    int data;
    struct Node* next;
};
typedef struct Node Node;

// Creating a node
Node* createNode(int value) {
    Node* NewNode = (Node*)malloc(sizeof(Node));
    NewNode->data = value;
    NewNode->next = NULL;
    return NewNode;
}

// Append new node
void append(Node** head, int value) {
    Node* new_node = createNode(value);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    Node* last_node = *head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;
}

// Function to free the memory allocated for the linked list.
void freeLinkedList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to check if a linked list is a palindrome.
bool isPalindrome(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;
    Node* temp;

    // Move fast pointer to the end and slow pointer to the middle.
    while (fast && fast->next) {
        fast = fast->next->next;
        temp = slow->next;
        slow->next = prev;
        prev = slow;
        slow = temp;
    }

    // If the number of nodes is odd, move slow pointer one step forward.
    if (fast) {
        slow = slow->next;
    }

    // Compare nodes from the middle to the ends.
    while (prev && slow) {
        if (prev->data != slow->data) {
            return false;
        }
        prev = prev->next;
        slow = slow->next;
    }

    return true;
}

int main() {

    // Creating a sample linked list: 1 -> 2 -> 3 -> 2 -> 1
    Node* head = NULL; // Initializing an empty linked list

    // Appending nodes to the linked list: 1 -> 2 -> 3 -> 2 -> 1
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 2);
    append(&head, 1);


    // Checking if the linked list is a palindrome.
    if (isPalindrome(head)) {
        printf("The linked list is a palindrome.\n");
    } else {
        printf("The linked list is not a palindrome.\n");
    }

    // Free the memory allocated for the linked list.
    freeLinkedList(head);

    return 0;
}

