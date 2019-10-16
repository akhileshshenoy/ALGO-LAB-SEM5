#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node* lchild;
	struct node* rchild;
};

typedef struct node* NODE;

NODE insertNode(NODE root,int val)
{
	if(root == NULL)
	{
		root = (NODE)malloc(sizeof(struct node));
		root->val = val;
		root->lchild = NULL;
		root->rchild = NULL;
		printf("Inserted %d\n",val);
	}
	else if(val == root->val)
	{
		printf("Duplicate value!!");
		return root;
	}
	else if(val<root->val)
	{
		root->lchild = insertNode(root->lchild,val);
	}
	else
		root->rchild = insertNode(root->rchild,val);
	return root;
}

void printNodes(NODE root)
{
	if(root == NULL)
		return;
	printNodes(root->lchild);
	printf("%d ",root->val);
	printNodes(root->rchild);
}

int heightOfTree(NODE root)
{
	if(root==NULL)
		return 0;
	return heightOfTree(root->lchild) + heightOfTree(root->rchild) + 1; 
}

void balFactor(NODE root)
{
	if(root == NULL)
		return;
	balFactor(root->lchild);
	int n = heightOfTree(root->lchild)-heightOfTree(root->rchild);
	printf("Balance factor of node with val = %d is %d\n",root->val,n);
	balFactor(root->rchild);
}

void main()
{
	NODE root = NULL;
	int ch,val,flag=1;
	while(flag)
	{
		printf("Enter 1) Add a node\n2) Print the tree\n3) Print number of nodes\n4) Exit :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the value of the node :");
				scanf("%d",&val);
				root = insertNode(root,val);
				break;
			case 2:
				printf("Inorder : ");
				printNodes(root);
				printf("\n");
				break;
			case 3:
				balFactor(root);
				break;
			case 4:
				flag = 0;
			default:
				printf("Invalid Choice!!\n");
		}
	}
} 