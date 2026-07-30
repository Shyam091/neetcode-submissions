class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int m = t.size();
        if(n!=m)
        {
            return false;
        }        
        unordered_map<char , int>mp;
        for( char ch : s)
        {
            mp[ch]++;
        }

        for(char ch : t)
        {
            mp[ch]--;
        }

        for( char ch : s)
        {
            if(mp[ch]>0)
            {
                return false;
            }
        }
        return true;
        
    }
};
