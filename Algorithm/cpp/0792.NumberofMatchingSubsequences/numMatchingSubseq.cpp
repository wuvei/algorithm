// bucket
char*cursor[26][50001];
int len[26];
class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        memset(len,0,sizeof(len));
        for(int i=0;i<words.size();i++){
            int c=words[i][0]-'a';
            cursor[c][len[c]++]=&words[i][0];
        }
        int ans=0;
        for(char c:S){
            c-='a';
            int k=len[c];
            len[c]=0;
            for(int i=0;i<k;i++){
                char*next=cursor[c][i]+1;
                if(!*next)ans++;
                else{
                    int d=*next-'a';
                    cursor[d][len[d]++]=next;
                }
            }
        }
        return ans;
    }
};

int _IO=[](){
	ios::sync_with_stdio(0);
	cin.tie(0); //cout.tie(0);
	return 0;
}();

// appearance of ch after pos i

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) 
    {
        int m = S.size();
        S = "#"+S;
        int next[m+1][26];
        
        for (int k=0; k<26; k++)
            next[m][k] = -1;
        for (int i=m; i>=1; i--)
        {
            for (int k=0; k<26; k++)
                next[i-1][k] = next[i][k];
            next[i-1][S[i]-'a'] = i;
        }
        
        int ret = 0;
        for (auto word: words)
        {
            int flag = 1;
            int i = 0;
            for (auto ch: word)
            {
                i = next[i][ch-'a'];
                if (i==-1)
                {
                    flag = 0;
                    break;
                }                
            }
            if (flag) ret++;
        }
        return ret;        
    }    
};