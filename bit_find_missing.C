#include <iostream>
using namespace std;

int fetchBit(int bit, int no)
{
  no>>=bit;
  return (no&1);
}

void find_missing(int A[], int &n, int col, int &v)
{
  if(n<2)return;

  int b0[(n/2)+1], b1[(n/2+1)];
  int count0=0;
  int count1=0;

  for(int i=0;i<n;i++){
    if(fetchBit(col,A[i])){
      b1[count1]=A[i];
      count1++;
    }else{
      b0[count0]=A[i];
      count0++;
    }
  }

  // cout << "find_missing v= " << v << endl;

  if(count0<=count1){
    v=v|(0<<col);
    A=b0;
    n=count0;
    // v=find_missing(b0,count0,col+1);

    cout << "find_missing even v= " << v << endl;
    // return ((v<<1)|0);
  }else{
    v=v|(1<<col);
    A=b1;
    n= count1;
    // v=find_missing(b1,count1,col+1);

    cout << "find_missing odd v= " << v << endl;
    // return ((v<<1)|1);
  }
  cout << "find_missing size A= " << (sizeof(A)/sizeof(A[0])) << endl;
}

void print_missing(int A[], int n)
{
  // cout << find_missing(A,n,0) << endl;
  int v=0;
  int nn=n;
  cout << "nn= " << nn << endl;
  cout << "size A= " << (sizeof(A)/sizeof(A[0])) << endl;

  find_missing(A, nn, 0, v);
  cout << nn << " " << v << endl;
  for(int i=0;i<nn;i++){
    cout << A[i] << " ";
  }
  cout << endl;
  cout << "size A= " << (sizeof(A)/sizeof(A[0])) << endl;
}

int main()
{
  int A[]={2, 5, 6, 0, 1, 3, 4, 8, 7, 10, 11, 12};
  print_missing(A,12);

  return 0;
}










