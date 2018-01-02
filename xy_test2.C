#include <iostream>
using namespace std;

void funA(int A[])
{
  int b[2];
  b[0]=3;b[1]=4;
  A=b;
  // A[0]=3;A[1]=4;
}

void funAa(int *A)
{
  int b[2];
  b[0]=3;b[1]=4;
  A=b;
  // A[0]=3;A[1]=4;
}

int *funAb(int A[])
{
  int b[2];
  b[0]=3;b[1]=4;

  return b;
}

int main()
{
  int A[]={1,2};
  cout << "A: " << A[0] << A[1] << endl;

  funA(A);
  cout << "funA: " << A[0] << A[1] << endl;

  funAa(A);
  cout << "funAa: " << A[0] << A[1] << endl;

  int out[]=funAb(A);
  cout << "funAb: " << out[0] << out[1] << endl;

  return 0;
}

















