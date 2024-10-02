class MinStack {
public:

    long long mini;
    stack<long long> st;

    MinStack() {
        if(!st.empty()){
            st.pop();
        }
        mini = INT_MAX;
    }
    
    void push(int val) {
        long long i = val;
        if(st.empty()){
            st.push(i);
            mini = i;
        }
        else{
            if(i < mini){
                st.push(2 * i * 1LL - mini);
                mini = i;
            }
            else{
                st.push(i);
            }
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        long long temp = st.top();
        st.pop();

        if(temp < mini){
            mini = 2 * mini - temp;
        }
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }

        long long temp = st.top();
        if(temp < mini){
            return mini;
        }

        return temp;
    }
    
    int getMin() {
        return mini;
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