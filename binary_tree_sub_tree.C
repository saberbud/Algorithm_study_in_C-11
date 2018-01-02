#include <iostream>
using namespace std;

struct node
{ 
  int data;
  node *right,*left;
};

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

bool is_identical(node* root1, node* root2)
{
  if(root1==NULL && root2==NULL)return true;
  if(root1==NULL || root2==NULL)return false;

  if(root1->data==root2->data && is_identical(root1->left,root2->left) && is_identical(root1->right,root2->right))return true;

  return false;
}

bool is_sub_tree(node* root, node* subroot)
{
  if(root==NULL && subroot==NULL)return true;
  if(root==NULL || subroot==NULL)return false;
  return (is_identical(root,subroot) || is_sub_tree(root->left,subroot) || is_sub_tree(root->right,subroot));
}

int main()
{
  int arr[]={1,2,3,4,5,6,7,8,9};
  int arr1[]={1,2,3,4};
  node *root,*subroot;
  root=subroot=NULL;
  create_tree(root,arr,0,8);
  create_tree(subroot,arr1,0,3);

  cout << "Is sub tree? " << is_sub_tree(root,subroot) << endl;

  return 0;
}










