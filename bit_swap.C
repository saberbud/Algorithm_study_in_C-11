#include <iostream>
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

int swapOE(int a)
{
  int mask=0xaaaaaaaa;  //....1010
  int mask1=0x55555555;  //....0101
  int oB=a&mask;
  int eB=a&mask1;

  oB>>=1;
  eB<<=1;
  return (oB|eB);
}

int main()
{
  int a=0xaaaaaaaa;
  print_binary(a);
  print_binary(swapOE(a));

  return 0;
}










