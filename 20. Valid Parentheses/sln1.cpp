#include <iostream>
#include <stack>

using namespace std;

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

int main ()
{
    Solution s;
    cout<<s.isValid("({})[]");
    return 0;
}