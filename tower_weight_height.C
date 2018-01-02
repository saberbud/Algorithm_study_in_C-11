#include <iostream>
#include <vector>
using namespace std;

struct htWt
{
  int height,weight;
};

void sortHeight(htWt arr[], int n)
{
  htWt tmp;
  for(int i=0;i<n;i++){
    for(int j=0;j<n-1;j++){
      if(arr[j].height>arr[j+1].height){
        tmp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=tmp;
      }
    }
  }
}

unsigned int get_seq(htWt arr[], int n, vector<vector<int>> &wt)
{
  sortHeight(arr,n);

  bool flag;
  vector<int> v;
  for(int i=0;i<n;i++){
    flag=true;
    for(unsigned int j=0;j<wt.size();j++){
      if(arr[i].weight>wt.at(j).back()){
        flag=false;
        wt.at(j).push_back(arr[i].weight);
      }
    }

    if(flag){
      v.clear();
      v.push_back(arr[i].weight);
      wt.push_back(v);
    }
  }

  unsigned int max=0;
  for(unsigned int j=0;j<wt.size();j++){
    if(max<wt.at(j).size())max=wt.at(j).size();
    cout << j << " | " << max << endl;
  }

  return max;
}

int main()
{
  htWt arr[]={{12, 13}, {11, 15}, {9, 20}, {20, 20}, {40, 21}, {8, 42}};
  vector<vector<int>> wto;
  cout << "Max= " << get_seq(arr,6,wto) << endl;

  cout << "wt " << endl;
  for(unsigned int i=0;i<wto.size();i++){
    for(unsigned int j=0;j<wto.at(i).size();j++){
      cout << wto.at(i).at(j) << " ";
    }
    cout << endl;
  }

  return 0;
}










