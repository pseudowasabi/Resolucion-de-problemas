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

/*
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
*/
/*
// BOJ ID 2981
#include <iostream>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long tmp;
    set<long long > dat, dat2;
    for(int i=1;i<=n;++i){
        cin >> tmp;
        dat.insert(tmp);
    }

    long long prev = 0;
    for(auto i:dat){
        if(prev != 0){
            dat2.insert(i - prev);
        }
        prev = i;
    }
    
    long long crit = *(dat2.begin());
    bool flag;
    set<long long> candidate;
    for(long long i=2;i*i<=crit;++i){
        if(crit % i == 0){
            candidate.insert(i);
            candidate.insert(crit / i);
        }
    }
    candidate.insert(crit);
    for(auto i:candidate){
        flag = true;
        for(auto j:dat2){
            if(j % i != 0){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << i << ' ';
        }
    }
    return 0;
}
*/
/*
// BOJ ID 2164
#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n;

    cin >> n;
    queue<int> model;
    for(int i=1;i<=n;++i){
        model.push(i);
    }
    int tmp;
    for(;model.size() != 1;){
        model.pop();
        tmp = model.front();
        model.pop();
        model.push(tmp);
    }
    cout << model.front();
    return 0;
}
*/

/*
// BOJ ID 11866
#include <iostream>
using namespace std;

int eliminated[100010];
int main(){
    int n, k;
    cin >> n >> k;

    int check = 0;
    cout << '<';
    bool if_first = true;
    for(int i = 1, kk = 0;check != n;){
        if(!eliminated[i]){
            ++ kk;

            if(kk == k){
                eliminated[i] = 1;
                if(if_first){
                    cout << i;
                    if_first = false;
                }
                else {
                    cout << ", " << i;
                }
                kk = 0;
                check ++;
            }
        }
        ++ i;
        if(i > n){
            i = 1;
        }
    }
    cout << '>';
    return 0;
}
*/

/*
// BOJ ID 1966
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    int n, m;    
    queue<pair<int, int>> dat;
    int check[10];
    for(int t=1;t<=T;++t){
        for(;!dat.empty();dat.pop());
        memset(check, 0, sizeof(check));

        cin >> n >> m;
        for(int i=0, tmp;i<n;++i){
            cin >> tmp;
            dat.push(make_pair(i, tmp));
            check[tmp] ++;
        }

        int time_count = 0;
        bool flag1, flag2;
        while (true) {
            flag1 = true;
            for(int i=dat.front().second+1;i<10;++i){
                if(check[i] > 0){
                    flag1 = false;
                    break;
                }
            }
            pair<int, int> fr = dat.front();
            dat.pop();
            if(!flag1){
                dat.push(fr);
            }
            else {
                time_count ++;
                check[fr.second] --;

                if(fr.first == m){
                    cout << time_count << '\n';
                    break;
                }
            }
        }
    }
    return 0;
}*/

/*
// BOJ ID 1629
// 분할 정복의 분할 정복
#include <iostream>
#include <cmath>
using namespace std;

double log2(double x){
    return log(x) / log(2);
}


long long a, b, c;

long long multiply(long long k2){
    if(k2 == 1){
        return a % c;
    }
    return (multiply(k2/2) * multiply(k2/2)) % c;
} // 승수를 분할 정복으로 (분할 정복 1)

int main(){
    cin >> a >> b >> c;
    long long ktmp, k, d;
    long long res = 1, tt;
    while(b > 0){
        ktmp = int(log2(double(b))); 
        k = int(pow(2.0, ktmp));// b보다 작은 가장 큰 2의 승수
        d = b - k; // b와의 차이.

        tt = multiply(k);
        res = (res * tt) % c;

        b = d; // 남은 것에 대해 한번 더 해줌.
    } // 나머지 파트를 또 2의 자승으로 나누는 (분할 정복 2)

    cout << res;
    return 0;
} */

/*
// BOJ ID 1931 회의실 배정 (Greedy)
// 종료 시간 기준으로 정렬해서 하나씩 차자작 고르면 되는 문제.
#include <iostream>
#include <set>
#include <utility>
using namespace std;

int main(){
    int n;
    cin >> n;
    multiset<pair<long long, long long> > timetable;
    long long s, e;
    for(int i=1;i<=n;++i){
        cin >> s >> e;
        timetable.insert({e, s});
    }

    pair<long long, long long> prev = {-1, 0};
    long long count = 0;
    for(auto i:timetable){
        if(i.second >= prev.first){
            count ++;
            prev = i;
        }
    }

    cout << count;
    return 0;
}
*/

