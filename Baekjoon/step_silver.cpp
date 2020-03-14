/*
// BOJ ID 15652
#include <iostream>
#include <vector>
using namespace std;

void pick(int n, int mtogo, vector<int>& picked){
    if(mtogo == 0){
        for(auto i:picked){
            cout << i << ' ';
        }
        cout << '\n';
        return ;
    }
    int now;
    if(picked.empty() == true){
        now = 1;
    }
    else {
        now = picked.back();
    }
    for(int i=now;i<=n;++i){
        picked.push_back(i);
        pick(n, mtogo-1, picked);
        picked.pop_back();
    }
}

int main(){
    int n, m;
    vector<int> picked;

    cin >> n >> m;
    pick(n, m, picked);
    return 0;
} */
/*
// BOJ ID 1912
#include <iostream>
using namespace std;

int max(int a, int b){
    return a > b ? a: b;
}

int main(){
    int n;
    cin >> n;
    long long local_min, local_max, accumulation, candidate;
    local_min = local_max = accumulation;
    candidate = -9999999999;
    for(int tmp;n>0;--n){
        cin >> tmp;
        accumulation += tmp;
        if(accumulation < local_min){ // local 최소값 들어오면 local 최대값 초기화, 후보 선택 보류.
            local_min = accumulation;
            local_max = local_min;
        }
        if(accumulation > local_max){ // local 최대값 들어오면 후보 선택.
            local_max = accumulation;
            candidate = max(local_max-local_min, candidate);
        }
        candidate = max(candidate, tmp); // 지금 것 하나만 가져가는 경우.
        //cout << "lmin: " << local_min << "lmax: " << local_max << "cand: " << candidate << endl;
    }
    cout << candidate;
    return 0;
}*/

/*
// BOJ ID 10773
#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> zerothatout;
    int k;

    cin >> k;
    for(int i=1, tmp;i<=k;++i){
        cin >> tmp;
        if(tmp != 0){
            zerothatout.push(tmp);
        }
        else{
            zerothatout.pop();
        }
    }

    int sum = 0;
    for(;!zerothatout.empty();){
        sum += zerothatout.top();
        zerothatout.pop();
    }

    cout << sum;
}*/

// BOJ ID 2004
// 조합 0의 개수 (예전에 못 풀고 남겨 두었던 것)
#include <iostream>
#include <vector>
using namespace std;

void get_divs(vector<long long>& data, long long n){
    long long delim = 2000000000;
    for(long long i=1;i<=delim;i*=n){
        if(i != 1){
            data.push_back(i);
        }
    }
}

void check(vector<long long>& data, long long& count, long long now){
    for(auto i:data){
        count += (now / i);
    }
}

long long min(long long a, long long b){
    return a < b? a: b;
}

int main(){
    long long n, m;
    cin >> n >> m;

    vector<long long> div2, div5;
    get_divs(div2, 2);
    get_divs(div5, 5);

    long long cnt2, cnt5;
    cnt2 = cnt5 = 0;
    
    long long a2, b2, c2, a5, b5, c5;
    a2 = b2 = c2 = a5 = b5 = c5 = 0;

    check(div2, a2, n);
    check(div2, b2, m);
    check(div2, c2, n-m);
    check(div5, a5, n);
    check(div5, b5, m);
    check(div5, c5, n-m);

    long long r2, r5;
    r2 = a2 - (b2 + c2);
    r5 = a5 - (b5 + c5);

    cout << min(r2, r5);
    return 0;
}