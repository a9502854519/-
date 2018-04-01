//
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \\|     |// '.
//                 / \\|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \\\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//
//
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
//               佛祖保佑         永無BUG
//
//
//
#include<iostream>
#include<cstdio>
#include<algorithm>
#define MAX_N 100000 + 100

using namespace std;
typedef long long ll;

struct Data{
    ll w, f;
    Data() {}
    Data(ll w, ll f) : w(w), f(f) {}
}p[MAX_N];
int N;

bool cmp(const Data& a, const Data& b){
    return a.w * b.f < b.w * a.f;
}
ll solve(){
    sort(p, p + N, cmp);
    ll res = 0, sum = 0;
    for(int i = 0; i < N; i++){
        res += sum * p[i].f;
        sum += p[i].w;
    }
    return res;
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++) scanf("%lld", &p[i].w);
    for(int i = 0; i < N; i++) scanf("%lld", &p[i].f);
    cout << solve() << endl;
    return 0;
}