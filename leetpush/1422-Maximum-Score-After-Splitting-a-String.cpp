class Solution {
public:
    int maxScore(string s) {
   
  vector<int>perfix(s.length());
    int n = s.length();
    int ans{0};
    perfix[0] = s[0] -'0';
    for(int i{1};i<n;++i)
        perfix[i] = perfix[i-1] + (s[i]-'0');
    for(int i{0};i<n-1;++i)
    {
        int R_ones = perfix[n-1] - perfix[i];
        int L_ones = perfix[i];
        int L_zeros =   (i+1)- L_ones;

        ans = max(ans, L_zeros + R_ones);
    }
    return ans;
    }
};