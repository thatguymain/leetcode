#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::sort(strs.begin(),strs.end());
        string res;
        string first=strs[0],last=strs[strs.size()-1];
        for(int i=0;i<first.size();i++)
        {
            if(first[i]!=last[i])
            {
                return res;
            }
            res+=first[i];
        }
        return res;
    }
};


int main ()
{
    Solution s;
    vector<string> data{"flower","flow","flight"};
    cout<<s.longestCommonPrefix(data);
    return 0;
}