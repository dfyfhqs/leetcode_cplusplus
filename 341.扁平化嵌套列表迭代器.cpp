/*
 * @lc app=leetcode.cn id=341 lang=cpp
 *
 * [341] 扁平化嵌套列表迭代器
 */

// @lc code=start
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    std::vector<int> element_;
    int index_ = 0;


    NestedIterator(vector<NestedInteger> &nestedList) {
        flat(nestedList);
    }

    void flat(const vector<NestedInteger> &nestedList) {
        for (const auto& val : nestedList) {
            if (val.isInteger()) {
                element_.emplace_back(val.getInteger());
                continue;
            }
            flat(val.getList());
        }
    }
    
    int next() {
        return element_[index_++];
    }
    
    bool hasNext() {
        return index_ < element_.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
// @lc code=end

