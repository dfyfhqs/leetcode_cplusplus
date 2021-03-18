/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        return normalReverseList(head);
    }

    ListNode* normalReverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode pre;
        while(head) {
            auto next = head->next;
            head->next = pre.next;
            pre.next = head;
            head = next;
        }
        return pre./Users/mac/code/gitlab/leetcode_cplusplus/206.反转链表.cppnext;
    }
};
// @lc code=end

