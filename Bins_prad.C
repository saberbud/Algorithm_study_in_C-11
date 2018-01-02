#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct st
{
  double Q2;
  double stat;
  double sys;
};

bool cmp(const st &a, const st &b)
{
  return a.Q2 < b.Q2;
}

double GE_dipole(double Q2, double R)
{
  double p0=12./(R*R);
  double GE=1./(1.+Q2/p0)/(1.+Q2/p0);

  return GE;
}

int main()
{
  int n;

  //1GeV bins
  vector<st> T1;
  ifstream infile("/Users/saberbud/Documents/1GeV_bins_PRad.txt");
  if(!infile.is_open()){
    cout << "Input file 1GeV not exist: " << endl;
    return 1;
  }
  infile >> n;
  T1.resize(n);
  cout << "Table 1 GeV n= " << n << endl;
  for(int i=0;i<n;i++){
    infile >> T1.at(i).Q2 >> T1.at(i).stat >> T1.at(i).sys;
  }
  infile.close();

//  for(auto a:T1)cout << a.Q2 << " " << a.stat << " " << a.sys << endl;
//  cout << endl;

  //2GeV bins
  vector<st> T2;
  infile.open("/Users/saberbud/Documents/2GeV_bins_PRad.txt");
  if(!infile.is_open()){
    cout << "Input file 2GeV not exist: " << endl;
    return 1;
  }
  infile >> n;
  T2.resize(n);
  cout << "Table 2 GeV n= " << n << endl;
  for(int i=0;i<n;i++){
    infile >> T2.at(i).Q2 >> T2.at(i).stat >> T2.at(i).sys;
  }
  infile.close();

//  for(auto a:T2)cout << a.Q2 << " " << a.stat << " " << a.sys << endl;
//  cout << endl;


  vector<st> Tcom=T1;
  Tcom.insert(Tcom.end(),T2.begin(),T2.end());
  cout << "Table combined size: " << Tcom.size() << endl;

//  for(auto a:Tcom)cout << a.Q2 << " " << a.stat << " " << a.sys << endl;
//  cout << endl;

  cout << "Sort Tcom" << endl;
  sort(Tcom.begin(),Tcom.end(),cmp);

//  for(auto a:Tcom)cout << a.Q2 << " " << a.stat << " " << a.sys << endl;
//  cout << endl;

  cout << endl;
  cout << "Output: Bins_out.txt" << endl;

  vector<st> Tout=Tcom;  //1GeV T1, 2GeV T2, combine Tcom
//  for(auto a:Tout)cout << a.Q2 << " " << a.stat << " " << a.sys << endl;
//  cout << endl;
  int etype=2;  //0: stat, 1:sys, 2:rms combine
  double Rin=0.85;
  double GE,err;
  cout << "Tout size= " << Tout.size() << endl;
  for(auto a:Tout){
    GE=GE_dipole(a.Q2,Rin);
    if(etype==0){
      err=a.stat;
    }else if(etype==1){
      err=a.sys;
    }else{
      err=sqrt(a.stat*a.stat+a.sys*a.sys);
    }
    cout << a.Q2 << " " << GE << " " << err << endl;
  }

  // return 0;

  ofstream outfile("Bins_out.txt");
  outfile << Tout.size() << endl;
//  for(auto a:Tout)outfile << a.Q2 << " " << a.stat << " " << a.sys << endl;
  for(auto a:Tout){
    GE=GE_dipole(a.Q2,Rin);
    if(etype==0){
      err=a.stat;
    }else if(etype==1){
      err=a.sys;
    }else{
      err=sqrt(a.stat*a.stat+a.sys*a.sys);
    }
    outfile << a.Q2 << " " << GE << " " << err << endl;
  }
  outfile.close();

  return 0;
}












