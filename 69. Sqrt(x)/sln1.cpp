#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int count = 0;
        int odd = 1;
        while (x >= odd) {
            x=x-odd;
            odd+=2;
            count++;
        }
        return count;
    }
};

int main() {
    Solution s;
    cout << s.mySqrt(8) << endl;
    return 0;

}