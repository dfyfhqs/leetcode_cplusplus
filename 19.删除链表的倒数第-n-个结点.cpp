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
      if (head == nullptr) return head;
      ListNode* first, *second;
      first = second = head;
      while ((second != nullptr) && (n-- > 0)) {
        second = second->next;
      }

      // n > 队列长度
      if (n > 0) {
        return head;
      }

      // n == 队列长度 则删除头结点
      if (second == nullptr) {
        return head->next;
      }

      // n < 队列长度，获取倒数n+1个节点，删除倒数n个点解
      while (second->next != nullptr) {
        second = second->next;
        first = first->next;
      }
      first->next = first->next->next;
      return head;
    }
};
// @lc code=end

