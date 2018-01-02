#include <iostream>
#include <vector>
using namespace std;

void zero_vec(vector<int> &A)
{
  for(unsigned int i=0;i<A.size();i++){
    A.at(i)=0;
  }
}

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

void get_max_sum_mat(vector<vector<int>> A, int *res)
{
  int rn=A.size();
  int cn=A.at(0).size();

  int rres[3];
  vector<int> tempv;
  tempv.resize(cn);
  int tempsum=0;
  res[3]=0;
  res[4]=rn-1;

  for(int k=0;k<rn;k++){
    zero_vec(tempv);
    for(int j=k;j<rn;j++){
      for(int i=0;i<cn;i++){
        tempv.at(i)=tempv.at(i)+A.at(j).at(i);
      }
      get_max_sum(tempv,rres);
      if(rres[0]>tempsum){
        tempsum=rres[0];
        res[0]=rres[0];
        res[1]=rres[1];
        res[2]=rres[2];
        res[3]=k;
        res[4]=j;
      }
    }
  }

}

int main()
{
  // vector<vector<int>> A={{1,2,3,4,5},{-1,2,3,4,-5},{-2,-1,3,5,4}};
  vector<vector<int>> A={{1,2,3,4,5},{-1,2,3,4,-5},{-2,-1,3,5,-4}};
  for(unsigned int i=0;i<A.size();i++){
    for(unsigned int j=0;j<A.at(i).size();j++){
      cout << A.at(i).at(j) << " ";
    }
    cout << endl;
  }

  int res[5];
  get_max_sum_mat(A,res);

  cout << "Max sum= " << res[0] << " , start= " << res[3] << " , " << res[1] << " , end= " << res[4] << " , " << res[2] << endl;

  return 0;
}










