#include <iostream>
#include "linked_list.h"

using namespace std;

int main()
{
  LinkedList ll;

  for(int i=1;i<10;i++){
    ll.insert(i);
  }

  /*ll.insert(7);
  ll.insert(3);
  ll.insert_position(2,7);
  ll.delete_position(3);
  */

  cout << "ll: " << endl;
  ll.display();

  Node* cur=ll.head;
  int n=0;
  while(cur){
    n++;
    cout << n << " " << cur->data << endl;

    cur=cur->next;
  }
  cout << "n= " << n << endl;

  cout << endl;
  cur=ll.head;
  n=0;
  while(cur->next){
    n++;
    cout << n << " " << cur->data << " " << cur->next->data << endl;

    cur=cur->next;
  }
  cout << "n= " << n << endl;

  Node* n_a;
  n_a=new Node[3];
  n_a[0].data=7;
  cout << n_a[0].data << endl;

  Node** n_ap;
  n_ap=new Node*[3];
  cout << "xy1" << endl;
  n_ap[0]=new Node();
  n_ap[0]->data=7;
  cout << "xy2" << endl;
  cout << n_ap[0]->data << endl;

  return 0;
}
