#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insert(struct node** head_Ref, int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = data;
    new_node -> next = (*head_Ref);
    (*head_Ref)= new_node;
}

void printMiddle(struct node* head){
    struct node* slow_ptr = head;
    struct node* fast_ptr = head;

    if(head != NULL){
        while(fast_ptr != NULL && fast_ptr -> next != NULL){
            slow_ptr = slow_ptr-> next;
            fast_ptr = fast_ptr -> next -> next;
        }

        printf("The middle element is %d\n", slow_ptr->data);
    }
}

void display(struct node* head){
    while(head != NULL){
        printf("%d ", head-> data);
        head = head -> next;
    }
    printf("\n");
}

int main(){
    struct node* head = NULL;

    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 1);

    printf("Linked list is: ");
    display(head);

    printMiddle(head);
}