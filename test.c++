using namespace std;
#include<stdio.h>
#include<bits/stdc++.h>

typedef struct Node{
    int paint_self_cost;
    int paint_subtree_cost;
}node;



int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int parent;
    vector<int> adj_map[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &parent);
        if(parent != -1){
            adj_map[i].push_back(parent);
        }
    }
    node tree_node[n];
    for(int i = 0; i < n; i++){
        scanf("%d%d", &tree_node[i].paint_self_cost, &tree_node[i].paint_subtree_cost);
    }

    

    return 0;
}