class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, int target,
                   int ind, int sum, vector<int>& v) {

        if (sum == target) {
            ans.push_back(v);
            return;
        }

        for (int i = ind; i < nums.size(); i++) {

            if (sum + nums[i] > target)
                break;

            v.push_back(nums[i]);

            // i, not i+1, because we can reuse nums[i]
            backtrack(nums, target, i,
                      sum + nums[i], v);

            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums,
                                        int target) {

        sort(nums.begin(), nums.end());

        vector<int> v;
        backtrack(nums, target, 0, 0, v);

        return ans;
    }
};