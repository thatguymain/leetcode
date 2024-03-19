#include <iostream>
#include <vector>

using namespace std;
    
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1) return strs[0];
        string res="";
        int letter=0;
        while(true)
        {
            for(int i = 1 ; i< strs.size(); ++i)
            {
                if(letter>strs[i-1].size()-1 || !strs[i-1].length() || strs[i-1][letter]!=strs[i][letter])   
                {
                    return res;
                }
            }
            res.push_back(strs[0][letter]);
            letter++;
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