/*
You are given the following :

A positive number N
Heights : A list of heights of N persons standing in a queue
Infronts : A list of numbers corresponding to each person (P) that gives the number of persons who are taller than P and standing in front of P
You need to return list of actual order of persons’s height

Consider that heights will be unique

Example

Input : 
Heights: 5 3 2 6 1 4
InFronts: 0 1 2 0 3 2
Output : 
actual order is: 5 3 2 1 6 4 
So, you can see that for the person with height 5, there is no one taller than him who is in front of him, and hence Infronts has 0 for him.

For person with height 3, there is 1 person ( Height : 5 ) in front of him who is taller than him.

You can do similar inference for other people in the list.

LINK: https://www.interviewbit.com/problems/order-of-people-heights/
*/

/////////////////////////////////////////////////////////////
// Using Segment Tree | Complexity-> O(NlogN)
/////////////////////////////////////////////////////////////

int *SegTree;
 
void build(int node, int start, int end)
{
    if(start==end)
        SegTree[node] = 1;
    else
    {
        int mid = (start+end)/2;
        build(2*node+1, start, mid);
        build(2*node+2, mid+1, end);
        SegTree[node] = SegTree[2*node+1] + SegTree[2*node+2];
    }
}
 
void update(int node, int start, int end, int ind, int val)
{
    if(start==end)
        SegTree[node] = val;
    else
    {
        int mid = (start+end)/2;
        if(ind<=mid)
            update(2*node+1, start, mid, ind, val);
        else
            update(2*node+2, mid+1, end, ind, val);
        SegTree[node] = SegTree[2*node+1] + SegTree[2*node+2];
    }
}
 
int query(int node, int start ,int end, int spaces)
{
    if(start>end)
        return -1;
    if(start==end)
        return start;
 
    int leftspace = SegTree[node*2+1];
    int rightspace = SegTree[node*2+2];
 
    int mid = (start+end)/2;
 
    if(leftspace >= spaces)
        return query(node*2+1, start, mid, spaces);
    else
        return query(node*2+2, mid+1, end, spaces-leftspace);
}
 
vector<int> Solution::order(vector<int> &A, vector<int> &B)
{
    vector<pair<int,int> > v;
    int n = A.size();
 
    for(int i=0;i<n;i++)
        v.push_back({A[i],B[i]});
 
    sort(v.begin(), v.end());
 
    vector<int> res(n);
 
    SegTree = new int[4*n];
    memset(SegTree,1,sizeof(SegTree));
    build(0,0,n-1);
 
    for(int i=0;i<n;i++)
    {
        int ind = query(0,0,n-1,v[i].second+1);
        res[ind] = v[i].first;
        update(0,0,n-1,ind,0);
    }
 
    return res;
}

/////////////////////////////////////////////////////////////
// Using Sorting Only | Complexity-> O(N^2)
/////////////////////////////////////////////////////////////

vector<int> Solution::order(vector<int> &A, vector<int> &B)
{
    vector<pair<int,int> > v;
    int n = A.size();
 
    for(int i=0;i<n;i++)
        v.push_back({A[i],B[i]});
 
    sort(v.rbegin(), v.rend());
 
    vector<int> res;
 
    for(int i=0;i<n;i++)
    {
        int ind = v[i].second;
        if(ind<res.size())
            res.insert(res.begin()+ind,v[i].first);
        else
            res.push_back(v[i].first);
    }
    return res;
}