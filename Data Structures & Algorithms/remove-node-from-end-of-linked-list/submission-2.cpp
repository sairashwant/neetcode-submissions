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
        int size = 0;
        ListNode* curr = head;

        while(curr)
        {
            size++;
            curr = curr->next;
        }

        if(size==1)
            return nullptr;

        size = size - (n-1);
        curr = head;

        if(size == 1)
        {
            ListNode* newHead = head->next;
            return newHead;
        }
        int currsize = 0;

        ListNode* prev = nullptr;
        ListNode* nxt = nullptr;

        while(curr)
        {   
            currsize++;
            if(currsize == size-1)
                {
                    prev = curr;
                }

            if(currsize == size+1)
                {
                    nxt = curr;
                }
            curr = curr->next;
        }

        prev->next = nxt;
        return head;
    }
};
