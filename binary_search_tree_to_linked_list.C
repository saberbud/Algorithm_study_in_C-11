#include <iostream>
#include <cmath>
#include <vector>
#include <list>
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

void findLevelLinkedLists(vector<list<node*> > &res, node* root){
    list<node*> li;
    li.push_back(root);
    res.push_back(li);
    int depth = 0;
    while(!res[depth].empty()){
        list<node*> l;
        list<node*>::iterator iter;
        for(iter = res[depth].begin(); iter!=res[depth].end(); iter++ ){
            node *ptr = *iter;
            if(ptr->left)
                l.push_back(ptr->left);
            if(ptr->right)
                l.push_back(ptr->right);
        }
        res.push_back(l);
        depth++;
    }
}

void printLevelLinkedLists(vector<list<node*> > res){
    vector<list<node*> >::iterator iter;
    for(iter = res.begin(); iter!= res.end(); iter++){
        list<node*> li = *iter;
        list<node*>::iterator it;
        for(it = li.begin(); it!=li.end(); it++){
            node* ptr = *it;
            cout<<ptr->data<<" ";
        }
        cout<<'\n';
    }
}

void print_right(node *root)
{
  while(root){
    cout << root->data << " ";
    root=root->right;
  }
}

node* get_tail(node *root)
{
  if(root==NULL)return NULL;
  while(root->right){
    root=root->right;
  }

  return root;
}

void concat(node *x, node *y)
{
  x->right=y;
  y->left=x;
}

node* convert(node *root)
{
  if(root==NULL)return NULL;

  node* nl=convert(root->left);
  node* nr=convert(root->right);

  if(nl!=NULL){
    concat(get_tail(nl),root);    
  }

  if(nr!=NULL){
    concat(root,nr);
  }

  if(nl==NULL)return root;
  return nl;
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

  cout << endl;
  cout << "find and print level" << endl;
  vector<list<node*>> res;
  findLevelLinkedLists(res,root);
  printLevelLinkedLists(res);

  cout << endl;
  cout << "Print right" << endl;
  print_right(root);
  cout << endl;
  print_right(root);
  cout << endl;

  node* nx=get_tail(root);
  cout << "nx" << endl;
  cout << nx->data << endl;
  if(nx==NULL)cout << "nx is NULL" << endl;
  cout << root->data << endl;

  cout << endl;
  cout << "convert" << endl;
  node* nc=convert(root);
  print_right(nc);
  cout << endl;

  return 0;
}













