#include <stdio.h>
#include <malloc.h>
struct node
{
struct node *prev;
int data;
struct node *next;
};
struct node *start = NULL;
struct node *create_doublylinkedlist(struct node *);
struct node *display(struct node *);
int main()
{
int choice;
do{
printf("\n1. Create a list");
printf("\n2. Display the list");
printf("\n3. Exit the list");
printf("\n Enter your choice : ");
scanf("%d",&choice);
switch(choice)
{
case 1:
start = create_doublylinkedlist(start);
printf("\n Linked List Created Successfully");
break;
case 2:
start = display(start);
break;
}
}while(choice != 3);
return 0;
}
struct node *create_doublylinkedlist(struct node *start)
{
struct node *new_node, *ptr;
int num;
printf("\n Enter -1 to end");
printf("\n Enter the data : ");
scanf("%d",&num);
while(num != -1)
{
new_node = (struct node*)malloc(sizeof(struct node));
new_node -> data = num;
if(start == NULL)
{
start = new_node;
new_node -> next = NULL;
new_node -> prev = NULL;
}
else
{
ptr = start;
while(ptr -> next != NULL)
ptr = ptr ->next;
ptr -> next = new_node;
new_node -> prev = ptr;
new_node -> next = NULL;
}
printf("\n Enter the data: ");
scanf("%d",&num);
}
return start;
}
struct node *display(struct node *start)
{
struct node *ptr;
ptr = start;
while(ptr != NULL)
{
printf("\t %d", ptr -> data);
ptr = ptr -> next;
}
return start;
}
struct node *insert_beg(struct node *start)
{
struct node *new_node;
int num;
printf("\n Enter the data : ");
scanf("%d",&num);
new_node = (struct node *)malloc(sizeof(struct node));
new_node -> data = num;
start -> prev = new_node;
new_node -> next = start;
start -> prev = NULL;
start = new_node;
return start;
}
struct node *insert_end(struct node *start)
{
struct node *ptr, *new_node;
int num;
printf("\n Enter the data : ");
scanf("%d",&num);
new_node = (struct node *)malloc(sizeof(struct node));
new_node -> data = num;
ptr = start;
while(ptr -> next != NULL)
ptr = ptr -> next;
ptr -> next = new_node;
new_node -> prev = ptr;
new_node -> next = NULL;
return start;
}
struct node *insert_before(struct node *start)
{
struct node *new_node, *ptr;
int num, val;
printf("\n Enter the data : ");
scanf("%d",&num);
printf("\n Enter the value before which the data has to be inserted");
scanf("%d",&val);
new_node = (struct node *)malloc(sizeof(struct node));
new_node -> data = num;
ptr = start;
while(ptr -> data != val);
ptr = ptr -> next;
new_node -> next = ptr;
new_node -> prev = ptr -> prev;
ptr -> prev -> next = new_node;
ptr -> prev = new_node;
return start;
}
struct node *insert_after(struct node *start)
{
struct node *new_node, *ptr;
int num, val;
printf("\n Enter the data : ");
scanf("%d",&num);
printf("\n Enter the value after which the data has to be inserted : ");
scanf("%d",&val);
new_node = (struct node *)malloc(sizeof(struct node));
new_node -> data = num;
ptr = start;
while(ptr -> data != val)
ptr = ptr -> next;
new_node -> prev = ptr;
new_node -> next = ptr -> next;
ptr -> next -> prev = new_node;
ptr -> next = new_node;
return start;
}
struct node *delete_beg(struct node *start)
{
struct node *ptr;
ptr = start;
start = start -> next;
start -> prev = NULL;
free(ptr);
return start;
}
struct node *delete_end(struct node *start)
{
struct node *ptr;
ptr = start;
while(ptr -> next != NULL)
ptr = ptr -> next;
ptr -> prev -> next = NULL;
free(ptr);
return start;
}
struct node *delete_after(struct node *start)
{
struct node *ptr, *temp;
int val;
printf("\n Enter the value after which the node has to deleted : ");
scanf("%d",&val);
ptr = start;
while(ptr -> data != val)
ptr = ptr -> next;
temp = ptr -> next;
ptr -> next = temp -> next;
temp -> next -> prev = ptr;
free(temp);
return start;
}
struct node *delete_before(struct node *start)
{
struct node *ptr, *temp;
int val;
printf("\n Enter the value after which the node has to deleted : ");
scanf("%d",&val);
ptr = start;
while(ptr -> data != val)
ptr = ptr -> next;
temp = ptr -> prev;
if(temp == start)
start = delete_beg(start);
else {
ptr -> prev = temp -> prev;
temp -> prev -> next = ptr;
}
free(temp);
return start;
}
struct node *delete_list(struct node *start) {
while(start != NULL)
start = delete_end(start);
free(start);
return start;
}
