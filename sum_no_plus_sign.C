#include <iostream>
using namespace std;

int add(int a, int b, int level)
{
  cout << "level= " << level << " | a= " << a << " , b= " << b << endl;
  if(b==0)return a;
  // if(a==0)return b;

  int sum=a^b;  //add no carrying
  int carry=(a&b)<<1;  //carrying no add

  return add(sum,carry,level+1);
}

int main()
{
  int a=3;
  int b=7;

  int c=add(a,b,0);

  cout << endl;
  cout << "add= " << c << endl;

  return 0;
}



















