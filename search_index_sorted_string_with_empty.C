#include <iostream>
#include <string>
using namespace std;

int search(string arr[], int low, int high, string str)
{
  int mid=(low+high)/2;

  if(arr[mid]==str)return mid;
  if(low>=high)return -1;

  int i;
  if(arr[mid]==""){
    i=1;
    while((mid-i)>=low || (mid+1)<=high){
      if((mid-i)>=low && arr[mid-i]!="" && arr[mid-i]>=str){
        return search(arr,low,mid-i,str);
      }

      if((mid+1)<=high && arr[mid+i]!="" && arr[mid+i]<=str){
        return search(arr,mid+i,high,str);
      }
      i++;
    }
  }else{
    if(arr[mid]<str){
      search(arr,mid+1,high,str);
    }else{
      search(arr,low,mid-1,str);
    }
  }

  return -1;
}

int main()
{
  string arr[] = {"abc", "", "", "", "ball", "cat", "", "dog", "elephant", "fox", "", "", "", "goat"};

  cout << search(arr,0,13,"goat") << endl;
  cout << search(arr,0,12,"goat") << endl;

  return 0;
}

















