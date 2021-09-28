/*
Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

class Node {
    public int val;
    public List<Node> neighbors;
}
 

Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.
*/




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

//BFS
unordered_map<Node*,Node*>copies; 

Node* cloneGraph(Node* node)
{
    if(!node) return NULL; 

    Node* copy = new Node(node->val, {}); 

    copies[node] = copy; 
    queue<Node*>Q; 
    Q.push(node);
    while(!Q.empty())
    {
        Node* curr = Q.front(); 
        Q.pop(); 
        for(Node* neighbor : curr->neighbors){
            if(copies.find(neighbor) == copies.end()){
                copies[neighbor] = new Node(neighbor->val, {}); 
                Q.push(neighbor); 
            }
            copies[curr]->neighbors.push_back(copies[neighbor]); 
        }
    }
    return copy; 
}

//DFS
unordered_map<Node*, Node*>copies; 
Node* cloneGraph(Node* node)
{
    if(!node)
    return; 

    if(copies.find(node) == copies.end()){
        copies[node] = new Node(node->val, {}); 
        for(Node* neighbor : node->neighbors)
            copies[node]->neighbors.push_back(cloneGraph(neighbor)); 
    }
    return copies[node]; 
}