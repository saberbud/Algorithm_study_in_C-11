#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
  int N=1000000;

  clock_t startTime = clock();

  vector<double> a;
  for(int i=0;i<N;i++)a.push_back(0.1*i);

  vector<double> b;
  for(int i=0;i<N;i++)b.push_back(0.0001*i*i);

  double sum=0.;
  for(int i=0;i<N;i++)sum+=a.at(i)*b.at(i);

  double time=clock()-startTime;
  time=time/(double)CLOCKS_PER_SEC*1000.;  //mini s

  cout << "sum= " << sum << " , time= " << time << " ms" << endl;

  return 0;
}





























