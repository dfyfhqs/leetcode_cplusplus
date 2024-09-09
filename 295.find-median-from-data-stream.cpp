// @leet start
class MedianFinder {
 public:
  MedianFinder() {}

  void addNum(int num) {
    if (first_queue_.empty()) {
      first_queue_.push(num);
      // cout << "num: " << num << " first size: " << first_queue_.size()
      //      << " sec size: " << sec_queue_.size()
      //      << " first top: " << first_queue_.top() << endl;
      return;
    }
    if (num > first_queue_.top()) {
      sec_queue_.push(num);
      if (sec_queue_.size() > first_queue_.size()) {
        first_queue_.push(sec_queue_.top());
        sec_queue_.pop();
      }
    } else {
      first_queue_.push(num);
      if (first_queue_.size() > sec_queue_.size() + 1) {
        sec_queue_.push(first_queue_.top());
        first_queue_.pop();
      }
    }
    // cout << "num: " << num << " first size: " << first_queue_.size()
    //      << " sec size: " << sec_queue_.size()
    //      << " first top: " << first_queue_.top()
    //      << " sec top: " << sec_queue_.top() << endl;
  }

  double findMedian() {
    // cout << "findmedian: " << endl;
    // cout << " first size: " << first_queue_.size()
    //      << " sec size: " << sec_queue_.size()
    //      << " first top: " << first_queue_.top();
    // if (sec_queue_.empty()) {
    //   cout << endl;
    // } else {
    //   cout << " sec top: " << sec_queue_.top() << endl;
    // }

    if (first_queue_.size() == sec_queue_.size()) {
      return double((first_queue_.top() + sec_queue_.top())) / 2;
    }
    // cout << " 2: " << endl;
    return double(first_queue_.top());
  }
  // 大端堆
  priority_queue<int, vector<int>, std::less<int>> first_queue_;
  // 小端堆
  priority_queue<int, vector<int>, std::greater<int>> sec_queue_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @leet end
