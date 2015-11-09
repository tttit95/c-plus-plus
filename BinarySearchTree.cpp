#include<iostream>
#include<conio.h>
#include<stdio.h>
using namespace std;
struct TreeNode
{
	int info;
	TreeNode *left;
	TreeNode *right;
};
TreeNode *F = NULL;
TreeNode *MakeNode(int x)
{
	TreeNode *q = new TreeNode;
	q->left = NULL;
	q->right = NULL;
	q->info = x;
	return q;
}
TreeNode *Insert(TreeNode **root,TreeNode *q)
{
        	if(*root == NULL)
        	{
                *root = q;
				if(F == NULL)
				    F = *root;
        	}
            else if(*root != NULL){
				if((*root)->info > q->info){
                    Insert(&((*root)->left),q);
				}
				else if((*root)->info < q->info){
                    Insert(&((*root)->right),q);
				}
				   	
			}
			return F;
}
void PrintTree(TreeNode *root)
{
	if(root != NULL)
	{
		
		PrintTree(root->left);
		cout<<root->info<<endl;
		PrintTree(root->right);
		
	}

}
int main()
{
	TreeNode *root = NULL,*q;
	int x;
	cin>>x;
	while(x != 0)
	{
        q = MakeNode(x);
        F = Insert(&F,q);
        cin>>x;
	}
	PrintTree(F);
	getch();
}
