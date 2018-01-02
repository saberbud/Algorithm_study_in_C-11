#include <iostream>
#include <string>
using namespace std;

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

int main()
{
  string a="badcgf";
  cout << "Orig string: " << a << endl;

  bubbleSort(a,0,3);
  cout << "Sort string: " << a << endl;

  return 0;
}









