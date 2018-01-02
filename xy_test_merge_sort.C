#include <iostream>
using namespace std;

int ntot;

void merge(int arr[], int low, int middle, int high){
  int helper[high-low+1];
  for (int i = low; i <= high; ++i) {
    helper[i-low] = arr[i];
  }
  int i=low, j=middle+1, k=low;

  cout << "merge start i j k= " << i << " " << j << " " << k << " low middle high= " << low << " " << middle << " " << high << endl;

  while(i<=middle and j<=high){
    if (helper[i-low] < helper[j-low]) {
      cout << "c1 | i j k= " << i << " " << j << " " << k << endl; 
      arr[k] = helper[i-low];
      i++;
    }
    else {
      cout << "c2 | i j k= " << i << " " << j << " " << k << endl;
      arr[k] = helper[j-low];
      j++;
    }
    k++;

    cout << "  arr:" << endl;
    for(int i=0;i<ntot;i++)cout << arr[i] << " ";
    cout << endl;
  }

  cout << "merge i j k= " << i << " " << j << " " << k << endl;
  // return;

  cout << "merge middle arr" << endl;
  for(int i=0;i<ntot;i++)cout << arr[i] << " ";
  cout << endl;

  if (i>middle) {
    cout << "case 1" << endl;
    /*for (; j <= high; ++j) {
      if(arr[k] != helper[j-low])cout << " case 1 useful" << endl;
      arr[k] = helper[j-low];
      k++;
    }
    */
  }
  else {
    cout << "case 2" << endl;
    for (; i <= middle; ++i) {
      if(arr[k] != helper[i-low])cout << " case 2 useful" << endl;
      arr[k] = helper[i-low];
      k++;
    }
  }



  cout << "merge end arr" << endl;
  for(int i=0;i<ntot;i++)cout << arr[i] << " ";
  cout << endl;
}

void mergeSort(int arr[], int low, int high){
  if (high <= low) {
    return;
  }
  int noOfElements = high - low + 1;
  int middleElement = (high+low)/2;
  mergeSort(arr, low, middleElement);
  mergeSort(arr, middleElement+1, high);
  merge(arr, low, middleElement, high);
}

int main()
{
  // int arr[]={6,3,2,5,1,7,4};
  // int arr[]={6,3,2,5};
  int arr[]={6,3,2,5,2};
  int n=sizeof(arr)/sizeof(arr[0]);
  ntot=n;
  cout << "n= " << n << endl;
  cout << "Orig arr" << endl;
  for(auto i:arr)cout << i << " ";
  cout << endl;

  cout << endl;
  cout << "After merge arr" << endl;
  merge(arr,0,n/2,n-1);
  // mergeSort(arr,0,n-1);
  for(auto i:arr)cout << i << " ";
  cout << endl;

  return 0;
}






















