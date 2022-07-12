/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
      if (head == nullptr || k == 1) return head;

      head = new ListNode(0, head);
      ListNode* node = head;
      ListNode* cur = head->next;
      int count = 0;
      ListNode *label = nullptr;
      while ((count++ < k) && (cur != nullptr)) { 
        if (count == 1) {
          label = cur;
          cur = cur->next;
          label->next = nullptr;
          continue;
        }

        auto* tmpCur = cur->next;
        cur->next = node->next;
        node->next = cur;
        cur = tmpCur;
        label->next = cur;

        if ((cur != nullptr) && (count == k)) {
          count = 0;
          node = label;
        }
      }

      if (count <= k) {
        cur = node->next->next;
        node->next->next = nullptr;
        while(cur != nullptr) {
          auto* tmp = cur->next;
          cur->next = node->next;
          node->next = cur;
          cur = tmp;
        }

      }
      return head->next;
    }
};
// @lc code=end

