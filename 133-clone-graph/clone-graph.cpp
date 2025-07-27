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
        if(!node) return nullptr;

        unordered_map<Node*,Node*> vis;

        queue<Node*> q;

        Node* newNode = new Node(node->val);
        vis[node] = newNode;
        q.push(node);

        while(!q.empty()){
            Node* u = q.front();

            q.pop();
            
            Node* clone_u = vis[u]; 
            
            for(auto &v: u->neighbors){
                if(vis.find(v) == vis.end()){
                    Node* clone_v = new Node(v->val);
                    vis[v] = clone_v;
                    q.push(v);
                }
                clone_u->neighbors.push_back(vis[v]);
            }
        }

        return newNode;

    }
};