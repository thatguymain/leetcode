#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int removeElement(vector<int>& nums, int val) {
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
                if(nums[i]!=val)
                {
                    nums[count]=nums[i];
                        count++;
                }
        }
        return count;
    }
};


int main ()
{
    vector<int> a = {0,1,2,2,3,0,4,2};
    int res = Solution::removeElement(a, 2);
    cout<<res<<endl;
    for(int i=0;i<res;i++){cout<<a[i]<<" ";}cout<<endl;
    return 0;
}