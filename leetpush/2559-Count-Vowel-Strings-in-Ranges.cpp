class Solution {
public:
    
    bool is_vowel(char c)
    {
        vector<char>vowels={'a', 'e', 'i', 'o',  'u'};
        for(auto &i:vowels)
            if(c == i)
                return true;
        return false;
    }
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries) 
    {
        vector<int>ans(queries.size());
        vector<int>perfix(words.size());
        int pre_idx{0}, ans_idx{0};

        for(auto &s:words)
        {
            int sz=s.length();
            perfix[pre_idx++] = ((is_vowel(s[0]) and is_vowel(s[sz-1])) == 1 ? 1:0);
            
        }

        for(int i{1};i<perfix.size();++i)
            perfix[i] += perfix[i-1];

        for(auto &q:queries)
             ans[ans_idx++] = perfix[q[1]] - ((q[0] > 0)? perfix[q[0] -1] : 0) ;
            
           

        return ans;


    }
};