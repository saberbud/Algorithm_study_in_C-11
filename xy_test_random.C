#include <iostream>
#include <random>
using namespace std;

int main(){
  mt19937 rng;
  rng.seed(random_device()());

  int a,b;
  a=1;b=5;

  uniform_int_distribution<unsigned int> uni_dist(a, b);

  int n=17;
  int temp;
  for(int i=0;i<n;i++){
    temp=uni_dist(rng);
    cout << temp << " ";
  }
  cout << endl;

  a=2;b=4;
  for(int i=0;i<n;i++){
    temp=uniform_int_distribution<int>{a,b}(rng);
    cout << temp << " ";
  }
  cout << endl;


  return 0;
}























