#include <iostream>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        return haystack.find(needle);
    }
};

int main() {
    Solution s;
    std::cout << s.strStr("mississippi", "issip") << std :: endl;
    return 0;

}