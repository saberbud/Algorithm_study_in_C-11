#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct node
{
  int data;
};

void fn(node* a)
{
  cout << "fn" << endl;

  node *p=new node;
  p->data=10;
  a=p;

  cout << "fn end." << endl;
}

void fn1(node* &a)
{
  cout << "fn1" << endl;

  node *p=new node;
  p->data=10;
  a=p;

  // a->data=10;
  cout << "fn1 end." << endl;
}

void funp(int *p)
{
  int *a;
  int b=10;
  a=&b;
  p=a;
  cout << "In funp p= " << (*p) << endl;
}

void funp1(int* &p)
{
  int *a=new int;
  *a=10;
  p=a;
  cout << "In funp1 p= " << (*p) << endl;
}

void func(int a)
{
  a=10;
}

void func1(int &a)
{
  a=10;
}

void func2(int *a)
{
  (*a)=20;
}

void funa(int *a)
{
  a[0]=10;
}

void funa2(int a[])
{
  a[0]=20;
}

void funv(vector<int> &a)
{
  a.at(0)=10;
}

void funv1(vector<int> *a)
{
  (*a).at(0)=20;
}

void funv3(vector<int> a)
{
  a.at(0)=70;
}

void funv2(vector<int> &a)
{
  vector<int> b;
  // b.push_back(30);
  // b.push_back(40);
  b={30,40};
  a=b;
}

void funs(stack<int> &a)
{
  a.pop();
  a.push(10);
}

int main()
{
  node *no;
  no=NULL;
  fn(no);
  if(no==NULL){
    cout << "after fn no is still NULL." << endl;
    // return 1;
  }
  fn1(no);
  cout << "fn1: " << no->data << endl;

  int *p;
  int x2=1;
  p=&x2;
  cout << "orig p= " << (*p) << endl;

  funp(p);
  cout << "funp p= " << (*p) << endl;

  funp1(p);
  cout << "funp1 p= " << (*p) << endl;

  int x=1;
  cout << "x orig: " << x << endl;

  func(x);
  cout << "x func: " << x << endl;

  func1(x);
  cout << "x func1: " << x << endl;

  func2(&x);
  cout << "x func2: " << x << endl;

  int y[2];
  y[0]=1;
  cout << "y orig: " << y[0] << endl;

  funa(y);
  cout << "y funa: " << y[0] << endl;

  funa2(y);
  cout << "y funa2: " << y[0] << endl;

  y[0]=1;
  cout << "y orig: " << y[0] << endl;
  
  funa(&y[0]);
  cout << "y[0] funa: " << y[0] << endl;

  vector<int>z, z1;
  z.resize(1);
  z.at(0)=1;
  cout << "z orig: " << z.at(0) << endl;

  z1={1};
  cout << "z1 orig: " << z1.at(0) << endl;

  funv2(z);
  cout << "z size funv2: " << z.size() << " | " << z.at(0) << " " << z.at(1) << endl;

  funv(z);
  cout << "z funv: " << z.at(0) << endl;

  funv1(&z);
  cout << "z funv1: " << z.at(0) << endl;

  funv3(z);
  cout << "z funv3: " << z.at(0) << endl;

  stack<int> s;
  s.push(1);
  cout << "s orig: " << s.top() << endl;

  funs(s);
  cout << "s funs: " << s.top() << endl;

  return 0;
}
















