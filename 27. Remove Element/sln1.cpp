#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int removeElement(vector<int>& nums, int val) {
        if(nums.empty()) return 0;
        int pos=nums.size()-1;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
                if(nums[i]==val && pos-count+1>i)
                {
                    int s=nums[i];
                    nums[i]=nums[pos-count];nums[pos-count]=s;
                    count++;
                    i--;
                }
        }
        return nums.size()-count;
    }
};


int main ()
{
    vector<int> a = {0,1,2,2,3,0,4,2};
    int val=3;
    cout<<Solution::removeElement(a,2)<<endl;
    for(int i=0;i<Solution::removeElement(a,2);i++){cout<<a[i]<<" ";}cout<<endl;
    return 0;
}