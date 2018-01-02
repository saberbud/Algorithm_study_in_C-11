#include <iostream>
#include <cmath>
using namespace std;

struct node
{
  int data;
  node *right,*left;
};

int height(node* root)
{
  if(root==NULL)return 0;

  return (max(height(root->left),height(root->right))+1);
}

void inorder_print(node* root)
{
  if(root==NULL)return;

  int h=height(root);

  inorder_print(root->left);
  cout << root->data << " height= " << h << endl;
  inorder_print(root->right);
}

void create_tree(node* &root,int arr[],int start,int end)
{
  if(start>end)return;

  if(root==NULL){
    node* p=new node;
    int ind=start+(end-start)/2;
    p->data=arr[ind];
    p->left=NULL;
    p->right=NULL;
    root=p;
    create_tree(root->left,arr,start,ind-1);
    create_tree(root->right,arr,ind+1,end);
  }
}

int main()
{
  int arr[]={1,2,3,4,5,6,7,8,9};
  node* root;
  root=NULL;
  create_tree(root,arr,0,8);

  cout << root->left->data << " " << root->data << " " << root->right->data << endl;

  cout << "Height= " << height(root) << endl;

  inorder_print(root);

  return 0;
}













