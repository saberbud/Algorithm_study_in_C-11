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

int insert_bit(int N, int M, int i, int j)
{
  int allOnes=~0;
  int left=allOnes<<(j+1);
  int right=(1<<i)-1;
  int mask=left|right;
  int clr=N&mask;
  int shifted=M<<i;

  return shifted|clr;
}

int main(){
  int N,M,i,j;
  N= 1<<10; //10000000000
  M=19;  //10011

  j=6;i=2;

  print_binary(N);
  print_binary(M);

  int x=insert_bit(N,M,i,j);
  print_binary(x);

  return 0;
}















