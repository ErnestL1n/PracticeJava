// c++ Prim's with priority queue(min priority queue) implementation 
typedef pair<int,int> pr;
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int res=0,connected=0,n=points.size(),from=0;
        vector<bool> visited(n);
        priority_queue<pr,vector<pr>,greater<pr>> pq;
        while(++connected<n){
            visited[from]=true;
            for(int j=0;j<n;++j)
                if(!visited[j])
                    pq.push({abs(points[from][0]-points[j][0])+abs(points[from][1]-points[j][1]),j});
            while(visited[pq.top().second])
                pq.pop();
            res+=pq.top().first;
            from=pq.top().second;
            pq.pop();
        }
        return res;
    }
};

//Kruskal  ,min heap implementation(fetch from back,compare to min priority queue fetch from top())
typedef array<int,3> ar;
class Solution {
public:
    int find(vector<int>& ds,int i){
        return ds[i]<0?i:ds[i]=find(ds,ds[i]);
    }
    int minCostConnectPoints(vector<vector<int>>& pts) {
        int res=0,n=pts.size();
        vector<int> ds(n,-1);
        vector<ar> arr;
        for(auto i=0;i<n-1;++i)
            for(auto j=i+1;j<n;++j)
                arr.push_back({abs(pts[i][0]-pts[j][0])+abs(pts[i][1]-pts[j][1]),i,j});
        make_heap(arr.begin(),arr.end(),greater<ar>());
        while(!arr.empty()){
            pop_heap(arr.begin(),arr.end(),greater<ar>());
            auto [dist,i,j]=arr.back();
            arr.pop_back();
            i=find(ds,i),j=find(ds,j);
            if(i!=j){
                res+=dist;
                ds[i]+=ds[j];
                ds[j]=i;
                if(ds[i]==-n)
                    break;
            }
        }
        return res;
    }
};



//Kruskal v2 much slower,text book union
typedef array<int,3> ar;
class Union{
    int components;
    vector<int> component;
public:
    Union(int n){
        components=n;
        for(int i=0;i<=n;++i)
            component.push_back(i);
    };
    int Find(int a){
        if(component[a]!=a)
            component[a]=Find(component[a]);
        return component[a];
    }
    bool Unite(int a,int b){
        if(Find(a)==Find(b))
            return false;
        component[Find(a)]=b;
        --components;
        return true;
    }
    bool United(){
        return components==1;
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int res=0,n=points.size();
        vector<ar> arr;
        for(int i=0;i<n-1;++i)
            for(int j=0;j<n;++j)
                arr.push_back({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]),i,j});
        make_heap(arr.begin(),arr.end(),greater<ar>());
        Union uf(n);
        while(!arr.empty()&&!uf.United()){
            pop_heap(arr.begin(),arr.end(),greater<ar>());
            auto [dist,i,j]=arr.back();
            arr.pop_back();
            if(uf.Unite(i,j))
                res+=dist;
        }
        return res;
    }
};









//optimal Prim's for Complete Graph
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size(),res=0,i=0,connected=0;
        vector<int> min_d(n,4000000);          //constraint:-10^6 <= xi, yi <= 10^6  thus initialization must >= 4*10^6
        while(++connected<n){
            min_d[i]=INT_MAX;
            int min_j=i;
            for(int j=0;j<n;++j){
                if(min_d[j]!=INT_MAX){
                min_d[j]=min(min_d[j],abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]));
                min_j = min_d[j] < min_d[min_j] ? j : min_j;
				}
            }
            res+=min_d[min_j];
            i=min_j;
        }
        return res;
    }
};















