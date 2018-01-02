#include <iostream>
#include <string>
using namespace std;

string decimal_to_binary(double a)
{
  if(a<0 || a>=1)return "Error.";
  string res="";
  res=res+"0.";

  while(a>0){
    if(res.length()>32)return "Error";

    a*=2;
    if(a>=1){
      res=res+"1";
      a=a-1.0;
    }else{
      res=res+"0";
    }
  }

  return res;
}

int main()
{
  double a=0.125;
  cout << decimal_to_binary(a) << endl;

  return 0;
}


















