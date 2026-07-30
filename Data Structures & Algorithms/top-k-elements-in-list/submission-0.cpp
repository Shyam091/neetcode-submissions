class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        unordered_map<int, int>mp;
        vector<int>ans;
        for(int x : nums)
        {
            mp[x]++;
        }

        for(auto [element, count] : mp)
        {
            pq.push({count , element});
        }
    
      while(k>0)
      {
        auto [freq , num] = pq.top();
        ans.push_back(num);
        pq.pop();
        k--;
      }
        return ans;
    }
};
