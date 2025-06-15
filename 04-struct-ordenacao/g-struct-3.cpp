// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// int main() {
//     // Declaração de variáveis
//     int n, m;
//     cin >> n >> m;

//     // Vetor para armazenar o dono de cada setor (indexado a partir de 0 para facilitar)
//     vector<int> donoDosSetores(m);
//     for (int i = 0; i < m; i++) {
//         cin >> donoDosSetores[i];
//         donoDosSetores[i]--;  // Ajustando para indexação em 0
//     }

//     // Vetor para armazenar o número alvo de amostras para cada estado
//     vector<long long> amostrasAlvo(n);
//     for (int i = 0; i < n; i++) {
//         cin >> amostrasAlvo[i];
//     }

//     // Vetor para armazenar as amostras coletadas por cada estado
//     vector<long long> amostrasColetadas(n, 0);

//     // Vetor para armazenar quando cada estado atinge seu objetivo
//     vector<int> momentoDeTermino(n, -1);

//     // Número de chuvas de meteoros
//     int k;
//     cin >> k;

//     // Processar cada chuva de meteoros
//     for (int chuva = 1; chuva <= k; chuva++) {
//         int l, r, a;
//         cin >> l >> r >> a;
//         l--;
//         r--;  // Ajustando para indexação em 0

//         // Distribuir as amostras desta chuva
//         if (l <= r) {
//             // Caso linear: setores l até r
//             for (int setor = l; setor <= r; setor++) {
//                 int estado = donoDosSetores[setor];
//                 amostrasColetadas[estado] += a;
//             }
//         } else {
//             // Caso circular: setores l até m-1 e 0 até r
//             for (int setor = l; setor < m; setor++) {
//                 int estado = donoDosSetores[setor];
//                 amostrasColetadas[estado] += a;
//             }
//             for (int setor = 0; setor <= r; setor++) {
//                 int estado = donoDosSetores[setor];
//                 amostrasColetadas[estado] += a;
//             }
//         }

//         // Verificar se algum estado atingiu seu objetivo nesta chuva
//         for (int estado = 0; estado < n; estado++) {
//             if (momentoDeTermino[estado] == -1 && amostrasColetadas[estado] >= amostrasAlvo[estado]) {
//                 momentoDeTermino[estado] = chuva;
//             }
//         }
//     }

//     // Exibir os resultados
//     for (int estado = 0; estado < n; estado++) {
//         if (momentoDeTermino[estado] != -1) {
//             cout << momentoDeTermino[estado] << endl;
//         } else {
//             cout << "NIE" << endl;
//         }
//     }

//     return 0;
// }




#include <cstdio>
#include <cctype>

#include <algorithm>
#include <vector>

typedef long long LL;

inline char fgc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
}

inline LL readint() {
    register LL res = 0, neg = 1;
    register char c = fgc();
    while(!isdigit(c)) {
        if(c == '-') neg = -1;
        c = fgc();
    }
    while(isdigit(c)) {
        res = (res << 1) + (res << 3) + c - '0';
        c = fgc();
    }
    return res * neg;
}

const int MAXN = 300005;

int n, m, k, p[MAXN];
std::vector<int> slist[MAXN];

struct Operation {
    int l, r, a;
} ops[MAXN];

LL bit[MAXN];

inline int lowbit(int x) {
    return x & -x;
}

inline void add(int x, LL v) {
    for(int i = x; i <= m; i += lowbit(i)) {
        bit[i] += v;
    }
}

inline LL query(int x) {
    LL res = 0;
    for(int i = x; i; i -= lowbit(i)) {
        res += bit[i];
    }
    return res;
}

inline void doop(int op, int neg) {
    add(ops[op].l, neg * ops[op].a);
    add(ops[op].r + 1, neg * -ops[op].a);
    if(ops[op].l > ops[op].r) add(1, neg * ops[op].a);
}

int que[MAXN], tmp[MAXN], now = 0, ans[MAXN];
bool can[MAXN];

inline void divide(int l, int r, int lpos, int rpos) {
    if(lpos > rpos) return;
    if(l == r) {
        for(int i = lpos; i <= rpos; i++) {
            ans[que[i]] = l;
        }
        return;
    }
    int mid = (l + r) >> 1;
    while(now < mid) {
        now++; doop(now, 1);
    }
    while(now > mid) {
        doop(now, -1); now--;
    }
    int lcnt = 0;
    for(int i = lpos; i <= rpos; i++) {
        LL tot = 0;
        for(int j = 0; j < slist[que[i]].size(); j++) {
            tot += query(slist[que[i]][j]);
            if(tot >= p[que[i]]) break;
        }
        if(tot >= p[que[i]]) {
            can[que[i]] = true; lcnt++;
        } else {
            can[que[i]] = false; 
        }
    }
    int lpos1 = lpos, lpos2 = lpos + lcnt;
    for(int i = lpos; i <= rpos; i++) {
        if(can[que[i]]) tmp[lpos1++] = que[i];
        else tmp[lpos2++] = que[i];
    }
    for(int i = lpos; i <= rpos; i++) {
        que[i] = tmp[i];
    }
    divide(l, mid, lpos, lpos1 - 1);
    divide(mid + 1, r, lpos1, lpos2 - 1);
}

