#include <iostream>
#include "linked_list.h"

using namespace std;

Node* reverse(Node* head)
{
  if(head==NULL)return NULL;

  Node* pre=NULL;
  Node* temp;
  while(head){
    temp=head->next;
    head->next=pre;
    pre=head;
    head=temp;

    /*if(head->next!=NULL && head!=NULL)cout << "head->next: " << head->next->data << " ";
    if(head!=NULL)cout << "head: " << head->data << " ";
    if(pre!=NULL)cout << "pre: " << pre->data << endl;
    */
  }
  head=pre;

  return head;
}

LinkedList sum_list_r(Node* list1, Node* list2)
{
  LinkedList s;

  int i1,i2;
  int power=1;
  int npower=1;

  Node* l1=list1;
  Node* l2=list2;

  i1=0;
  while(l1){
    i1=i1+(l1->data)*power;

    power=power*10;
    npower++;
    l1=l1->next;
  }
  cout << "i1= " << i1 << " power= " << power << " , npower= " << npower << endl;

  i2=0;
  int power2=1;
  int npower2=1;
  while(l2){
    i2=i2+(l2->data)*power2;

    power2=power2*10;
    npower2++;
    l2=l2->next;
  }

  cout << "i2= " << i2 << " power2= " << power2 << " , npower2= " << npower2 << endl;

  int is=i1+i2;

  if(power2>power){
    power=power2;
    npower=npower2;
  }

  if(is<power){
    power=power/10;
    npower--;
  }

  cout << "is= " << is << " , power= " << power << " , npower= " << npower << endl;

  int id;
  for(int i=0;i<npower;i++){
    id=is/power;
    is=is-id*power;
    s.insert(id);

    power=power/10;
  }


  return s;
}

int main()
{
  LinkedList l1;
  l1.insert(3);
  l1.insert(8);
  l1.insert(7);

  LinkedList l2;
  l2.insert(9);
  l2.insert(1);
  l2.insert(8);

  LinkedList ls;
  ls=sum_list_r(l1.head,l2.head);

  cout << "sum list:" << endl;
  ls.display();

  cout << "Reverse sum digits" << endl;
  Node* hr;
  hr=reverse(ls.head);
  ls.head=hr;
  ls.display();

  return 0;
}
















