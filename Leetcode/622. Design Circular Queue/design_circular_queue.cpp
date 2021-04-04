// Leetcode 622. Design Circular Queue
// https://leetcode.com/problems/design-circular-queue/

class MyCircularQueue 
{
    int* data;
    int front;
    int rear;
    int size;
    int maxSize;
    
public:
    MyCircularQueue(int k) 
    {
        data = (int*)malloc(sizeof(int) * k);
        front = 0;
        rear = -1;
        maxSize = k;
        size = 0;
    }
    
    bool enQueue(int value) 
    {
        if (isFull())
        {
            return false;
        }
        else
        {
            rear++;
            rear %= maxSize;
            data[rear] = value;
            size++;
            return true;
        }
    }
    
    bool deQueue() 
    {
        if (isEmpty())
        {
            return false;
        }
        else
        {
            front++;
            front %= maxSize;
            size--;
            return true;
        }
    }
    
    int Front() 
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return data[front];
        }
    }
    
    int Rear() 
    {        
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return data[rear];
        }
    }
    
    bool isEmpty() 
    {
        return size == 0;
    }
    
    bool isFull() 
    {
        return size == maxSize;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
