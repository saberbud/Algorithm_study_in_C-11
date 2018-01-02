#include <iostream>
#include <vector>
using namespace std;

void find_subsets(vector<vector<int>> &sub, int arr[], int n)
{
  if(n<0)return;

  find_subsets(sub,arr,n-1);

  unsigned int m=sub.size();
  vector<int> v;
  for(unsigned int i=0;i<m;i++){
    v.clear();
    for(unsigned int j=0;j<sub.at(i).size();j++){
      v.push_back(sub.at(i).at(j));
    }
    v.push_back(arr[n]);
    sub.push_back(v);
  }

  v.clear();
  v.push_back(arr[n]);
  sub.push_back(v);

}

int main()
{
  int arr[]={1,2,3,7};
  vector<vector<int>> sub;
  find_subsets(sub,arr,3);

  for(unsigned int i=0;i<sub.size();i++){
    for(unsigned int j=0;j<sub.at(i).size();j++){
      cout << sub.at(i).at(j) << " ";
    }
    cout << endl;
  }

  return 0;
}


















