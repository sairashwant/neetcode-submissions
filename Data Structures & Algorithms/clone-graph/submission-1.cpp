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
        unordered_map<Node*, Node*> nodeMap;

        nodeMap[node] = new Node(node->val);

        q.push(node);

        while(!q.empty())
        {
            auto oldNode = q.front();
            q.pop();

            for(auto nei : oldNode->neighbors)
            {
                if(nodeMap.find(nei) == nodeMap.end())
                {
                    nodeMap[nei] = new Node(nei->val);
                    q.push(nei);
                }

                nodeMap[oldNode]->neighbors.push_back(nodeMap[nei]);
            }

        }
        return nodeMap[node];
    }
};
