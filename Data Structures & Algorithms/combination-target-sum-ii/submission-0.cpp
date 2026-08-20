class Solution {
   public:
    vector<vector<int>> ans;
    vector<int>used;
    void backtrack(vector<int>& nums, int target, int ind, int sum, int n, vector<int>v) {
    
                if (target == sum) {
                ans.push_back(v); return;
            }
        if (ind >= n) {

            return;
        }

        if (sum > target) {
            return;
        }
      // 1 2 2 4 5 6 9
        for (int i = ind; i < n; i++) {
    //  same level , skip it.....
    if (i > ind && nums[i] == nums[i - 1]) {
        continue;
    }
    
    // 1. Choose
    v.push_back(nums[i]);
    
    
    backtrack(nums, target, i + 1, sum + nums[i], n, v);
    
    // 3. Un-choose (Backtrack)
    v.pop_back();
}
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int n = candidates.size();
        // {arr, target, index, sum , size of arr, current array}
        used.assign(n,0);
        backtrack(candidates, target, 0, 0, n,{});

        return ans;
    }
};
