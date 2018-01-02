#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string,bool> map;

void sort_length(string A[], int low, int high)
{ 
  if (high <= low) {
    return;
  }
  
  string temps;
  int noOfElements = high - low + 1;
  for (int i = 0; i < noOfElements-1; i++) {
    for (int j = low; j < high; j++) {
      if(A[j].length()>A[j+1].length()){
        temps=A[j];
        A[j]=A[j+1];
        A[j+1]=temps;
      }
    }
  }
}

bool can_build_word(string str, bool is_orig);

string print_longest_word(string A[], int n)
{
  for(int i=0;i<n;i++){
    map[A[i]]=true;
  }

  sort_length(A,0,n-1);

  string result="";
  for(int i=0;i<n;i++){
    if(can_build_word(A[i],true))result=A[i];
  }

  return result;
}

bool can_build_word(string str, bool is_orig)
{
  if(map[str] && !is_orig)return true;

  string ls,rs;
  for(unsigned int i=1;i<str.length();i++){
    ls=str.substr(0,i);
    rs=str.substr(i);

    if(map[ls] && can_build_word(rs,false))return true;
  }
  // map[str]=false;

  return false;
}

int main()
{
  string A[]={"yxyx","xy","xx","xxxy","xyxw","ww","xyxyyy","yy","yyxwxyyxx"};
  int n=sizeof(A)/sizeof(A[0]);
  cout << "n= " << n << endl;

  string res=print_longest_word(A,n);
  cout << res << endl;

  return 0;
}











