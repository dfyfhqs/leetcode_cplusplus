/*
 * @lc app=leetcode.cn id=895 lang=cpp
 *
 * [895] 最大频率栈
 */

// @lc code=start
class FreqStack {
public:
    int max_freq_ = 0;
    std::unordered_map<int, int> val_2_freq_map_;
    std::unordered_map<int, std::stack<int>>  freq_2_val_map_;

    FreqStack() {
    }
    
    void push(int val) {
        auto find_iter = val_2_freq_map_.find(val);
        if (find_iter != val_2_freq_map_.end()) {
            freq_2_val_map_[0].push(val);
            return;
        }
    }
    
    int pop() {
        if 
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end

