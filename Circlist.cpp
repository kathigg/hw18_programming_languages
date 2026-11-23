#include<iostream>
using namespace std;

template <typename T>
class cell
{

    friend class circlist<T>;
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
    circlist() { rear = new cell<T>(T()); }
    void push(T);
    T pop();
    void enter(T);
};

template <typename T>
void circlist<T>::push(T x)
{
   rear->next = new cell<T> (x, rear->next);
}

template <typename T>
void circlist<T>::enter(T x)
{
  rear->info = x;
  rear = rear->next = new cell<T>(T(), rear->next);
}

template <typename T>
T circlist<T>::pop()
{
    // T() gives you the default value, 
    // like 0 for numbers and empty string 
    // for strings, etc
   if ( empty() ) return T(); 
   cell<T> *front = rear->next;
   rear->next  = front->next;
   T x = front->info;
   delete front;
   return x;
}

template <typename T>
class Stack : private circlist<T>
{
    public:
       using circlist<T>::pop;
       using circlist<T>::push;
};

template <typename T>
class Queue : private circlist<T>
{
     public:
        void enque(T i) { circlist<T>::enter(i);}
        T leaveq() { return circlist<T>::pop();}
};


int main()
{

  Stack<int> s;
  s.push(20); s.push(10); s.push(9);
  cout << s.pop() <<endl;
  cout << s.pop() <<endl;
  cout << s.pop() <<endl;


  circlist<int> circ;
  circ.push(10);
  circ.push(11);
  circ.enter(20);
  circ.push(10);
  return 0;

}

