class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        deque<pair<int,int>> dq;
        dist[0][0]=grid[0][0];
        dq.push_front({0,0});
        vector<pair<int,int>> directions = {
            {-1,0}, {1,0},{0,-1},{0,1}
        };

        while (!dq.empty()){
            pair<int,int> current = dq.front();
            dq.pop_front();

            int row = current.first;
            int col = current.second;

            for (auto dir : directions){
                int newRow=row+dir.first;
                int newCol=col+dir.second;

                if(newRow <0 ||
                   newRow>= rows ||
                   newCol <0 ||
                   newCol>= cols){
                    continue;
                }
                
                int cost = grid[newRow][newCol];
                int newHealthLost = dist[row][col]+cost;
                if(newHealthLost<dist[newRow][newCol]){
                    dist[newRow][newCol]=newHealthLost;
                    if(cost==0){
                        dq.push_front({newRow,newCol});
                    }
                    else{
                        dq.push_back({newRow,newCol});
                    }
                }
            }
        } 
        return dist[rows-1][cols-1]< health;   
    }
};