/*
Given an array with n objects colored red, white or blue, 
sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: Using library sort function is not allowed.

Example :

Input : [0 1 2 0 1 2]
Modify array so that it becomes : [0 0 1 1 2 2]

LINK: https://www.interviewbit.com/problems/sort-by-color/
*/

void Solution::sortColors(vector<int> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    int i=0,j=0,k=A.size()-1;
 
    while(j<=k)
    {
        if(A[j]==0)
            swap(A[i++],A[j++]);
        else
        if(A[j]==2)
            swap(A[j],A[k--]);
        else
            j++;
    }
}