/*
There are two sorted arrays A and B of size m and n respectively.

Find the median of the two sorted arrays ( The median of the array formed by merging both the arrays ).

The overall run time complexity should be O(log (m+n)).

Sample Input

A : [1 4 5]
B : [2 3]

Sample Output

3
 NOTE: IF the number of elements in the merged array is even, then the median is the average of n / 2 th and n/2 + 1th element. 
For example, if the array is [1 2 3 4], the median is (2 + 3) / 2.0 = 2.5 

LINK: https://www.interviewbit.com/problems/median-of-array/
*/

double getkth(const vector<int> &A, int i, const vector<int> &B, int j, int k)
{
    if(i==A.size())
        return B[j+k];
    else
    if(j==B.size())
        return A[i+k];
    else
    if(k==0)
        return min(A[i], B[j]);
 
    int mid1 = min(int(A.size()-i), (k+1)/2);
    int mid2 = min(int(B.size()-j), (k+1)/2);
    int a = A[i+mid1-1];
    int b = B[j+mid2-1];
 
    if(a<b)
        return getkth(A,i+mid1,B,j,k-mid1);
    else
        return getkth(A,i,B,j+mid2,k-mid2);
}
 
double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B)
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    int total_num = A.size() + B.size();
 
    if(total_num%2==0)
        return (getkth(A,0,B,0,(total_num/2)-1) + getkth(A,0,B,0,total_num/2))/2.0;
    else
        return getkth(A,0,B,0,total_num/2);
}