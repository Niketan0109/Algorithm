#include<iostream>
using namespace std;

class queue
{
    private:
    int data;
    queue* next;
    queue* head;
    queue* tail;
    public:
    queue()
    {   
        data=-1;
        next=NULL;
        tail=NULL;
        head = NULL;
    }

    void enqueue(int val)
    {
        queue* temp = new queue();
        temp->data=val;
        if(head==NULL)
        {
            tail=temp;
            head=temp;
        }

        else
        {
            tail->next=temp;
            tail=temp;
        }
    }

    void dequeue()
    {
        queue* temp=head;
        if(head==NULL)
        {
            cout<<"No elements to delete\n";
        }

        else
        {
            head=head->next;
            delete temp;
        }
    }
    bool empty()
    {
        if(head==NULL)
        {
            return 1;
        }
        return 0;
    }
    int peak()
    {
        if(empty())
        {
            return -1;
        }
    return head->data;
    }

};


int main()
{
    queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    // q.dequeue();


    cout<<q.empty()<<'\n';
    cout<<q.peak()<<'\n';
}