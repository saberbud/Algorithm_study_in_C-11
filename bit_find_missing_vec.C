#include <iostream>
#include <vector>
using namespace std;

int fetchBit(int bit, int no)
{
  no>>=bit;
  return (no&1);
}

void find_missing(vector<int> &A, int col, int &v)
{
  if(A.size()<1)return;

  vector<int>b0, b1;

  for(unsigned int i=0;i<A.size();i++){
    if(fetchBit(col,A.at(i))){
      b1.push_back(A.at(i));
    }else{
      b0.push_back(A.at(i));
    }
  }

  // cout << "find_missing v= " << v << endl;

  if(b0.size()<=b1.size()){
    v=v|(0<<col);
    A=b0;

    // cout << "find_missing even v= " << v << endl;
  }else{
    v=v|(1<<col);
    A=b1;

    // cout << "find_missing odd v= " << v << endl;
  }
  // cout << "find_missing size A= " << A.size() << endl;
}

void print_missing(vector<int> A)
{
  int v=0;
  // cout << "size A= " << A.size() << endl;

  int col=0;
  while(A.size()>=1){
    find_missing(A, col, v);
    col++;

    // cout << "v= " << v << endl;
    /*for(unsigned int i=0;i<A.size();i++){
      cout << A.at(i) << " ";
    }
    */
    // cout << endl;
    // cout << "size A= " << A.size() << endl;
  }
  cout << "Missing: " << v << endl;
}

int main()
{
  vector<int> A={2, 5, 6, 0, 1, 3, 4, 9, 7, 10, 11, 12};
  print_missing(A);

  return 0;
}










