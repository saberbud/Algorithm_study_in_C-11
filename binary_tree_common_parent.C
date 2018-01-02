#include <iostream>
using namespace std;

struct node
{
  int data;
  node *right, *left;
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

bool isDecendent(node *root, node *root1)
{
  if(root==NULL)return false;
  if(root==root1)return true;

  return (isDecendent(root->left,root1) || isDecendent(root->right,root1));
}

node* common_ancestor(node *root, node *root1, node *root2)
{
  if(root==NULL)return NULL;
  if(root==root1 || root==root2)return root;

  bool root1_on_left=isDecendent(root->left,root1);
  bool root2_on_left=isDecendent(root->left,root2);

  if(root1_on_left && root2_on_left){
    return common_ancestor(root->left,root1,root2);
  }else if(root1_on_left || root2_on_left){
    return root;
  }else{
    return common_ancestor(root->right,root1,root2);
  }

}

int main()
{
  int arr[]={1,2,3,4,5,6,7,8,9};
  node* root;
  root=NULL;
  create_tree(root,arr,0,8);

  node *anc=common_ancestor(root,root->left->left,root->left->right->right);

  cout << "Common ancestor: " << anc->data << endl;

  return 0;
}














