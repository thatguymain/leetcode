#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        int left=0, right=nums.size()-1;
        while (left<=right) {
            int mid = (left+right)/2;
            if (nums[mid]==target) return mid;
            else if (nums[mid]<target) left=mid+1;
            else right=mid-1;
        }
        return right+1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,3,5,6};
    int target = 5;
    cout << s.searchInsert(nums, target) << endl;
    return 0;

}