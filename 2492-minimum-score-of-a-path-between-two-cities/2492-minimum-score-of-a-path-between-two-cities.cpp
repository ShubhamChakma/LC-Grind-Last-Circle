class Solution {
public:
    int findparent(int node, vector<int>& parent) {
        if(parent[node]==node){
            return node;
        }      
        parent[node]= findparent(parent[node], parent);
        return parent[node];

    }
    int minScore(int n, vector<vector<int>>&roads ){
        vector <int> parent(n+1);
        for( int i=1; i<=n; i++){
            parent[i]=i;

        }
        for (auto road:roads){
            int city1=road[0];
            int city2=road[1];
            int parent1= findparent(city1, parent);
            int parent2= findparent(city2, parent);
            parent[parent1]=parent2;


        }
        int group=findparent(1, parent);
        int answer = INT_MAX;
        for (auto road:roads){
            int city1=road[0];
            int distance=road[2];
            if(findparent(city1, parent)==group){
                answer=min(answer,distance);

            }

        }
        return answer;

    }
};