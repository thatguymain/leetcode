#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(std::string s) {

        std::unordered_map<char, int> ht = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int res = 0;
        int prev = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            int num = ht[s[i]];
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