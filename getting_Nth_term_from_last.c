#include<stdio.h>
#include<Stdlib.h>
struct node{
    int data;
    struct node* next;
};

void insert(struct node** q, int data){
    struct node* temp, *r;
    if(*q == NULL){
        temp = (struct node*)malloc(sizeof(struct node));
        temp -> data = data;
        temp -> next = NULL;
        *q = temp;
    }else{
        temp = *q;
        while(temp -> next != NULL)
            temp = temp -> next;
            r = (struct node*)malloc(sizeof(struct node));
            r -> data = data;
            r -> next = NULL;
            temp -> next = r;
    }   
}

void print_Nth_From_last(struct node* head, int N){
    int len = 0, i;
    struct node* temp = head;

    while(temp != NULL){
        temp = temp -> next;
        len++;
    }

    if(len < N)
        return;
    temp = head;

    for(i = 1; i < len - N +1; i++){
        temp = temp -> next;
    }
    printf("%d", temp->data);
    return;
}

void display(struct node* head){
    while(head != NULL){
        printf("%d ", head -> data);
        head = head -> next;
    }
    printf("\n");
}

int main(){
    struct node* head =NULL;
    int n;

    insert(&head, 9);
    insert(&head, 10);
    insert(&head, 8);
    insert(&head, 12);

    display(head);

    printf("Enter the position from which you want to extract the number: ");
    scanf("%d", &n);
    print_Nth_From_last(head, n);
}