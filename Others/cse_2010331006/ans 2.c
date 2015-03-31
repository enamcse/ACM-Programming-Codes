#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}node;

int main()
{
    node *start,*ptr,*temp;
   temp=(node*)malloc(sizeof(node));
    printf("enter an integer :\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
    start=temp;

    while(temp->data!=0)
    {
    temp=(node*)malloc(sizeof(node));
    printf("enter an integer :\n");
    scanf("%d",&temp->data);
    temp->link=start;
    start=temp;
    }
    ptr=start;

    while(ptr->link!=0)
    {
        printf("%d ",ptr->link->data);
        ptr=ptr->link;
    }
}