/*
// BOJ ID 11399
#include <iostream>
using namespace std;

int p[1010];
int main(){
    int n;
    cin >> n;
    for(int i=1, tmp;i<=n;++i){
        cin >> tmp;
        p[tmp] ++;
    }
    long long result = 0;
    long long count = 0;
    for(int i=1;i<=1000;++i){
        for(;p[i]>0;--p[i]){
            count += i;
            result += count;
        }
    }
    cout << result;
    return 0;
} */
/*
// BOJ ID 1541
// -가 나오면 그 뒤에 나오는거 쭉 다 빼주고
// 다음 -가 나올 때까지 위 과정을 반복. (Greedy)
#include <iostream>
using namespace std;

int main(){
    char formula[55];
    cin >> formula;

    int result = 0;
    int now = 0;
    int subres = 0;
    bool minus_active = false;
    for(char *c=formula;*c!='\0';c++){
        if(*c >= '0' && *c <= '9'){
            now *= 10;
            now += int(*c - '0');
        }
        else if(*c == '+'){
            subres += now;
            now = 0;
        }
        else if(*c == '-'){
            subres += now;
            if(!minus_active){
                result += subres;
                minus_active = true;
            }
            else {
                result -= subres;
            }
            now = 0;
            subres = 0;
        }
    }
    subres += now;

    if(minus_active){
        result -= subres;
    }
    else {
        result += subres;
    }
    cout << result;
    return 0;
}*/
/*
// BOJ ID 1021
#include <iostream>
#include <deque>
using namespace std;

inline void rotate_left(deque<int>& dat){
    int tmp = dat.front();
    dat.pop_front();
    dat.push_back(tmp);
}

inline void rotate_right(deque<int>& dat){
    int tmp = dat.back();
    dat.pop_back();
    dat.push_front(tmp);
} // 사용 x

int min(int a, int b){
    return a < b? a: b;
}

int main(){
    deque<int> dat;
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;++i){
        dat.push_back(i);
    }
    int cnt = 0, cnt_now;
    for(int i=1, now;i<=m;++i){
        cin >> now;
        cnt_now = 0;
        while(dat.front() != now){
            rotate_left(dat);
            cnt_now ++;
        }

        cnt += min(cnt_now, dat.size()-cnt_now);
        dat.pop_front();
    }
    cout << cnt;
    return 0;
} */
/*
// BOJ ID 5430
#include <iostream>
#include <cstring>
#include <deque>
using namespace std;

char cmd[100001];
deque<int> check;
char elem[10100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    
    int n;
    bool flag;
    int now;
    bool error;
    for(int t=1;t<=T;++t){
        cin >> cmd;
        check.clear();
        flag = false;
        cin >> n;
        cin >> elem;

        now = 0;
        for(char *c=elem;*c!='\0';++c){
            switch(*c){
            case '[':
            break;
            case ',':
            case ']':
                if(now != 0){
                    check.push_back(now);
                }
                now = 0;
            break;
            default:
                now = now * 10 + int(*c-'0');
            }
        }

        error = false;
        for(char *c=cmd;*c!='\0' && !error;++c){
            switch(*c){
            case 'R':
                flag = !flag;
            break;
            case 'D':
                if(check.empty()){
                    error = true;
                }
                else{
                    if(!flag) check.pop_front();
                    else check.pop_back();
                }
            break;
            }
        }

        if(error){
            cout << "error\n";
        }
        else {
            cout << '[';
            while(!check.empty()){
                if(!flag){
                    cout << check.front();
                    check.pop_front();
                }
                else {
                    cout << check.back();
                    check.pop_back();
                }
                if(!check.empty()){
                    cout << ',';
                }
            }
            cout << "]\n";
        }
    }
    return 0;
} */

/*
// BOJ ID 2667
#include <iostream>
#include <queue>
#include <utility>
#include <set>
using namespace std;

int n;
char map[30][30];
int check[30][30];

int dx[] = {0, +1, 0, -1};
int dy[] = {+1, 0, -1, 0};

//int result[400];
multiset<int> result;

void bfs(int x, int y, int count){
    queue<pair<int, int> > next;

    next.push({x, y});
    pair<int, int> now;
    check[x][y] = count;

    int this_count = 0;
    while(!next.empty()){
        now = next.front();
        next.pop();
        this_count ++;
        for(int i=0;i<4;++i){
            if(now.first+dx[i]>=0 && now.first+dx[i]<n && now.second+dy[i]>=0 && now.second+dy[i]<n && map[now.first+dx[i]][now.second+dy[i]] == '1' && !check[now.first+dx[i]][now.second+dy[i]]){
                next.push({now.first+dx[i], now.second+dy[i]});
                check[now.first+dx[i]][now.second+dy[i]] = count;
            }
        }
    }

    result.insert(this_count);
}

int main(){
    cin >> n;
    for(int i=0;i<n;++i){
        cin >> map[i];
    }

    int count = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(map[i][j] == '1' && !check[i][j]){
                bfs(i, j, ++count);
            }
        }
    }

    cout << count << endl;
    for(auto i:result){
        cout << i << endl;
    }
    return 0;
} */

