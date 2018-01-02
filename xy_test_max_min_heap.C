#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main()
{
  vector<int> v={3,1,4,1,5,9};
  vector<int> v1=v;

  cout << "Orig v" << endl;
  for(auto i:v)cout << i << " ";
  cout << endl;

  make_heap(v.begin(),v.end());
  // make_heap(v.begin(),v.end(),operator<);

  cout << "After make_heap v" << endl;
  for(auto i:v)cout << i << " ";
  cout << endl;

  cout << "v back: " << v.back() << endl;

  pop_heap(v.begin(),v.end());
  cout << "After pop_heap v" << endl;
  for(auto i:v)cout << i << " ";
  cout << endl;

  v.pop_back();
  cout << "After v.pop_back" << endl;
  for(auto i:v)cout << i << " ";
  cout << endl;

  v.push_back(8);
  cout << "After v.push_back" << endl;
  for(auto i:v)cout << i << " ";
  cout << endl;

  push_heap(v.begin(),v.end());
  cout << "After push_heap" << endl;
  for(auto i:v)cout << i << " ";
  cout << endl;

  sort_heap(v.begin(),v.end());
  cout << "After sort_heap" << endl;
  for(auto i:v)cout << i << " ";
  cout << endl;

  v.erase(v.begin(),v.begin()+2);
  cout << "After v.erase 2 ele" << endl;
  for(auto i:v)cout << i << " ";
  cout << endl;

  v.erase(v.begin());
  cout << "After v.erase 1 ele" << endl;
  for(auto i:v)cout << i << " ";
  cout << endl;


  cout << endl;
  cout << "Simple priority queue" << endl;
  priority_queue<int> q;
  for(int n:{1,3,7,2,5,4,6})q.push(n);

  while(!q.empty()){
    cout << q.top() << " ";
    q.pop();
  }
  cout << endl;

  cout << endl;
  cout << "Greater comp priority queue" << endl;
  priority_queue<int, vector<int>, greater<int>> q2;
  for(int n:{1,3,7,2,5,4,6})q2.push(n);
  cout << "size= " << q2.size() << endl;

  while(!q2.empty()){
    cout << q2.top() << " ";
    q2.pop();
  }
  cout << endl;

  return 0;
}





















