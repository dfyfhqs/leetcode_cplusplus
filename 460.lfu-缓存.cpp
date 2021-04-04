/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

// @lc code=start
struct Node {
public:
    Node(int key, int val, int freq) :
        key_(key), val_(val), freq_(freq) {};
    int key_;
    int val_;
    int freq_;
}; // struct Node 

class LFUCache {
public:
    std::unordered_map<int, list<Node>::iterator> keyNode_; // key to node
    unordered_map<int, list<Node> > freqTable_;  // freq to node
    int cap_;
    int minFreq_;
public:
    LFUCache(int capacity) {
        cap_ = capacity;
    }
    
    int get(int key) {
        if (cap_ == 0) {
            return -1;
        }
        auto findIter = keyNode_.find(key);
        if (findIter == keyNode_.end()) {
            return -1;
        }
        list<Node>::iterator iter = findIter->second;
        Node curNode = *(keyNode_[key]);
        freqTable_[curNode.freq_].erase(iter);
        if (freqTable_[curNode.freq_].empty()) {
            freqTable_.erase(curNode.freq_);
            if (minFreq_ == curNode.freq_) {
                minFreq_ += 1;
            }
        }
        curNode.freq_ += 1;
        freqTable_[curNode.freq_].push_front(curNode);
        keyNode_[key] = freqTable_[curNode.freq_].begin();
        return curNode.val_;
    }
    
    void put(int key, int value) {
        if(cap_== 0) {
           return;
        }
        auto findIter = keyNode_.find(key);
        Node curNode(key, value, 1);
        if (findIter == keyNode_.end()) {
            if (keyNode_.size() == cap_) {
                auto curkey = freqTable_[minFreq_].rbegin()->key_;
                freqTable_[minFreq_].pop_back();
                keyNode_.erase(curkey);
                if (freqTable_[minFreq_].empty()) {
                    freqTable_.erase(minFreq_);
                }
            }
            minFreq_ = 1;
            freqTable_[minFreq_].push_front(curNode);
            keyNode_[key] = freqTable_[minFreq_].begin();
            return;
        } else {
            findIter->second->val_ = value;
            get(key);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