/*
// BOJ ID 1012
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int m, n;
int farm[60][60];
int dx[] = {+1, 0, -1, 0};
int dy[] = {0, +1, 0, -1};
void worm(int x, int y){
    queue<pair<int, int> > next;
    pair<int, int> now;

    next.push({x, y});
    farm[x][y] = 2;
    while(!next.empty()){
        now = next.front();
        next.pop();
        for(int i=0;i<4;++i){
            if(now.first+dx[i]>=0 && now.first+dx[i]<m && now.second+dy[i]>=0 && now.second+dy[i]<n && farm[now.first+dx[i]][now.second+dy[i]] == 1){
                next.push({now.first+dx[i], now.second+dy[i]});
                farm[now.first+dx[i]][now.second+dy[i]] = 2;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    int k, x, y;
    int count;
    for(int t=1;t<=T;++t){
        cin >> m >> n;
        memset(farm, 0, sizeof(farm));
        cin >> k;
        for(int i=1;i<=k;++i){
            cin >> x >> y;
            farm[x][y] = 1;
        }

        count = 0;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(farm[i][j] == 1){
                    worm(i, j);
                    ++ count;
                }
            }
        }

        cout << count << '\n';
    }
    return 0;
} */

/*
// BOJ ID 2178
// BFS로 최단 경로 찾기 (가중치 x, goal state 있음)
#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

inline int in_scale(int a, int s){
    return a>=0 && a<s? 1: 0;
}

int main(){
    int n, m;
    char maze[101][101];
    int check[101][101];
    int dx[] = {0, +1, 0, -1};
    int dy[] = {+1, 0, -1, 0};

    memset(check, 0, sizeof(check));
    cin >> n >> m;
    for(int i=0;i<n;++i){
        cin >> maze[i];
    }

    queue<pair<int, int> > next;
    pair<int, int> now;

    next.push({0, 0});
    check[0][0] = 1;
    int next_x, next_y;

    bool end_flag = false;
    while(!next.empty() && !end_flag){
        now = next.front();
        next.pop();
        for(int i=0;i<4;++i){
            next_x = now.first + dx[i];
            next_y = now.second + dy[i];

            if(in_scale(next_x, n) && in_scale(next_y, m) && maze[next_x][next_y] == '1' && !check[next_x][next_y]){
                next.push({next_x, next_y});
                check[next_x][next_y] = check[now.first][now.second] + 1;

                if(next_x == n-1 && next_y == m-1){
                    end_flag = true;
                    break;
                }
            }
        }
    }

    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cout << check[i][j];
        }
        cout << endl;
    }
    cout << check[n-1][m-1];
    return 0;
} */
/*
// BOJ ID 7576
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

inline bool in_range(int a, int s){
    return a >=0 && a < s? true: false;
}

int box[110][110][110];
const int dx[] = {0, 0, 0, +1, 0, -1};
const int dy[] = {0, 0, +1, 0, -1, 0};
const int dz[] = {+1, -1, 0, 0, 0, 0};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, h;
    cin >> m >> n >> h;

    queue<pair<pair<int, int>, int> > next;
    pair<pair<int, int>, int> now;

    for(int k=0;k<h;++k){
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin >> box[i][j][k];
                if(box[i][j][k] == 1){
                    next.push({{i, j}, k});
                }
            }
        }
    }

    if(next.size() == m * n * h){
        cout << 0;
        return 0;
    }

    int next_x, next_y, next_h;
    while(!next.empty()){
        now = next.front();
        next.pop();

        for(int i=0;i<6;++i){
            next_x = now.first.first + dx[i];
            next_y = now.first.second + dy[i];
            next_h = now.second + dz[i];

            if(in_range(next_x, n) && in_range(next_y, m) && in_range(next_h, h) && !box[next_x][next_y][next_h]){
                box[next_x][next_y][next_h] = box[now.first.first][now.first.second][now.second] + 1;
                next.push({{next_x, next_y}, next_h});
            }
        }
    }

    int day = 0;
    bool impossible = false;
    for(int i=0;i<n && !impossible;++i){
        for(int j=0;j<m;++j){
            for(int k=0;k<h;++k){
                day = box[i][j][k] > day? box[i][j][k]: day;
                if(!box[i][j][k]){
                    impossible = true;
                    break;
                }
            }
        }
    }

    cout << (impossible? -1: day - 1);
    return 0;
} */

// BOJ ID 1697
#include <iostream>
#include <queue>
using namespace std;

int check[100001];
int main(){
    int n, k;
    cin >> n >> k;
    check[n] = 1;
    // 다 돌려도 탐색 공간이 10만 * log2(10만) = 160만 정도

    queue<int> next;
    next.push(n);

    int now;
    while(!next.empty()){
        now = next.front();
        next.pop();
        
        if(now == k){
            break;
        }

        if(now-1 >=0 && !check[now-1]){
            check[now-1] = check[now] + 1;
            next.push(now-1);
        }
        if(now+1 <= 100000 && !check[now+1]){
            check[now+1] = check[now] + 1;
            next.push(now+1);
        }
        if(2*now <= 100000 && !check[2*now]){
            check[2*now] = check[now] + 1;
            next.push(2*now);
        }
    }
    while(!next.empty()){
        next.pop();
    }
    cout << check[k] - 1;
    return 0;
}