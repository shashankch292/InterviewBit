/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.
Example :
If S = [1,2,2], the solution is:

[
[],
[1],
[1,2],
[1,2,2],
[2],
[2, 2]
]

LINK: https://www.interviewbit.com/problems/subsets-ii/
*/

set<vector<int> > sets;
 
void backtrack(vector<int> &A, int i, vector<int> temp)
{
    for(;i<A.size();i++)
    {
        vector<int> subset = temp;
        subset.push_back(A[i]);
        sets.insert(subset);
        backtrack(A, i+1, subset);
    }
}
 
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A)
{
    sets.clear();
    sort(A.begin(),A.end());
 
    vector<int> temp;
 
    sets.insert(temp);
 
    backtrack(A, 0, temp);
 
    vector<vector<int> > res;
 
    set<vector<int> >::iterator it = sets.begin();
 
    for(;it!=sets.end();it++)
        res.push_back(*it);
 
    return res;
}