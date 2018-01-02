#include <iostream>
#include <cmath>
using namespace std;

struct node
{
  int data;
  node *right, *left;
};

void insert_node(node* &head, int data)
{
  if(head==NULL){
    node* p=new node;
    p->data=data;
    p->left=NULL;
    p->right=NULL;
    head=p;
    return;
  }

  if(data<=head->data){
    if(head->left==NULL){
      node* p=new node;
      p->data=data;
      p->left=NULL;
      p->right=NULL;
      head->left=p;
      return;
    }
    insert_node(head->left,data);
  }else{
    if(head->right==NULL){
      node* p=new node;
      p->data=data;
      p->left=NULL;
      p->right=NULL;
      head->right=p;
      return;
    }
    insert_node(head->right,data);
  }

}

int height(node* root)
{
  if(root==NULL)return 0;

  return (max(height(root->left),height(root->right))+1);
}

bool is_balanced(node* root)
{
  if(root==NULL)return true;

  int diff=height(root->left)-height(root->right);

  if(abs(diff)>1){
    return false;
  }else{
    return true;
  }

}

int main()
{
  node *root;
  root=NULL;

  int arr[]={5,7,3,1,6,8};

  for(unsigned int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
    insert_node(root,arr[i]);    
  }

  cout << "Height= " << height(root) << endl;
  cout << "Is balanced? " << is_balanced(root) << endl;

  cout << root->left->left->data << endl;
  cout << root->right->left->data << endl;

  return 0;
}










