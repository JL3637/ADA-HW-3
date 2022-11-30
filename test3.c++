using namespace std;
#include<stdio.h>
#include<bits/stdc++.h>
#define MAXIN 3050

typedef struct Node{
    long long paint_self_cost;
    long long paint_subtree_cost;
    long long subtree_sum;
    int subtree_size;
}node;

vector<int> adj_map[MAXIN];
node tree_node[MAXIN];
vector<int> finish_stack;
int visited[MAXIN];
long long ans[MAXIN][MAXIN];
int pre_subt_node[MAXIN];

void DFS(int v){
    visited[v] = 1;
    long long subt_sum = tree_node[v].paint_self_cost;
    int subt_size = 1;
    for(auto i : adj_map[v]){
        if(!visited[i]){
            DFS(i);
            subt_sum += tree_node[i].subtree_sum;
            subt_size += tree_node[i].subtree_size;
        }
    }
    tree_node[v].subtree_sum = subt_sum;
    tree_node[v].subtree_size = subt_size;
    finish_stack.push_back(v);
}

void DP(int n, int m){
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            long long result = 0;
            long long self_c = tree_node[finish_stack[i-1]].paint_self_cost;
            long long subtree_c = tree_node[finish_stack[i-1]].paint_subtree_cost;
            long long subt_sum = tree_node[finish_stack[i-1]].subtree_sum;
            if(self_c > j && subtree_c > j){
                ans[i][j] = ans[i-1][j];
                continue;
            }
            else if(self_c <= j && subtree_c > j){
                long long tmp1 = ans[i-1][j-self_c] + self_c;
                long long tmp2 = ans[i-1][j];
                if(tmp1 > tmp2){
                    result = tmp1;
                }
                else{
                    result = tmp2;
                }
            }
            else if(self_c > j && subtree_c <= j){
                long long tmp1 = ans[i-tree_node[finish_stack[i-1]].subtree_size][j-subtree_c] + subt_sum;
                long long tmp2 = ans[i-1][j];
                if(tmp1 > tmp2){
                    result = tmp1;
                }
                else{
                    result = tmp2;
                }
            }
            else{
                long long tmp1 = ans[i-1][j-self_c] + self_c;
                long long tmp2 = ans[i-tree_node[finish_stack[i-1]].subtree_size][j-subtree_c] + subt_sum;
                long long tmp3 = ans[i-1][j];
                if(tmp1 > tmp2){
                    if(tmp1 > tmp3){
                        result = tmp1;
                    }
                    else{
                        result = tmp3;
                    }
                }
                else{
                    if(tmp2 > tmp3){
                        result = tmp2;
                    }
                    else{
                        result = tmp3;
                    }
                }
            }
            ans[i][j] = result;
        }
    }
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int parent;
    for(int i = 0; i < n; i++){
        scanf("%d", &parent);
        if(parent != -1){
            adj_map[parent].push_back(i);
        }
    }
    for(int i = 0; i < n; i++){
        scanf("%lld%lld", &tree_node[i].paint_self_cost, &tree_node[i].paint_subtree_cost);
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            DFS(i);
        }
    }
    DP(n, m);
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            printf("%lld ", ans[i][j]);
        }
        printf("\n");
    }
    printf("%lld", ans[n][m]);


    return 0;
}