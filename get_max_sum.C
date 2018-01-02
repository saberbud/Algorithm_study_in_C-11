#include <iostream>
#include <vector>
using namespace std;

void get_max_sum(vector<int> A, int *result)
{
  int maxsum=0;
  int sum=0;

  int id_s=0;
  int id_e=A.size()-1;

  for(unsigned int i=0;i<A.size();i++){
    sum+=A.at(i);
    if(maxsum<sum){
      maxsum=sum;
      id_e=i;
    }else if(sum<0){
      sum=0;
      id_s=i+1;
    }
  }

  result[0]=maxsum;
  result[1]=id_s;
  result[2]=id_e;
}

int main()
{
  // vector<int> A={2,3,-8,-1,2,4,-2,3,-1};
  vector<int> A={2,8,-8,-1,9,4,-4,3,-1};

  for(unsigned int i=0;i<A.size();i++){
    cout << A.at(i) << " ";
  }
  cout << endl;

  cout << endl;
  int res[3];
  get_max_sum(A,res);

  cout << "Max sum= " << res[0] << " | " << res[1] << " , " << res[2] << endl;

  return 0;
}


















