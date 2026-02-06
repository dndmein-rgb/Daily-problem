class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>result(n,0);
        for(int i=0;i<n;i++){
            // if(nums[i]>0)result[i]=nums[(i+nums[i])%n];
           result[i]=nums[abs(i+n+nums[i]%n)%n];
        }
        return result;
    }
};
