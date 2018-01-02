#include <iostream>
#include <string>
#include <vector>
using namespace std;

string A;
vector<string> dic;

bool valid(string a)
{
  for(unsigned int i=0;i<dic.size();i++){
    if(a==dic.at(i))return true;
  }

  return false;
}

int parse0(int w_s, int w_e, int level)
{
  cout << "  " << w_s << " " << w_e << " | " << level << endl;

  if(w_e>=A.length())return (w_e-w_s);

  //break
  string word=A.substr(w_s,w_e-w_s+1);
  cout << word << " | " << w_s << " " << (w_e+1) << " | " << level << endl;

  //next break point
  int bEx=parse0(w_e+1,w_e+1,level+1);
  if(!valid(word))bEx+=word.length();
  cout << " bEx= " << bEx << " | " << (w_e+1) << " " << (w_e+1) << " | " << level << endl;

  //extend
  int bEt=parse0(w_s,w_e+1,level+1);
  cout << " bEt= " << bEt << " | " << w_s << " " << (w_e+1) << " | " << level << endl;

  int min=bEx;
  if(bEt<min)min=bEt;

  cout << "  min= " << min << " | " << w_s << " " << w_e << " | " << level << endl;

  return min;
}

int main()
{
  dic.clear();
  dic.push_back("xy");
  dic.push_back("man");

  A="iamxyman";

  int inv;
  inv=parse0(0,0,0);
  cout << "inv= " << inv << endl;

  return 0;
}

















