# 1. Two sum 
__________________
Given an array of integers `nums` and an integer `target`, *return indices of the two numbers such that they add up to* *`target`*.
You may assume that each input would have **exactly** *one solution*, and you may not use the same element twice.
You can return the answer in any order.

___________________
### **Example 1:**


**Input:** nums = [2,7,11,15], target = 9 

**Output:** [0,1]

**Explanation:** Because nums[0] + nums[1] == 9, we return [0, 1].


### **Example 2:**


**Input:** nums = [3,2,4], target = 6

**Output:** [1,2]


### **Example 3:**


**Input:** nums = [3,3], target = 6

**Output:** [0,1]
 
_________________
### **Constraints:**

`2 <= nums.length <= 104`

`-109 <= nums[i] <= 109`

`-109 <= target <= 109`

Only one valid answer exists.
 

**Follow-up:** Can you come up with an algorithm that is less than O(n2) time complexity?


_________________
## Solution #1
_________________



Simple brute force, not optimal, but easy to understand. We utilize the first loop to select the first addend, and then employ a second loop, starting from the next index after the chosen addend, to verify if the sum of the addends matches the target number. 
<br>

```Cpp
class Solution 
{
    public:
        vector<int> twoSum(vector<int>& nums, int target)            // O(1) - accessing parameters  
        {
            for (int i = 0; i < nums.size(); i++)                    // O(n) - looping through the input vector where n is the size  
                for (int j = i + 1; j < nums.size(); j++)            // O(n) - looping through the input vector where n is the size  
                    if (nums[i] + nums[j] == target) return {i, j};  // O(1) - calculating sum 
            return {};                                               // O(1) - returning default values 
        }
};
```

Total Big O calculation: O(n) * O(n) =  O(n2)

_________________
## Solution #2
_________________


Little better.
Used binary search, in result we got Big O = n * log(n). std::sort used, and we might change sort algoritm, but there are no reason because of binary search complexity, so we always will get it in final result
<br>

```Cpp
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
                            if (freqMap[m].first == t) { std::cout << "is"; return {freqMap[i].second, freqMap[m].second};        // O(1) - checking for target element match 
                        } 
                } 
            return {0, 0}; // O(1) - returning default values 
        } 
    };
```

Total Big O calculation: O(1) + O(n) + O(n * log(n)) + O(n) * O(log(n)) =  O(n*log(n))

_________________
## Solution #3
_________________

Now that we have some experience, let's try to apply it. The main problems are nested loops and sorting arrays. Sorting was necessary for the binary search algorithm, so we can safely abandon it. Let's analyze the nested loops, with their help we selected the terms and checked whether their sum corresponds to a given number. And if we cannot refuse the first cycle, then it is worth paying attention to the second. In fact, we need the second array to find the element m, the value of which must satisfy the condition m = n - target. Among all common data structures, the hash table has the lowest average element search time - O(1). The shortest element search time in the worst case is a balanced tree, but its use is pointless, since it will require sorting the array values. In other words, creating a balanced tree from an unsorted vector requires O(nlog(n)). Using the counting sort algorithm will also not be the best solution, since the range of values nums[i] is greater than the number of elements in the array, therefore Big O (n+k) = 10^9 while Big O (nlog(n)) = 10^4
<br>

```Cpp
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
```        
      
    
Total Big O calculation: O(n)
    
      
___________

## Additional information
![alt text](https://github.com/thatguy/leetcode/blob/[branch]/image.jpg?raw=true)
