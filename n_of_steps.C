#include <iostream>
using namespace std;

int n_of_steps(int n,int arr[])
{
  if(arr[n])return arr[n];

  if(n<4){
    if(n==1){
      arr[n]=1;
    }else if(n==2){
      arr[n]=2;
    }else if(n==3){
      arr[n]=4;
    }
  }else{
    arr[n]=n_of_steps(n-1,arr)+n_of_steps(n-2,arr)+n_of_steps(n-3,arr);
  }

  return arr[n];
}

int main()
{
  const int n=5;
  int arr[n+1]={-1};

  cout << "# of ways for " << n << " steps: " << n_of_steps(n,arr) << endl;

  cout << endl;
  cout << "list: " << endl;
  for(int i=0;i<(n+1);i++){
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}



















