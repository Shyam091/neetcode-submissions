class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // prefix product - [1,2,4,6] - [1,1,2,8]
        // suffix product - [1,2,4,6] - [48,24,6,1]
        // final output - [48, 24, 12, 8];

        int n = nums.size();
        int prefix = nums[0];
        int suffix = nums[n - 1];
        vector<int>ans(n,1);
        vector<int> prefixArr(n, 1);
        vector<int> suffixArr(n, 1);
        for (int i = 1; i < n; i++) {
            prefixArr[i] = prefix;  // [1,1,2,8]
            prefix *= nums[i];
        }
        for (int j = n - 2; j >= 0; j--) {
            suffixArr[j] = suffix;  // [1,6,24,48]
            suffix *= nums[j];
        }
        for(int i=0;i<n;i++)
        {
            ans[i]=prefixArr[i]*suffixArr[i];
        }
        return ans;
    }
};
