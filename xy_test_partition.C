#include<iostream>
using namespace std;

int ntot;

void print_arr(int arr[], int n)
{ 
  for(int i=0;i<n;i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    cout << "p pivot= " << x << endl;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
        cout << " p after swap arr: " << (i-1) << " " << j << endl;
        print_arr(arr,ntot);
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int partition2(int arr[], int left, int right)
{
  int pivot=arr[right];
  int temp;
  while(true){
    while(left<=right && arr[left]<=pivot)left++;
    while(left<=right && arr[right]>pivot)right--;
    if(left>right)return (left-1);
    temp=arr[left];
    arr[left]=arr[right];
    arr[right]=temp;
  }
  
  return -1;
}

int partition3(int arr[], int low, int high) {
  int pivot = arr[int((low+high)/2)];
  cout << "p3 pivot= " << pivot << endl;
  while(low <= high) {
    while(arr[low] < pivot)
      low++;
    while(arr[high] > pivot)
      high--;
    cout << "p3 low high start= " << low << " " << high << endl;
    cout << " p3 before swap arr" << endl;
    print_arr(arr,ntot);
    if(low <= high) {
      swap(arr[low], arr[high]);
      low++;
      high--;
    }
    cout << " p3 after swap arr" << endl;
    print_arr(arr,ntot);
    cout << "p3 low high end= " << low << " " << high << endl;
  }
  return low;
}

int partition4(int arr[], int l, int r)
{  
  cout << "p4" << endl; 
  if(l>r)return l;
  // int x = arr[r], i = l; 
  int i=l;
  int x=arr[(l+r)/2];
  swap(&arr[(l+r)/2],&arr[r]);
  for (int j = l; j <= r - 1; j++){   
    if (arr[j] <= x){   
      swap(&arr[i], &arr[j]);
      i++;
    }
  }
  swap(&arr[i], &arr[r]);
  return i;
}

void quickSort(int arr[], int low, int high) {
  // int index = partition3(arr, low, high);
  int index = partition4(arr, low, high);

  cout << "quick sort low high index= " << low << " " << high << " " << index << endl;

  // if (low<index-1)
  if(low<index)
    quickSort(arr, low, index-1);
  // if (index<high)
  if((index+1)<high)
    quickSort(arr, index, high);
}

int main()
{
  // int arr[]={8,4,7,5,6,3,1,2};
  int arr[]={8,4,7,5,6,3,1,2,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  ntot=n;
  cout << "n= " << n << endl;


  cout << "Orig arr: " << endl;
  print_arr(arr,ntot);

  // int pid=partition(arr,0,7);
  // int pid=partition2(arr,0,7);
  // int pid=partition3(arr,0,7);
  // int pid=partition4(arr,0,7);  //XY invented
  // cout << "Partitioned pid= " << pid << " , pivod= " << arr[pid] << " , arr:" << endl;

  cout << "quick sort" << endl;
  quickSort(arr,0,ntot-1);

  print_arr(arr,ntot);


  return 0;
}










