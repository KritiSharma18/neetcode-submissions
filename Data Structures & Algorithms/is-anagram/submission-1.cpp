class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        int counts[26] = {0};
        for (char c : s) counts[c - 'a']++;
        for (char c : t) counts[c - 'a']--;
        
        for (int c : counts) if (c != 0) return false;
        return true;
    }
};
