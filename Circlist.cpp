#include<iostream>
using namespace std;

template <typename T>
class cell
{

    friend class circlist;
    private: 
       T info;
       cell<T>* next;
       cell ( T i )  { info = i; next = this; }
       cell ( T i, cell<T>* ptr)  { info = i; next = ptr; }
};

template <typename T>
class circlist
{
  private:
    cell<T>* rear;
  public:
    int empty() { return rear == rear->next;}
    circlist() { rear = new cell(0); }
    void push(T);
    T pop();
    void enter(T);
};

template <typename T>
void circlist<T>::push(T x)
{
   rear->next = new cell (x, rear->next);
}

template <typename T>
void circlist<T>::enter(T x)
{
  rear->info = x;
  rear = rear->next = new cell(0, rear->next);
}

template <typename T>
T circlist<T>::pop()
{
   if ( empty() ) return 0;
   cell *front<T> = rear->next;
   rear->next  = front->next;
   T x = front->info;
   delete front;
   return x;
}

template <typename T>
class Stack : private circlist<T>
{
    public:
       using circlist::pop;
       using circlist::push;
};

template <typename T>
class Queue : private circlist
{
     public:
        void enque(T i) { circlist::enter(i);}
        int leaveq() { return circlist::pop();}
};
template <typename T>
int main()
{

  Stack<T> s;
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

