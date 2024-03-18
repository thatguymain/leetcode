#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(!x) return true;
        long res = 0;
        long e=x;
        while (e!=0)
        {
            res*=10;    
            res += e%10; 
            e=e/10;     
        }
        if(res==x)return true;
        return false;
    }
};

int main()
{
    Solution q;
    cout<<q.isPalindrome(1223221);
    return 0;
}