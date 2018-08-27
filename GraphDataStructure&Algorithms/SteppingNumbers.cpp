/*
Given N and M find all stepping numbers in range N to M

The stepping number:

A number is called as a stepping number if the adjacent digits have a difference of 1.
e.g 123 is stepping number, but 358 is not a stepping number

Example:

N = 10, M = 20
all stepping numbers are 10 , 12 
Return the numbers in sorted order.

LINK: https://www.interviewbit.com/problems/stepping-numbers/
*/

typedef long long int ll;
 
vector<int> res;
int a;
int b;
 
void solve(ll num)
{
    if(num>b)
        return;
 
    if(num>=a)
        res.push_back(num);
 
    int lastDig = num%10;
 
    if(lastDig == 0)
        solve(num*10 + 1);
    else
    if(lastDig == 9)
        solve(num*10 + 8);
    else
    {
        solve(num*10 + lastDig - 1);
        solve(num*10 + lastDig + 1);
    }
}
 
vector<int> Solution::stepnum(int A, int B)
{
    res.clear();
    a = A;
    b = B;
 
    if(A>B)
        return res;
 
    if(A==0)
        res.push_back(0);
 
    for(int i=1;i<=9;i++)
        solve(i);
 
    if(!res.empty())
        sort(res.begin(), res.end());
 
    return res;
}