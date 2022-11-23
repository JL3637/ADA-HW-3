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

typedef struct Length_and_sum{
    long long max_length;
    long long toll_sum;
}length_and_sum;

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
length_and_sum max_len_sum[MAXIN];
int visited[MAXIN];
priority_queue<edge, vector<edge>, cmp_weight> pq;

void find_MST(){
    visited[0] = 1;
    for(auto i : adj_map[0]){
        pq.push(i);
    }
    edge tmp;
    while(!pq.empty()){
        tmp = pq.top();
        pq.pop();
        if(visited[tmp.dest]){
            continue;
        }
        visited[tmp.dest] = 1;
        if(tmp.source == 0 || tmp.length > max_len_sum[tmp.source].max_length){
            max_len_sum[tmp.dest].max_length = tmp.length;
        }
        else{
            max_len_sum[tmp.dest].max_length = max_len_sum[tmp.source].max_length;
        }
        max_len_sum[tmp.dest].toll_sum = tmp.toll;
        for(auto i : adj_map[tmp.dest]){
            if(!visited[i.dest]){
                if(i.length == max_len_sum[tmp.dest].max_length){
                    i.toll += max_len_sum[tmp.dest].toll_sum;
                }
                else if(i.length < max_len_sum[tmp.dest].max_length){
                    i.toll = max_len_sum[tmp.dest].toll_sum;
                }
                pq.push(i);
            }
        }
    }
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
        ans += max_len_sum[i].toll_sum;
    }
    printf("%lld\n", ans);

    return 0;
}