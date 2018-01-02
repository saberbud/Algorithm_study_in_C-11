#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <array>
#include <algorithm>
using namespace std;

/*struct st
{
  int a;
  int b;
};
*/

class st
{
public:
  int a;
  int b;
};

bool cmp(const st &a, const st &b)
{
  return a.b < b.b;
}

int main()
{
  vector<st> A;
  A.resize(3);

  A.at(0).a=1.;
  A.at(0).b=3.;

  A.at(1).a=2.;
  A.at(1).b=2.;

  A.at(2).a=3.;
  A.at(2).b=1.;

  for(auto k:A)cout << k.a << " ";
  cout << endl;

  sort(A.begin(),A.end(),cmp);

  for(auto k:A)cout << k.a << " ";
  cout << endl;

  return 0;
}






















