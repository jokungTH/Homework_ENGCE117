#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};



void createList(struct Node** start_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *start_ref;

    new_node->prev = NULL;
    if (*start_ref != NULL) {
       (*start_ref)->prev = new_node; 
    }
    *start_ref = new_node;
}

void displayList(struct Node* node) {
    struct Node* last;
    while (node != NULL) {
        printf("Address :%d , data : %d \n",node , node->data);
        last = node;
        node = node->next;
    }
}

void swapNodes(struct Node** head_ref, int First_num, int Second_num) {
    if (First_num == Second_num) {
        return;
    }

    struct Node *prev_Firstnum = NULL, *curr_Firstnum = *head_ref;
    
    while (curr_Firstnum && curr_Firstnum->data != First_num) {
        prev_Firstnum = curr_Firstnum;
        curr_Firstnum = curr_Firstnum->next;
    }

    struct Node *prev_Secondnum = NULL, *curr_Secondnum = *head_ref;
    while (curr_Secondnum && curr_Secondnum->data != Second_num) {
        prev_Secondnum = curr_Secondnum;
        curr_Secondnum = curr_Secondnum->next;
    }

    if (curr_Firstnum == NULL || curr_Secondnum == NULL) {
        return;
    }
        
    if (prev_Firstnum != NULL) {
        prev_Firstnum->next = curr_Secondnum;
    }else {
        *head_ref = curr_Secondnum;  
    }
        
    if (prev_Secondnum != NULL) {
        prev_Secondnum->next = curr_Firstnum;
    }else {
        *head_ref = curr_Firstnum;
    }

    struct Node* temp = curr_Secondnum->prev;
    curr_Secondnum->prev = curr_Firstnum->prev;
    curr_Firstnum->prev = temp;
    temp = curr_Secondnum->next;
    curr_Secondnum->next = curr_Firstnum->next;
    curr_Firstnum->next = temp;
}

int main() {
    struct Node* start = NULL;
    struct Node* data = NULL;
    int count_node;
    
    printf("Enter number of node : ");
    scanf("%d", &count_node);
    printf("Enter data in node : ");
    for (int i = 0; i < count_node; i++) {
        scanf("%d", &data);
        createList(&start, data);
    }
    printf("Current Linked list : \n");
    displayList(start);
    printf("\n\t======================");
    int A_pos , B_pos;
    printf("\nEnter first number to swap : ");
    scanf("%d", &A_pos);
    printf("\nEnter secondary number to swap : ");
    scanf("%d", &B_pos);
    printf("\nSwapping...");
    printf("\n\t======================");
    swapNodes(&start, A_pos, B_pos);
    printf("\nNew Linked list : \n");
    displayList(start);

    return 0;
}
