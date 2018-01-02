#include <iostream>
#include <stack>
using namespace std;

void sort_stack(stack<int> &st)
{
  stack<int> so;  //top smallest

  int temp;
  while(!st.empty()){
    temp=st.top();
    st.pop();

    while(!so.empty() && temp>so.top()){
      st.push(so.top());
      so.pop();
    }
    
    so.push(temp);
  }

  while(!so.empty()){
    st.push(so.top());
    so.pop();
  }

}

void sort_stack1(stack<int> &st)
{ 
  stack<int> so;  //top biggest
  
  int temp;
  while(!st.empty()){
    temp=st.top();
    st.pop();
    
    while(!so.empty() && temp<so.top()){
      st.push(so.top());
      so.pop();
    }
    
    so.push(temp);
  }
  
  while(!so.empty()){
    st.push(so.top());
    so.pop();
  }

}

int main()
{
  stack<int> s;
  int arr[]={7,3,4,5,8,9,2,17};
  for(unsigned int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
    s.push(arr[i]);
  }

  // sort_stack(s);  //top biggest
  sort_stack1(s);  //top smallest
  while(!s.empty()){
    cout << s.top() << endl;
    s.pop();
  }

  return 0;
}


















