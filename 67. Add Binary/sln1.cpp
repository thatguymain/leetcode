#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int sum = 0;
        int i=a.size()-1;
        int j=b.size()-1;
        while (sum || i>=0 || j>=0) 
        {
            if(i >=0) {sum += a[i--] - '0';}
            if(j >=0) {sum += b[j--] - '0';}
            res.push_back(sum % 2 + '0') ;
            sum /= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    cout << s.addBinary("11", "1") << endl;
    return 0;

}