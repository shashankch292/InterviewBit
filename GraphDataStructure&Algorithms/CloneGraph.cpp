/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

LINK: https://www.interviewbit.com/problems/clone-graph/
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node)
{
    if(node == NULL)
        return node;
 
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
    queue<UndirectedGraphNode*> q;
 
    UndirectedGraphNode* src = new UndirectedGraphNode(node->label);
    mp[node] = src;
 
    q.push(node);
 
    while(!q.empty())
    {
        UndirectedGraphNode* u = q.front();
        q.pop();
 
        vector<UndirectedGraphNode*> v = u->neighbors;
        int n = v.size();
 
        for(int i=0;i<n;i++)
        {
            if(mp[v[i]] == NULL)
            {
                UndirectedGraphNode* temp = new UndirectedGraphNode(v[i]->label);
                mp[v[i]] = temp;
                q.push(v[i]);
            }
 
            mp[u]->neighbors.push_back(mp[v[i]]);
        }
    }
 
    return src;
}