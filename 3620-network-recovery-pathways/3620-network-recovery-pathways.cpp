class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        vector<vector<pair<int,int>>> adj(n);
        vector<int> indeg(n,0), costs;
        for (auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
            indeg[e[1]]++;
            costs.push_back(e[2]);

        } 
        sort(costs.begin(), costs.end());
        costs.erase(unique(costs.begin(), costs.end()),costs.end());
        queue<int> q;
        for(int i=0; i<n;i++){
            if(indeg[i]==0) q.push(i);

        }  
        vector<int> topo;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            topo.push_back(u);
            for(auto &p:adj[u]){
                int v=p.first;
                indeg[v]--;
                if(indeg[v]==0) q.push(v);

            }
        }
        auto check =[&](int mn){
            vector<long long> dp(n, 1e18);
            dp[0]=0;
            for(int u:topo){
                if (dp[u]==1e18||!online[u]) continue;
                for (auto &p:adj[u]){
                    int v=p.first;
                    int w=p.second;
                    if (w>=mn&&online[v]){
                        if (dp[u]+w<dp[v]){
                            dp[v]=dp[u]+w;
                        }
                    }
                }
            }
            return dp[n-1]<=k;
        };
        int l=0, r=costs.size()-1, ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if (check(costs[mid])){
                ans=costs[mid];
                l=mid+1;
            }else r=mid-1;
        }
        return ans;
    }
};