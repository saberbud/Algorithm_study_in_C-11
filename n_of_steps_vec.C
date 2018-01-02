#include <iostream>
#include <vector>
using namespace std;

vector<int> A;

int n_of_steps(unsigned int n)
{
  if(A.size()<1){
    A.push_back(0);
    A.push_back(1);
    A.push_back(2);
    A.push_back(4);
  }

  if(n<A.size()){
    return A.at(n);
  }else{
    A.push_back(n_of_steps(n-1)+n_of_steps(n-2)+n_of_steps(n-3));
  }

  return A.at(n);
}

int main()
{
  A.clear();
  unsigned int n=5;

  cout << "# of ways for " << n << " steps: " << n_of_steps(n) << endl;

  return 0;
}


















