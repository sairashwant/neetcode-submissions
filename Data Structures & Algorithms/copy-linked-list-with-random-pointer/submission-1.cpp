/*
// Definition for a Node.
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
        
        unordered_map<Node*, Node*> CopyMap;
        
        Node* copy = new Node(0);
        Node* currCopy = copy;
        Node* curr = head;

        while(curr)
        {
            Node* newNode = new Node(curr->val);
            currCopy->next = newNode;
            CopyMap[curr] = newNode;
            curr = curr->next;
            currCopy = currCopy->next;
        }

        currCopy = copy->next;
        curr = head;
        while(currCopy)
        {
            if(curr->random != nullptr)
                currCopy->random = CopyMap[curr->random];

            curr = curr->next;
            currCopy = currCopy->next;
        }

        return copy->next;
    }
};
