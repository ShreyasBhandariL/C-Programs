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
    NODE x;
    x=(NODE)malloc(sizeof(NODE));
    return x;
}
NODE insert_rear(NODE first,int item)
{
    NODE temp;
    NODE cur;
    temp=getnode();
   temp->info=item;
   if(first==NULL)
   {
    temp->link=NULL;
    first=temp;
return first;
   }
   else{
    cur=first;
    while(cur->link!=NULL)
    {
        cur=cur->link;
    }
    temp->link=NULL;
    cur->link=temp;
    return first;
   }

   
   
}
NODE delete_front(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("The Stack Is empty");
    }
    else{
        temp = first;
        temp =temp->link;
        printf("The deelted element is %d",first->info);
        free(first);
        first=temp;
        return first;
    }
}
void display(NODE first)
{
    if(first==NULL)
    {
        printf("The Stack Is empty");
    }
    
        NODE cur;
        cur=first;
        while(cur!=NULL)
        {
            printf("%d\n",cur->info);
            cur=cur->link;
        }
    } 

void main()
{
    int ch;
    NODE first;
    first=NULL;
    int item;
 
    while(1)
    {
        printf("\n1.Insert rear 2.Delete the element from front 3.Display the element in the list 4.Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the item to insert in node \n");
            scanf("%d",&item);
            first=insert_rear(first,item);
            break;
            case 2:first=delete_front(first);
            break;
            case 3:display(first);
            break;
            case 4:exit(0);
            default:printf("Invalid choice\n");
            break;
        }
    }
}
