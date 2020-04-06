/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
struct
new
delete
###End banned keyword*/

#include <iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
};

struct List{
    Node *head, *tail;
};

void list_initializing(List &l){
    l.head = l.tail = NULL;
}
void add_tail(List &l, int x){
    Node*p = new Node;
    p->val = x;
    p->next = NULL;

    if (l.head == NULL){
        l.head = l.tail = p;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}


bool is_palindrome(List &l){
//###INSERT CODE HERE
  List l2;

   list_initializing(l2);
  Node *p;
    p=l.head;
    while (p!=NULL)
    {
        add_tail(l2,p->val);
        p=p->next;
    }



   //List l1=l;
  Node *Node1,*Node2;
  Node1=l.head;
  l.head=l.head->next;
  Node2=l.head;
   Node1->next=NULL;
  while ( l.head!=NULL)
  {
      l.head=l.head->next;
        Node2->next=Node1;
        Node1=Node2;
        Node2=l.head;
  }
  l.head=Node1;
 // l1.head=Node1;

   Node *p1=l.head,*p2=l2.head;
int x,x1;
   while (p2!=NULL)
   {

       x=p1->val;
        x1=p2->val;
       if ( x!=x1) return 0;
       p1=p1->next;
       p2=p2->next;


   }




   return 1;

}

int main()
{
    freopen("DanhSach.txt","r",stdin);
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    List l; list_initializing(l);

    int x;
    do{
        cin >> x;
        if (x != 0) add_tail(l, x);
        else break;
    } while(true);

    if (is_palindrome(l)) cout << "TRUE";
    else cout << "FALSE";
    cout << endl;

    return 0;
}
