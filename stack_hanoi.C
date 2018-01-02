#include <iostream>
#include <stack>
using namespace std;
int ncount;

void towerOfHanoi(stack<int> *a, stack<int> *buff, stack<int> *dest, int n){
    if(n==0){
        return;
    }
    ncount++;
    towerOfHanoi(a, dest, buff, n-1);
    (*dest).push((*a).top());
    (*a).pop();
    towerOfHanoi(buff, a, dest, n-1);
}

int main(){
    stack<int> primary, buffer, destination;
    int n = 3;
    for(int i=n; i>0; i--)
        primary.push(i);

    ncount=0;
    towerOfHanoi(&primary, &buffer, &destination, n);
    while(!destination.empty()){
        cout<<destination.top()<<" ";
        destination.pop();
    }
    cout << endl;

    cout << "ncount= " << ncount << endl;

    return 0;
}
