/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

 Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The combinations themselves must be sorted in ascending order.
CombinationA > CombinationB iff (a1 > b1) OR (a1 = b1 AND a2 > b2) OR … (a1 = b1 AND a2 = b2 AND … ai = bi AND ai+1 > bi+1)
The solution set must not contain duplicate combinations.
Example, 
Given candidate set 2,3,6,7 and target 7,
A solution set is:

[2, 2, 3]
[7]

LINK: https://www.interviewbit.com/problems/combination-sum/
*/

vector<vector<int> > comb;
 
void backtrack(vector<int> &A, int i, int sum, int B, vector<int> &temp)
{
    if(sum>=B)
        return;
    for(;i<A.size();i++)
    {
        temp.push_back(A[i]);
        sum += A[i];
        if(sum == B)
            comb.push_back(temp);
        backtrack(A, i, sum, B, temp);
        temp.pop_back();
        sum -= A[i];
    }
}
 
vector<vector<int> > Solution::combinationSum(vector<int> &A, int B)
{
    sort(A.begin(), A.end());
    int i=1;
    while(i<A.size())
    {
        if(A[i]==A[i-1])
            A.erase(A.begin()+i);
        else
            i++;
    }
    comb.clear();
    vector<int> temp;
 
    backtrack(A, 0, 0, B, temp);
 
    return comb;
}