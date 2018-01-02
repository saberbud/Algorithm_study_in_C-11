#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool perm_xy(const string &a, const string &b)
{
    if(a.length()!=b.length()){
      cout << "Not equal length." << endl;
      return false;
    }

    int asc_count[256]={0};

    int val=0;

    for(unsigned int i=0;i<a.length();i++){
      val=a[i];
      asc_count[val]++;
    }

    for(unsigned int i=0;i<b.length();i++){
      val=b[i];
      if((--asc_count[val])<0){
        return false;
      }
    }

    return true;
}

int main()
{
    string a="abc";
    string b="acd";

    cout << "Permutation: " << perm_xy(a,b) << endl;

    string r="dbcafe";
    cout << "r orig: " << r << endl;

    sort(r.begin(),r.end());
    cout << "r sort: " << r << endl;

    return 0;
}
