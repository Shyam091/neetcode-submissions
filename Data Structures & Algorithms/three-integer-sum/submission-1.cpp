class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // three numbers sum == 0;
        // -1 with other two.
        //we will do sorting.
        sort(nums.begin() , nums.end());
        // now we can use two pointers approach as the data is now sorted.
        int n =  nums.size();
        vector<vector<int>>ans;
        // -4, -1, -1, 0, 1, 2
        for(int i=0;i<n;i++)
        {
            // traverse one by one at all .
            
            if(i + 3 >n)
            {
                break;
            }
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }

            int left = i+1;
            int right = n-1;

            while(left < right)
            {
                int sum = nums[i]+nums[left]+nums[right];
                if(sum == 0)
                {
                    ans.push_back({nums[i],nums[left],nums[right]});
                    int l = nums[left];
                    int r = nums[right];
                    left++;
                    while(left < right && nums[left] == l)
                    {
                        left++;
                    }

                    while(left < right && nums[left] == r)
                    {
                        right--;
                    }
                }

                if(sum > 0)
                {
                    right--;
                }
                if(sum < 0)
                {
                    left++;
                }
            }

        }
        // -2, 0, 0, 2, 2

        return ans;
    }
};
