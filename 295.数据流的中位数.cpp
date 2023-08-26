/*
 * @Author: stone stone
 * @Date: 2023-08-26 20:10:52
 * @LastEditors: stone stone
 * @LastEditTime: 2023-08-26 20:44:42
 * @FilePath: /leetcode_cplusplus/295.数据流的中位数.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 *
 * https://leetcode.cn/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (53.55%)
 * Likes:    862
 * Dislikes: 0
 * Total Accepted:    113.5K
 * Total Submissions: 212K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n' +
  '[[],[1],[2],[],[3],[]]'
 *
 * 中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。
 * 
 * 
 * 例如 arr = [2,3,4] 的中位数是 3 。
 * 例如 arr = [2,3] 的中位数是 (2 + 3) / 2 = 2.5 。
 * 
 * 
 * 实现 MedianFinder 类:
 * 
 * 
 * 
 * MedianFinder() 初始化 MedianFinder 对象。
 * 
 * 
 * void addNum(int num) 将数据流中的整数 num 添加到数据结构中。
 * 
 * 
 * double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10^-5 以内的答案将被接受。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入
 * ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
 * [[], [1], [2], [], [3], []]
 * 输出
 * [null, null, null, 1.5, null, 2.0]
 * 
 * 解释
 * MedianFinder medianFinder = new MedianFinder();
 * medianFinder.addNum(1);    // arr = [1]
 * medianFinder.addNum(2);    // arr = [1, 2]
 * medianFinder.findMedian(); // 返回 1.5 ((1 + 2) / 2)
 * medianFinder.addNum(3);    // arr[1, 2, 3]
 * medianFinder.findMedian(); // return 2.0
 * 
 * 提示:
 * 
 * 
 * -10^5 <= num <= 10^5
 * 在调用 findMedian 之前，数据结构中至少有一个元素
 * 最多 5 * 10^4 次调用 addNum 和 findMedian
 * 
 * 
 */

// @lc code=start
class MedianFinder {
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
      first_.push(num);
      sec_.push(first_.top());
      first_.pop();
      if (sec_.size() > first_.size()) {
        first_.push(sec_.top());
        sec_.pop();
      }
      // cout << "add num: " << num <<  " first: " << first_.size() << " second: " << sec_.size() << endl;
    }
    
    double findMedian() {
      // cout << "first: " << first_.top() << " second: " << sec_.top() << endl;
      if (first_.size() == sec_.size()) {
        return (first_.top() + sec_.top()) * 1.0 / 2;
      }
      return first_.top();
    }
    std::priority_queue<int, vector<int>, less<int>> first_;  // 大顶堆
    std::priority_queue<int, vector<int>, greater<int>> sec_;  // 小顶堆
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

