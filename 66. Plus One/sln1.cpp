#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        if(digits[len-1]<9) {
            digits[len-1]++;
            return digits;
        }
        else {
            digits[len-1]=0;
            for(int i=len-2;i>=0;i--) {
                if(digits[i]==9) {
                    digits[i]=0;
                }
                else {
                    digits[i]++;
                    break;
                }
            }
            if(digits[0]==0) {
                digits.insert(digits.begin(),1);
            }
        }
        return digits;
    }
};

int main() {
    Solution s;
    vector<int> digits = {9, 9, 9};
    vector<int> result = s.plusOne(digits);
    for (auto i : result) {
        cout << i << endl;
    }
    return 0;
}