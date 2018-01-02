#include <iostream>
#include <vector>

using namespace std;

void xy_trans(vector<vector<double>> &A)
{
    unsigned int nx=A.size();
    if(nx<1){
      cout << "Null input matrix." << endl;
      return;
    }
    unsigned int ny=A.at(0).size();

    // cout << "nx= " << nx << " , ny= " << ny << endl;

    vector<vector<double>> B;
    B.resize(ny);
    for(unsigned int j=0;j<ny;j++){
       B.at(j).resize(nx);
       for(unsigned int i=0;i<nx;i++){
         B.at(j).at(i)=A.at(i).at(j);
       }
    }

    A=B;

}

void show_mat(vector<vector<double>> &A)
{
    unsigned int nx=A.size();
    if(nx<1){
      cout << "Null input matrix." << endl;
      return;
    }
    unsigned int ny=A.at(0).size();
    
    cout << "nx= " << nx << " , ny= " << ny << endl;

    for(unsigned int i=0;i<nx;i++){
      if(ny!=A.at(i).size()){
        cout << "Matrix not rectangular." << endl;
        return;
      }
      for(unsigned int j=0;j<ny;j++){
        cout << A.at(i).at(j) << " ";
      }
      cout << endl;
    }

}

int main()
{
    vector<double> tempv;
    vector<vector<double>> tempm;

    tempm.clear();

    tempv={1.,2.,3.};
    tempm.push_back(tempv);

    tempv={4.,5.,6.};
    tempm.push_back(tempv);

    cout << "Original matrix:" << endl;
    show_mat(tempm);

    xy_trans(tempm);

    cout << "Transposed matrix:" << endl;
    show_mat(tempm);

    return 0;
}
