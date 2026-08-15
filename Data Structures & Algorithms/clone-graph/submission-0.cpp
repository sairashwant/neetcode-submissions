/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {

        if(node == nullptr)
            return nullptr;
        queue<Node*> q;
        unordered_map<Node*, Node*> hashmap;
        hashmap[node] = new Node(node->val);
        q.push(node);

        while(!q.empty())
        {
        
            Node* old = q.front(); 
            q.pop();

            for( auto nei : old->neighbors)
                {
                    if(hashmap.find(nei) == hashmap.end())
                        {
                            hashmap[nei] = new Node(nei->val);
                            q.push(nei);
                        }
                    hashmap[old]->neighbors.push_back(hashmap[nei]);
                }
                
        }

        return hashmap[node];
    }
};
