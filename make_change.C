#include <iostream>
using namespace std;

int make_change(int n, int pre)
{
  if(n==0)return 1;

  int ways=0;

  if(n>0){
    if(pre>=25)ways+=make_change(n-25,25);
    if(pre>=10)ways+=make_change(n-10,10);
    if(pre>=5)ways+=make_change(n-5,5);
    if(pre>=1)ways+=1;
  }

  return ways;
}

int main()
{
  int n=10;
  cout << "Make change for " << n << " , ways: " << make_change(n,25) << endl;

  return 0;
}



















