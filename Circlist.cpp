#include<iostream>
using namespace std;

template <typename T>
class cell
{

    friend class circlist;
    private: 
       T info;
       cell* next;
       cell ( T i )  { info = i; next = this; }
       cell ( T i, cell* ptr)  { info = i; next = ptr; }
};

class circlist
{
  private:
    cell* rear;
  public:
    int empty() { return rear == rear->next;}
    circlist() { rear = new cell(0); }
    void push(int);
    int pop();
    void enter(int);
};

void circlist::push(int x)
{
   rear->next = new cell (x, rear->next);
}

void circlist::enter(int x)
{
  rear->info = x;
  rear = rear->next = new cell(0, rear->next);
}

int circlist::pop()
{
   if ( empty() ) return 0;
   cell *front = rear->next;
   rear->next  = front->next;
   int x = front->info;
   delete front;
   return x;
}

class Stack : private circlist
{
    public:
       using circlist::pop;
       using circlist::push;
};
class Queue : private circlist
{
     public:
        void enque(int i) { circlist::enter(i);}
        int leaveq() { return circlist::pop();}
};
int main()
{

  Stack s;
  s.push(20); s.push(10); s.push(9);
  cout << s.pop() <<endl;
  cout << s.pop() <<endl;
  cout << s.pop() <<endl;


  circlist circ;
  circ.push(10);
  circ.push(11);
  circ.enter(20);
  circ.push(10);
  return 0;

}

