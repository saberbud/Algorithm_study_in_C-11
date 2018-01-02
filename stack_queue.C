#include <iostream>
#include <stack>
#include <climits>
#include <queue>
using namespace std;

class Queue{
private:
  stack<int> pri, buff;

public:
  void EnQueue(int data){
    while(!buff.empty()){
      pri.push(buff.top());
      buff.pop();
    }
    pri.push(data);
  }

  int DeQueue(){
    if(pri.empty()&&buff.empty())return INT_MIN;
    while(!pri.empty()){
      buff.push(pri.top());
      pri.pop();
    }
    int temp=buff.top();
    buff.pop();
    return temp;
  }

  int size(){
    return (pri.size()+buff.size());
  }

};

int main()
{
  Queue q;
  stack<int> s;
  queue<int> cq;
  for(int i=0;i<8;i++){
    q.EnQueue(i);
    s.push(i);
    cq.push(i);
  }

  for(int i=0;i<8;i++){
    cout << i << " q: " << q.DeQueue() << " s: " << s.top() << " cq: " << cq.front() << endl;
    s.pop();
    cq.pop();
  }

  return 0;
}


















