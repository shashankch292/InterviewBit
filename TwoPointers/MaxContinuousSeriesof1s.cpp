/*
You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:

Input : 
Array = {1 1 0 1 1 0 0 1 1 1 } 
M = 1

Output : 
[0, 1, 2, 3, 4] 

If there are multiple possible solutions, return the sequence which has the minimum start index.

LINK: https://www.interviewbit.com/problems/max-continuous-series-of-1s/
*/

vector<int> Solution::maxone(vector<int> &A, int B)
{
    int l=0,r=0,n=A.size();
    int zcnt = 0;
    int mxcnt=0,ind=0;
 
    while(r<n)
    {
        if(zcnt<=B)
        {
            if(A[r]==0)
                zcnt++;
            r++;
        }
        if(zcnt>B)
        {
            if(A[l]==0)
                zcnt--;
            l++;
        }
        if((r-l)>mxcnt)
        {
            mxcnt = r-l;
            ind = l;
        }
    }
 
    vector<int> v;
    for(int i=0;i<mxcnt;i++)
        v.push_back(ind+i);
    return v;
}
