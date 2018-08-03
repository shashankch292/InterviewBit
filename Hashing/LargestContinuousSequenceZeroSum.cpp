/*
Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

 NOTE : If there are multiple correct answers, return the sequence which occurs first in the array. 

LINK: https://www.interviewbit.com/problems/largest-continuous-sequence-zero-sum/
*/

vector<int> Solution::lszero(vector<int> &A)
{
    unordered_map<int,int> hash;
 
    int n = A.size();
    int sum=0;
    int st = INT_MAX, len = 0;
 
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
 
        if(A[i]==0 && len==0)
        {
            st = i;
            len = 1;
        }
        if(sum==0)
        {
            st=0;
            len = i+1;
        }
 
        if(hash.find(sum)!=hash.end())
        {
            if(i-hash[sum] > len)
            {
                st = hash[sum]+1;
                len = i-hash[sum];
            }
        }
        else
            hash[sum]=i;
    }
 
    vector<int> res;
 
    for(int i=st;i<st+len;i++)
        res.push_back(A[i]);
 
    return res;
}