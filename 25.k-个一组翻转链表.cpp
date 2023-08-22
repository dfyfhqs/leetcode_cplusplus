/*
 * @Author: stone stone
 * @Date: 2023-08-03 23:35:47
 * @LastEditors: stone stone
 * @LastEditTime: 2023-08-20 20:09:08
 * @FilePath: /leetcode_cplusplus/25.k-个一组翻转链表.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
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
      ListNode* start = head, *end = head;
      ListNode* result = nullptr;
      int count = 0;
      while (end != nullptr) {
        if (count == k) {
          end = end->next;
          count = 0;
          auto* curhead = Reverse(start, end);
          if (result != nullptr) {
            result = curhead;
          }
          start->next = Reverse(start, end);
          start = end;
        } else if (count < k) {
          end = end + 1;
          count++;
        }
      }
      return result;
    }

    ListNode* Reverse(ListNode* start, ListNode* end) {
      ListNode* pre = nullptr, *cur = start, *next = start;
      while (start != end) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
      }
      return pre;
    }

};
// @lc code=end

