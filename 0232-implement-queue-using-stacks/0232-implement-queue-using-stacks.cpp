class MyQueue {
    stack<int> input, output;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(output.empty()){
            int x = peek();
            output.pop();
            return x;
        }else{
            int x = output.top();
            output.pop();
            return x;
        }
    }
    
    int peek() {
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
            return output.top();
        }else{
            return output.top();
        }
    }
    
    bool empty() {
        if(output.empty() && input.empty()){
            return true;
        }
        return false;
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