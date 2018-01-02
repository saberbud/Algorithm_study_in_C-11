#include <iostream>
using namespace std;

template <class T>
void Swap(T &a, T &b)
{
  T tmp=a;
  a=b;
  b=tmp;
}

template <class U>
U SUM(U a, U b)
{
  return (a+b);
}

int main()
{
  int a[5];
  a[0]=0;a[1]=1;

  cout << "Before swap: " << a[0] << " " << a[1] << endl;
  Swap(a[0],a[1]);
  cout << "After swap: " << a[0] << " " << a[1] << " " << SUM(a[0],a[1]) << endl;

  double b[5];
  b[0]=0.1;b[1]=1.1;

  cout << "Before swap: " << b[0] << " " << b[1] << endl;
  Swap(b[0],b[1]);
  cout << "After swap: " << b[0] << " " << b[1] << " " << SUM(b[0],b[1]) << endl;

  return 0;
}
















