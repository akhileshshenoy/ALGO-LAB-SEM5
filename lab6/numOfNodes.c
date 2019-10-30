#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node *left,*right;
};

typedef struct node* NODE;

NODE insert(NODE root,int val)
{
	if(!root)
	{	
		NODE newnode = (NODE)malloc(sizeof(struct node));
		root = newnode;
		root->val = val;
		root->left=root->right=NULL;
	}
	else if(val<root->val)
	{
		root->left = insert(root->left,val);
	}
	else
	{
		root->right = insert(root->right,val);
	}
	return root;
}

int totnodes(NODE root)
{
	if(!root)
		return 0;
	int tot = totnodes(root->left) + totnodes(root->right) + 1;
	return tot; 
}

void post(NODE root)
{
	if(!root)
		return;
	post(root->left);
	post(root->right);
	printf("%d ",root->val);
}

void main()
{
	int ch,val,flag=1;
	//NODE root = (NODE)malloc(struct node);
	NODE root = NULL;

	while(flag)
	{
		printf("\nEnter 1)To add a node to the binary tree \n2) To check the number of nodes \n3)To print \n4)To exit\n");
		scanf("%d",&ch);

		switch(ch)
		{
			case 1:
				printf("Enter the value of the node : ");
				scanf("%d",&val);
				root = insert(root,val);
				break;
			case 2:
				printf("Number of nodes = %d\n",totnodes(root));
				break;
			case 3:
				printf("Tree = ");
				post(root);
				printf("\n");
				break;
			case 4:	
				printf("Ending program...");
				flag=0;
				break;
			default:
				printf("Invalid Choice!");
		}
	}
}
