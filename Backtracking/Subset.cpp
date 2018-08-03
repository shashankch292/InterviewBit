/*
Given a set of distinct integers, S, return all possible subsets.

 Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.
Example :

If S = [1,2,3], a solution is:

[
  [],
  [1],
  [1, 2],
  [1, 2, 3],
  [1, 3],
  [2],
  [2, 3],
  [3],
]

LINK: https://www.interviewbit.com/problems/subset/
*/

vector<vector<int> > sets;
 
void backtrack(vector<int> &A, int i, vector<int> temp)
{
    for(;i<A.size();i++)
    {
        vector<int> subset = temp;
        subset.push_back(A[i]);
        sets.push_back(subset);
        backtrack(A, i+1, subset);
    }
}
 
vector<vector<int> > Solution::subsets(vector<int> &A)
{
    sets.clear();
    sort(A.begin(),A.end());
 
    vector<int> temp;
 
    sets.push_back(temp);
 
    backtrack(A, 0, temp);
 
    return sets;
}