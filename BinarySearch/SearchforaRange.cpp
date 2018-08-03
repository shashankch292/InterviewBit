/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm’s runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example:

Given [5, 7, 7, 8, 8, 10]

and target value 8,

return [3, 4].

LINK: https://www.interviewbit.com/problems/search-for-a-range/
*/

int b_search(const vector<int> &A, int n, int x, bool flag)
{
    int low = 0, high = n-1, result = -1;
 
    while(low<=high)
    {
        int mid = (low+high)/2;
        if(A[mid]==x)
        {
            result = mid;
            if(flag)
                high = mid-1;
            else
                low = mid+1;
        }
        else
        if(x<A[mid])
            high = mid-1;
        else
            low = mid+1;
    }
    return result;
}
 
vector<int> Solution::searchRange(const vector<int> &A, int B)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int fi = b_search(A,A.size(),B,true);
    int li = b_search(A,A.size(),B,false);
    
    vector<int> v = {fi,li};
    return v;
}