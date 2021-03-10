#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *left,*right;
};

int stack[0],i=0;

struct node* create();
int preorder(struct node* root);
int push(int data);

int main()
{
    struct node *root;
    root=0;
    root=create();
    printf("INORDER TRAVERSE\n");
    preorder(root);
    printf("Null\t");
    int i,count=0;
    for(i=0;i<0;i++)
    {
    	if(stack[i]==1)
    	{
    		count++;
		}
	}
	printf("Number of boys in the class are =%d",count);
}
int push(int x)
{
	stack[i++]=x;
	return x;
}
int preorder(struct node* root)
{
	if(root==0)
	{
		return 0;
	}
	else{
		printf("%d-->",push(root->data));
		preorder(root->left);
		preorder(root->right);
	}
}
struct node* create()
{
    int x;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter 99 for T\n 101,102,103...for P\n 0 for Boy \n 1 for Girl \n -1 for Null\n =");
    scanf("%d",&x);
    if(x==-1)
    {
        return 0;
    }
    else
    {
        newnode->data=x;
        printf("Enter the left child of %d\n",x);
        newnode->left=create();
        printf("Enter the right child of %d\n",x);
        newnode->right=create();
        return newnode;
    }
}

