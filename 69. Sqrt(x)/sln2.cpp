#include <iostream>
using namespace std;


// O(log n)


class Solution {
public:
    int mySqrt(int x) {
        if(!x) return 0;
        if(x==1) return 1;
        int left = 0;
        int right = x;
        double mid = (left + right) / 2;
        while (left < right) {
            mid = (left + right) / 2;
            if (mid * mid > x) {
                right = mid;
            } else {
                left = mid+1;
            }
            }
        return left-1;   
        }
        
        
    
};

int main() {
    Solution s;
    cout << s.mySqrt(16) << endl;
    return 0;
}