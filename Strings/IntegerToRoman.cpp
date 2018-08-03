/*
Given an integer, convert it to a roman numeral, and return a string corresponding to its roman numeral version

Input is guaranteed to be within the range from 1 to 3999.

Example :

Input : 5
Return : "V"

Input : 14
Return : "XIV"
 Note : This question has a lot of scope of clarification from the interviewer. Please take a moment to think of all the needed clarifications and see the expected response using “See Expected Output” For the purpose of this question, https://projecteuler.net/about=roman_numerals has very detailed explanations. 

LINK: https://www.interviewbit.com/problems/integer-to-roman/
*/

string Solution::intToRoman(int n)
{
    string s="";
    int r;
 
    r=n/1000;
    n%=1000;
    for(int i=0;i<r;i++)
        s+="M";
 
    if(n>=900)
    {
        s+="CM";
        n%=900;
    }
    if(n>=400 && n<500)
    {
        s+="CD";
        n%=400;
    }
    if(n>=500)
    {
        s+="D";
        n%=500;
    }
 
    r=n/100;
    n%=100;
    for(int i=0;i<r;i++)
        s+="C";
 
    if(n>=90)
    {
        s+="XC";
        n%=90;
    }
    if(n>=40 && n<50)
    {
        s+="XL";
        n%=40;
    }
    if(n>=50)
    {
        s+="L";
        n%=50;
    }
 
    r=n/10;
    n%=10;
    for(int i=0;i<r;i++)
        s+="X";
 
    if(n>=9)
    {
        s+="IX";
        n%=9;
    }
    if(n>=4 && n<5)
    {
        s+="IV";
        n%=4;
    }
    if(n>=5)
    {
        s+="V";
        n%=5;
    }
 
    for(int i=0;i<n;i++)
        s+="I";
 
    return s;
}