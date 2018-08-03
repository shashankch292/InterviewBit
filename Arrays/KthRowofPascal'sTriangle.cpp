/*
Given an index k, return the kth row of the Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Input : k = 3

Return : [1,3,3,1]
 NOTE : k is 0 based. k = 0, corresponds to the row [1]. 
Note:Could you optimize your algorithm to use only O(k) extra space?

LINK: https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/
*/

vector<int> Solution::getRow(int n) 
{
    vector<int> v;
    v.push_back(1);
    
    for(int i=0;i<n;i++)
    {
        v.push_back(v[i] * (n-i)/(i+1));
    }
    
    return v;
}
