/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets. For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:
(-1, 0, 1)
(-1, -1, 2) 

LINK: https://www.interviewbit.com/problems/3-sum-zero/
*/

vector<vector<int> > Solution::threeSum(vector<int> &A)
{
    sort(A.begin(), A.end());
    int n = A.size();
    vector< vector<int> > res;
 
    for(int i=0;i<n-2;i++)
    {
        while(i<n-2 && A[i]==A[i-1])
            i++;
        if(i>=n-2)
            break;
        int l=i+1, r=n-1;
 
        while(l<r)
        {
            int sum = A[i]+A[l]+A[r];
            if(sum == 0)
            {
                vector<int> v = {A[i],A[l],A[r]};
                res.push_back(v);
                l++;
                while(l<r && A[l]==A[l-1])
                    l++;
            }
            else
            if(sum<0)
                l++;
            else
                r--;
        }
    }
    return res;
}