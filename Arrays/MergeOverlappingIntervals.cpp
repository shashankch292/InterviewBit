/*
Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.

LINK: https://www.interviewbit.com/problems/merge-overlapping-intervals/
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool comp(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}
 
vector<Interval> Solution::merge(vector<Interval> &A) 
{
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<Interval> v;
 
    sort(A.begin(), A.end(), comp);
 
    int len = A.size();
 
    for(int i=0;i<len;i++)
    {
        Interval temp;
        temp.start = A[i].start;
        temp.end = A[i].end;
 
        int j;
 
        for(j=i+1;j<len;j++)
        {
            if(A[j].start > temp.end)
                break;
 
            temp.end = max(temp.end, A[j].end);
        }
 
        i = j-1;
 
        v.push_back(temp);
    }
 
    return v;
}