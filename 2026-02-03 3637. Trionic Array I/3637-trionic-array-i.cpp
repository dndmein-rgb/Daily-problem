class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        bool increasing=false;
        int count=0;
        if(nums[1]<nums[0])return false;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1])return false;
            if(nums[i]>nums[i-1] && !increasing ){
                increasing=!increasing;
                count++;
            }
            else if(nums[i]<nums[i-1] &&  increasing){
                increasing=!increasing;
                count++;
            }
        }
        return count==3;
    }
};
