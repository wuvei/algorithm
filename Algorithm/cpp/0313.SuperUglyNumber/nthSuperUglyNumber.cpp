// Heap
class Solution {
public:
    # define pi pair<int,int>
    #define ll long long
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n);
        ugly[0]=1;

        int N=primes.size();
        vector<int> pointers(N,0);

        priority_queue<pi,vector<pi>,greater<>> heap;

        for(int i=0;i<N;i++){
            heap.push({primes[i],i});
        }

        for(int i=1;i<n;i++){
            int val=heap.top().first;
            int idx=heap.top().second;
            int ptr=pointers[idx];
            heap.pop();

            if(ugly[i-1]==val){
                ll next_val= 1LL*primes[idx]*ugly[pointers[idx]+1];

                if(next_val <= INT_MAX)
                    heap.push({next_val,idx});

                pointers[idx]++;
                i--;
                continue;
            }

            ugly[i]=val;
            ll next_val= 1LL*primes[idx]*ugly[pointers[idx]+1];

            if(next_val <= INT_MAX)
                heap.push({next_val,idx});

            pointers[idx]++;
        }
        return ugly[n-1];
    }
};


// DP
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n);
        if(n==1) return 1;
        dp[0]=1;
        vector<int> dp_pri(primes.size(),0),candidate(primes);
        for(int j=1;j<n;j++)
        {
            int mm=INT_MAX;
            for(int k=0;k<primes.size();k++)
            {
                if(candidate[k]==dp[j-1])
                {
                    dp_pri[k]++;
                    candidate[k]=primes[k]*dp[dp_pri[k]];
                }
                mm=min(mm,candidate[k]);
            }
            dp[j]=mm;
        }
        return dp[n-1];
    }
};