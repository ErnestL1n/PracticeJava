//Dijkstra
typedef pair<int, int> pii;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pii>>vp(N+1);
        for(const auto&time:times)    vp[time[0]].emplace_back(time[1],time[2]);
        vector<bool>visited(N+1,false);
        vector<int>d(N+1,INT_MAX);
        d[0]=0,d[K]=0;
        priority_queue<pii,vector<pii>,greater<pii>>pq;
        pq.emplace(0,K);
        while(!pq.empty()){
            auto [c,u] = pq.top();
            pq.pop();
            if(visited[u]) continue;
            for(auto to:vp[u]){
                auto[v,w]=to;
                if(c+w<d[v])    {
                    d[v]=c+w;
                    pq.emplace(d[v],v);
                }
            }
            visited[u]=true;
        }
        int res = *max_element(begin(d),end(d));
        return res==INT_MAX?-1:res;
    }
};






//Bellman Ford
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N + 1, INT_MAX);
        dist[0] = dist[K] = 0;
        for (int i = 0; i < N; i++) {
            for (auto& e : times) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        int res=*max_element(begin(dist),end(dist));
        return res == INT_MAX ? -1 : res;
    }
};