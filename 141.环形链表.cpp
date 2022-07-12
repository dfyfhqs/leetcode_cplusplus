/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
      if (head == nullptr) {
        return false;
      }
      ListNode* first = head;
      ListNode* second = first;
      while (first != nullptr && first->next != nullptr) {
        first = first->next->next;
        second = second->next;
        if (first != nullptr && (first == second)) {
          return true;
        }
      }
      return false;
    }
};
// @lc code=end

