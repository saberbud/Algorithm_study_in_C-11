#include <iostream>
#include "linked_list.h"

using namespace std;

Node *ktolast(Node *head,int k)
{
  Node *cur=head;
  int l=0;

  while(cur){
    l++;
    cur=cur->next;
  }

  cur=head;

  if(k>l || k<1){
    return NULL;
  }

  int c=0;
  while(l-c!=k){
    c++;
    cur=cur->next;
  }

  return cur;
}

int main()
{
  LinkedList ll;
  
  for(int i=1;i<10;i++){
    ll.insert(i);
  }

  cout << "list: " << endl;
  ll.display();

  int k=3;
  cout << k << " to the last: " << ktolast(ll.head,k)->data << endl;


  return 0;
}


















