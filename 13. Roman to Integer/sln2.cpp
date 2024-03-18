#include <iostream>

using namespace std;

class Solution 
{
public:
    int romanToInt(string s) 
    {
        int res = 0;
        int prev = 0;

        for(int i = s.length() - 1; i >= 0; i--)
        {
            int num;
            switch (s[i]) {
                case 'I': num = 1; break;
                case 'V': num = 5; break;
                case 'X': num = 10; break;
                case 'L': num = 50; break;
                case 'C': num = 100; break;
                case 'D': num = 500; break;
                case 'M': num = 1000; break;
            }
            res += (prev <= num)? num : -num;
            prev = num;
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