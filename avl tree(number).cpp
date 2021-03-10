#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*left;
	struct node*right;
	int height;
};
struct node*new_node(int val);
int max(int a,int b);
int height(struct node*r);
int getbalance(struct node*r);
struct node*rightrotate(struct node*r);
struct node*leftrotate(struct node*r);
struct node*insert(struct node*r,int val);
int preorder(struct node*r);

struct node*new_node(int val)
{
	struct node*temp=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->left=NULL;
	temp->right=NULL;
	temp->height=1;
	return temp;
}
int max(int a,int b)
{
	return((a>b)?a:b);
}
int height(struct node*r)
{
	if(r==NULL)
	{
		return 0;
	}
	else
	{
		return r->height;
	}
}
int getbalance(struct node*r)
{
	if(r==NULL)
	{
		return 0;
	}
	else
	{
		return (height(r->left)-height(r->right));
	}
}
struct node*leftrotate(struct node*r)
{
	struct node*h=r->right;
	struct node*s=r->left;
	h->right=r;
	r->left=s;
	h->height=1+max(height(h->left),height(h->right));
	r->height=1+max(height(s->left),height(s->right));
	return h;
}
struct node*rightrotate(struct node*r)
{
	struct node*h=r->left;
	struct node*s=r->right;
	h->left=r;
	r->right=s;
	h->height=1+max(height(h->left),height(h->right));
	r->height=1+max(height(s->left),height(s->right));
	return h;
}
struct node*insert(struct node*r,int val)
{
	if(r==NULL)
	{
		return new_node(val);
	}
	else if(val<r->data)
	{
		r->left=insert(r->left,val);
	}
	else if(val>r->data)
	{
		r->right=insert(r->right,val);
	}
	else
	{
		return r;
	}
	r->height=1+max(height(r->left),height(r->right));
	int balance=getbalance(r);
	//left-left
	if(balance>1 && val<r->left->data)
	{
		return rightrotate(r);
	}
	if(balance>1 && val>r->left->data)
	{
		r->left=leftrotate(r->left);
		return rightrotate(r);
	}
	if(balance<-1 && val>r->left->data)
	{
		return leftrotate(r);
	}
	if(balance<-1 && val<r->left->data)
	{
		r->right=rightrotate(r->right);
		return leftrotate(r);
	}
}
int preorder(struct node*r)
{
	if(r==0)
	{
		return 0;
	}
	else
	{
		printf("%d->",r->data);
		preorder(r->left);
		preorder(r->right);
	}
}

int main(int argc, char *argv[])
{
	struct node*root=NULL;
	int val,k=0;
	while(k<6)
	{
		printf("enter data:");
		scanf("%d",&val);
		root=insert(root,val);
		k++;
		//printf("enter 1 to continue:");
		//scanf("%d",&k);
		//continue;
	}
	//printf("\n\n");
	printf("preorder:\n");
	preorder(root);
	return 0;
	
}
