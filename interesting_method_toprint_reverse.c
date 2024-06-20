#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void printReverse(struct node* head){
    if(!head)
        return;
    
    printReverse(head->next);
    printf("%d->", head->data);
}

void insert(struct node** head, int n){
    struct node* new_node;
    struct node* temp;
    int value, i;

    for(i=0; i<n; i++){
        new_node = (struct node*)malloc(sizeof(struct node));
        if(new_node == NULL){
            printf("Memory allocation failed.\n");
            return;
        }

        printf("Enter data for node %d: ", i+1);
        scanf("%d", &value);

        new_node->data = value;
        new_node->next = NULL;

        if(*head == NULL){
            *head = new_node;
            temp = *head;
        }else{
            temp->next = new_node;
            temp = temp->next;
        }
    }
}

void display(struct node* head){
    printf("Linked list->");
    while(head != NULL){
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(){
    struct node* head =NULL;
    int number_of_nodes;

    printf("Enter the number of nodes to be present in the linked list: ");
    scanf("%d", &number_of_nodes);

    insert(&head, number_of_nodes);
    display(head);

    printf("Reversed linked list is: ");
    printReverse(head);
}