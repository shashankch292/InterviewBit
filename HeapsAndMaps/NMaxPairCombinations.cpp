/*
Given two arrays A & B of size N each.
Find the maximum n elements from the sum combinations (Ai + Bj) formed from elements in array A and B.

For example if A = [1,2], B = [3,4], then possible pair sums can be 1+3 = 4 , 1+4=5 , 2+3=5 , 2+4=6
and maximum 2 elements are 6, 5

Example:

N = 4
a[]={1,4,2,3}
b[]={2,5,1,6}

Maximum 4 elements of combinations sum are
10   (4+6), 
9    (3+6),
9    (4+5),
8    (2+6)

LINK: https://www.interviewbit.com/problems/n-max-pair-combinations/
*/

vector<int> Solution::solve(vector<int> &A, vector<int> &B)
{
    vector<int> res;
 
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
 
    int n = A.size();
 
    priority_queue<pair<int, pair<int, int> > > pq;
    set<pair<int,int> > st;
 
    pq.push({A[n-1]+B[n-1], {n-1, n-1}});
    st.insert({n-1, n-1});
 
    for(int k=0;k<n;k++)
    {
        pair<int, pair<int, int> > pi = pq.top();
        pq.pop();
 
        res.push_back(pi.first);
        int i = pi.second.first;
        int j = pi.second.second;
 
        if(st.find({i-1, j})==st.end())
        {
            st.insert({i-1, j});
            pq.push({A[i-1]+B[j], {i-1, j}});
        }
        if(st.find({i, j-1})==st.end())
        {
            st.insert({i, j-1});
            pq.push({A[i]+B[j-1], {i, j-1}});
        }
    }
    return res;
}