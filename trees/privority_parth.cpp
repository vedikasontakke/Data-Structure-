#include <iostream>
using namespace std;

class PriorityQueue
{
public:
    static const int size = 5;
    int front, rear;
    int arr[size];

    void insertion_sort(int num)
    {

        int temp = this->rear;

        while (this->arr[temp] > num)
        {
            arr[temp + 1] = arr[temp];
            temp -= 1;
        }

        arr[temp] = num;
    }

    PriorityQueue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return this->front == -1 || this->front == rear + 1;
    }

    bool isFull()
    {
        return this->rear == size - 1;
    }

    void enque(int num)
    {

        if (this->isFull())
        {
            cout << "Queue Is Overflow";
            return;
        }

        if (front == -1)
            front += 1;

        this->insertion_sort(num);
        cout << "Data Inserted Successfully" << endl;
        rear += 1;
    }

    void deque()
    {

        if (this->isEmpty())
        {
            cout << "Queue Is Empty" << endl;
            return;
        }

        cout << "Top Element is " << arr[front] << endl;

        front += 1;
    }

    void display()
    {
        for (int i = 0; i < 5; i++)
        {
            int data = arr[i];
            cout << data << " ";
        }

        cout << endl;
    }
};

int main()
{

    PriorityQueue pq;

    pq.display();

    pq.enque(10);

    pq.display();

    //	for(int i=5; i>0; i--){
    //		pq.enque(i);
    //	}
    //
    //	for(int i=0; i<5; i++){
    //		pq.deque();
    //	}

    return 0;
}