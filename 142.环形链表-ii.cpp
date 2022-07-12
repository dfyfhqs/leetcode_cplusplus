/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
    ListNode *detectCycle(ListNode *head) {
      if (head == nullptr) return nullptr;
      if (head->next == nullptr) return nullptr;

      ListNode *first, *second;
      first = second = head;
      while (first != nullptr && first->next != nullptr) {
        first = first->next->next;
        second = second->next;
        if (first == second) {
          break;
        }
      }

      if (first == nullptr || first->next == nullptr) {
        return nullptr;
      }

      second = head;
      while (first != second) {
        first = first->next;
        second = second->next;
      }
      return first;
    }
};
// @lc code=end

