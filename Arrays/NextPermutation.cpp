/*
Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.

If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.

The replacement must be in-place, do not allocate extra memory.

Examples:

1,2,3 → 1,3,2

3,2,1 → 1,2,3

1,1,5 → 1,5,1

20, 50, 113 → 20, 113, 50
Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

LINK: https://www.interviewbit.com/problems/next-permutation/
*/

void Solution::nextPermutation(vector<int> &A)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    int n=A.size();
    int idx = -1;
 
    for(int i=n-2;i>=0;i--)
    {
        if(A[i]<A[i+1])
        {
            idx = i;
            break;
        }
    }
 
    if(idx==-1)
        sort(A.begin(), A.end());
    else
    {
        int mxi=-1;
        for(int i=idx+1;i<n;i++)
        {
            if(A[i]>A[idx] && (mxi=-1 || A[i]<A[mxi]))
                mxi = i;
        }
 
        if(mxi!=-1)
        {
            int temp = A[idx];
            A[idx] = A[mxi];
            A[mxi] = temp;
            idx++;
        }
 
        sort(A.begin()+idx, A.end());
    }
}