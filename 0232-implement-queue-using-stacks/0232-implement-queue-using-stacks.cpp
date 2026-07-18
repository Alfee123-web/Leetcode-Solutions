class MyQueue {
    std::stack<int>input;
    std::stack<int>output;
    void shift(){
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
    }

public:
    MyQueue() {
    
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        shift();
        int front = output.top();
        output.pop();
        return front;
    }
    
    int peek() {
        shift();
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
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