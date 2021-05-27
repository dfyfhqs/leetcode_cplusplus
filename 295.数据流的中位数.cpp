/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
class MedianFinder {
public:
    int cnt_ = 0;
    priority_queue<int, std::vector<int>, std::less<int>> left_queue_; // 大跟堆
    priority_queue<int, std::vector<int>, std::greater<int>> right_queue_; // 小跟堆

    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        if (cnt_ % 2 == 0) {  // 偶数
            right_queue_.push(num);
            left_queue_.push(right_queue_.top());
            right_queue_.pop();
        } else {
            left_queue_.push(num);
            right_queue_.push(left_queue_.top());
            left_queue_.pop();
        }
        cnt_ += 1;
    }
    
    double findMedian() {
        if ((cnt_ % 2) != 0) {
            return (double)(left_queue_.top());
        } else {
            return (double(left_queue_.top() + right_queue_.top())) / 2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

