#include <iostream>
#include <climits>
#include <cmath>
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

void next_small(int n)
{
  int len=0;
  int tmp=n;
  int res;

  while(len<31){
    if((tmp&1)==0){
      tmp>>=1;
      len++;
      if((tmp&1)==1){  //10 found
        res=n-(1<<len)+(1<<(len-1));
        print_binary(res);
        return;
      }
    }else{
      tmp>>=1;
      len++;
    }
  }
  cout << INT_MIN << endl;
}

void next_large(int n)
{
  int len=0;
  int tmp=n;
  int res;

  while(len<31){
    if((tmp&1)==1){
      tmp>>=1;
      len++;
      if((tmp&1)==0){  //01 found
        res=n+(1<<len)-(1<<(len-1));
        print_binary(res);
        return;
      }
    }else{
      tmp>>=1;
      len++;
    }
  }
  cout << INT_MAX << endl;
}

int main()
{
  int a=(1<<31)+(1<<29);
  cout << a << endl;
  print_binary(a);
  next_small(a);
  next_large(a);

  return 0;
}










