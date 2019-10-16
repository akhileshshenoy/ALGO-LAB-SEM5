#include<stdio.h>
#include<stdlib.h>

struct node
{
	int val;
	struct node *llink,*rlink;	
};

typedef struct node *NODE; //node Pointer typedef 
NODE head = NULL;

void CreateList(){
	NODE nd;int val;
	if (head == NULL){
		printf("Enter val:");
		scanf("%d",&val);
		nd = (NODE)malloc(sizeof(struct node));
		nd->llink=nd->rlink=NULL;
		nd->val=val;
		head=nd;
	}
	else
		printf("List is already created.\n");
}

void insertIntoList(int before,int val){
	NODE newnd;
	NODE nd=head;
	while (nd->val != before){
		nd=nd->rlink;
	}
	if (nd!=NULL){
		newnd=(NODE)malloc(sizeof(struct node));
		newnd->val=val;		
		newnd->llink=newnd->rlink=NULL;
		if (nd->llink!=NULL)
		{
			nd->llink->rlink=newnd;
			newnd->llink=nd->llink;
			newnd->rlink=nd;
			nd->llink=newnd;
		}
		else{
			nd->llink=newnd;
			newnd->rlink=nd;
			head=newnd;
		}}
	else
		printf("Unable to insert, node with value %d not found.\n",val);	
}

void deleteAll(int delVal){
	NODE nd=head;
	while (nd!=NULL){
		if (nd->val==delVal){
			if(nd->llink!=NULL){
				nd->llink->rlink=nd->rlink;
				if (nd->rlink!=NULL){
					nd->rlink->llink=nd->llink;
					nd=nd->rlink;		
				}
				else
				{
					nd->llink->rlink=NULL;
					nd=NULL;
				}
			}
			else{
				if(nd->rlink!=NULL){
					head=nd->rlink;
					nd->rlink->llink=NULL;
					free(nd);
					nd=head;
				}
				else
				{
					free(nd);
					head=nd=NULL;
				}
			}
		}
		else{
			nd=nd->rlink;
		}
	}
}

void displayAll(){
	NODE nd=head;
	printf("list is: ");
	while(nd!=NULL){
		printf("%d ",nd->val);
		nd=nd->rlink;
	}
}

void main(){
	
	int ch,val,bef;
	while (ch!=4){
	printf("Enter 1 or 2 or 3 \n");
	scanf("%d",&ch);

		switch(ch){
		case 1:
		
		CreateList();
		displayAll();
		break;
		case 2:
		printf("Enter val,bf:");
		scanf("%d %d",&val,&bef);
		insertIntoList(bef,val);
		displayAll();
		break;
		case 3:
		printf("Enter val:");
		scanf("%d",&val);
		deleteAll(val);
		displayAll();
		break;
		default:
		printf("Invalid no.");
	}
	}
}

