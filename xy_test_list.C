#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main()
{
  vector<list<int>> lv;

  list<int> l;
  for(int i=1;i<8;i++){
    l.push_back(i);
  }

  lv.push_back(l);

  l.push_back(8);

  lv.push_back(l);

  list<int>::iterator it;
  for(int i=0;i<2;i++){
    // list<int>::iterator it;
    for(it=lv.at(i).begin();it!=lv.at(i).end();it++){
      cout << (*it) << " ";
    }
    cout << endl;
  }

  return 0;
}























