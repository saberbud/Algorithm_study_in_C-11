#include <iostream>
#include <stack>
#include <climits>
using namespace std;

class stack_with_min
{
private:
  stack<int> s1,s2;

public:
  int min(){
    if(s2.empty())return INT_MAX;
    return s2.top();
  }

  void push(int x){
    s1.push(x);
    if(min()>=x)s2.push(x);
  }

  void pop(){
    if(min()==s1.top())s2.pop();
    s1.pop();
  }

  int top(){
    return s1.top();
  }

};

int main()
{
  stack<int> s;
  for(int i=0;i<8;i++){
    s.push(i);
  }

  cout << s.top() << endl;
  s.pop();
  cout << s.top() << endl;

  stack_with_min swm;
  int arr[]={7,3,9,5,6,7,1,8};
  for(int i=0;i<8;i++){
    swm.push(arr[i]);
    cout << arr[i] << " " << swm.min() << endl;
  }

  cout << endl;
  for(int i=0;i<8;i++){
    swm.pop();
    cout << swm.top() << " " << swm.min() << endl;
  }

  return 0;
}




















