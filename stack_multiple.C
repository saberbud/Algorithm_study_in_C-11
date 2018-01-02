#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

class multi_stack
{
private:
  vector<stack<int>> mstack;
  int nmax;
  unsigned int curS;

public:
  multi_stack(){
    nmax=10;
    mstack.resize(1);
    curS=0;
  }

  void push(int data){
    if(mstack.at(curS).size()>=nmax){
      curS++;
      mstack.resize(curS+1);
      cout << "Adding stack. size= " << mstack.size() << endl;
    }
    mstack.at(curS).push(data);
  }

  void pop(){
    if(mstack.at(curS).empty()){
      if(curS==0){
        cout << "stack is empty." << endl;
        return;
      }
      curS--;
    }
    mstack.at(curS).pop();
  }

  int top(){
    if(mstack.at(curS).empty()){
      if(curS==0)return INT_MIN;
      curS--;
    }
    return mstack.at(curS).top();
  }

  void popAt(unsigned int id){
    if(id>=mstack.size()){
      cout << "popAt id out of stack range, id= " << id << ", size= " << mstack.size() << endl;
      return;
    }

    if(mstack.at(id).empty()){
      cout << "sub stack " << id << " is empty." << endl;
      return;
    }
    mstack.at(id).pop();
  }

};

int main()
{
  vector<stack<int>> stackv;
  stackv.resize(1);
  stackv.at(0).push(7);
  cout << stackv.at(0).top() << endl;

  stackv.resize(2);
  stackv.at(1).push(77);
  cout << stackv.at(0).top() << " " << stackv.at(1).top() << endl;

  cout << endl;
  cout << "multi_stack" << endl;
  multi_stack ms;
  for(int i=0;i<21;i++){
    ms.push(i);
  }

  ms.popAt(0);

  for(int i=0;i<21;i++){
    cout << ms.top() << endl;
    ms.pop();
  }


  return 0;
}




















