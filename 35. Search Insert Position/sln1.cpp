#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        // if we dont care about constraints  O (log n)

        for(int i=0;i<nums.size();i++){
            if(nums[i]>=target){
                return i;
            }
        }
        return nums.size();
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,3,5,6};
    int target = 7;
    cout << s.searchInsert(nums, target) << endl;
    return 0;

}