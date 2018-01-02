#include <iostream>
#include <string>
using namespace std;

void gen_paren(string str, int left, int right)
{
  cout << left << " " << right << endl;
  if(left==0 && right==0){
    cout << str << endl;
    return;
  }

  if(left==right){
    gen_paren(str+"(",left-1,right);
    return;
  }else{
    if(left)gen_paren(str+"(",left-1,right);
    gen_paren(str+")",left,right-1);
  }
}

void gen_paren1(string str, int left, int right){
  if(left<0 || right<left)return;

  if(left==0 && right==0){
    cout << str << endl;
    return;
  }else{
    if(left>0)gen_paren1(str+"(",left-1,right);
    if(right>left)gen_paren1(str+")",left,right-1);
  }
}

int main()
{
  int n=3;
  // gen_paren("",n,n);
  gen_paren1("",n,n);

  return 0;
}


















