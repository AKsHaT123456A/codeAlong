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
    void reverse(ListNode*& head, ListNode* current, ListNode* prev) {
        if (current == nullptr) {
            head = prev;
            return;
        }
        ListNode* nextNode = current->next;
        current->next = prev;
        reverse(head, nextNode, current);
    }

    ListNode* reverseList(ListNode* head) {
        reverse(head, head, nullptr);
        return head;
    }
};
