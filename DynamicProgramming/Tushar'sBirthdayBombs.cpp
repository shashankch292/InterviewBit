/*
It’s Tushar’s birthday today and he has N friends. Friends are numbered [0, 1, 2, …., N-1] and i-th friend have a positive strength S(i). Today being his birthday, his friends have planned to give him birthday bombs (kicks :P). Tushar’s friends know Tushar’s pain bearing limit and would hit accordingly.
If Tushar’s resistance is denoted by R (>=0) then find the lexicographically smallest order of friends to kick Tushar so that the cumulative kick strength (sum of the strengths of friends who kicks) doesn’t exceed his resistance capacity and total no. of kicks hit are maximum. Also note that each friend can kick unlimited number of times (If a friend hits x times, his strength will be counted x times)

Note:

Answer format = Vector of indexes of friends in the order in which they will hit.
Answer should have the maximum no. of kicks that can be possibly hit. If two answer have the same no. of kicks, return one with the lexicographically smaller.
[a1, a2, …., am] is lexicographically smaller than [b1, b2, .., bm] if a1 < b1 or (a1 = b1 and a2 < b2) … .
Input cases are such that the length of the answer does not exceed 100000.
Example:
R = 11, S = [6,8,5,4,7]

ans = [0,2]
Here, [2,3], [2,2] or [3,3] also give the maximum no. kicks.

LINK: https://www.interviewbit.com/problems/tushars-birthday-bombs/
*/

vector<int> res;
int n, len;
 
void kicks(int i, vector<pair<int,int> > &v, int s)
{
    if(i==n)
        return;
 
    int Nlen = res.size() + 1 + (s-v[i].first)/v[n-1].first;
 
    if(s >= v[i].first && Nlen == len)
    {
        res.push_back(v[i].second);
        kicks(i, v, s-v[i].first);
    }
    else
        kicks(i+1, v, s);
}
 
vector<int> Solution::solve(int A, vector<int> &B)
{
    res.clear();
    n = B.size();
 
    vector<pair<int,int> > newB;
 
    int minInd = 0;
    newB.push_back({B[minInd],0});
 
    for(int i=1;i<n;i++)
    {
        if(B[i] < B[minInd])
        {
            minInd = i;
            newB.push_back({B[i],i});
        }
    }
 
    len = A/B[minInd];
 
    n = newB.size();
 
    kicks(0, newB, A);
 
    return res;
}