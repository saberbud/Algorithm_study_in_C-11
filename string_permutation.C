#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<string> Vstr;

Vstr find_perm(string str)
{
  Vstr v, vs;

  if(str.length()==0){
    vs.push_back("");
    return vs;
  }

  string a=str.substr(0,1);
  string b;
  v=find_perm(str.substr(1));
  for(unsigned int i=0;i<v.size();i++){
    for(unsigned int j=0;j<=v.at(i).length();j++){
      b=v.at(i).substr(0,j)+a+v.at(i).substr(j);
      vs.push_back(b);
    }
  }

  return vs;
}

int main()
{
  string str="abcd";
  Vstr res;
  res=find_perm(str);

  for(unsigned int i=0;i<res.size();i++){
    cout << res.at(i) << endl;
  }

  return 0;
}














