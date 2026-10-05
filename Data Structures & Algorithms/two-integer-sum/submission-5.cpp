class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        unordered_map<int,int>mp;

        for(int i=0;i<n;i++)
        {
            mp[nums[i]]=i;
        }

        for(int i=0;i<n;i++)
        {
            int rem = target-nums[i];
            if(mp.find(rem) != mp.end() && i!=mp[rem])
            {
                int j=mp[rem];

                return (i<j)? vector<int>{i,j} : vector<int>{j,i};
            }
        }




        return {};
    }
};
