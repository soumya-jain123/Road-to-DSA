#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insert(struct node** head, int n) {
    struct node* new_node;
    struct node* temp;
    int num, i;

    for (i = 0; i < n; i++) {
        new_node = (struct node*)malloc(sizeof(struct node));
        if (new_node == NULL) {
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &num);

        new_node->data = num;
        new_node->next = NULL;

        if (*head == NULL) {
            *head = new_node;
            temp = *head;
        } else {
            temp->next = new_node;
            temp = temp->next;
        }
    }
}

void display(struct node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int count(struct node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int getNth(struct node* head, int N) {
    int i;
    for (i = 1; i < N && head != NULL; i++) {
        head = head->next;
    }
    if (head != NULL)
        return head->data;
    else
        return -1; 
}

void addatBeg(struct node** head, int num){
    struct node* temp;
    temp = (struct node*)malloc(sizeof(struct node));
    temp -> data = num;
    temp -> next = *head;
    *head = temp;
}
 
void nodeAtEnd(struct node** head, int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL){
        printf("memory allocation failed\n");
    }
    new_node->data = data;
    new_node->next=NULL;
    if(*head == NULL){
        *head = new_node;
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}


void insert_after_position(struct node** head, int position, int data) {
    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = data;

    // Traverse the list to find the node at the specified position
    struct node* temp = *head;
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    // Insert the new node after the node at the specified position
    new_node->next = temp->next;
    temp->next = new_node;
}

void insert_before_position(struct node** head, int position, int data) {
    if (position <= 1) {
        printf("Invalid position.\n");
        return;
    }

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = data;

    if (*head == NULL) {
        // If the list is empty, make the new node the head of the list
        *head = new_node;
        new_node->next = NULL;
        return;
    }

    if (position == 2) {
        // If position is 2, insert at the beginning
        new_node->next = *head;
        *head = new_node;
        return;
    }

    // Traverse the list to find the node at (position - 1)
    struct node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    // Insert the new node before the node at (position - 1)
    new_node->next = temp->next;
    temp->next = new_node;
}


int main() {
    struct node* head = NULL;
    int n, N;
    int position;

    printf("Enter the number of nodes to be inserted: ");
    scanf("%d", &n);

    insert(&head, n);
    display(head);

    printf("Total number of elements in linked list: %d\n", count(head));

    printf("Enter the position from which you want to extract the number: ");
    scanf("%d", &N);

    if (N <= 0 || N > count(head))
        printf("Invalid position.\n");
    else
        printf("The element at position %d is: %d\n", N, getNth(head, N));

    int Num;
    printf("Enter the value to be inserted in New_Node: ");
    scanf("%d", &Num);

    addatBeg(&head, Num);
    display(head);

    printf("Enter the value to be inserted in New_Node: ");
    scanf("%d", &Num);

    nodeAtEnd(&head, Num);
    display(head);

     printf("Enter the position at which you want to insert the node: ");
    scanf("%d", &position);
    printf("Enter the data value for the new node: ");
    scanf("%d", &Num);

    insert_after_position(&head, position, Num);
    display(head);

    printf("Enter the position at which you want to insert the node: ");
    scanf("%d", &position);
    printf("Enter the data value for the new node: ");
    scanf("%d", &Num);
    insert_before_position(&head, position, Num);
    display(head);

    

    return 0;
}
