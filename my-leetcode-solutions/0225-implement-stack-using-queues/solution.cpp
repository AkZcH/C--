class MyStack {
private:
    queue<int> prime;
    queue<int> second;

public:
    MyStack() {}
    
    void push(int x) {
        second.push(x);
        while(!prime.empty()){
            int node = prime.front();
            second.push(node);
            prime.pop();
        }
        while(!second.empty()){
            int node = second.front();
            prime.push(node);
            second.pop();
        }
    }
    
    int pop() {

        if(prime.empty()) return -1;
        int node = prime.front();
        prime.pop();
        return node;
    }
    
    int top() {

        if(prime.empty()) return -1;
        return prime.front();
    }
    
    bool empty() {

        return prime.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
