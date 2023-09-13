const int ZERO = [](){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}();

class MinStack {

private:

struct Pair {

    int Val;
    int Min;
    Pair(int Val_, int Min_) : Val(Val_),Min(Min_) {} // необходим для emplace, см. например: https://en.cppreference.com/w/cpp/container/vector/emplace_back 
};

stack<Pair, list<Pair>> Stack;

public:
    MinStack() {}
    
    void push(int val) {
        
        if(Stack.empty()){
            Stack.emplace(val,val);
        }else{
            Stack.emplace(val,min(val, getMin()));
        }

    }
    
    // "Methods pop, top and getMin operations will always be called on non-empty stacks."
    void pop() {
        Stack.pop();
    }
    
    int top() const {
        return Stack.top().Val;
    }
    
    int getMin() const {
        return Stack.top().Min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
