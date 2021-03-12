#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct node {
  struct node *left,*right;
  char word[10];
}*Root=NULL;

typedef struct node Node;
char arr;
int check(char[],char[]);
void insert(Node *);
void Search();
void view(Node *);
int storeinorder(Node*node);
char balanceBST(char arr[10][10],int start,int end);
int check(char a[],char b[]){
     int i,j,c;
     for(i=0,j=0 ; a[i]!='\0'&&b[j]!='\0' ; i++,j++){
       if(a[i]>b[j]){
         c=1;
         break;
       }
        else if(b[j]>a[i]){
          c=-1;
          break;
        }
      else
         c=0;
     }
     if(c==1)
       return 1;
      else if(c==-1)
        return -1;
      else
        return 0;
}


void insert(Node*temp){
  int flag=0;
  Node *ptr,*par;
  ptr=Root;

  if(Root==NULL)
     Root=temp;
  else{
     while(ptr!=NULL ){
       if(check(temp->word,ptr->word)>0){
         par=ptr;
         ptr=ptr->right;
       }

       else if(check(temp->word,ptr->word)<0)
     {
       par=ptr;
       ptr=ptr->left;
     }
       else if(check(temp->word,ptr->word)==0){
          flag=1;
            printf("\nWord exists!!");
          break;
       }

   }
       if(flag==0 && ptr==NULL){

         if(check(par->word,temp->word)==1)
            par->left=temp;
         else if(check(par->word,temp->word)==-1)
            par->right=temp;
       }

     }

}

void view(Node *ptr){
  if(Root==NULL)
    printf("\nEmpty \n");
//	return NULL;
  else if(ptr !=NULL){
   view(ptr->left);

   printf("%css->",ptr->word);
   //printf("\nMeaning:%s->\n",ptr->meaning);

   view(ptr->right);
  }

}
int storeinorder(Node*node)
{
	char arr[10][10];
	int k=0;
	if(node==NULL)
	{
		return 0;
	}
	else
	{
	storeinorder(node->left);
	strcpy(arr[k++],node->word);
	storeinorder(node->right);
}
}

//function to balance the BST
char balanceBST(char arr[10][10],int start,int end1)
{
	int mid;
	if(start>end1)
	{
		return NULL;
	}
	mid=(start+end1)/2;
	strcpy(arr[mid],Root);
	Root->left=balanceBST(arr,start,mid-1);
	Root->right=balanceBST(arr,mid+1,end1);
}

int main() {
  int ch=0;
  Node *temp;
  while(ch!=12){
  	
    
    temp=(Node*)malloc(sizeof(Node));
    temp->left=NULL;
    temp->right=NULL;
    printf("Insert month:\n");
    scanf("%s",temp->word);
    insert(temp);
    ch++;
    }
    view(Root);
    storeinorder(Root);
    printf("\n\n");
    balanceBST(arr,0,11);
    view(Root);
  return 0;
}
