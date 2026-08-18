/*
// Definition for a Node.w
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        unordered_map<Node*, Node*> copyMap;

        Node* headCopy = new Node(0);
        Node* currCopy = headCopy;
        Node* curr = head;
        
        while(curr)
        {
            currCopy->next = new Node(curr->val);
            copyMap[curr] = currCopy->next;
            curr = curr->next;
            currCopy = currCopy->next;
        }

        currCopy = headCopy->next;
        curr = head;

        while(currCopy)
        {
            if(curr->random != nullptr)
                currCopy->random = copyMap[curr->random];

            curr = curr->next;
            currCopy = currCopy->next;
        } 

        return headCopy->next;
    }
};
