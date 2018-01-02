#include <iostream>
#include <string>
#include <vector>
using namespace std;

class x_class
{
public:
  double x,y;

  x_class(double X, double Y){
    x=X;
    y=Y;
  }

};

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

void print_x_class(vector<x_class> A)
{
  for(auto a:A)cout << a.x << " " << a.y << endl;
}

int main()
{
  string A[]={"yxyx","xy","xx","xxxy","xyxw","ww","xyxyyy","yy","yyxxyyxx"};

  int n=sizeof(A)/sizeof(A[0])-1;
  cout << "n= " << n << endl;

  for(auto a:A){
    cout << a << endl;
  }

  cout << endl;
  cout << "Sort" << endl;
  sort_length(A,0,8);

  for(auto a:A){
    cout << a << endl;
  }

  vector<x_class> xc;
  xc.emplace_back(1,2);
  xc.emplace_back(3,4);
  xc.emplace_back(5,6);
  cout << xc.at(0).x << " " << xc.at(0).y << endl;

  for(auto a:xc)cout << a.x << " " << a.y << endl;

  cout << endl;
  print_x_class(xc);

  return 0;
}























