/*
Pretty print a json object using proper indentation.

Every inner brace should increase one indentation to the following lines.
Every close brace should decrease one indentation to the same line and the following lines.
The indents can be increased with an additional ‘\t’
Example 1:

Input : {A:"B",C:{D:"E",F:{G:"H",I:"J"}}}
Output : 
{ 
    A:"B",
    C: 
    { 
        D:"E",
        F: 
        { 
            G:"H",
            I:"J"
        } 
    } 
}
Example 2:

Input : ["foo", {"bar":["baz",null,1.0,2]}]
Output : 
[
    "foo", 
    {
        "bar":
        [
            "baz", 
            null, 
            1.0, 
            2
        ]
    }
]
[] and {} are only acceptable braces in this case.

Assume for this problem that space characters can be done away with.

Your solution should return a list of strings, where each entry corresponds to a single line. The strings should not have “\n” character in them.

LINK: https://www.interviewbit.com/problems/pretty-json/
*/

vector<string> Solution::prettyJSON(string A)
{
    vector<string> res;
    int n = A.length();
 
    int br = 0, i = 0, flag = 0;
    string s="";
 
    while(i<n)
    {
        if(A[i]==' ')
        {
            i++;
            continue;
        }
 
        for(int j=0;j<br;j++)
            s.push_back('\t');
 
        flag=0;
 
        if(A[i]=='{' || A[i]=='[')
        {
            s.push_back(A[i]);
            res.push_back(s);
            s="";
            br++;
            i++;
            continue;
        }
 
        while(i<n)
        {
            if(A[i]=='{' || A[i]=='[')
            {
                res.push_back(s);
                s="";
                break;
            }
            if(A[i]=='}' || A[i]==']')
            {
                if(flag)
                    res.push_back(s);
                s="";
                br--;
                for(int j=0;j<br;j++)
                    s.push_back('\t');
                s+=A[i];
                i++;
                if(!(i<n && A[i]==','))
                {
                    res.push_back(s);
                    s="";
                    break;
                }
            }
            s.push_back(A[i]);
            if(A[i]==',')
            {
                res.push_back(s);
                s="";
                i++;
                break;
            }
            i++;
            flag=1;
        }
    }
 
    return res;
}