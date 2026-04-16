// GPT5
#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
using i128 = __int128_t;

struct PP {
    long long p, a, m;           // prime p, exponent a, modulus m=p^a
    vector<long long> f;         // f[i] = product_{1..i, p∤j} j (mod m)
};

long long powll(long long a, long long e, long long mod){
    long long r = 1 % mod;
    while(e){
        if(e&1) r = (i128)r*a % mod;
        a = (i128)a*a % mod;
        e >>= 1;
    }
    return r;
}

long long exgcd(long long a, long long b, long long &x, long long &y){
    if(b==0){ x= (a>=0?1:-1); y=0; return llabs(a); }
    long long x1,y1; long long g=exgcd(b,a%b,x1,y1);
    x=y1; y=x1 - (a/b)*y1; return g;
}

long long invmod(long long a, long long m){
    long long x,y; long long g = exgcd(a,m,x,y);
    // 여기서는 항상 gcd(a,m)=1 보장(배수 제거 팩토리얼)
    x%=m; if(x<0) x+=m; return x;
}

long long vp(long long n, long long p){
    long long s=0; while(n){ n/=p; s+=n; } return s;
}

// factmod(n): n!에서 p-인수 제거한 나머지 (mod p^a)
long long factmod(long long n, const PP& pp){
    if(n==0) return 1 % pp.m;
    long long res = factmod(n/pp.p, pp);
    // 블록 곱 f[m]은 홀수 p에 대해 -1 (mod p^a) → (n/ m) 번만큼 곱 → 부호만 반전
    if( (n/pp.m) & 1 ) res = (pp.m - res) % pp.m;   // 곱하기 -1
    res = (i128)res * pp.f[n % pp.m] % pp.m;
    return res;
}

long long nCk_mod_p_power(long long n, long long k, const PP& pp){
    if(k<0 || k>n) return 0;
    long long e = vp(n, pp.p) - vp(k, pp.p) - vp(n-k, pp.p);
    if(e >= pp.a) return 0;

    long long num = factmod(n, pp);
    long long den = (i128)factmod(k, pp) * factmod(n-k, pp) % pp.m;
    long long inv = invmod(den, pp.m);
    long long ans = (i128)num * inv % pp.m;
    if(e) ans = (i128)ans * powll(pp.p, e, pp.m) % pp.m;
    return ans;
}

pair<long long,long long> crt_pair(long long r1, long long m1, long long r2, long long m2){
    // m1, m2 are coprime
    long long t = (r2 - r1) % m2; if(t<0) t+=m2;
    long long inv = invmod(m1 % m2, m2);
    long long k = (i128)t * inv % m2;
    long long res = (r1 + (i128)m1 * k) % (m1*m2);
    if(res<0) res += m1*m2;
    return {res, m1*m2};
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 준비: 3^3, 11, 13, 37
    vector<PP> mods;
    {
        PP x; x.p=3; x.a=3; x.m=27; x.f.assign(x.m+1,1);
        for(long long i=1;i<=x.m;i++) x.f[i] = (i%3? (i128)x.f[i-1]*i % x.m : x.f[i-1]);
        mods.push_back(x);
    }
    for(long long p: {11,13,37}){
        PP x; x.p=p; x.a=1; x.m=p; x.f.assign(x.m+1,1);
        for(long long i=1;i<=x.m;i++) x.f[i] = (i%p? (i128)x.f[i-1]*i % x.m : x.f[i-1]);
        mods.push_back(x);
    }

    int T; if(!(cin>>T)) return 0;
    const long long MOD = 142857LL;

    while(T--){
        long long N,K; cin>>N>>K;

        long long r = 0, m = 1;
        for(const auto& pp: mods){
            long long ri = nCk_mod_p_power(N, K, pp);
            auto pr = crt_pair(r, m, ri, pp.m);
            r = pr.first; m = pr.second;
        }
        cout << (r % MOD + MOD) % MOD << '\n';
    }
    return 0;
}
