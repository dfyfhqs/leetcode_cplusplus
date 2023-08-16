/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      auto end = head;
      auto pre = head;
      int count = 0;
      while (count < n && end != nullptr) {
        end = end->next;
        ++count;
      }

      if (count < n) {
        return nullptr;
      }

      if (end == nullptr) {
        return head->next;
      }

      while(end != nullptr && end->next != nullptr) {
        pre = pre->next;
        end = end->next;
        //std::cout << end->val << std::endl;
      }

      //std::cout << pre->next->val;
      if (pre != nullptr && pre->next != nullptr) {
        pre->next = pre->next->next;
      }
      return head;
    }
};
// @lc code=end

