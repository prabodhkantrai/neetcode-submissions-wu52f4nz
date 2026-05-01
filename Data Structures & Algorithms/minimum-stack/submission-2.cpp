class MinStack {
public:
    stack<int> st;
    stack<int> minSet;
    int currMin = INT_MAX;

    MinStack() {
    }
    
    void push(int val) {
        this->st.push(val);
        if (val < this->currMin) this->currMin = val;
        this->minSet.push(this->currMin);
    }
    
    void pop() {
        this->st.pop();
        this->minSet.pop();
        this->currMin = minSet.size() == 0? INT_MAX : minSet.top();
    }
    
    int top() {
        return this->st.top();
    }
    
    int getMin() {
        return this->minSet.top();
    }
};
