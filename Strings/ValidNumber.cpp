/*
Validate if a given string is numeric.

Examples:

"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Clarify the question using “See Expected Output”

Is 1u ( which may be a representation for unsigned integers valid?
For this problem, no.
Is 0.1e10 valid?
Yes
-01.1e-10?
Yes
Hexadecimal numbers like 0xFF?
Not for the purpose of this problem
3. (. not followed by a digit)?
No
Can exponent have decimal numbers? 3e0.1?
Not for this problem.
Is 1f ( floating point number with f as prefix ) valid?
Not for this problem.
How about 1000LL or 1000L ( C++ representation for long and long long numbers )?
Not for this problem.
How about integers preceded by 00 or 0? like 008?
Yes for this problem

LINK: https://www.interviewbit.com/problems/valid-number/
*/

int Solution::isNumber(const string A)
{
    int n = A.length();
    int i=0, j=n-1;
    while(i<n && A[i]==' ')
        i++;
    while(j>=i && A[j]==' ')
        j--;
 
    string s = A.substr(i,j-i+1);
    n = s.length();
 
    if(n==0)
        return 0;
    if(n==1 && !isdigit(s[0]))
        return 0;
    if(!isdigit(s[0]) && s[0]!='+' && s[0]!='-' && s[0]!='.')
        return 0;
 
    int flag = 0, cntdot=0;
    if(s[0]=='.')
        cntdot++;
 
    for(int i=1;i<n;i++)
    {
        if(!isdigit(s[i]) && s[i]!='+' && s[i]!='-' && s[i]!='.' && s[i]!='e')
            return 0;
 
        if(s[i]=='.')
        {
            if(flag || cntdot>0 || (i+1)>n)
                return 0;
            cntdot++;
 
            if(!isdigit(s[i+1]))
                return 0;
        }
        else
        if(s[i]=='e')
        {
            flag=1;
            if(!isdigit(s[i-1]))
                return 0;
            if((i+1)>n)
                return 0;
            if(!isdigit(s[i+1]) && s[i+1]!='+' && s[i+1]!='-')
                return 0;
        }
    }
    return 1;
}