int main() {
    n = readint(); m = readint();
    for(int i = 1, oi; i <= m; i++) {
        oi = readint(); slist[oi].push_back(i);
    }
    for(int i = 1; i <= n; i++) {
        p[i] = readint();
    }
    k = readint();
    for(int i = 1; i <= k; i++) {
        ops[i].l = readint();
        ops[i].r = readint();
        ops[i].a = readint();
    }
    ops[++k] = Operation {1, m, int(1e9)};
    for(int i = 1; i <= n; i++) {
        que[i] = i;
    }
    divide(1, k, 1, n);
    for(int i = 1; i <= n; i++) {
        if(ans[i] < k) printf("%d\n", ans[i]);
        else puts("NIE");
    }
    return 0;
}


// #include <cstdio>
// #include <cctype>
// #include <algorithm>
// #include <vector>

// typedef long long LL;

// // Fast input
// inline char fgc() {
//     static char buf[100000], *p1 = buf, *p2 = buf;
//     return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? EOF : *p1++;
// }

// inline LL readint() {
//     LL res = 0, neg = 1;
//     char c = fgc();
//     while(!isdigit(c)) {
//         if(c == '-') neg = -1;
//         c = fgc();
//     }
//     while(isdigit(c)) {
//         res = res * 10 + c - '0';
//         c = fgc();
//     }
//     return res * neg;
// }

// const int MAXN = 300005;

// int n, m, k;
// LL p[MAXN];
// std::vector<int> slist[MAXN];

// struct Operation {
//     int l, r;
//     LL a;
// } ops[MAXN];

// LL bit[MAXN];

// inline int lowbit(int x) { return x & -x; }

// inline void add(int x, LL v) {
//     for(; x <= m; x += lowbit(x))
//         bit[x] += v;
// }

// inline LL query(int x) {
//     LL res = 0;
//     for(; x > 0; x -= lowbit(x))
//         res += bit[x];
//     return res;
// }

// inline void applyOperation(int op, int sign) {
//     add(ops[op].l, sign * ops[op].a);
//     add(ops[op].r + 1, sign * -ops[op].a);
//     if(ops[op].l > ops[op].r) add(1, sign * ops[op].a);
// }

// int que[MAXN], tmp[MAXN], currentOp = 0, ans[MAXN];
// bool sufficient[MAXN];

// void binarySearch(int left, int right, int qLeft, int qRight) {
//     if(qLeft > qRight) return;
    
//     if(left == right) {
//         for(int i = qLeft; i <= qRight; i++)
//             ans[que[i]] = left;
//         return;
//     }
    
//     int mid = (left + right) >> 1;
    
//     // Adjust operations to reflect state at mid
//     while(currentOp < mid) applyOperation(++currentOp, 1);
//     while(currentOp > mid) applyOperation(currentOp--, -1);
    
//     // Count states with sufficient samples
//     int leftCount = 0;
//     for(int i = qLeft; i <= qRight; i++) {
//         int state = que[i];
//         LL total = 0;
        
//         for(int station : slist[state]) {
//             total += query(station);
//             if(total >= p[state]) break;
//         }
        
//         sufficient[state] = (total >= p[state]);
//         if(sufficient[state]) leftCount++;
//     }
    
//     // Partition the query array
//     int leftPtr = qLeft, rightPtr = qLeft + leftCount;
//     for(int i = qLeft; i <= qRight; i++) {
//         int state = que[i];
//         tmp[sufficient[state] ? leftPtr++ : rightPtr++] = state;
//     }
    
//     for(int i = qLeft; i <= qRight; i++)
//         que[i] = tmp[i];
    
//     // Recursively search in partitions
//     binarySearch(left, mid, qLeft, qLeft + leftCount - 1);
//     binarySearch(mid + 1, right, qLeft + leftCount, qRight);
// }

// int main() {
//     n = readint(); m = readint();
    
//     // Read state ownership for each sector
//     for(int i = 1; i <= m; i++) {
//         int owner = readint();
//         slist[owner].push_back(i);
//     }
    
//     // Read sample requirements for each state
//     for(int i = 1; i <= n; i++)
//         p[i] = readint();
    
//     // Read meteor shower predictions
//     k = readint();
//     for(int i = 1; i <= k; i++) {
//         ops[i].l = readint();
//         ops[i].r = readint();
//         ops[i].a = readint();
//     }
    
//     // Add a final operation with enough samples to satisfy any requirement
//     ops[++k] = {1, m, (LL)1e18};
    
//     // Initialize query array with all states
//     for(int i = 1; i <= n; i++)
//         que[i] = i;
    
//     // Find the earliest shower when each state gets enough samples
//     binarySearch(1, k, 1, n);
    
//     // Output results
//     for(int i = 1; i <= n; i++) {
//         if(ans[i] < k) 
//             printf("%d\n", ans[i]);
//         else 
//             puts("NIE");
//     }
    
//     return 0;
// }