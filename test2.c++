using namespace std;
#include<stdio.h>
#include<bits/stdc++.h>
#define MAXIN 2050

typedef struct Edge{
    int dest;
    long long weight;
}edge;

struct cmp_weight{
    bool operator()(edge a, edge b){
        return a.weight > b.weight;
    }
};

vector<edge> adj_map[MAXIN];
long long master_dis[MAXIN];
long long dis[MAXIN];
priority_queue<edge, vector<edge>, cmp_weight> pq;

void master_dis_init(int n){
    for(int i = 1; i <= n; i++){
        master_dis[i] = LLONG_MAX;
    }
    master_dis[1] = 0;
    for(auto i : adj_map[1]){
        master_dis[i.dest] = i.weight;
    }
}

void dis_init(int n, int portal){
    edge tmp;
    for(int i = 1; i <= n; i++){
        if(i == portal){
            dis[i] = 0;
            tmp.weight = 0;
            tmp.dest = i;
            pq.push(tmp);
        }
        else if(master_dis[i] != LLONG_MAX){
            dis[i] = master_dis[i];
            tmp.weight = master_dis[i];
            tmp.dest = i;
            pq.push(tmp);
        }
        else{
            dis[i] = LLONG_MAX;
        }
    }
}

long long dis_sum(int n){
    long long sum = 0;
    for(int i = 1; i <= n; i++){
        sum += dis[i];
    }
    return sum;
}

void dijkstra(int n){
    while(!pq.empty()){
        edge tmp;
        tmp = pq.top();
        pq.pop();
        for(auto i : adj_map[tmp.dest]){
            if(dis[tmp.dest] + i.weight < dis[i.dest]){
                dis[i.dest] = dis[tmp.dest] + i.weight;
                pq.push(i);
            }
        }
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int start;
    edge tmp;
    for(int i = 0; i < m; i++){
        scanf("%d%d%lld", &start, &tmp.dest, &tmp.weight);
        adj_map[start].push_back(tmp);
    }
    master_dis_init(n);
    long long min_sum = LLONG_MAX;
    for(int i = 2; i <= n; i++){
        dis_init(n, i);
        dijkstra(n);
        long long sum = dis_sum(n);
        if(sum < min_sum){
            min_sum = sum;
        }
    }

    printf("%lld\n", min_sum);

    return 0;
}