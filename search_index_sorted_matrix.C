#include <iostream>
using namespace std;

int res_M,res_N;
bool found;

void binarySearch(int *arr, int MStart, int NStart, int MEnd, int NEnd, int N, int ele)
{
  if(found)return;

  int MMid = (MStart+MEnd)/2;
  int NMid = (NStart+NEnd)/2;
  int midEle = *(arr+MMid*N+NMid);
  cout << "midEle= " << midEle << endl;

  res_M=-1;res_N=-1;
  if(midEle == ele){
    cout << "Found" << endl;
    found=true;
    res_M=MMid;
    res_N=NMid;
    return;
  }
  if (MStart >= MEnd && NStart >= NEnd)return;

  // if element in first partition
  if(*(arr+MStart*N+NStart) <= ele && *(arr+MMid*N+NMid) >= ele) {
    cout << "X1" << endl;
    binarySearch(arr, MStart, NStart, MMid, NMid, N, ele);
  }
  // if element in second partition
  if (*(arr+MStart*N+NMid+1) <= ele && *(arr+MMid*N+NEnd) >= ele) {
    cout << "X2" << endl;
    binarySearch(arr, MStart, NMid+1, MMid, NEnd, N, ele);
  }
  // if element in third partition
  if (*(arr+(MMid+1)*N+NStart) <= ele && *(arr+MEnd*N+NMid) >= ele) {
    cout << "X3 " << MMid << " " << NMid << endl;
    binarySearch(arr, MMid+1, NStart, MEnd, NMid, N, ele);
  }
  // if element in forth partition
  if (*(arr+(MMid+1)*N+NEnd) <= ele && *(arr+MEnd*N+NEnd) >= ele) {
    cout << "X4" << endl;
    binarySearch(arr, MMid+1, NMid+1, MEnd, NEnd, N, ele);
  }
}

int main()
{
  int arr[4][5] = {
    {15, 20, 70, 85, 90},
    {25, 35, 81, 94, 100},
    {30, 55, 95, 105, 105},
    {40, 80, 120, 135, 150}
  };

  int in_M=2;
  int in_N=2;
  int targ=arr[in_M][in_N];
  cout << targ << endl;
  found=false;
  binarySearch(*arr, 0, 0, 3, 4, 5, targ);

  cout << "Result: " << res_M << " " << res_N << endl;

  return 0;
}


















