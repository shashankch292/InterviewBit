/*
There are n islands and there are many bridges connecting them. Each bridge has some cost attached to it.

We need to find bridges with minimal cost such that all islands are connected.

It is guaranteed that input data will contain at least one possible scenario in which all islands are connected with each other.

Example :
Input

         Number of islands ( n ) = 4
         1 2 1 
         2 3 4
         1 4 3
         4 3 2
         1 3 10
In this example, we have number of islands(n) = 4 . Each row then represents a bridge configuration. In each row first two numbers represent the islands number which are connected by this bridge and the third integer is the cost associated with this bridge.

In the above example, we can select bridges 1(connecting islands 1 and 2 with cost 1), 3(connecting islands 1 and 4 with cost 3), 4(connecting islands 4 and 3 with cost 2). Thus we will have all islands connected with the minimum possible cost(1+3+2 = 6). 
In any other case, cost incurred will be more.

LINK: https://www.interviewbit.com/problems/commutable-islands/
*/

int Rank[1000005];
int Parent[1000005];
 
int Find(int x)
{
    if(x!=Parent[x])
        Parent[x] = Find(Parent[x]);
    return Parent[x];
}
 
int Union(int u, int v, int cost)
{
    int x = Find(u);
    int y = Find(v);
 
    if(x==y)
        return 0;
 
    if(Rank[x] > Rank[y])
    {
        Parent[y] = x;
        Rank[x] += Rank[y];
    }
    else
    {
        Parent[x] = y;
        Rank[y] += Rank[x];
    }
 
    return cost;
}
 
bool comp(const vector<int> &a, const vector<int> &b)
{
    return a[2] < b[2];
}
 
int Solution::solve(int A, vector<vector<int> > &B)
{
    for(int i=0;i<A;i++)
    {
        Parent[i] = i;
        Rank[i] = 1;
    }
 
    sort(B.begin(), B.end(), comp);
 
    int n = B.size();
    int ans = 0;
 
    for(int i=0;i<n;i++)
        ans += Union(B[i][0]-1, B[i][1]-1, B[i][2]);
 
    return ans;
}