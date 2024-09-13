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
    void reorderList(ListNode* head) {
        if(head == NULL || head-> next == NULL || head->next->next == NULL){
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head-> next;

        while(fast != NULL && fast-> next != NULL){
            slow = slow-> next;
            fast = fast->next->next;
        }

        ListNode* curr = slow-> next;
        slow-> next = NULL;

        ListNode* prev = NULL;

        while(curr != NULL){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        ListNode* head1 = head;
        ListNode* head2 = prev;

        while(head2 != NULL){
           ListNode* temp1 = head1-> next;
           ListNode* temp2 = head2-> next;

           head1->next = head2;
           head2->next = temp1;

           head1 = temp1;
           head2 = temp2;
        }
    }
};