#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int,int> map;

template <class T>
void Swap(T &a, T &b){
  T tmp = a;
  a = b;
  b = tmp;
}

template <class U>
void bubbleSort(U &arr, int low, int high){
  if (high <= low) {
    return;
  }
  int noOfElements = high - low + 1;
  for (int i = 0; i < noOfElements-1; ++i) {
    for (int j = low; j < high; ++j) {
      if (int(arr[j]) > int(arr[j+1])) {
        Swap(arr[j], arr[j+1]);
      }
    }
  }
}

vector<int> scan(vector<int> A)
{
  vector<int> B;
  B.push_back(A.at(0));

  for(unsigned int i=0;i<A.size();i++){
    map[A.at(i)]++;
    if(A.at(i)!=B.back())B.push_back(A.at(i));
  }

  return B;  
}

int pairs(vector<int> A, int sum)
{
  int np=0;
  int first=0;
  int last=A.size()-1;

  int s;
  vector<int> v;
  v.resize(2);
  while(first<last){
    int s=A.at(first)+A.at(last);

    if(s==sum){
      cout << np << " " << A.at(first) << " " << A.at(last) << endl;
      np=np+map[A.at(first)]*map[A.at(last)];
      first++;
      last--;
    }else{
      if(s<sum)first++;
      last--;
    }
  }

  return np;
}

int main()
{
  vector<int> A={3,2,1,4,1,5,0,3};
  bubbleSort(A,0,A.size()-1);

  vector<int> B;
  B=scan(A);

  for(unsigned int i=0;i<A.size();i++){
    cout << A.at(i) << " " << map[A.at(i)] << endl;
  }
  cout << endl;

  for(unsigned int i=0;i<B.size();i++){
    cout << B.at(i) << " " << map[B.at(i)] << endl;
  }
  cout << endl;

  cout << "# of pairs= " << pairs(B,5) << endl;

  return 0;
}










