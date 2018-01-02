#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <array>
#include <algorithm>
using namespace std;

int main()
{
  int n=3;

  array<int,10> s={5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

  // int s[10]={5, 7, 4, 2, 8, 6, 1, 9, 0, 3};

  // s.resize(5);

  cout << s[0] << endl;

  for(auto a:s){
    cout << a << " ";
  }
  cout << endl;

  sort(s.begin(),s.end());

  for(auto a:s){
    cout << a << " ";
  }
  cout << endl;

  // s.push(7);

  cout << "dynamic array" << endl;
  /*int *d;
  d= new int[n];
  d[0]=3;d[1]=1;d[2]=2;
  */

  n=7;
  double *d;
  d= new double[n];
  d[0]=3.1;d[1]=1.1;d[2]=2.1;
  d[3]=7.1;d[4]=0.1;d[5]=1.2;
  d[6]=1.1;

  // cout << "size of d= " << (sizeof(d)/sizeof(d[0])) << endl;  //returns the wrong size

  for(int i=0;i<n;i++){
    cout << d[i] << " ";
  }
  cout << endl;

  sort(d,d+n);

  for(int i=0;i<n;i++){
    cout << d[i] << " ";
  }
  cout << endl;

  cout << "vector" << endl;
  vector<double> va={2.,1.,3.,4.};
  for(auto a:va)cout << a << " ";
  cout << endl;

  sort(va.begin(),va.end());
  for(auto a:va)cout << a << " ";
  cout << endl;



  return 0;
}





















