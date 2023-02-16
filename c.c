#include<stdio.h>
#include<stdlib.h>
struct node
{
int info;
struct node *link;
};
typedef struct node *NODE;
NODE getnode()
{
NODE *x;
x=(NODE)malloc(sizeof(NODE));
return x;
}
NODE insert_front(NODE first,int item)
{
NODE temp;
temp=getnode();
temp->info=item;
temp->link=first;
return temp;
}
NODE delete(NODE first,int key)
{
NODE cur;
NODE prev;
cur=first;
if(first==NULL)
{
printf("The List is Empty\n");
return first;
}
else if(first->info==key)
{
first=first->link;
printf("The Deleted item is %d\n",cur->info);
free(cur);
return first;
}
else
{
prev=NULL;
while(cur!=NULL)
{
if(key==cur->info)
{
printf("The Deleted item is %d\n",cur->info);
prev->link=cur->link;
free(cur);
}
prev=cur;
cur=cur->link;
}
if(cur==NULL)
{
printf("The given element is not there\n");
return first;
}
}
}
void display(NODE first)
{
if(first==NULL)
{
printf("The List is empty\n");
}
else
{
NODE cur;
cur=first;
while(cur!=NULL)
{
printf("%d\n",cur->info);
cur=cur->link;
}
}
}
void main()
{
int ch, item;
NODE first;
first=NULL;
while(1)
{
printf("\n1.Insert Element\n 2. Deleted specified number\n 3.Display the contents in the list\n \n");
printf("Enter the choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1:printf("Enter the item\n");
scanf("%d",&item);
first=insert_front(first,item);
break;
case 2:printf("Enter the key element to delete\n");
scanf("%d",&item);
first=delete(first,item);
break;
case 3:display(first);
break;
default:exit(0);
}
}
}
