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
    int *x;
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
NODE delete_front(NODE first)
{
    NODE temp;
    if(first==NULL)
    {
        printf("The Stack Is empty\n");
    }
    else{
        temp = first;
        temp =temp->link;
        printf("The deleted element is %d",first->info);
        free(first);
        first=temp;
        return first;
    }
}
NODE display(NODE first)
{
    if(first==NULL)
    {
        printf("The Stack Is empty\n");
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
    int ch;
    NODE first;
    first=NULL;
    int item;
 
    while(1)
    {
        printf("\n1.Insert front 2.Delete front 3.Display 4.Exit\n");
        printf("Enter the choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the item to insert in node \n");
            scanf("%d",&item);
            first=insert_front(first,item);
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