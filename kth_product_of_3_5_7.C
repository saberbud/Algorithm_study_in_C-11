#include <iostream>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int rm_min()
{
  if(q.size()<1)return 0;

  int min=q.top();

  while(q.top()==min){
    q.pop();
  }

  return min;
}

void add_products(int v)
{
  q.push(v*3);
  q.push(v*5);
  q.push(v*7);
}

int get_kth_num(int k)
{
  int val=0;
  if(k<0)return 0;

  val=1;
  add_products(val);
  for(int i=0;i<k;i++){
    val=rm_min();
    add_products(val);
  }

  return val;
}

int main()
{
  /*add_products(1);
  cout << "q size= " << q.size() << " , q top= " << q.top() << endl;
  q.push(3);
  cout << "q size= " << q.size() << " , q top= " << q.top() << endl;
  int min=rm_min();
  cout << "q size= " << q.size() << " , q top= " << q.top() << endl;
  */

  int k=5;
  int xy=get_kth_num(k);
  cout << k << "th :" << xy << endl;

  return 0;
}











