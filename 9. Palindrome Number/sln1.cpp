#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(!x) return true;
        vector<int> arr;
        int t;
        while (x)
        {
            t = x % 10;
            arr.push_back(t);
            x = x / 10;
        } 
        for(int i =0;i<arr.size();++i)
            if(arr[i]!=arr[arr.size()-i-1]) return false;
        return true;
    }
};

int main()
{
    Solution q;
    cout<<q.isPalindrome(1223221);
    return 0;
}