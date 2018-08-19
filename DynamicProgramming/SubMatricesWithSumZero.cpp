/*
Given a 2D matrix, find the number non-empty sub matrices, such that the sum of the elements inside the sub matrix is equal to 0. (note: elements might be negative).

Example:

Input

-8 5  7
3  7 -8
5 -8  9
Output
2

Explanation
-8 5 7
3 7 -8
5 -8 9

-8 5 7
3 7 -8
5 -8 9

LINK: https://www.interviewbit.com/problems/sub-matrices-with-sum-zero/
*/

int res;
 
void maxZero(int temp[], int n)
{
    unordered_map<int,int> mp;
    mp[0] = 1;
    int sum = 0;
 
    for(int i=0;i<n;i++)
    {
        sum += temp[i];
 
        if(mp.find(sum) != mp.end())
        {
            res += mp[sum];
            mp[sum]++;
        }
        else
        {
            mp[sum] = 1;
        }
    }
}
 
int Solution::solve(vector<vector<int> > &A)
{
    res = 0;
 
    int r = A.size();
    if(r==0)
        return res;
 
    int c = A[0].size();
    if(c==0)
        return res;
 
    int temp[r];
 
    for(int i=0;i<c;i++)
    {
        memset(temp,0,sizeof(temp));
 
        for(int j=i;j<c;j++)
        {
            for(int k=0;k<r;k++)
                temp[k] += A[k][j];
 
            maxZero(temp, r);
        }
    }
    return res;
}