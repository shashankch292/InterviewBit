/*
Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input:

[3 4 1 4 1]
Sample Output:

1
If there are multiple possible answers ( like in the sample case above ), output any one.

If there is no duplicate, output -1

LINK: https://www.interviewbit.com/problems/find-duplicate-in-array/
*/

int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
 
    int valueRange = A.size()-1;
    int range = sqrt(valueRange);
 
    if(range*range < valueRange)
        range++;
 
    int count[range+1];
    memset(count, 0, sizeof(count));
 
    for(int i=0;i<A.size();i++)
    {
        count[(A[i]-1)/range]++;
    }
 
    int repeatedRange = -1;
    int numRanges = ((valueRange-1)/range)+1;
 
    for(int i=0;i<numRanges && repeatedRange==-1;i++)
    {
        if(i<numRanges-1 || valueRange%range==0)
        {
            if(count[i]>range)
                repeatedRange = i;
        }
        else
        if(count[i] > valueRange%range)
            repeatedRange = i;
    }
 
    if(repeatedRange == -1)
        return -1;
 
    memset(count, 0, sizeof(count));
 
    for(int i=0;i<A.size();i++)
    {
        if((A[i]-1)/range == repeatedRange)
            count[(A[i]-1)%range]++;
    }
 
    for(int i=0;i<range;i++)
    {
        if(count[i]>1)
            return repeatedRange*range+i+1;
    }
 
    return -1;
}