class MyStack {
    private:
    queue<int> q1;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        int n = q1.size();
        if(n == 0){
            q1.push(x);
            return;
        }
        q1.push(x);
        while(n >= 1){
            q1.push(q1.front());
            q1.pop();
            n--;
        }
        
        
    }
    
    int pop() {
        if(q1.size() == 0){
            return -1;
        }
      int x = q1.front();
      q1.pop();
      return x;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(q1.size() == 0){
            return true;
        }
        else{
            return false;
        }
    }
};