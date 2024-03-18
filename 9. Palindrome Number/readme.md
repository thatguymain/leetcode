# 9. Palindrome Number
__________________
Given an integer `x`, return `true` *if* x is a palindrome, and `false` otherwise.

__________________

### Example 1:

**Input:** x = 121
**Output:** true
**Explanation:** 121 reads as 121 from left to right and from right to left.

### Example 2:

**Input:** x = -121
**Output:** false
**Explanation:** From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

### Example 3:

**Input:** x = 10
**Output:** false
**Explanation:** Reads 01 from right to left. Therefore it is not a palindrome.
 
### Constraints:

`-23^1 <= x <= 23^1 - 1`
 

**Follow up:** Could you solve it without converting the integer to a string?

_________________

## Solution

The first thing we will need is a dynamic array, and at this stage we can already abandon this solution, however, we will still make our mistake for a better understanding of the problem. Since we will need an array with a previously unknown number of elements and all the operations we will perform are accessing the element and adding it, we will use vector because the mentioned operations are performed with an average time complexity of O(1).

```Cpp
class Solution {
public:
    bool isPalindrome(int x) {
        vector<int> arr;
        int t;
        while (x)
        {
            t = x % 10;
            arr.push_back(t);
            x = x / 10;
        } 
        for(int i =0;i<arr.size();++i)
            if(arr[i]!=arr[arr.size()-i-1]) return false;
        return true;
    }
};
```
Can we abandon the array while still maintaining the logic of our code? Of course, because all we need to do is step by step check if the first and last digits in the given number match, and then move on to the next/previous digit. We have understood how to get the value of the first digit of the number, it is simple to calculate the remainder of the division t = x % 10;, now we need to understand how to calculate the value of the last digit. This is also not a problem, all our digits are decimal, which means that the rounded value of the decimal logarithm +1 (floor(log10(x))+1) of our number will give us an understanding of the number of digits in the number, and then simply by dividing our number by 10 to the power of "number of digits - 1" we will obtain the value of our last digit.

```Cpp
class Solution {
public:
    bool isPalindrome(int x) {
        int currentval = x;
        int t = x % 10;
        int e;
        int len = floor (log10 (currentval)) + 1;
        while (currentval)
        {
            len = floor (log10 (currentval)) + 1;
            if(len>1) e = x / pow(10, len-1);     // Since the first digit is essentially the desired number, there is no need to divide it.
            else e = x;
            currentval = currentval / 10;
            x = x - e*pow(10, len-1);
            if (e!=t) return false;
            t = currentval % 10;
        }
        return true;
    }
};
```

Time complexity remains the same - O(1), however the number of lines increased, so we got a slower solution. But we achieved our goal - to get rid of the array. We can think further and ask ourselves why we use logic justified for arrays when comparing prime numbers. Why do we need extra work to determine digits, essentially similar to the index-element system of an array. If to obtain the value of each digit we searched for the remainder of division and divided the original number by ten, it can be noticed that by initializing a variable with the value of the first digit, and then multiplying it by ten and adding the remainder of the division of the original number by ten, we will eventually get our original number, but written backwards.

```Cpp
class Solution {
public:
    bool isPalindrome(int x) {
        int res = 0;
        int e=x;
        while (e!=0)
        {
            res*=10;    
            res += e%10; 
            e=e/10;     
        }
        if(res==x)return true;
        return false;
    }
};
```

And yes, it seemed like this was the solution, however, we forgot about the initial conditions. The number is in the range -23^1 <= x <= 23^1 - 1 or in other words INT_MIN <= x <= INT_MAX. We have multiplication by 10 in our code, and the maximum range of the int variable written in reverse order is 7 463 847 412 which exceeds the range and will cause overflow. In addition, in example #2 it is stated that any negative number is not a palindrome. Furthermore, any single-digit number should also be a palindrome (which slightly contradicts the definition of a palindrome itself according to the conditions of leetcode), and our code successfully handles this, except for handling the digit 0. Taking all additions into account, the code will look like this.

```Cpp
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(!x) return true;
        long res = 0;
        long e=x;
        while (e!=0)
        {
            res*=10;    
            res += e%10; 
            e=e/10;     
        }
        if(res==x)return true;
        return false;
    }
};
```