class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
         if(n == 0)
         {
            return 0;
         }
        // 2 , 20 , 4, 10 , 3, 4 , 5
        // - > 2,3,4,5

        // map - 
        /*
            2 - 1
            20-1
            4-1
            10-1
            3-1
            4-1
            5-1
        */

        // search for k-1
        int count = 1;
        int ans = INT_MIN;
        unordered_map<int, int>mp;
        for(int x:nums)
        {
            mp[x]++;
        }

        for( auto it : mp)
        {
            if(mp.find(it.first - 1) == mp.end())
            {
                int k = 1;
                while(mp.find(it.first + k ) != mp.end())
                {
                    k++;
                    count++;
                }
                
                ans = max(ans, count);
                count = 1;
            }


        }

        return ans;
    }
};
