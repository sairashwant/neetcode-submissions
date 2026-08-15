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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1 = 0;
        int num2 = 0;
        
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;

        //Calculating size
        int i = 0;
        while(curr1)
        {
            num1 = num1 + (curr1->val * pow(10,i++));
            curr1 = curr1->next;
        }
        i=0;
        while(curr2)
        {
            num2 = num2 + (curr2->val * pow(10,i++));
            curr2 = curr2->next;
        }

        int sum = num1 + num2;
        cout<<"Num1: "<<num1<<endl;
        cout<<"Num2: "<<num2<<endl;
        ListNode* dummy = new ListNode();
        ListNode* res = dummy;
        
        if(sum == 0)
        {
            res->next = new ListNode(0);
            res = res->next;
        }
        
        while(sum)
        {
            int digit = sum % 10;
            res->next = new ListNode(digit);
            res = res->next;
            sum = sum/10;            
        }

        
        return dummy->next;
    }
};
