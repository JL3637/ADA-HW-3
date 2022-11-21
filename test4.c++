using namespace std;
#include<stdio.h>
#include<bits/stdc++.h>
#define MAXIN 400050

typedef struct Edge{
    int source;
    int dest;
    long long length;
    long long toll;
}edge;

typedef struct Tree{
    int parent;
    long long l;
    long long t;
}tree;

struct cmp_weight{
    bool operator()(edge a, edge b){
        if(a.length > b.length){
            return 1;
        }
        else if(a.length == b.length){
            return a.toll > b.toll;
        }
        else{
            return 0;
        }
    }
};

vector<edge> adj_map[MAXIN];
tree mst[MAXIN];
int visited[MAXIN];
priority_queue<edge, vector<edge>, cmp_weight> pq;

void find_MST(){
    edge tmp;
    tmp.source = -1;
    tmp.dest = 0;
    tmp.length = 0;
    tmp.toll = 0;
    pq.push(tmp);
    while(!pq.empty()){
        tmp = pq.top();
        pq.pop();
        if(visited[tmp.dest]){
            continue;
        }
        visited[tmp.dest] = 1;
        mst[tmp.dest].parent = tmp.source;
        mst[tmp.dest].l = tmp.length;
        mst[tmp.dest].t = tmp.toll;
        for(auto i : adj_map[tmp.dest]){
            if(!visited[i.dest]){
                pq.push(i);
            }
        }
    }
}

long long toll_sum(int a){
    int tmp = a;
    int max_len = -1;
    long long t_sum = 0;
    while(tmp != -1){
        if(mst[tmp].l > max_len){
            max_len = mst[tmp].l;
            t_sum = mst[tmp].t;
        }
        else if(mst[tmp].l == max_len){
            t_sum += mst[tmp].t;
        }
        tmp = mst[tmp].parent;
    }
    
    return t_sum;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int start, end;
    edge tmp;
    for(int i = 0; i < m; i++){
        scanf("%d%d%lld%lld", &start, &end, &tmp.length, &tmp.toll);
        tmp.source = start;
        tmp.dest = end;
        adj_map[start].push_back(tmp);
        tmp.source = end;
        tmp.dest = start;
        adj_map[end].push_back(tmp);
    }
    find_MST();
    long long ans = 0;
    for(int i = 1; i < n; i++){
        ans += toll_sum(i);
        printf("%lld\n", ans);
    }
    printf("%lld\n", ans);

    return 0;
}