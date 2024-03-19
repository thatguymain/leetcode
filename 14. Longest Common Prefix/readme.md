# 14. Longest Common Prefix
______________
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

______________

### Example 1:

**Input:** strs = ["flower","flow","flight"]

**Output:** "fl"

### Example 2:

**Input:** strs = ["dog","racecar","car"]

**Output:** ""

**Explanation:** There is no common prefix among the input strings.
 

### Constraints:

`1 <= strs.length <= 200`
`0 <= strs[i].length <= 200`
`strs[i]` consists of only lowercase English letters.
_________________

## Solution

The first version of the solution is straightforward. We take the character at index i of the first word and compare it with the character at the corresponding index in other words. If there are matches in all words, we add the character to the answer and repeat the process. It is important to remember that the length of the strings may vary, and the minimum prefix cannot exceed the length of the shortest string.

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1) return strs[0];
        string res="";
        int letter=0;
        while(true)
        {
            for(int i = 1 ; i< strs.size(); ++i)
            {
                if(letter>strs[i-1].size()-1 || !strs[i-1].length() || strs[i-1][letter]!=strs[i][letter])   
                {
                    return res;
                }
            }
            res.push_back(strs[0][letter]);
            letter++;
        }
        return res;
    }
};
```

In the end, we get a total time complexity of `O(m*n)`, where m is the minimum length of a string among the vector elements (`in the worst case (n^2)`). As a result, we obtain a working solution that is somewhat difficult to read. Let's think about how we can reduce the code volume. The first thing we would like to eliminate is nested loops. But do we really have to check all elements and characters in them to find a solution? Actually, no. To start with, we can sort the existing array, then all elements will be organized in alphabetical order, and now, since we need to find a prefix common to ALL elements, it will be sufficient to check the characters of the first and last elements.

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string res;
        string first=strs[0],last=strs[strs.size()-1];
        for(int i=0;i<first.size();i++)
        {
            if(first[i]!=last[i])
            {
                return res;
            }
            res+=first[i];
        }
        return res;
    }
};
```

Now the code is easily readable, and the time complexity is equal to `O(n_log(n))` for the worst case, taking into account the constraints `1 <= strs.length <= 200` and `0 <= strs[i].length <= 200`, on average, it will be executed faster than the first version.