#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

typedef vector<string> VS;
unordered_map <string,int>map;

void scan(VS A)
{
  for(unsigned int i=0;i<A.size();i++){
    map[A.at(i)]++;
  }
}

int get_freq(string a)
{
  return map[a];
}

int main()
{
  VS A={"xy","xx","xy","xy","xf","xx"};
  scan(A);

  string a="xh";
  cout << "Freq of " << a << " : " << get_freq(a) << endl;


  return 0;
}










