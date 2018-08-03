/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7  might become 4 5 6 7 0 1 2 ).

You are given a target value to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Input : [4 5 6 7 0 1 2] and target = 4
Output : 0

NOTE : Think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*

LINK: https://www.interviewbit.com/problems/rotated-sorted-array-search/
*/

int b_search(const vector<int> &v, int  l, int h, int x)
{
    if(l>h)
        return -1;
 
    int mid = l + (h-l)/2;
 
    if(v[mid] == x)
        return mid;
 
    if(v[l] <= v[mid])
    {
        if(x >= v[l] && x <= v[mid])
            return b_search(v, l, mid-1, x);
        return b_search(v, mid+1, h, x);
    }
 
    if(x >= v[mid] && x <= v[h])
        return b_search(v, mid+1, h, x);
    return b_search(v, l, mid-1, x);
}
 
int Solution::search(const vector<int> &A, int B)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    return b_search(A,0,A.size()-1,B);
}