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
  }
  head=pre;

  return head;
}

bool is_palindrome(Node* head)
{
  Node* temp=head;
  LinkedList rev;
  int len=0;
  int count=0;

  while(temp){
    rev.insert(temp->data);
    temp=temp->next;
    len++;
  }

  temp=head;

  rev.head=reverse(rev.head);

  Node* rh=rev.head;

  while(count!=len/2){
    if(rh->data!=temp->data)return false;

    temp=temp->next;
    rh=rh->next;
    count++;
  }

  return true;
}

int main()
{
  LinkedList ll;
  ll.insert(1);
  ll.insert(2);
  ll.insert(1);

  cout << "list: " << endl;
  ll.display();

  LinkedList lr;
  // lr=ll;
  Node* hn=ll.head;
  while(hn){
    lr.insert(hn->data);
    hn=hn->next;
  }
  lr.head=reverse(lr.head);

  cout << "list orig:" << endl;
  ll.display();

  cout << "list reverse:" << endl;
  lr.display();

  cout << endl;
  cout << "Is list palindrome? " << is_palindrome(ll.head) << endl;

  return 0;
}







