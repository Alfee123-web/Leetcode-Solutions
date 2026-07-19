class MyQueue {
    std::stack<int>i;
    std::stack<int>o;
    void shift(){
    if(o.empty()){
        while(!i.empty()){
            o.push(i.top());
            i.pop();
        }
    }
    }
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        i.push(x);
    }
    
    int pop() {
        shift();
        int front = o.top();
        o.pop();
        return front;

    }
    
    int peek() {
        shift();
        return o.top();

    }
    
    bool empty() {
        return i.empty() && o.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */