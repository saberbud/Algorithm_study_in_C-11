#include <iostream>
#include <queue>
#include <string>
#include <climits>
using namespace std;

class animal
{
private:
  queue<int> dog,cat;
  int id;

public:
  animal(){
    id=1;
  }

  void enque(string a){
    cout << "enque: " << a << endl;
    if(a=="dog"){
      dog.push(id);
      id++;
    }else if(a=="cat"){
      cat.push(id);
      id++;
    }
    return;
  }

  int deque_any(){
    int temp;
    if(dog.front()>cat.front()){
      temp=cat.front();
      cat.pop();
    }else{
      temp=dog.front();
      dog.pop();
    }

    return temp;
  }

  int deque_dog(){
    if(dog.empty())return INT_MIN;
    int temp=dog.front();
    dog.pop();

    return temp;
  }

  int deque_cat(){
    if(cat.empty())return INT_MIN;
    int temp=cat.front();
    cat.pop();

    return temp;
  }

};

int main()
{
  animal a;
  a.enque("dog");
  a.enque("cat");
  a.enque("cat");
  a.enque("dog");

  cout << a.deque_any() << endl;
  cout << a.deque_dog() << endl;

  return 0;
}










