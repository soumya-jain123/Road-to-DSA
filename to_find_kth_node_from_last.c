#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insertNode(struct node** head, int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode -> data = data;
    newNode -> next = *head;
    *head = newNode;
}

struct node* findKthFromEnd(struct node* head, int k){
    if(head == NULL || k<=0){
        return NULL;
    }

    struct node* slow = head;
    struct node* fast = head;
    for(int i = 0; i<k; ++i){
        if(fast == NULL){
            return NULL; // If list length < k
        }
        fast = fast->next;
    }
    while(fast != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    return slow; // Return the kth node from the end
}


int main(){
    struct node* head = NULL;
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    int k = 2;
    struct node* result = findKthFromEnd(head, k);
    if(result != NULL)
        printf("The %d'th node from the end is: %d\n", k, result->data);
    else
        printf("Invalid input or list length is less than %d\n", k);

    while(head!=NULL){
        struct node* temp = head;
        head = head-> next;
        free(temp);
    }
    return 0;
}