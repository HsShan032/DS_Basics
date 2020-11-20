
#include <stdio.h>
#include <malloc.h>
struct node{
int data;
struct node *next;
};
struct node *start = NULL;
struct node *create_linkedlist(struct node *);
struct node *display(struct node *);
int main(){
int choice;
do{
printf("\n1. Create a list");
printf("\n2. Display the list");
printf("\n3. Exit the list");
printf("\n\nEnter your choice : ");
scanf("%d",&choice);
switch(choice){
case 1:
start = create_linkedlist(start);
printf("\n Linked List Created Successfully");
break;
case 2:
start = display(start);
break;
}
}while(choice != 3);
return 0;
}
struct node *create_linkedlist(struct node *start)
{
struct node *new_node, *ptr;
int num;
printf("\n Enter -1 to end");
printf("\n Enter the data : ");
scanf("%d",&num);
while(num != -1){
new_node = (struct node*)malloc(sizeof(struct node));
new_node -> data = num;
if(start == NULL)
{
new_node -> next = NULL;
start = new_node;
}
else{
ptr = start;
while(ptr -> next != NULL)
ptr = ptr -> next;
ptr -> next = new_node;
new_node -> next = NULL;
}
printf("\n Enter the data : ");
scanf("%d",&num);
}
return start;
}
struct node *display(struct node *start){
struct node *ptr;
ptr = start;
while(ptr != NULL)
{
printf("\t %d", ptr -> data);
ptr = ptr -> next;
}
return 0;
}
