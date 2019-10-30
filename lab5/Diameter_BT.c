#include <stdio.h> 
#include <stdlib.h> 
#define max(a,b) (a>b?a:b) 

struct Node
{ 
	int data; 
	struct Node* left;
	struct Node* right; 
}; 

typedef struct Node* Nodeptr;

int height(Nodeptr root) 
{ 
	if(root == NULL) 
		return 0; 
	return (1 + max(height(root->left), height(root->right))); 
} 

Nodeptr newNode(int data) 
{ 
	Nodeptr temp = (Nodeptr)malloc(sizeof(struct Node)); 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return(temp); 
} 

int diameter(Nodeptr tree) 
{ 
	if (tree == NULL) 
		return 0; 

	int lh = height(tree->left); 
	int rh = height(tree->right); 

	int ld = diameter(tree->left); 
	int rd = diameter(tree->right); 

	return max(lh + rh + 1, max(ld, rd)); 
} 


int main() 
{ 
	/* Constructed binary tree is  
				1 
			  /   \ 	
			2      3 
		  /  \ 
		4     5 
	*/
	Nodeptr root = newNode(1); 
	root->left	 = newNode(2); 
	root->right	 = newNode(3); 
	root->left->left = newNode(4); 
	root->left->right = newNode(5); 

	printf("Diameter is %d.\n", diameter(root)); 
	return 0; 
} 
