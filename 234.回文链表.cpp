/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* left_;
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) {
            return true;
        }
        left_ = head;
        return helper(head);
    }
    bool helper(ListNode* head) {
        if (head == nullptr) {
            return true;
        }
        if (!helper(head->next)) {
            return false;
        }
        if (head->val != left_->val) {
            return false;
        }
        left_ = left_->next;
        return true;
    }
};
// @lc code=end

