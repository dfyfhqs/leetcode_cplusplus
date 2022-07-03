// 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
// 输入：l1 = [], l2 = []
// 输出：[]

// 输入：l1 = [1,2,4], l2 = [1,3,4]
// 输出：[1,1,2,3,4,4]


/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode* head = new ListNode();
      ListNode* node = head;
      while (list1 != nullptr && list2 != nullptr) {
        ListNode* cur = nullptr;
        if (list1->val < list2->val) {
          cur = list1;
          list1 = list1->next;
        } else {
          cur = list2;
          list2 = list2->next;
        }
        cur->next = nullptr;
        node->next = cur;
        node = cur;
      }

      if (list1) {
        node->next = list1;
      } else {
        node->next = list2;
      }
      return head->next;
    }
};
// @lc code=end

