#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
};
struct node*createNode(int value)
{
	struct node*newNode;
	newNode = malloc(sizeof(struct node));
	
	newNode->data = value;
	
	newNode->left =newNode->right = NULL;
	
	return newNode;
}
struct node*insert(struct node* root,int value)
{
	if(root==NULL)
		return createNode(value);
	if(value < root->data)
		root->left=insert(root->left,value);
	else if (value > root->data)
		root->right=insert(root->right,value);
		
	return root;
}
void inorder(struct node* root)
{
	if(root !=NULL)
	{
		inorder(root->left);
		printf("%d ",root->data);
		inorder(root->right);
	}
}
void preorder(struct node*root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node*root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ",root->data);
	}
}
int main()
{
	struct node* root=NULL;
	int choice,value;
	while(1)
	{
		printf("\n-----MENU-----\n")	;
		printf("1:Insert\n");
		printf("2:InOrder Traveral\n");
		printf("3:PreOrder Traveral\n");
		printf("4:PostOrder Traveral\n");
		printf("5:Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter value: ");
				scanf("%d",&value);
				root = insert(root,value);
				break;
			case 2:
				inorder(root);
				printf("\n");
				break;
			case 3:
				preorder(root);
				printf("\n");
				break;
			case 4:
				postorder(root);
				printf("\n");
				break;
			case 5:
				exit(0);
		}
		
	}
}
