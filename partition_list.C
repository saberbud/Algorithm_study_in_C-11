#include <iostream>
#include "linked_list.h"

using namespace std;

void partition(Node* head,int val)
{
  if(head==NULL)return;

  LinkedList* U=new LinkedList();
  LinkedList* L=new LinkedList();
  Node* cur=head;

  while(cur){
    if(cur->data<val){
      L->insert(cur->data);
    }else{
      U->insert(cur->data);
    }

    cur=cur->next;
  }

  cur=head;
  Node* cL=L->head;
  while(cL){
    cur->data=cL->data;

    cur=cur->next;
    cL=cL->next;
  }

  Node* cU=U->head;
  while(cU){
    cur->data=cU->data;

    cur=cur->next;
    cU=cU->next;
  }

}

int main()
{
  LinkedList ll;
  ll.insert(3);
  ll.insert(1);
  ll.insert(6);
  ll.insert(7);
  ll.insert(4);

  cout << "list: " << endl;
  ll.display();

  int val=5;
  partition(ll.head,val);

  cout << "list after partition: " << endl;
  ll.display();

  return 0;
}
















