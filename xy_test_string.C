#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> vs;

string add_string_paren(string a, char op, string b)
{
  string str;
  string ops=" ";
  ops[0]=op;

  str="("+a+")"+ops+"("+b+")";

  return str;
}

int stest(string a, string b, string &c)
{
  char op='&';
  c=add_string_paren(a,op,b);

  return 0;
}

int main()
{
  string a="abcd";
  string b="1234";
  string c;

  vs.clear();

  int t;
  t=stest(a,b,c);
  vs.push_back(c);
  cout << "c= " << c << " , in vs: " << vs.at(0) << endl;


  return 0;
}










