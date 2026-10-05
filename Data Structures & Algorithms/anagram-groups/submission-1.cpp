class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 1 sort all strings
        // act = act
        // pots = opst
        // tops =opst
        // cat = act 
        // stop = opts
        //hat = aht

        // combined = [act,cat], [pots,tops,stop],[hat]
        vector<string>str = strs;
        unordered_map<string, vector<string>>mp;

        for(int i=0 ; i <  strs.size();i++)
        {
            string s=strs[i];
            sort(s.begin(), s.end());
            strs[i]=s;

        }

        for(int i=0;i<strs.size();i++)
        {
            mp[strs[i]].push_back(str[i]);
        }

        vector<vector<string>>ans;

        for( auto& [key,val]:mp)
        {
            ans.push_back(val);
        }
        

        return ans;
    }
    
};
