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
        
        vector<ListNode*> nodes;
        ListNode* curr = head;

        while(curr)
        {
            nodes.push_back(curr);
            curr = curr->next;
        }

        int pos = 0;

        if(nodes.size() == n)
        {
            return nodes.size() > 1 ? nodes[1] : nullptr;
        }
        for(int i = nodes.size()-1; i >= 0; i--)
        {
            pos++;
            if(pos == n)
            {
                if(i == nodes.size()-1)
                    nodes[i-1]->next = nullptr;
                
                else
                    nodes[i-1]->next = nodes[i+1];
            }
        }

        return head;
    }
};
