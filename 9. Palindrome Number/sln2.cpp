#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(!x) return true;
        int currentval = x;
        int t = x % 10;
        int e;
        int len = floor (log10 (currentval)) + 1;
        while (currentval)
        {
            len = floor (log10 (currentval)) + 1;
            if(len>1) e = x / pow(10, len-1);     // Since the first digit is essentially the desired number, there is no need to divide it.
            else e = x;
            currentval = currentval / 10;
            x = x - e*pow(10, len-1);
            if (e!=t) return false;
            t = currentval % 10;
        }
        return true;
    }
};

int main()
{
    Solution q;
    cout<<q.isPalindrome(1223221);
    return 0;
}