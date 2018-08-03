/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R
And then read line by line: PAHNAPLSIIGYIR
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
**Example 2 : **
ABCD, 2 can be written as

A....C
...B....D
and hence the answer would be ACBD.

LINK: https://www.interviewbit.com/problems/zigzag-string/
*/

string Solution::convert(string A, int B)
{
    int n = A.length();
 
    if(B==1)
        return A;
 
    string res="";
 
    for(int i=(B-1)*2,j=0;i>=0;i-=2,j+=2)
    {
        int k=j/2;
        int flag=1;
        while(k<n)
        {
            if(j==0)
            {
                res.push_back(A[k]);
                k+=i;
                continue;
            }
            if(i==0)
            {
                res.push_back(A[k]);
                k+=j;
                continue;
            }
            if(flag)
            {
                res.push_back(A[k]);
                k+=i;
                flag^=1;
            }
            else
            {
                res.push_back(A[k]);
                k+=j;
                flag^=1;
            }
        }
    }
    return res;
}