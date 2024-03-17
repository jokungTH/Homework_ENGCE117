#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

void swapNodes(struct Node head_ref, int first, int second) {
    if (first == second) {
        return;
    }
    struct Node* prevA = NULL;
    struct Node* currA = head_ref;
    while (currA != NULL && currA->data != first) {
        prevA = currA;
        currA = currA->next;
    }
    struct Node prevB = NULL;
    struct Node* currB = *head_ref;
    while (currB != NULL && currB->data != second) {
        prevB = currB;
        currB = currB->next;
    }
    if (currA == NULL || currB == NULL) {
        return;
    }
    if (prevA != NULL) {
        prevA->next = currB;
    } else {
        *head_ref = currB;
    }
    if (prevB != NULL) {
        prevB->next = currA;
    } else {
        head_ref = currA;
    }
    struct Node temp = currA->next;
    currA->next = currB->next;
    currB->next = temp;
}

void push(struct Node head_ref, struct Node** new_data) {
    struct Node* new_node = (struct Node)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (head_ref);
    (head_ref) = new_node;
}

void printList(struct Node node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main() {
    struct Node* head = NULL;
    struct Node* data = NULL;
    int count_node;
    printf("Enter number of node : ");
    scanf("%d", &count_node);
    printf("Enter data node : ");
    for( int i = 0; i < count_node; i++) {
        scanf("%d", &data);
        push(&head, data);
    }
    // Print the list
    printf("\n\tlist: \n");
    printList(head);
    int x, y;
    printf("\nEnter first pos to swap : ");
    scanf("%d", &x);
    printf("\nEnter second pos to swap : ");
    scanf("%d", &y);
    // Swap nodes
    swapNodes(&head, x, y);
    // Print the new list
    printf("\nList after swapping nodes %d and %d: \n", x, y);
    printList(head);

    return 0;
}
