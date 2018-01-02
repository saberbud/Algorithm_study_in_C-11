#include <iostream>
#include <stack>
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

node* in_order_successor(node* root, int k)
{
  node *ptr=root;
  stack<node*> S;
  bool searched=false;

  while(true){
    while(ptr){
      S.push(ptr);
      ptr=ptr->left;
    }

    // if(S.empty())break;

    if(S.empty()){
      cout << "empty S." << endl;
      break;
    }

    ptr=S.top();
    S.pop();

    cout << ptr->data << " , S size= " << S.size() << endl;

    if(searched)return ptr;
    if(ptr->data==k){
      cout << "Found" << endl;
      searched=true;
    }
    ptr=ptr->right;
  }

  return ptr;
}

int main()
{
  int arr[]={1,2,3,4,5,6,7,8,9};
  node* root;
  root=NULL;
  create_tree(root,arr,0,8);

  node *sd=in_order_successor(root,6);

  cout << "successor= " << sd->data << endl;

  return 0;
}










