//write a function that count the number of times a given data is occurs in a linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

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

int occurenceOfAnInteger(struct node* head, int data_for_search){
    struct node* current = head;
    int count = 0;
    while(current != NULL){
        if(current-> data == data_for_search)
            count++;
        current = current -> next;
    }
    return count;
}

void display(struct node* head){
    printf("linked list: ");
    while(head != NULL){
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(){
    struct node* head = NULL;
    int number_of_node;
    printf("Enter the number of nodes to be inserted in the linked list: ");
    scanf("%d", &number_of_node);

    insert(&head, number_of_node);
    display(head);

    int count=0,value;
    printf("Enter the data for which you want to check the occurence: ");
    scanf("%d", &value);

    count = occurenceOfAnInteger(head, value);
    printf("Therefore %d occurs %d times in given linked list.", value, count);

    return 0;
}