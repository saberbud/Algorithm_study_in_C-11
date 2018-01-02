#include <iostream>
#include <climits>
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

bool isBst(node* root, int lower, int upper)
{
  if(root==NULL) return true;

  if(root->data<=upper && root->data>=lower){
    return (isBst(root->left,lower,root->data) && isBst(root->right,root->data+1,upper));
  }else{
    return false;
  }

}

int main(){
  // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int arr[] = {2, 1, 3, 4, 5, 6, 7, 8, 9};

  node* root;
  root=NULL;
  create_tree(root,arr,0,8);

  cout << "Is tree BST? " << isBst(root,INT_MIN,INT_MAX) << endl;

  return 0;
}











