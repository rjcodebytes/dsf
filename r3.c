#include<stdio.h>
#include<stdlib.h>

struct node{
 int data;
 struct node *next;
};
struct node *front;
struct node *rear;

void enqueue(int data){
 struct node *newNode;
 newNode = (struct node*)malloc(sizeof(struct node));
 newNode -> data = data;
 newNode -> next = NULL;
 if(rear == NULL){
   front = rear = newNode;
 } 
 else{
   rear -> next = newNode;
   rear = newNode;
 }
}

void dequeue(){
  if(front == NULL && rear == NULL){
     printf("Queue is empty\n");}
    else{
     printf("Dequeued element is %d",front->data);
     struct node *temp;
     temp = front;
     front = front -> next;
     free(temp);
    } 
  }

void peek(){
 if(front == NULL && rear == NULL){
   printf("Queue is empty\n");
 }
 
 else{
  printf("Front of queue: %d",front -> data);
  printf("\nRear of queue: %d",rear -> data);
 }
}


void display(){
 if(front == NULL && rear == NULL ){
   printf("Queue is empty\n");
 }
 
 else{
  struct node *temp;
  temp = front;
  printf("Queue: ");
  while(temp != NULL){
    printf("%d ",temp -> data);
    temp = temp -> next;
  }
 }
}

int main(){
 int ch,data;
 while(1){
   printf("\n\n1.Enqueue");
   printf("\n2.Dequeue");
   printf("\n3.DisplayQueue");
   printf("\n4.Peek");
   printf("\n5.Exit");
   printf("\nEnter your choice:");
   scanf("%d",&ch);
   
   switch(ch){
     case 1:printf("Enter data:");
        scanf("%d",&data);
        enqueue(data);
        break;
     
     case 2:
        dequeue();
        break;
     
     case 3:
        display();
        break;
     
     case 4: peek();
       break;
     
     case 5:
       exit(1);
        
     default:
        printf("Invalid choice\n");   
   }
 }
 return 0;
}
