class MinStack {
public:
    vector<int> stack_vector;
    vector<int> min_stack_vector;
    MinStack() {
       
    }
 
    void push(int val) {
        stack_vector.push_back(val);
        if (min_stack_vector.empty() || min_stack_vector.back() >= val)
            min_stack_vector.push_back(val);
        
    }
 
    void pop() {
        
        if (stack_vector.back() == min_stack_vector.back())
        {
            min_stack_vector.pop_back();
        }
        stack_vector.pop_back();
       
    }
 
    int top() {
        return stack_vector.back();
    }
 
    int getMin() {
        return min_stack_vector.back();
    }
 
};