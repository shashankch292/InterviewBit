/*
Compare two version numbers version1 and version2.

If version1 > version2 return 1,
If version1 < version2 return -1,
otherwise return 0.
You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 1.13 < 1.13.4

LINK: https://www.interviewbit.com/problems/compare-version-numbers/
*/

int Solution::compareVersion(string v1, string v2)
{
    string vnum1 = "", vnum2 = "";
    int flag1=1, flag2=1;
 
    for(int i=0,j=0;(i<v1.length() || j<v2.length());)
    {
        while(i<v1.length() && v1[i]!='.')
        {
            if(flag1)
            {
                while(i<v1.length() && v1[i]=='0')
                    i++;
            }
            if(i==v1.length())
                break;
            vnum1 += v1[i];
            i++;
            flag1=0;
        }
 
        while(j<v2.length() && v2[j]!='.')
        {
            if(flag2)
            {
                while(j<v2.length() && v2[j]=='0')
                    j++;
            }
            if(j==v2.length())
                break;
            vnum2 += v2[j];
            j++;
            flag2=0;
        }
 
        flag1=1;
        flag2=1;
 
        if(vnum1.length()>vnum2.length())
            return 1;
        else
        if(vnum1.length()<vnum2.length())
            return -1;
        else
        {
            if(vnum1>vnum2)
                return 1;
            if(vnum1<vnum2)
                return -1;
        }
 
        vnum1 = vnum2 = "";
        i++;
        j++;
    }
    return 0;
}