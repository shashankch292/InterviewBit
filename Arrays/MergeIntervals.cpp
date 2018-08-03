/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted.

LINK: https://www.interviewbit.com/problems/merge-intervals/
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
 
bool doesOverlap(Interval a, Interval b)
{
    return (min(a.end, b.end) >= max(a.start, b.start));
}
 
vector<Interval> Solution::insert(vector<Interval> &Intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<Interval> ans;
    int n = Intervals.size();
    
    if (n == 0)
    {
        ans.push_back(newInterval);
        return ans;
    }
 
    if (newInterval.end < Intervals[0].start || newInterval.start > Intervals[n - 1].end)
    {
        if (newInterval.end < Intervals[0].start)
            ans.push_back(newInterval);
 
        for (int i = 0; i < n; i++)
            ans.push_back(Intervals[i]);
 
        if (newInterval.start > Intervals[n - 1].end)
            ans.push_back(newInterval);
 
        return ans;
    }
 
    if (newInterval.start <= Intervals[0].start && newInterval.end >= Intervals[n - 1].end)
    {
        ans.push_back(newInterval);
        return ans;
    }
 
    bool overlap = true;
    for (int i = 0; i < n; i++)
    {
        overlap = doesOverlap(Intervals[i], newInterval);
        if (!overlap)
        {
            ans.push_back(Intervals[i]);
 
            if (i < n && newInterval.start > Intervals[i].end && newInterval.end < Intervals[i + 1].start)
                ans.push_back(newInterval);
 
            continue;
        }
 
        Interval temp;
        temp.start = min(newInterval.start, Intervals[i].start);
 
        while (i < n && overlap)
        {
            temp.end = max(newInterval.end, Intervals[i].end);
            if (i == n - 1)
                overlap = false;
            else
                overlap = doesOverlap(Intervals[i + 1], newInterval);
            i++;
        }
 
        i--;
        ans.push_back(temp);
    }
 
    return ans;
}