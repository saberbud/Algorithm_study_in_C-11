#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include "sort.h"
using namespace std;

// typedef map<string,vector<string>> mvs;
typedef unordered_map<string,vector<string>> mvs;

void sort_ana(string arr[],int n)
{
  mvs Map;

  string tmps;
  for(int i=0;i<n;i++){
    tmps=arr[i];
    bubbleSort(arr[i],0,arr[i].length()-1);
    Map[arr[i]].push_back(tmps);
  }

  vector<string> tmpv;
  mvs::iterator iter;
  int ind=0;
  for(iter=Map.begin();iter!=Map.end();iter++){
    tmpv=iter->second;
    for(unsigned int i=0;i<tmpv.size();i++){
      arr[ind]=tmpv.at(i);
      ind++;
    }
  }

}

int main()
{
  string arr[] = {"abc", "bca", "aaaa", "abccde", "edbcac", "cbed", "cdeb"};
  sort_ana(arr,7);

  for(int i=0;i<7;i++){
    cout << arr[i] << endl;
  }

  return 0;
}














