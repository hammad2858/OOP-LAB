#include<iostream>
#include<exception>
using namespace std;

class QueueOverflowException:public exception{};
class QueueUnderflowException:public exception{};

template<typename T>
class Queue{
    private:
    T* data;
    int front,rear,count;
    int capacity;

    public:
    Queue(int c):capacity(c),front(0),rear(0),count(0){

        data = new T[capacity];
    }

    ~Queue(){
        delete[] data;
    }

    void enqueue(T value){
        if(count == capacity){
            throw QueueOverflowException();
        }
        data[rear] = value;
        rear = (rear+1)%capacity;
        count++;
    }
    T dequeue(){
        if(count == 0)
        throw QueueUnderflowException();
    
    T value = data[front];
    front  = (front+1)%capacity;
    count --;
    return value;
    }
    bool isEmpty() {
        return count ==0;
    }

    bool isFull(){
        return count == capacity;
    }

    int size() {
        return count;
    }
};


int main (){
    Queue<int> q(3);

    try{
        cout<<"Attempting to enqueue to a full queue"<<endl;
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);
    }
    catch (QueueOverflowException e){
        cout<<"Caught Queue Over floe Exception"<<endl;
        cout<<"What() :"<<e.what()<<endl;
    }
    try{
        cout<<"Dequeuing all elements "<<endl;
        cout<<q.dequeue()<<endl;
        cout<<q.dequeue()<<endl;
        cout<<q.dequeue()<<endl;

        cout<<"Attempting to dequeue from an empty queue"<<endl;
        cout<<q.dequeue()<<endl;
    }
    catch(QueueUnderflowException e){
        cout<<"Caught queue under flow exception"<<endl;
        cout<<"What() : "<<e.what()<<endl;

    }


}