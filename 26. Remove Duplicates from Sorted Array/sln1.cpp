#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int removeDuplicates(vector<int>& nums) {
        int pos=0;
        for(int i=1;i<nums.size();i++)
        {
                if(nums[i]!=nums[pos])
                {
                    pos++;
                    nums[pos]=nums[i];
                }
        }
        return pos+1;
    }
};

int main ()
{
    vector<int> a = {1,1,2};
    cout<<Solution::removeDuplicates(a);
    return 0;
}