#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

constexpr int sz = 1 << 10;

class BigInt {
public:
    bool flag; // 0: pos, 1: neg
    int length;
    char* number;

    BigInt();
    BigInt(const BigInt& bi);
    BigInt(const char *str);
    ~BigInt();

    BigInt& operator= (const BigInt& bi) {
        if (number != NULL) free(number);
        flag = bi.flag;
        length = bi.length;
        number = (char*)malloc(sz);
        strcpy(number, bi.number);
        return *this;
    }
};

BigInt operator+(const BigInt& b1, const BigInt& b2);
bool compare(const BigInt& b1, const BigInt& b2);
void PrintBigInt(const BigInt& bi);

int main() {
    int n; scanf("%d", &n);
    char num[100]; scanf("%s", num);
    BigInt dp, dp_prev(num);
    BigInt M(dp_prev);
    for (int i = 1; i < n; i++) {
        scanf("%s", num);
        if (dp_prev.flag) dp = BigInt(num);
        else dp = dp_prev + BigInt(num);
        if (M.flag == 0) {
            if (dp.flag == 0 && compare(dp, M)) M = dp;
        }
        else {
            if (dp.flag == 0 || (dp.flag && compare(M, dp))) M = dp;
        }
        dp_prev = dp;
    }
    PrintBigInt(M);
    return 0;
}

BigInt::BigInt() {
    this->flag = 0;
    this->length = 1;
    this->number = (char*)malloc(sz);
    memset(this->number, '0', sz - 1);
    this->number[sz - 1] = '\0';
}

BigInt::BigInt(const BigInt& bi) {
    this->flag = bi.flag;
    this->length = bi.length;
    this->number = (char*)malloc(sz);
    strcpy(this->number, bi.number);
}

BigInt::BigInt(const char* str) {
    if (str[0] == '-') {
        this->flag = 1;
        str++;
    }
    else this->flag = 0;
    this->length = strlen(str);
    this->number = (char*)malloc(sz);
    memset(this->number, '0', sz - this->length - 1);
    this->number[sz - this->length - 1] = '\0';
    strcat(this->number, str);
}

BigInt::~BigInt() {
    free(this->number);
}

BigInt operator+(const BigInt& b1, const BigInt& b2) {
    if (b1.flag == b2.flag) {
        if (b1.length <= b2.length) {
            BigInt ret;
            ret.flag = b1.flag;
            ret.length = b2.length;
            for (int i = 0; i < b2.length - 1; i++) {
                ret.number[sz - i - 2] += b1.number[sz - i - 2] + b2.number[sz - i - 2] - 96;
                if (ret.number[sz - i - 2] > '9') {
                    ret.number[sz - i - 2] -= 10;
                    ret.number[sz - i - 3]++;
                }
            }
            ret.number[sz - b2.length - 1] += b1.number[sz - b2.length - 1] + \
                b2.number[sz - b2.length - 1] - 96;
            if (ret.number[sz - b2.length - 1] > '9') {
                ret.number[sz - b2.length - 1] -= 10;
                ret.number[sz - b2.length - 2]++;
                ret.length++;
            }
            return ret;
        }
        else return b2 + b1;
    }
    else {
        if (compare(b1, b2)) {
            BigInt ret;
            ret.flag = b1.flag;
            ret.length = b1.length;
            for (int i = sz - 2; i >= sz - b1.length - 1; i--) {
                ret.number[i] += b1.number[i] - b2.number[i];
                if (ret.number[i] < '0') {
                    ret.number[i] += 10;
                    ret.number[i - 1]--;
                }
            }
            int i = 0;
            while (ret.number[i++] == '0');
            ret.length = sz - i;
            return ret;
        }
        else return b2 + b1;
    }
}

void PrintBigInt(const BigInt& bi) {
    if (bi.flag) printf("-");
    printf(bi.number + (sz - bi.length - 1));
}

bool compare(const BigInt& b1, const BigInt& b2) { // b1 <= b2 이면 0, 아니면 1
    if (b1.length < b2.length) return 0;
    if (b1.length > b2.length) return 1;
    for (int i = sz - b1.length - 1; i < sz - 1; i++) {
        if (b1.number[i] < b2.number[i]) return 0;
        if (b1.number[i] > b2.number[i]) return 1;
    }
    return 0;
}