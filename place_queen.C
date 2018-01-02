#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int GRID_SIZE=8;
// #define GRID_SIZE 8
typedef vector<vector<int>> vi;

bool check_valid(vector<int> colums, int row1, int col1)
{
  int col2,rowDist,colDist;

  for(int row2=0;row2<row1;row2++){
    col2=colums.at(row2);
    if(col1==col2)return false;

    rowDist=row1-row2;
    colDist=abs(col1-col2);
    if(rowDist==colDist)return false;
  }

  return true;
}

void place_Q(int row, vector<int> &colums, vi &result)
{
  if(row==GRID_SIZE){
    result.push_back(colums);
  }else{
    for(int col=0;col<GRID_SIZE;col++){
      if(check_valid(colums,row,col)){
        colums.at(row)=col;
        place_Q(row+1,colums,result);
      }
    }
  }
}

int main()
{
  vi v;
  vector<int> colums;
  colums.resize(GRID_SIZE);

  place_Q(0,colums,v);

  for(unsigned int i=0;i<v.size();i++){
    for(int j=0;j<GRID_SIZE;j++){
      cout << v.at(i).at(j) << " ";
    }
    cout << endl;
  }


  return 0;
}









