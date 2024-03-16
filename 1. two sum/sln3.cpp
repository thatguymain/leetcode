#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution 
    {
    public:
        vector<int> twoSum(vector<int>& nums, int target)              // O(1) - accessing parameters 
        {
            unordered_map<int, int> pairIdx;                           // O(1) - initialize an unordered map
            for (int i = 0; i < nums.size(); ++i)                      // O(n) - iterate through the input vector
            {
                int num = nums[i];                                     // O(1) - accessing parameters 
                if (pairIdx.find(target - num) != pairIdx.end())       // O(1) - because the unordered map is typically balanced and the data is evenly distributed 
                {
                    return {i, pairIdx[target - num]};                 // O(1) - return the index of the element in the input vector and the index of the corresponding element in the unordered map
                }
                pairIdx[num] = i;                                      // O(1) - update the unordered map with the current element as the key and its index in the input vector as the value
            }
        return {};                                                     // O(1) - return an empty vector since no pair was found
        }
    };


int main() 
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution s;
    vector<int> res = s.twoSum(nums, target);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    
    return 0;
}