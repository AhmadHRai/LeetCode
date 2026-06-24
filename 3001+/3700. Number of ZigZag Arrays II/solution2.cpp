constexpr int mod = 1e9 + 7;
// using 1D vector to denote the compressed form: a[i*m+j]=m[i][j]
using matrix = vector<int>;
static int m, m2;
static inline matrix operator*(const matrix& A, const matrix& B) {
    // all matrix size m*m
    matrix C(m2, 0);
    for (int i = 0; i < m; i++) {
        for (int k = 0; k < m; k++) {
            if (A[i * m + k] == 0)
                continue;
            for (int j = 0; j < m; j++) {
                C[i * m + j] =
                    (C[i * m + j] + 1LL * A[i * m + k] * B[k * m + j]) % mod;
            }
        }
    }
    return C;
}
// matrix A*B=B*A with A, B symmetric=> A*B symmetric
static inline matrix symMul(const matrix& A, const matrix& B) {
    matrix C(m2, 0);
    for (int i = 0; i < m; i++) { // compute the lower triangle part
        for (int j = 0; j <= i; j++) {
            long long dotSum = 0;
            for (int k = 0; k < m; k++) {
                dotSum += 1LL * A[i * m + k] * B[j * m + k];
                if (dotSum >= mod)
                    dotSum %= mod;
            }
            C[i * m + j] = C[j * m + i] = dotSum; // use symmetric property
        }
    }
    return C;
}
static matrix I() {
    matrix ans(m * m, 0);
    for (int i = 0; i < m; i++)
        ans[i * m + i] = 1;
    return ans;
}
// MSBF modular Matrix Exponentiation
static matrix pow(const matrix& M, unsigned m) {
    if (m == 0)
        return I();
    int bMax = 31 - __builtin_clz(m);
    matrix ans = M;
    for (int i = bMax - 1; i >= 0; i--) {
        ans = symMul(ans, ans);
        if ((m >> i) & 1)
            ans = symMul(ans, M);
    }
    return ans;
}

class Solution {
public:
    static int zigZagArrays(int n, int l, int r) {
        m = r - l + 1;
        m2 = m * m;
        matrix U(m2, 0), L(m2, 0);
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++)
                U[i * m + j] = 1;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++)
                L[i * m + j] = 1;
        }
        n--;
        const int n0 = n >> 1;
        const matrix UL = U * L;
        matrix P = pow(UL, n0);
        if (n & 1)
            P = L * P;
        return 2LL * reduce(P.begin(), P.end(), 0LL) % mod;
    }
};
