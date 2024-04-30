#include <stdio.h>
#include <stdlib.h>
 
// Linked List Node
struct node {
    int data;
    struct node* link;
};
struct node* start = NULL;

void display(){
 struct node* temp;
 
    // List is empty
    if (start == NULL)
        printf("\nList is empty\n");
 
    // Else print the LL
    else {
        temp = start;
        printf("Linked List:");
        while (temp != NULL) {
            printf(" %d->", temp->data);
            temp = temp->link;
        }
    }
}

void create()
{
    if (start == NULL) {
        int n;
        printf("\nEnter the number of nodes: ");
        scanf("%d", &n);
        if (n != 0) {
            int data;
            struct node* newnode;
            struct node* temp;
            newnode = malloc(sizeof(struct node));
            start = newnode;
            temp = start;
            printf("\nEnter number to"
                " be inserted : ");
            scanf("%d", &data);
            start->data = data;
 
            for (int i = 2; i <= n; i++) {
                newnode = malloc(sizeof(struct node));
                temp->link = newnode;
                printf("\nEnter number to"
                    " be inserted : ");
                scanf("%d", &data);
                newnode->data = data;
                temp = temp->link;
            }
        }
        printf("\nThe list is created\n");
    }
    else
        printf("\nThe list is already created\n");
}

void insertfront(){
 int data;
    struct node* temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to"
        " be inserted : ");
    scanf("%d", &data);
    temp->data = data;
 
    // Pointer of temp will be
    // assigned to start
    temp->link = start;
    start = temp;
}

void insertend(){
  int data;
    struct node *temp, *head;
    temp = malloc(sizeof(struct node));
 
    // Enter the number
    printf("\nEnter number to"
        " be inserted : ");
    scanf("%d", &data);
 
    // Changes links
    temp->link = 0;
    temp->data = data;
    head = start;
    while (head->link != NULL) {
        head = head->link;
    }
    head->link = temp;
}

void insertpos(){
  struct node *temp, *newnode;
    int pos, data, i = 1;
    newnode = malloc(sizeof(struct node));
 
    // Enter the position and data
    printf("\nEnter position and data :");
    scanf("%d %d", &pos, &data);
 
    // Change Links
    temp = start;
    newnode->data = data;
    newnode->link = 0;
    while (i < pos - 1) {
        temp = temp->link;
        i++;
    }
    newnode->link = temp->link;
    temp->link = newnode;
}

void delfront(){
  struct node* temp;
    if (start == NULL)
        printf("\nList is empty\n");
    else {
        temp = start;
        start = start->link;
        free(temp);
     }
}

void delend(){
   struct node *temp, *prevnode;
    if (start == NULL)
        printf("\nList is Empty\n");
    else {
        temp = start;
        while (temp->link != 0) {
            prevnode = temp;
            temp = temp->link;
        }
        free(temp);
        prevnode->link = 0;
    }
}

void delpos(){
  struct node *temp, *position;
    int i = 1, pos;
 
    // If LL is empty
    if (start == NULL)
        printf("\nList is empty\n");
 
    // Otherwise
    else {
        printf("\nEnter index : ");
 
        // Position to be deleted
        scanf("%d", &pos);
        position = malloc(sizeof(struct node));
        temp = start;
 
        // Traverse till position
        while (i < pos - 1) {
            temp = temp->link;
            i++;
        }
 
        // Change Links
        position = temp->link;
        temp->link = position->link;
 
        // Free memory
        free(position);
    }
}

int main(){
 create();
 int ch;
 while(1){
 
   printf("\n\n1.Insert at front");
   printf("\n2.Insert at end");
   printf("\n3.Insert at any position");
   printf("\n4.Delete from front");
   printf("\n5.Delete from end");
   printf("\n6.Delete from any position");
   printf("\n7.Display linked list");
   printf("\n8.Exit");
   printf("\nEnter your choice:");
   scanf("%d",&ch);
   
   switch(ch){
     case 1: insertfront();
         break;
     
     case 2: insertend();
         break;
     
     case 3: insertpos();
          break;
     
     case 4: delfront();
          break;
     
     case 5:delend();
          break;
          
     case 6:delpos();
          break;     
          
     case 7: display();
          break;
               
     case 8:
          exit(1);
          break;
      default:
         printf("Invalid choice\n");         
               
   }
 }
 return 0;
}
 
