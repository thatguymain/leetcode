#include <iostream>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        int pos = 0;
        for(int i = 0; i < haystack.size(); i++){
            while(needle[pos]!='\0' && needle[pos]== haystack[i+pos])
            {
                pos++;
            }
            if(pos == needle.size()) return i;
            pos = 0;
        }
        return -1;
    }
};

int main() {
    Solution s;
    std::cout << s.strStr("mississippi", "issip") << std :: endl;
    return 0;

}