#include <bits/stdc++.h>
using namespace std;

stack<long long> dango_stack;

void put_dango(){
    long long dango_weight;
    scanf("%lld", &dango_weight);
    dango_stack.push(dango_weight);
}

void take_dango(){
    printf("%lld\n", dango_stack.top());
    dango_stack.pop();
}

void CC(){
    vector<long long> vec;
    stack<long long> tmp;
    int x;
    scanf("%d", &x);
    for(int i = 0; i < x; i++){
        vec.push_back(dango_stack.top());
        tmp.push(dango_stack.top());
        dango_stack.pop();
    }
    sort(vec.begin(), vec.end());
    int k;
    scanf("%d", &k);
    long long dango_sum = 0;
    int a;
    if(x % k == 0){
        a = x / k;
    }
    else{
        a = x / k + 1;
    }
    for(int i = vec.size() - a; i < vec.size(); i++){
        dango_sum += vec[i];
    }
    long long target = vec[vec.size() - a];
    for(int i = 0; i < x; i++){
        if(tmp.top() < target){
            dango_stack.push(tmp.top());
        }
        tmp.pop();
    }
    printf("%lld\n", dango_sum);
}

void DD(){
    stack<long long> tmp;
    long long dango_sum = 0;
    int x;
    scanf("%d", &x);
    for(int i = 0; i < x; i++){
        dango_sum += dango_stack.top();
        tmp.push(dango_stack.top());
        dango_stack.pop();
    }
    printf("%lld\n", dango_sum);
    for(int i = 0; i < x; i++){
        dango_stack.push(tmp.top());
        tmp.pop();
    }
}

int main(){
    int m;
    scanf("%d", &m);
    char operation[10]; 
    for(int i = 0; i < m; i++){
        scanf("%s", operation);
        if(strcmp(operation, "PUT") == 0){
            put_dango();
        }
        else if(strcmp(operation, "TAKE") == 0){
            take_dango();
        }
        else if(strcmp(operation, "CC") == 0){
            CC();
        }
        else if(strcmp(operation, "DD") == 0){
            DD();
        }
    }

    return 0;
}