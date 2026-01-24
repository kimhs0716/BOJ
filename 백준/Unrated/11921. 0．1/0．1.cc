#include <cstdio>
#include <unistd.h>
using namespace std;
typedef long long int lld;
constexpr int SZ = 1 << 16;
int main(){
    char r[SZ], *p = r; read(0, r, SZ);
    auto ReadChar = [&](){
        if(p == r + SZ) read(0, p = r, SZ);
        return *p++;
    };
    auto ReadInt = [&](){
        int ret = 0;
        for(char c = ReadChar(); c & 16; ret = ret * 10 + (c & 15), c = ReadChar());
        return ret;
    };
    lld n = ReadInt(), sum = 0;
    for(int i = 0; i < n; i++){
        sum += ReadInt();
    }
    printf("%lld\n%lld\n", n, sum);
    return 0;
}
