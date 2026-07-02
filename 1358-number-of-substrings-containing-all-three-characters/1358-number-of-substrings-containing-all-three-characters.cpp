class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        int p[3]={-1,-1,-1};

        for (int i=0; i<s.length(); i++){
            if (s[i]=='a')
                p[0]=i;

            else if (s[i]=='b')
                p[1]=i;

            else
                p[2]=i;

            ans += min({p[0],p[1],p[2]})+1;
        }
        return ans;

    }
};