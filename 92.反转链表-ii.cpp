/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr) {
            return nullptr;
        }
        return reverseNotStartBetween(head, left, right);
    }

    ListNode* successor_;

    // 从head向后反转n个元素
    ListNode* reverseN(ListNode* head, int n) {
        if (head->next == nullptr || n == 1) {
            successor_ = head->next;
            return head;
        }
        auto lastNode = reverseN(head->next, n-1);
        head->next->next = head;
        head->next = successor_;
        return lastNode;
    }

    ListNode* reverseNotStartBetween(ListNode* head, int left, int right) {
        if (head->next == nullptr) {
            return head;
        }
        successor_ = nullptr;
        if (left == 1) {
            return reverseN(head, right-left+1);
        }
        head->next = reverseNotStartBetween(head->next, left-1, right-1);
        return head;
    }


};
// @lc code=end

