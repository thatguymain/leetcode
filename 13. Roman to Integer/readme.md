# 13. Roman to Integer
______________
Roman numerals are represented by seven different symbols: `I`, `V`, `X`, `L`, `C`, `D` and `M`.

|**Symbol**|**Value**|
|:-:|:-:|
|I|1|
|V|5|
|X|10|
|L|50|
|C|100|
|D|500|
|M|1000|


For example, `2` is written as `II` in Roman numeral, just two ones added together. `12` is written as `XII`, which is simply `X + II`. The number `27` is written as `XXVII`, which is `XX + V + II`.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not `IIII`. Instead, the number four is written as `IV`. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as `IX`. There are six instances where subtraction is used:

+ I can be placed before V (5) and X (10) to make 4 and 9. 
+ X can be placed before L (50) and C (100) to make 40 and 90. 
+ C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

______________ 

### Example 1:

**Input:** s = "III"

**Output:** 3

**Explanation:** III = 3.

### Example 2:

**Input:** s = "LVIII"

**Output:** 58

**Explanation:** L = 50, V= 5, III = 3.

### Example 3:

**Input:** s = "MCMXCIV"

**Output:** 1994

**Explanation:** M = 1000, CM = 900, XC = 90 and IV = 4.
 

### Constraints:

`1 <= s.length <= 15`
`s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').`
`It is guaranteed that s is a valid roman numeral in the range [1, 3999].`
_________________

## Solution

By tradition, the first solution is the simplest one. We can achieve the desired result by simply comparing the characters of the string with the specified conditions.

```Cpp

class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        for(int i=0;i<s.length();++i)
        {
            if(s[i]=='I') 
                {
                    if(s[i+1]=='V' || s[i+1]=='X') {res-=2;}
                    res++;
                }
            if(s[i]=='V') res+=5;
            if(s[i]=='X') 
                {
                    if(s[i+1]=='L' || s[i+1]=='C') {res-=20;}
                    res+=10;
                }
            if(s[i]=='L') res+=50;
            if(s[i]=='C')
                {
                    if(s[i+1]=='D' || s[i+1]=='M') {res-=200;}
                    res+=100;
                }
            if(s[i]=='D') res+=500;
            if(s[i]=='M') res+=1000;
        }
        return res;
    }
};
```

It is worth noting separately that for `I, X, C` the increase by the required amount always occurs, even in cases where only one subtraction is required, so the value is doubled. The solution is simple, it accomplishes the required task, however, it is difficult to read. Let's try some refactoring. `if-statements` can be easily replaced with `switch-case` statements which would be a better choice, as in `asm`, `switch-case` construction executes faster compared to a large number of `if-else` statements. Let's reflect on the peculiarities of the Roman numeral system. Besides the numerical values for each symbol used, the following rules exist:

+ I can be placed before V (5) and X (10) to form 4 and 9.
+ X can be placed before L (50) and C (100) to form 40 and 90.
+ C can be placed before D (500) and M (1000) to form 400 and 900.

For example, with the symbol `I` - it decreases the value by one if the symbols `V` or `X` follow it. The same is true in reverse, if there is an `I` before `V` or `X`, then the final value should be decreased by 1. Taking this into account, it is possible to implement traversing the given string in reverse order.

```cpp
class Solution 
{
public:
    int romanToInt(string s) 
    {
        int res = 0;
        int prev = 0;

        for(int i = s.length() - 1; i >= 0; i--)
        {
            int num;
            switch (s[i]) {
                case 'I': num = 1; break;
                case 'V': num = 5; break;
                case 'X': num = 10; break;
                case 'L': num = 50; break;
                case 'C': num = 100; break;
                case 'D': num = 500; break;
                case 'M': num = 1000; break;
            }
            res += (prev <= num)? num : -num;
            prev = num;
        }
        return res;
    }
};
```

This solution will be slightly faster, but a bit more memory-intensive. However, it is still simple and now easily readable. But if you are a staunch supporter of modern programming practices, you will probably want to use a hash table. And this will not be a bad solution, but for this particular task memory consumption and overall code execution time will still increase.

```Cpp
class Solution {
public:
    int romanToInt(std::string s) {

        std::unordered_map<char, int> ht = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int res = 0;
        int prev = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            int num = ht[s[i]];
            res += (prev <= num)? num : -num;
            prev = num;
        }
        return res;
    }
};
```

