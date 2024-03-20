
# 20. Valid Parentheses
__________________
Given a string s containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.
An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.
 
__________________

### Example 1:

**Input:** s = "()"

**Output:** true

### Example 2:

**Input:** s = "()[]{}"

**Output:** true

### Example 3:

**Input:** s = "(]"

**Output:** false
 

### Constraints:

`1 <= s.length <= 104`
`s` consists of parentheses only `'()[]{}'.`

__________________

## Solution

The first thing you might think about is that the number of open parentheses must be equal to the number of closing parentheses, and they must be in the correct order on the line. And you will try to convert all the symbols into mathematical expressions, like that

```cpp
class Solution {
public:
    bool isValid(string s) {
        int i = 0;
        long sum=0;
        while(s[i]!='\0')
        {
            switch(s[i])
            {
                case '(':
                    sum++;
                    break;
                case ')':
                    sum--;
                    break;
                case '[':
                    sum+=10000;
                    break;
                case ']':
                    sum-=10000;
                    break;
                case '{':
                    sum+=100000000;
                    break;
                case '}':
                    sum-=100000000;
                    break;
            }
            i++;
        }
        cout<<sum<<'\n';
    }
};
```
Now you have calculate through given string, and if sum equals to 0 - number of open brackets is equal to number of closing brackets. Looks that was a bad idea, we got code that essentially dont solve our problem. It looks like we started with the wrong thing, if you think about it, then an equal number of opening and closing parentheses is always an even number, which means in the general case we can replace the entire code with `if(s.length() % 2 !=0) return false;`, Next we have to think about the fact that the correct order in a string cannot start with a closing brackets, and then we have to think about how to determine whether the order is even correct. Not always open bracket must follow by the closingbracket, case when several open brackets follow each other will too might happen, as same case with closing brackets. But when first closing bracket appears, previous element must be open bracket with the same type.  We can add open brackets when they appers in string s to some string `open`, and previuos element for first appering of closing brackets will always located at the end of string`open`. 

```cpp
class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2 !=0) return false;    
        int pos=0;                              // insertion position in the sting `open`,
        string open;
        for(int i =0;i<s.size();i++)
        {
            if (s[i]=='[' || s[i]=='(' || s[i]=='{')    // adding open brackets in `open`
            {
                open+=s[i];
                pos++;
                continue;
            }   
            if(!pos && (s[i]==']' || s[i]==')' || s[i]=='}') ) return false;     // checking if closing brackets is the first symbol
            if (s[i]==']' && open[pos-1]=='[')              //removing "pairs"
            {
                pos--; 
                open.erase(pos);
            } else if(s[i]==')' && open[pos-1]=='(') 
                {
                    pos--; 
                    open.erase(pos);
                } else if(s[i]=='}' && open[pos-1]=='{') 
                    {
                        pos--; 
                        open.erase(pos);
                        }
                        else return false;
        }
        return open.length()==0?true:false;
    }
};
```

Looks like its a solution. But this code still not optimal, because std::string.erase() time complexity is O(n). This is because erasing a character at a specific position in a string requires shifting all subsequent characters to the left by one position. And since we're doing this in a loop, our overall time complexity will equals to O(n^2). Lets think how to replace that part. If we looks closer, our code trying to delete last added element in string, in other words - code works on the LIFO principle (last-in first-out), but this is the same what `stack` doing! We can abaddon all indexes, using stack.top(), abaddon erasing with O(n) using stack.pop() with O(1)!

```cpp
class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2 !=0) return false;    
        stack<char> st;                              
        for(int i =0;i<s.size();i++)
        {
            if (s[i]=='[' || s[i]=='(' || s[i]=='{')    // adding open brackets in `open`
            {
                st.push(s[i]);
                continue;
            }   
            if(st.empty() && (s[i]==']' || s[i]==')' || s[i]=='}') ) return false;     // checking if closing brackets is the first symbol
            if (s[i]==']' && st.top()=='[')              // removing "pairs"
            {
                st.pop();                               // deleting last added element 
            } else if(s[i]==')' && st.top()=='(') 
                {
                    st.pop();
                } else if(s[i]=='}' && st.top()=='{') 
                    {
                        st.pop();
                        }
                        else return false;
        }
        return st.empty();   // if there are no elements in stack - order was correct
    }
};
```

Now it works faster, but still not perfect, because its hard to read. Lets do some optimization
`if(st.empty() && (s[i]==']' || s[i]==')' || s[i]=='}') )` we dont need to check `(s[i]==']' || s[i]==')' || s[i]=='}')` if we replace `if` statement with `else-if`, so if symbol at the empty stack will not equal to open bracket we return 0. All other `else-if` can be replaced with `||`

```cpp
class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2 !=0) return false;    
        stack<char> st;                              
        for(int i =0;i<s.size();i++)
        {
            if (s[i]=='[' || s[i]=='(' || s[i]=='{')   st.push(s[i]); 
            else
            {
                if(st.empty()) return false;    
                if (s[i]==']' && st.top()=='[' || s[i]==')' && st.top()=='(' || s[i]=='}' && st.top()=='{')          
                {
                    st.pop();                             
                } 
                else return false;
            }
        }
        return st.empty();
    }
};
```

If you want more speed, you can use ASCII codes to operate digits instead of characters, which is slightly faster