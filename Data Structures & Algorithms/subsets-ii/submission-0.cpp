class Solution {
public:

    vector<vector<int>>ans;

    void backtrack(vector<int>& nums, int ind, vector<int>v, int n)
    {

            ans.push_back(v);
            
        for(int i = ind ; i<n;i++)
        {
            if(i > ind && nums[i] ==  nums[i-1])
            {
                continue ;
            }

            v.push_back(nums[i]);
            backtrack(nums, i+1, v,n);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // pick - not pick

        int n = nums.size();
        // { nums, index, {} , n}
        sort(nums.begin() , nums.end());
        backtrack(nums, 0, {}, n);

        return ans;
    }
};
