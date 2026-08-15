class MyCircularQueue {
public:

    vector<int> q;
    int front = 0;
    int end = 0;

    MyCircularQueue(int k) {
        q.resize(k+1);
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        
        else if(end == q.size()-1)
            end = 0;
        
        else end = end + 1;

        q[end] = value;

        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        
        else if(front == q.size()-1)
            front = 0;
        
        else front = front + 1;

        return true;
    }
    
    int Front() {
        if(isEmpty())   return -1;
        return q[(front+1) % q.size()];
    }
    
    int Rear() {
        if(isEmpty())   return -1;
        return q[end];
    }
    
    bool isEmpty() {
        if(front == end)
            return true;
        else
            return false;
    }
    
    bool isFull() {
        if((front == 0 && end == q.size()-1) || (front == end+1))
            return true;

        else
            return false;
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