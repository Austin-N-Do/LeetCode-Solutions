#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
private:
    stack<int> st;       // main stack for values
    stack<int> minSt;    // stack to keep track of minimums

public:
    MinStack() {
        // no initialization needed
    }
    
    void push(int val) {
        st.push(val);
        // If minSt is empty or val <= current minimum, push it
        if (minSt.empty() || val <= minSt.top())
            minSt.push(val);
        else
            minSt.push(minSt.top()); // duplicate current min for O(1) retrieval
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
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