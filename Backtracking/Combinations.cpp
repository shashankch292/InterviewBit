/*
Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.
Example :
If n = 4 and k = 2, a solution is:

[
  [1,2],
  [1,3],
  [1,4],
  [2,3],
  [2,4],
  [3,4],
]

LINK: https://www.interviewbit.com/problems/combinations/
*/

vector<vector<int> > comb;
 
void backtrack(int A, int i, int k, int B, vector<int> &temp)
{
    for(;i<=A;i++)
    {
        temp.push_back(i);
        k++;
        if(k==B)
            comb.push_back(temp);
        backtrack(A, i+1, k, B, temp);
        temp.pop_back();
        k--;
    }
}
 
vector<vector<int> > Solution::combine(int A, int B)
{
    comb.clear();
    vector<int> temp;
 
    backtrack(A, 1, 0, B, temp);
 
    return comb;
}