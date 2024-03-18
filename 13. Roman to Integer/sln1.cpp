#include <iostream>

using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        for(int i=0;i<s.length();++i)
        {
            if(s[i]=='I') 
                {
                    if(s[i+1]=='V' || s[i+1]=='X') {res-=2;}
                    res++;
                }
            if(s[i]=='V') res+=5;
            if(s[i]=='X') 
                {
                    if(s[i+1]=='L' || s[i+1]=='C') {res-=20;}
                    res+=10;
                }
            if(s[i]=='L') res+=50;
            if(s[i]=='C')
                {
                    if(s[i+1]=='D' || s[i+1]=='M') {res-=200;}
                    res+=100;
                }
            if(s[i]=='D') res+=500;
            if(s[i]=='M') res+=1000;
        }
        return res;
    }
};

int main()
{
    Solution q;
    cout<<q.romanToInt("MCMXCIV");
    return 0;
}