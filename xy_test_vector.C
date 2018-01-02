#include <iostream>
#include <vector>
using namespace std;

void zero_vec(vector<int> &A)
{
  for(unsigned int i=0;i<A.size();i++){
    A.at(i)=0;
  }
}

int main()
{
  vector<int> A={3,1,4};

  for(auto i:A)cout << i << " ";
  cout << endl;

  // A.clear();
  // A.resize(3);

  zero_vec(A);

  for(auto i:A)cout << i << " ";
  cout << endl;

  vector<vector<int>> B={{1,2,3,4,5},{-1,2,3,4,-5},{-2,-1,3,5,4}};
  for(unsigned int i=0;i<B.size();i++){
    for(unsigned int j=0;j<B.at(i).size();j++){
      cout << B.at(i).at(j) << " ";
    }
    cout << endl;
  }

  return 0;
}






















