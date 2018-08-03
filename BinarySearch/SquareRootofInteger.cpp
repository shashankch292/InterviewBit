/*
Implement int sqrt(int x).

Compute and return the square root of x.

If x is not a perfect square, return floor(sqrt(x))

Example :

Input : 11
Output : 3
DO NOT USE SQRT FUNCTION FROM STANDARD LIBRARY

LINK: https://www.interviewbit.com/problems/square-root-of-integer/
*/

int Solution::sqrt(int x)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    if(x==0 || x==1)
        return x;
 
    long long int low = 0, high = x,ans = -1;
 
    while(low<=high)
    {
        long long int mid = (low+high)/2;
 
        if(mid*mid == x)
            return mid;
 
        if(mid*mid < x)
        {
            low = mid + 1;
            ans = mid;
        }
        else
            high = mid - 1;
    }
    return ans;
}