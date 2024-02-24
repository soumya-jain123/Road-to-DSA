#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insert(struct node**, int);
int search_iterative(struct node*, int );
int search_recursive(struct node* , int);
int count(struct node*);
void display(struct node*);

int main(){
    struct node* p;
    int n;
    p = NULL;

    printf("No. of Elements in the genrated linked list = %d\n", count(p));
    insert(&p, 1);
    insert(&p, 2);
    insert(&p, 3);
    insert(&p, 4);

    display(p);

    printf("Enter the number you want to search: ");
    scanf("%d",&n);

    printf("Iterative search = %d\n", search_iterative(p, n));
    printf("Iteration recursive = %d\n", search_recursive(p, n));
    
}

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
// for iterative method
int search_iterative(struct node* head, int target){
    struct node* current = head;
    while(current != NULL){
        if(current -> data == target)
            return 1; // if found the element
        current = current -> next;
    }
    return 0; // if not found the element
}

int count(struct node* q){
    int count =0;
    while(q != NULL){
        q = q->next;
        count++;
    }
    return count;
}

void display(struct node* q){
    while(q != NULL){
        printf("%d ", q -> data);
        q = q -> next;
    }
    printf("\n");
}
// for recccursive method   
int search_recursive(struct node* q, int target){
    if (q == NULL){
        return 0;
    }
    if(q -> data == target){
        return 1;
    }
    return search_recursive(q -> next, target);
}