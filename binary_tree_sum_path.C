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

void print(node *root, int sum, int *path, int level)
{
  if(root==NULL)return;

  path[level]=root->data;
  int s=0;
  for(int i=level;i>=0;i--){
    s+=path[i];
    if(s==sum){
      for(int j=level;j>=i;j--){
        // cout << path[j] << " ";
        cout << path[j] << "(" << level << "," << i << "," << j << ") ";
      }
      cout << endl;
    }
  }

  if(root->left)print(root->left,sum,path,level+1);
  if(root->right)print(root->right,sum,path,level+1);
}

int main()
{
  int arr[]={1,2,3,4,5,6,7,8,9};
  node* root;
  root=NULL;
  create_tree(root,arr,0,8);

  int path[100];
  print(root,7,path,0);

  return 0;
}










