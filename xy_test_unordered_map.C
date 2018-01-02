#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
  unordered_map<int,bool> mapib;
  mapib[7]=1;

  unordered_map<int,int> mapii;
  mapii[7]=1;

  unordered_map<int,double> mapid;
  mapid[7]=1.1;
  mapid.insert({3,3.14});

  unordered_map<string,int> mapis;
  // mapis["xy"]=1;
  mapis["xy"]++;
  cout << mapis["xx"] << endl;

  for(int i=0;i<11;i++){
    cout << i << " , mapib= " << mapib[i] << " , mapii= " << mapii[i] << " , mapid= " << mapid[i] << endl;
  }
  

  cout << endl;
  cout << "count of xy: " << mapis.count("xy") << endl;
  mapis.erase("xy");
  // auto it=mapis.begin();
  // mapis.erase(it);
  cout << "count of xy: " << mapis.count("xy") << endl;
  for(auto &n:mapis){
    cout << n.first << " , " << n.second << endl;
  }

  return 0;
}























