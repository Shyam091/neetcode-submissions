class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // there are multiple ways to solve this question, we will solve this with sorting method.
        // 1 sort all strings
        // act = act
        // pots = opst
        // tops =opst
        // cat = act 
        // stop = opts
        //hat = aht

        // combined = [act,cat], [pots,tops,stop],[hat]
        vector<string>str = strs; // making a copy.
        unordered_map<string, vector<string>>mp; // map for storing same strings {string as key,  vector as values}

        for(int i=0 ; i <  strs.size();i++) // sorting the individual strings for using them as keys
        {
            string s=strs[i];
            sort(s.begin(), s.end());
            strs[i]=s;

        }

        for(int i=0;i<strs.size();i++) // pushing all the values within there corresponding keys.
        {
            mp[strs[i]].push_back(str[i]); // here
        }

        vector<vector<string>>ans; // we make one final answer vector.

        for( auto& [key,val]:mp)
        {
            ans.push_back(val); //here we are doing final setup, as we are pushing all collected values in our final anser.
        }
        

        return ans; // we are returning the answer.
    }
    
};
