#include <bits/stdc++.h>
using namespace std;

vector<long long> dango_stack;
vector<long long> dango_stack_sum;

void put_dango(){
    long long dango_weight;
    scanf("%lld", &dango_weight);
    if(dango_stack_sum.empty()){
        dango_stack.push_back(dango_weight);
        dango_stack_sum.push_back(dango_weight);
    }
    else{
        long long pre_dango = dango_stack_sum[dango_stack_sum.size()-1];
        dango_stack.push_back(dango_weight);
        dango_stack_sum.push_back(dango_weight + pre_dango);
    }
}

void take_dango(){
    printf("%lld\n", dango_stack[dango_stack.size()-1]);
    dango_stack.pop_back();
    dango_stack_sum.pop_back();
}

void CC(){
    vector<long long> vec;
    stack<long long> tmp;
    int x;
    scanf("%d", &x);
    for(int i = 0; i < x; i++){
        vec.push_back(dango_stack[dango_stack.size()-1]);
        tmp.push(dango_stack[dango_stack.size()-1]);
        dango_stack.pop_back();
        dango_stack_sum.pop_back();
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
            dango_stack.push_back(tmp.top());
            if(dango_stack_sum.empty()){
                dango_stack_sum.push_back(tmp.top());
            }
            else{
                long long pre_dango = dango_stack_sum[dango_stack_sum.size()-1];
                dango_stack_sum.push_back(tmp.top() + pre_dango);
            }
        }
        tmp.pop();
    }
    printf("%lld\n", dango_sum);
}

void DD(){
    long long dango_sum = 0;
    int x;
    scanf("%d", &x);
    if(x == dango_stack_sum.size()){
        printf("%lld\n", dango_stack_sum[dango_stack_sum.size()-1]);
    }
    else{
        printf("%lld\n", dango_stack_sum[dango_stack_sum.size()-1] - dango_stack_sum[dango_stack_sum.size()-x-1]);
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