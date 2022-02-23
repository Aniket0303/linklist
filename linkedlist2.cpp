#include<iostream>
#include<stdlib.h>
using namespace std;
class node
{
public:
                int data;
                node *next;
public:

                node* create_node();
};
node* node::create_node()
{
                node *p;
                p=new node;
                cout<<endl<<"enter the data";
                cin>>p->data;
                p->next=NULL;
                return p;
}
class SLL: public node
{
private:
                node *header;
public:
                void create(int x);
                void display();
                int search(int key);
                int update(int data ,int pos);
                SLL()
                {
                                header=NULL;
                }
                ~SLL()
                {
                                delete header;
                }
};
void SLL::create(int n)
{
                node *p,*q;
                for(int i=1;i<=n;i++)
                {
                                p=create_node();
                                if(i==1)
                                {
                                                header=p;
                                                q=p;
                                }
                                else
                                {
                                                q->next=p;
                                                q=p;
                                }
                }
}
void SLL :: display()
{
                if(header==NULL)
                {
                                cout<<"\n\t linked list is empty";
                }
                else
                {
                                node *q;
                                q=header;
                                while(q!=NULL)
                                {
                                                cout<<" "<<q->data;
                                                q=q->next;
                                }
                }
}
int SLL::search(int key)
{
                int x=0;
                if(header==NULL)
                {
                                cout<<endl<<"linked  list empty";
                }
                else
                {
                                node *q;
                                q=header;
                                while(q!=NULL)
                                {
                                                if(key==q->data)
                                                {
                                                                x++;
                                                }
                                                q=q->next;
                                }
                }
                return x;
}
int SLL::update(int data,int pos)
{
                int cnt=1;
                if(header==NULL)
                {
                                return 0;
                }
                else
                {
                                node *q;
                                q=header;
                                while(q!=NULL)
                                {
                                                if(cnt==pos)
                                                {
                                                                q->data=data;
                                                                return 1;
                                                }
                                                q=q->next;
                                                cnt++;
                                }
                }
                return 2;
}
int main()
{
                SLL obj;
                int n;
                int key;
                int pos,data,x;
                cout<<"\n\t enter the number of nodes:";
                cin>>n;
                obj.create(n);
                obj.display();
                cout<<"\n\t enter the key to search:";
                cin>>key;
               int res=obj.search( key);
                if(res==0)
                {
                    cout<<"\n\t key element not found";
                }
                else
                {
                   cout<<"\n\t key element  found";
                }
                cout<<"\n\t enter the position:";
                                                           cin>>pos;
                                                           cout<<"\n\t enter the data:";
                                                           cin>>data;
                                                           x=obj.update(data,pos);
                                                           if(x==0)
                                                           {
                                                                           cout<<"\n\t list is not udated";
                                                           }
                                                           else if(x==1)
                                                           {
                                                                           cout<<"\n\t list is updated";
                                                           }
                                                           else
                                                           {
                                                                           cout<<"\n\t position is not found";
                                                           }
                    obj.display();

}
