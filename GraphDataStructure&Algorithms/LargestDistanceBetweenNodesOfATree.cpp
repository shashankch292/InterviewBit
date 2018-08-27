/*
Find largest distance
Given an arbitrary unweighted rooted tree which consists of N (2 <= N <= 40000) nodes. The goal of the problem is to find largest distance between two nodes in a tree. Distance between two nodes is a number of edges on a path between the nodes (there will be a unique path between any pair of nodes since it is a tree). The nodes will be numbered 0 through N - 1.

The tree is given as an array P, there is an edge between nodes P[i] and i (0 <= i < N). Exactly one of the i’s will have P[i] equal to -1, it will be root node.

 Example:
If given P is [-1, 0, 0, 0, 3], then node 0 is the root and the whole tree looks like this: 
          0
       /  |  \
      1   2   3
               \
                4  
 One of the longest path is 1 -> 0 -> 3 -> 4 and its length is 3, thus the answer is 3. Note that there are other paths with maximal distance. 

LINK: https://www.interviewbit.com/problems/largest-distance-between-nodes-of-a-tree/
*/

int ans;
 
int maxLen(int u, vector<int> adj[], int p)
{
    vector<int> v;
 
    for(auto x : adj[u])
    {
        if(x!=p)
        {
            v.push_back(maxLen(x, adj, u));
        }
    }
 
    int nv = v.size();
 
    if(nv == 0)
    {
        ans = max(ans, 1);
        return 1;
    }
 
    if(nv == 1)
    {
        ans = max(ans, v[0] + 1);
        return v[0] + 1;
    }
 
    sort(v.rbegin(), v.rend());
 
    ans = max(ans, v[0] + v[1] + 1);
    return v[0] + 1;
}
 
int Solution::solve(vector<int> &A)
{
    int n = A.size();
 
    vector<int> adj[n];
 
    for(int i=0;i<n;i++)
    {
        if(A[i] == -1)
            continue;
 
        adj[A[i]].push_back(i);
        adj[i].push_back(A[i]);
    }
 
    ans = INT_MIN;
 
    maxLen(0, adj, -1);
 
    return ans-1;
}