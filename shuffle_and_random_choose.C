#include <iostream>
#include <vector>
#include <random>
using namespace std;

typedef vector<int> VI;

VI random_pick(VI A, int m)
{
  VI sub;
  sub.resize(m);

  for(int i=0;i<m;i++){
    sub.at(i)=A.at(i);
  }

  mt19937 rng;
  rng.seed(random_device()());

  int k;
  for(int i=m;i<(int)A.size();i++){
    k=uniform_int_distribution<int>{0,i}(rng);
    if(k<m)sub.at(k)=A.at(i);
  }

  return sub;
}

void shuffle(VI &A)
{
  mt19937 rng;
  rng.seed(random_device()());

  int k;
  int temp;
  for(int i=0;i<(int)A.size();i++){
    k=uniform_int_distribution<int>{0,i}(rng);
    temp=A.at(k);
    A.at(k)=A.at(i);
    A.at(i)=temp;
  }
}

int main()
{
  VI A={3,7,1,5,8};
  cout << "Orig A:" << endl;
  for(auto a:A)cout << a << " ";
  cout << endl;

  int m=3;
  VI sub=random_pick(A,m);
  cout << "sub:" << endl;
  for(auto a:sub)cout << a << " ";
  cout << endl;

  shuffle(A);
  cout << "Shuffled A:" << endl;
  for(auto a:A)cout << a << " ";
  cout << endl;

  return 0;
}
















