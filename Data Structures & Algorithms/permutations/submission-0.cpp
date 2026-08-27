class Solution {
public:
    vector<vector<int>>ans;
    vector<int>used;

    void backtrack(vector<int>&nums, int ind, vector<int>v, int n){
        if(v.size() == n)
        {
            ans.push_back(v);
            return ;
        }

        for(int i=0;i<n;i++)
        {
            if(used[i])
            {
                continue;
            }
            used[i]= 1;
            v.push_back(nums[i]);
            backtrack(nums,i, v,n);
            v.pop_back();
             used[i]=0;
        }
       
    }

    vector<vector<int>> permute(vector<int>& nums) {
        // [1,2,3]
        int n = nums.size();
        used.assign(n,0);
        // {nums, index, vector, size()}
        backtrack(nums, 0,{}, n);
        return ans;
    }
};
