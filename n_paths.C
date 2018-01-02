#include <iostream>
#include <vector>
using namespace std;

int get_paths(unsigned int x, unsigned int y, vector<vector<int>> &A)
{
  if(A.at(x).at(y)){
    if(A.at(x).at(y)!=-1)return A.at(x).at(y);
    return 0;
  }

  if(x==0 || y==0){
    if(x==0 && y==0){
      A.at(x).at(y)=1;
    }else if(x==0){
      A.at(x).at(y)=get_paths(x,y-1,A);
    }else{
      A.at(x).at(y)=get_paths(x-1,y,A);
    }
  }else{
    A.at(x).at(y)=get_paths(x-1,y,A)+get_paths(x,y-1,A);
  }

  return A.at(x).at(y);
}

int main()
{
  unsigned int X=3;
  unsigned int Y=3;

  vector<vector<int>> A;

  vector<int>tempv;
  tempv.clear();
  for(unsigned int i=0;i<Y;i++){
    tempv.push_back(0);
  }

  A.clear();
  for(unsigned int i=0;i<X;i++){
    A.push_back(tempv);
  }

  A.at(0).at(2)=-1; //dead point=-1

  X=2;Y=2;
  cout << "# of paths= " << get_paths(X,Y,A) << endl;

  return 0;
}


















