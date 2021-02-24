#include <stdio.h>
#include <stdlib.h>
#include <string.h>

  struct node
  {
        int data;
        struct node *next;
  };

  struct node *top = NULL;

  
  struct node* createNode (int data)
   {
        struct node *ptr = (struct node *) malloc(sizeof (struct node));
        ptr->data = data;
        ptr->next = NULL;
  }
 
 void push(int data) 
 {
        struct node *temp, *ptr = createNode(data);
        if (top == NULL) {
                top = ptr;
                return;
        }
        temp = top;
        ptr->next = temp;
        top = ptr;
  }

  
  int pop()
   {
        int data;
        struct node *temp;
        if (top == NULL)
                return -1;
        data = top->data;
        temp = top;
        top = temp->next;
        free (temp);
        return (data);
  }

  int main() {
        char str[100];
        int i, flag = 0, data = 0;
        printf("Enter ur expression:");
        fgets(str, 100, stdin);
        for (i = 0; i < strlen(str); i++)
		 {            
                if (str[i] == '(' || str[i] == '{'|| str[i] == '[')
				 {
                                push(str[i]);
                                continue;
                }
                if (str[i] == ')' || str[i] == '}' || str[i] == ']')
				 {
                        data = pop();
                        if ((str[i] == ')' && data != '(') || data == -1 ||(str[i] == '}' && data != '{') || (str[i] == ']' && data != '[')) {
                                flag = 1;
                                break;
                        }
                }
        }

        if (flag == 1 || top != NULL)
                printf("Not a balanced expression\n");
        else
                printf("Balanced Expression\n");
        return 0;
  }

