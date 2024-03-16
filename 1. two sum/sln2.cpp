#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution 
    {
    public:
        vector<int> twoSum(vector<int>& nums, int target)      // O(1) - accessing parameters 
        {
            vector<pair<int, int>> freqMap;                    // O(1) - initializing a vector 
            for (int i = 0; i < nums.size(); i++)              // O(n) - looping through the input vector where n is the size 
                {
                    freqMap.push_back(make_pair(nums[i], i));  // O(1) - creating pairs and pushing them into freqMap 
                } 
            sort(freqMap.begin(), freqMap.end());              // O(n * log(n)) - sorting the freqMap vector 
            for (auto it : freqMap)                            // O(n) - iterating over elements in freqMap 
                {
                    int val = it.first;                        // O(1) - accessing element from pair 
                    int freq = it.second;                      // O(1) - accessing element from pair 
                } 
            for (int i = 0; i < freqMap.size(); ++i)           // O(n) - iterating over elements in freqMap 
                {
                    int m;                                     // O(1) - declaring an integer 
                    int s = i + 1;                             // O(1) - calculating sum 
                    int e = freqMap.size();                    // O(1) - initializing e 
                    int t = target - freqMap[i].first;         // O(1) - calculating target difference
                    while (s < e)                              // O(log(n)) - binary search until s is less than e (for each iteration) 
                        {
                            m = s + (e - s) / 2;               // O(1) - calculating middle element 
                            t < freqMap[m].first ? e = m : s = m + 1;      // O(1) - updating bounds 
                            if (freqMap[m].first == t) 
                            { 
                                return {freqMap[i].second, freqMap[m].second};        // O(1) - checking for target element match 
                            } 
                        }
                } 
            return {0, 0}; // O(1) - returning default values 
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