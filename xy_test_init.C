#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX=10;

int main(){
  bool b[MAX][MAX];

  //memset method
  memset(b,false,sizeof(b));

  for(int i=0;i<MAX;i++){
    for(int j=0;j<MAX;j++){
      cout << b[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;
  double d[MAX][MAX];

  memset(d,0,sizeof(d));

  for(int i=0;i<MAX;i++){
    for(int j=0;j<MAX;j++){
      cout << d[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}





















