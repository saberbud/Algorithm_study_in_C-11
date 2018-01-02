#include <iostream>
#include <climits>
using namespace std;

void print_binary(int n)
{
  int arr[32];
  int len=8*sizeof(n);
  int mask=1;
  int index=0;

  while(len--){
    if(n&mask){
      arr[index]=1;
    }else{
      arr[index]=0;
    }
    index++;
    mask<<=1;
  }

  for(int i=31;i>=0;i--){
    cout << arr[i];
  }
  cout << endl;
}

int n_bits(int a, int b)
{
  int len=32;
  int n=0;

  while(len--){
    if((a&1)!=(b&1))n++;
    a>>=1;
    b>>=1;
  }

  return n;
}

int main()
{
  int a=9456;
  int b=12000;

  cout << "a= " << a << endl;
  print_binary(a);

  cout << "b= " << b << endl;
  print_binary(b);

  cout << "n bits needed= " << n_bits(a,b) << endl;

  cout << "INTMAX" << INT_MAX << endl;
  print_binary(INT_MAX);

  return 0;
}



















