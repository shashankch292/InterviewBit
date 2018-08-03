/*
Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:

A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]
NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length
NOTE 2: If there is still a tie, then return the segment with minimum starting index

LINK: https://www.interviewbit.com/problems/max-non-negative-subarray/
*/

vector<int> Solution::maxset(vector<int> &A) 
{
    int st=0,rs=-1,re=-1;
    long long int sum = 0, mxs = LLONG_MIN;
    
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>=0)
        {
            sum += A[i];
            if(sum>mxs)
            {
                mxs = sum;
                rs = st;
                re = i;
            }
            else
            if(sum==mxs)
            {
                if((re-rs)<(i-st))
                {
                    rs = st;
                    re = i;
                }
            }
        }
        else
        {
            sum=0;
            st=i+1;
        }
    }
    
    vector<int> v;
    
    if(rs==-1 || re==-1)
        return v;
    
    for(int i=rs;i<=re;i++)
        v.push_back(A[i]);
        
    return v;
}