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
    int getDecimalValue(ListNode* head) {
        int ans=0;
        int len=0;
        ListNode* temp=head;
        while(temp->next!=NULL){
            len++;
            temp=temp->next;
        }
        temp=head;
        while(temp!=NULL){
            ans+=pow(2,len--)*(temp->val);
            temp=temp->next;
        }
        return ans;
    }
};