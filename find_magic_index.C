#include <iostream>
#include <cmath>
using namespace std;

int find_magic_id_1(int arr[], int s_id, int e_id)
{
  if(e_id<s_id)return -1;

  int m_id=s_id+(e_id-s_id)/2;

  if(arr[m_id]==m_id)return m_id;

  //Left search
  int left_id=min(arr[m_id],m_id-1);
  int left=find_magic_id_1(arr,s_id,left_id);
  if(left>-1)return left;

  //Right search
  int right_id=max(arr[m_id],m_id+1);
  int right=find_magic_id_1(arr,right_id,e_id);
  if(right>-1)return right;

  return -1;
}

int main()
{
  int arr[]={-10, -5, 2, 2, 2, 3, 4, 8, 9, 12, 13};
  cout << "Magic id= " << find_magic_id_1(arr,0,10) << endl;

  return 0;
}


















