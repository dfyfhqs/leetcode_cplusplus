/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* t1 = l1;
      ListNode* t2 = l2;
      ListNode* head = new ListNode();
      ListNode* current = head;
       
      int carry = 0;
      while(t1 != nullptr || t2 != nullptr || carry > 0) {
        int sum = carry;
        if (t1 != nullptr) {
          sum += t1->val;
          t1 = t1->next;
        }
        if (t2 != nullptr) {
          sum += t2->val;
          t2 = t2->next;
        }
        carry = sum / 10;
        current->next = new ListNode(sum % 10);;
        current = current->next;
      }
      return head->next;
    }
};
// @lc code=end

