#include <iostream>

using namespace std;
struct NODE
{
    int info;
    NODE *pNext;
};
struct LIST {
    NODE *pHead;
    NODE *pTail;
}
;
void CreatEmptyList(LIST &l)
{
    l.pHead=NULL;
    l.pTail=NULL;
}
NODE* CreateNode(int x)
{
    NODE *p;
    p= new NODE;
    p->info=x;
    p->pNext=NULL;
    return p;

}
void AddHead(LIST &l, NODE *p)
{
    if (l.pHead==NULL)
    {
        l.pHead=p;
        l.pTail=l.pHead;
    }
    else
    {
        p->pNext=l.pHead;
        l.pHead=p;

    }
}
void AddTail(LIST &l,NODE *p)
{
    if ( l.pHead==NULL)
    {
        l.pHead=p;
        //l.pTail=p;
        l.pTail=l.pHead;
    }
    else
    {
        l.pTail->pNext=p;
        l.pTail=p;



    }
}
void AddAfter(LIST &l,NODE *q,NODE *p)
{
    if ( q==NULL ) AddHead(l,p)l;
    else
    {
        p->pNext=q->pNext;
        q->pNext=p;

    }
}
void PrinList(LIST l)
{
    NODE *p;
    p=l.pHead;
    while (p!=NULL)
    {
        cout<<p.info<<"\t";
        p=p->pNext;
    }
}
int main()
{
//    cout << "Hello world!" << endl;
    return 0;
}
