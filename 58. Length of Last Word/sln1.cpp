#include <iostream>


using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        for(int i = s.size()-1;i>=0;i--)
        {
            if(s[i]==' ')
            {
                if(res) return res;
            }
            else
            {
                res++;
            }
            }    
    return res;
    }
};

int main() {
    Solution s;
    cout << s.lengthOfLastWord("   fly me   to   the moon  ") << endl;
    return 0;

}