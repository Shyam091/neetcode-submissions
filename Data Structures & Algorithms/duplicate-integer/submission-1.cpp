class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        unordered_map<int, int>mp;

      

        for(int x:nums)
        {
               mp[x]++;
            if(mp.find(x) != mp.end())
            {
                if(mp[x] > 1)
                {
                    return true;
                }
            }

            // else{
             
            // }
        }

        return false;

    }
};