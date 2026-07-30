class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int , queue<int>>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push(i);
        }

        for(int i=0;i<n;i++)
        {
            int num1 = target - nums[i];
            //    mp[num1].pop();


                mp[nums[i]].pop();
                if(mp[nums[i]].empty())
                {
                    mp.erase(nums[i]);
                }
         
            if(mp.find(num1) != mp.end() )
            {
                    return {i , mp[num1].front()};
            }
        }




        return {};
    }
};
