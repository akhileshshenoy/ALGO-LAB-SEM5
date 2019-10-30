#include<stdio.h>
#include<stdlib.h>
typedef struct tree* TP;
typedef struct tree
{
        int key;
        TP lc,rc;
}tree;

TP search(TP* root,int d)
{
        TP temp=NULL;
        TP temp2=*root;
        while(temp2!=NULL)
        {
                temp=temp2;
                if(d==temp2->key)
                        return NULL;
                else if(d>temp2->key)
                        temp2=temp2->rc;
                else
                        temp2=temp2->lc;
        }

        return temp;
}

void create(TP* root,int d)
{

        TP temp=search(root,d);
        if(temp||!(*root))
        {
            TP node=(TP)malloc(sizeof(tree));
                node->key=d;
                node->lc=NULL; node->rc=NULL;
                if(*root)
                {
                        if(temp->key > d)
                                temp->lc=node;
                        else
                                temp->rc=node;
                }
                else
                    *root=node;
        }
        else
                printf("Key Found");
}
void inorder(TP root)
{
        if(root==NULL)
            return;
        inorder(root->lc);
        printf("%d",root->key);
        inorder(root->rc);
}

void preorder(TP root)
{
    if(root==NULL)
            return;
        printf("%d",root->key);
        preorder(root->lc);
        preorder(root->rc);
}
void postorder(TP root)
{
    if(root==NULL)
            return;
       postorder(root->lc);
        postorder(root->rc);
        printf("%d",root->key);

}
int main()
{
        TP root=NULL;
        for(;;)
        {
                printf("Enter 1 to insert,2 for in,3 for pre,4 for post,5 for exit");
                int n;
                scanf("%d",&n);
                switch(n)
                {
                        case 1:
                                printf("Enter data:");
                                int x;
                                scanf("%d",&x);
                                create(&root,x);
                                break;
                        case 2:
                                inorder(root);
                                break;
                        case 3:
                                preorder(root);
                                break;
                        case 4:
                                postorder(root);
                                break;
                }
                if(n==5)
                    break;
        }
}
