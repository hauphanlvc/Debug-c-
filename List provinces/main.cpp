/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
struct node
{
    int id;
  string TenTinh;
  int DanSo;
  float DienTich;
  node *next;
};
struct List
{
    node *head;
    node *tail;
};
void Init(List &l)
{
    l.head = NULL;
    l.tail = NULL;
}
node *CreateNode(int id, string TenTinh, int DanSo, float DienTich)
{
    node *temp;
    temp = new node;
    temp->id = id;
    temp->TenTinh =TenTinh;
    temp->DanSo = DanSo;
    temp->DienTich = DienTich;
    temp->next = NULL;
    return temp;
}
void AddTail(List &l, node *temp)
{
    if (l.head == NULL)
    {
        l.head = temp;
        l.tail = temp;
    }
    else
    {
        l.tail->next = temp;
        l.tail = temp;
    }
}
void inputListProvinces(List &l)
{
    node *temp;
    int n;
    int id, DanSo;
    float DienTich;
    string TenTinh;
    cin>>n;
    for ( int i=0;i<n;i++)
       {
            node *p;
            p = new node;
            cin>>p->id;
            fflush(stdout);
            cin.ignore();
            getline(cin,p->TenTinh);
            cin>>p->DanSo>>p->DienTich;
           AddTail(l,p);
       }
}
void outputListProvinces(List l)
{
    node *temp;
    temp = l.head;
    while (temp->next != NULL)
    {
        cout<<temp->id;
        cout<<"\t"<<temp->TenTinh<<"\t"<<temp->DanSo<<"\t"<<temp->DienTich<<endl;
        temp = temp->next;
    }
    cout<<temp->id;
    cout<<"\t"<<temp->TenTinh<<"\t"<<temp->DanSo<<"\t"<<temp->DienTich<<endl;
}
//###INSERT CODE HERE -
void outputProvincesMore1MillionPop(List l)
{
    node *temp;
    temp = l.head;
    int id = 1;
    while (temp->next != NULL)
    {
        if (temp->DanSo>1000)
        {
            cout<<temp->id;
            cout<<"\t"<<temp->TenTinh<<"\t"<<temp->DanSo<<"\t"<<temp->DienTich<<endl;
        }
        temp = temp->next;
    }
    if (temp->DanSo>1000)
    {
        cout<<temp->id;
        cout<<"\t"<<temp->TenTinh<<"\t"<<temp->DanSo<<"\t"<<temp->DienTich<<endl;
    }
}
node *findProMaxArea(List l)
{
    node *temp;
    temp = l.head;
    float maxx = temp->DienTich;
    while (temp->next != NULL)
    {
        if (temp->DienTich>maxx)
            maxx = temp->DienTich;
        temp = temp->next;
    }
    if (temp->DienTich>maxx)
        maxx = temp->DienTich;
    temp = l.head;
    while (temp->next!=NULL)
    {
        if (maxx == temp->DienTich)
            return temp;
        temp = temp->next;
    }
    if (maxx == temp->DienTich)
        return temp;
}
void outputProvince(node *temp)
{
    cout<<temp->id;
    cout<<"\t"<<temp->TenTinh<<"\t"<<temp->DanSo<<"\t"<<temp->DienTich<<endl;
}
int main()
{
    List L;
    Init(L);
    inputListProvinces(L);
    cout<<"List of provinces:"<<endl;
    cout<<"ID\t|Province\t|Population\t|Area"<<endl;
    outputListProvinces(L);
    cout<<"Provinces with a population of more than 1 million:"<<endl;
    outputProvincesMore1MillionPop(L);
    cout<<"The largest province:"<<endl;
    node *p = findProMaxArea(L);
    if(p) outputProvince(p);
    return 0;
}
