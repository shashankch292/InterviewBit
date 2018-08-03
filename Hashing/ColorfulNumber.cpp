/*
For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different contiguous sub-subsequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a contiguous subsequence is different
Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1

LINK: https://www.interviewbit.com/problems/colorful-number/
*/

int Solution::colorful(int A) 
{
    unordered_map<long long int, bool> hash;
    char s[20];
    int len = sprintf(s,"%d",A);
 
    for(int i=0;i<len;i++)
    {
        long long int mul = 1;
        for(int j=i;j<len;j++)
        {
            mul *= (s[j]-'0');
            if(hash[mul])
                return 0;
            hash[mul]=1;
        }        
    }
    return 1;
}