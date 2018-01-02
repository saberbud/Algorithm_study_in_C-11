#include <iostream>
#include "linked_list.h"

using namespace std;

Node* find_cycle_begin(Node* head)
{
  if(head==NULL)return NULL;

  Node* s=head;
  Node* f=head;

  while(f!=NULL &&f->next!=NULL){
    s=s->next;
    f=f->next->next;

    cout << "s data= " << s->data << " , f data= " << f->data << endl;

    if(s==f)break;
  }

  if(f==NULL || f->next==NULL){
    return NULL;
  }

  s=head;

  cout << endl;
  while(s!=f){
    s=s->next;
    f=f->next;

    cout << "s data= " << s->data << " , f data= " << f->data << endl;
  }

  return s;
}

int main()
{
  LinkedList ll;
  for(int i=1;i<8;i++){
    ll.insert(i);
  }

  cout << "Not cycled list: " << endl;
  ll.display();

  int n=0;
  int ns=3;
  Node* l_n=ll.head;
  int tempi;

  Node* cyc_s;
  while(l_n->next){
    tempi=l_n->data;
    n++;

    if(n==ns)cyc_s=l_n;

    l_n=l_n->next;

    cout << "n= " << n << " , data= " << tempi << endl;
  }
  n++;
  tempi=l_n->data;
  cout << "out loop n= " << n << " , data= " << tempi << endl;

  cout << "cyc_s: " << ns << " , data= " << cyc_s->data << endl;

  l_n->next=cyc_s;  //set cycle
  for(int i=1;i<8;i++){
    tempi=l_n->data;
    n++;

    l_n=l_n->next;

    cout << "n= " << n << " , data= " << tempi << endl;
  }

  cout << endl;
  cout << "Find cycle begin" << endl;
  Node* cb;
  cb=find_cycle_begin(ll.head);

  return 0;
}



















