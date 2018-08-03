/*
Given a collection of numbers, return all possible permutations.

Example:

[1,2,3] will have the following permutations:

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]
 NOTE
No two entries in the permutation sequence should be the same.
For the purpose of this problem, assume that all the numbers in the collection are unique.

LINK: https://www.interviewbit.com/problems/permutations/
*/

vector<vector<int> > res;
 
void getPerm(vector<int> &A, vector<bool> &used, vector<int> &temp, int n)
{
    if(n==0)
    {
        res.push_back(temp);
        return;
    }
 
    for(int i=0;i<A.size();i++)
    {
        if(!used[i])
        {
            used[i]=true;
            temp.push_back(A[i]);
            getPerm(A,used,temp,n-1);
            temp.pop_back();
            used[i]=false;
        }
    }
}
 
vector<vector<int> > Solution::permute(vector<int> &A)
{
    res.clear();
    int n = A.size();
    vector<bool> used(n,false);
    vector<int> temp;
 
    getPerm(A, used, temp, n);
 
    return res;
}