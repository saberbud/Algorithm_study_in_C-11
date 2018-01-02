#include <iostream>
using namespace std;

struct node
{
  int data;
  node* left;
  node* right;
  int leftsize;
};

void track(int k, node* &root){
  if(root==NULL){
    root=new node;
    root->data=k;
    root->left=NULL;
    root->right=NULL;
    root->leftsize=0;
  }else{
    if((root->data) > k){
      root->leftsize++;
      track(k,root->left);
    }else{
      track(k,root->right);
    }
  }
}

int get_rank(int x, node* root)
{
  int data=root->data;
  if(data==x){
    cout << "Found: " << data << " , leftsize= " << root->leftsize << endl;
    return root->leftsize;
  }

  if(data>x){
    return get_rank(x,root->left);
  }else{
    return (root->leftsize+1+get_rank(x,root->right));
  }

  return -1;
}

int main()
{
  node *root=NULL;
  int arr[]={12, 15, 12, 11, 10, 10, 11, 13};
  for(int i=0;i<8;i++){
    track(arr[i],root);
  }

  cout << get_rank(15,root) << endl;

  return 0;
}










