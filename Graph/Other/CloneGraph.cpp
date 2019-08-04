/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
void solve(UndirectedGraphNode *node,unordered_map<int,UndirectedGraphNode*> &m){
    UndirectedGraphNode* x = new UndirectedGraphNode(node->label);
    m[node->label] = x;
    for(UndirectedGraphNode* y:node->neighbors){
        if(m.count(y->label)==0){
            solve(y,m);
        }
        x->neighbors.emplace_back(m[y->label]);
    }
}
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    unordered_map<int,UndirectedGraphNode*> m;
    UndirectedGraphNode* x = new UndirectedGraphNode(node->label);
    m[node->label] = x;
    for(UndirectedGraphNode* y:node->neighbors){
        if(m.count(y->label)==0){
            solve(y,m);
        }
        x->neighbors.emplace_back(m[y->label]);
    }
    return x;
}
