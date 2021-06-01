/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
public:
    stack<int> input_, output_;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        input_.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        SwapStack(input_, output_);
        int result = output_.top();
        output_.pop();
        SwapStack(output_, input_);
        return result;
    }
    
    /** Get the front element. */
    int peek() {
        SwapStack(input_, output_);
        int result = output_.top();
        SwapStack(output_,input_);
        return result;
    }
    
    bool SwapStack(stack<int>& input, stack<int>& output) {
        if (output.empty()) {
            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
            return true;
        }
        return false;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return input_.empty() && output_.empty();
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
// @lc code=end