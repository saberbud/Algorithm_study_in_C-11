#include <iostream>
#include <fstream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int MAX=100;

bool route_exist(int a,int b,bool graph[][MAX])
{
  queue<int> Que;
  bool visited[MAX];
  memset(visited,false,sizeof(visited));
  Que.push(a);
  visited[a]=true;

  int temp;
  while(!Que.empty()){
    temp=Que.front();
    Que.pop();
    for(int i=0;i<MAX;i++){
      if(graph[temp][i] && !visited[i]){
        if(b==i){
          cout << "In RE: " << temp << " " << i << " | " << graph[temp][i] << endl;
          return true;
        }
        Que.push(i);
        visited[i]=true;
      }
    }
  }

  return false;
}

int main(){
  int n,u,v;
  bool dgraph[MAX][MAX];

  //loop init
  /*for(int i=0;i<MAX;i++){
    for(int j=0;j<MAX;j++){
      dgraph[i][j]=false;
    }
  }
  */

  memset(dgraph,false,sizeof(dgraph));

  ifstream infile("directed_graph.txt");
  infile >> n;
  cout << "Read graph n= " << n << endl;
  for(int i=0;i<n;i++){
    infile >> u >> v;
    dgraph[u][v]=true;
    cout << u << " " << v << " | " << dgraph[u][v] << endl;
  }

  infile.close();

  cout << endl;
  // u=0;v=9;  //No route
  u=0;v=3;  //Yes route

  bool rex=route_exist(u,v,dgraph);
  cout << "Route exist between " << u << " and " << v << ": ";
  if(rex){
    cout << "Yes." << endl;
  }else{
    cout << "No." << endl;
  }


}
