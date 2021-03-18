#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* prev;
    struct node* nxt;
}*head,*fnode,*temp1,*temp2;

void house_assets(int n)
{
    printf("\nHouse 1's asset value:");
    head=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&head->data);
    head->prev=NULL;
    head->nxt=NULL;
    temp1=head;
    int i;
    for(i=1;i<n;i++)
    {
        fnode=(struct node*)malloc(sizeof(struct node));
        printf("\nHouse %d's asset value>>>",i+1);
        scanf("%d",&fnode->data);
        fnode->prev=temp1;
        fnode->nxt=NULL;
        temp1->nxt=fnode;
        temp1=fnode;
    }
}

void rob_max(int n)
{
    temp1=head;
    int house[n],i;
    for(i=0;i<n;i++)
    {
        house[i]=temp1->data;
        temp1=temp1->nxt;
    }
    temp1=head;
    temp2=temp1->nxt;
    house[0]=temp1->data;
    if(temp1->data>temp2->data)
        house[1]=temp1->data;
    else
        house[1]=temp2->data;
    for(i=2;i<n;i++)
    {
        if(house[i-2]+house[i]>house[i-1])
            house[i]=house[i-2]+house[i];
        else
            house[i]=house[i-1];
    }
    printf("\nMaximum assets that can be robbed: %d\n",house[n-1]);
}

int main()
{
	int n;
    printf("Enter the no of houses>>>");
    scanf("%d",&n);
    house_assets(n);
    temp1=head;
    rob_max(n);
}

