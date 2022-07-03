/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      int count = 0;
      ListNode* head = new ListNode();
      ListNode* node = head;

      while (count < lists.size()) {
        count = 0;
        int min_index = INT_MIN;
        for (auto i = 0; i < lists.size(); ++i) {
          auto* val = lists[i];
          if (val == nullptr) {
            ++count;
            continue;
          }
          if (min_index == INT_MIN) {
            min_index = i;
          } else if (val->val < lists[min_index]->val) {
            min_index = i;
          }
        }
        if (min_index == INT_MIN) {
          continue;
        }
        node->next = lists[min_index];
        node = node->next;
        lists[min_index] = node->next;
        node->next = nullptr;
      }
      if (head == node) {
        return nullptr;
      }
      return head->next;
    }
};
// @lc code=end

