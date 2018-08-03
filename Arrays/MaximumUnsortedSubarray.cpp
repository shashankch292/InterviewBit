/*
You are given an array (zero indexed) of N non-negative integers, A0, A1 ,…, AN-1.
Find the minimum sub array Al, Al+1 ,…, Ar so if we sort(in ascending order) that sub array, then the whole array should get sorted.
If A is already sorted, output -1.

Example :

Input 1:

A = [1, 3, 2, 4, 5]

Return: [1, 2]

Input 2:

A = [1, 2, 3, 4, 5]

Return: [-1]
In the above example(Input 1), if we sort the subarray A1, A2, then whole array A should get sorted.

LINK: https://www.interviewbit.com/problems/maximum-unsorted-subarray/
*/

vector<int> Solution::subUnsort(vector<int> &A)
{
    int n=A.size();
    int st=0,end=n-1;
    int flags=0;
 
    for(int i=1;i<n;i++)
    {
        if(A[i]<A[i-1])
        {
            int j=st;
            while(j>=0 && A[j]>A[i])
                j--;
            if(j<st)
                st=j+1;
            // cout<<st<<" ";
            flags=1;
        }
        if(flags==0)
            st=i;
    }
 
    int flage=0;
 
    for(int i=n-2;i>=0;i--)
    {
        if(A[i]>A[i+1])
        {
            int j=end;
            while(j<n && A[j]<A[i])
                j++;
            if(j>end)
                end=j-1;
            // cout<<end<<" ";
            flage=1;
        }
        if(flage==0)
            end=i;
    }
 
    vector<int> v;
 
    if(flags==0 || flage==0)
    {
        v.push_back(-1);
        return v;
    }
 
    v.push_back(st);
    v.push_back(end);
    return v;
}