#include <iostream>
#include <random>
using namespace std;

void print_arr(int arr[], int n)
{
  for(int i=0;i<n;i++){
    cout << arr[i] << " ";
  }
  cout << endl;
}

int partition(int arr[], int left, int right, int pivot)
{
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

int find_rank(int arr[], int left, int right, int rank, int level)
{
  if(left>right)return -1;
  // if(level>5)return -2;

  mt19937 rng;
  rng.seed(random_device()());
  uniform_int_distribution<unsigned int> uni_dist(left, right);
  int tempid=uni_dist(rng);

  // int pivot=arr[(left+right)/2];
  int pivot=arr[tempid];

  int leftEnd=partition(arr,left,right,pivot);
  cout << "find_rank, leftEnd= " << leftEnd << " , left= " << left << " , right= " << right << " , pivot= " << pivot << endl;

  int leftSize=leftEnd-left+1;
  int result;
  print_arr(arr,8);
  if(leftSize==(rank+1)){
    result=arr[left];
    if(arr[leftEnd]>result)result=arr[leftEnd];
    cout << "Found: " << result << endl;
    return result;
  }else if(rank<leftSize){
    cout << " xy2 left= " << left << " , right= " << leftEnd << endl;
    return find_rank(arr,left,leftEnd,rank,level+1);
  }else{
    cout << " xy3 left= " << (leftEnd+1) << " , right= " << right << endl;
    return find_rank(arr,leftEnd+1,right,rank-leftSize,level+1);
  }

  return -1;
}


int main()
{
  int arr[]={8,4,7,5,6,3,1,2};
  cout << "Orig arr: " << endl;
  print_arr(arr,8);

  /*int leftEnd=partition(arr,0,7,2);
  cout << "Partitioned leftEnd= " << leftEnd << " , arr:" << endl;
  print_arr(arr,8);
  */

  int res=find_rank(arr,0,7,3,0);
  cout << "find_rank result index= " << res << " , value= " << arr[res] << endl;

  return 0;
}














