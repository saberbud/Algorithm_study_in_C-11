#include <iostream>
#include <unordered_map>
#include "linked_list.h"

using namespace std;

void remove_dup(Node *head)
{
  if(head==NULL)return;

  Node *cur=head;
  Node *runner;

  while(cur){
    runner=cur;

    while(runner->next){
      if(cur->data==runner->next->data){
        runner->next=runner->next->next;
      }else{
        runner=runner->next;
      }
    }

    cur=cur->next;
  }

}

void remove_dup2(Node *head)
{
  if(head==NULL)return;
  
  Node *cur=head;

  unordered_map<int,bool> map;

  map[cur->data]=1;

  while(cur->next){
    cout << "Data: " << cur->next->data << " , map= " << map[cur->next->data] << endl;
    if(map[cur->next->data]==0){
      map[cur->next->data]=1;
      cur=cur->next;
    }else{
      cur->next=cur->next->next;
      cout << "  dup: remove." << endl;
    }
  }

}

int main()
{
  LinkedList ll;

  for(int i=1;i<10;i++){
    ll.insert(i);
  }

  ll.insert(7);
  ll.insert(3);
  ll.insert_position(2,7);
  ll.delete_position(3);

  cout << "ll create: " << endl;
  ll.display();

  cout << "Remove dup: " << endl;
  // remove_dup(ll.head);
  remove_dup2(ll.head);
  ll.display();

  return 0;
}





















