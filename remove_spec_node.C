#include <iostream>
#include "linked_list.h"

using namespace std;

int remove_node(Node* node)
{
  if(node==NULL || node->next==NULL){
    return 0;
  }

  node->data=node->next->data;
  node->next=node->next->next;

  return 1;
}

int main()
{
  LinkedList ll;
  
  for(int i=1;i<10;i++){
    ll.insert(i);
  }

  cout << "list: " << endl;
  ll.display();

  Node* temp=ll.head;
  int k=3;
  for(int i=0;i<k;i++){
    temp=temp->next;
  }

  cout << "list mod: " << endl;
  ll.display();

  cout << "Chosen node: " << temp->data << endl;

  int suc=remove_node(temp);
  cout << "list after removal: " << endl;
  ll.display();

  return 0;
}
















