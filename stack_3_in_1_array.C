#include <iostream>
using namespace std;

struct node
{
  int val, preID;
};

class stack3
{
public:
  stack3(int totsize=900){
    buf=new node[totsize];
    stop[0]=stop[1]=stop[2]=-1;
    totalsize=totsize;
    cur=0;
  }

  void push(int sN, int data){
    if(cur>totalsize){
      cout << "Stack full. Do not push." << endl;
      return;
    }
    buf[cur].val=data;
    buf[cur].preID=stop[sN];
    stop[sN]=cur;
    cur++;
  }

  void pop(int sN){
    stop[sN]=buf[stop[sN]].preID;
  }

  int top(int sN){
    return buf[stop[sN]].val;
  }

private:
  node* buf;
  int stop[3];
  int totalsize;
  int cur;

};

int main()
{
  stack3 s;

  for(int i=0;i<10;i++){
    s.push(0,i);
  }

  for(int i=10;i<20;i++){
    s.push(1,i);
  }

  for(int i=70;i<80;i++){
    s.push(2,i);
  }

  for(int i=0;i<3;i++){
    cout << s.top(i) << " ";
  }
  cout << endl;

  for(int i=0;i<3;i++){
    s.pop(i);
    cout << s.top(i) << " ";
  }
  cout << endl;

  s.push(0,171);
  s.push(1,172);
  s.push(2,173);

  for(int i=0;i<3;i++){
    cout << s.top(i) << " ";
  }
  cout << endl;

  return 0;
}













