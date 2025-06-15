// #include <cstdio>
// #include <cstring>
// #include <iostream>
// using namespace std;

// const int TAMANHO_MAXIMO = 100000 + 10;
// int soma[TAMANHO_MAXIMO << 2], esquerda[TAMANHO_MAXIMO << 2], direita[TAMANHO_MAXIMO << 2];
// char sequencia[TAMANHO_MAXIMO];

// void AtualizarNo(int indice) {
//     int correspondencias = min(esquerda[indice << 1], direita[(indice << 1) | 1]);
//     soma[indice] = soma[indice << 1] + soma[(indice << 1) | 1] + correspondencias * 2;
//     esquerda[indice] = esquerda[indice << 1] + esquerda[(indice << 1) | 1] - correspondencias;
//     direita[indice] = direita[indice << 1] + direita[(indice << 1) | 1] - correspondencias;
// }

// void construir(int inicio, int fim, int indice) {
//     if (inicio == fim) {
//         esquerda[indice] = direita[indice] = soma[indice] = 0;
//         if (sequencia[inicio - 1] == '(')
//             esquerda[indice] = 1;
//         else
//             direita[indice] = 1;
//         return;
//     }
//     int meio = (inicio + fim) >> 1;
//     construir(inicio, meio, indice << 1);
//     construir(meio + 1, fim, (indice << 1) | 1);
//     AtualizarNo(indice);
// }

// int consultar(int inicioConsulta, int fimConsulta, int inicio, int fim, int indice, int &resultadoEsquerda, int &resultadoDireita) {
//     if (inicioConsulta <= inicio && fim <= fimConsulta) {
//         resultadoEsquerda = esquerda[indice];
//         resultadoDireita = direita[indice];
//         return soma[indice];
//     }

//     int meio = (inicio + fim) >> 1;

//     if (fimConsulta <= meio)
//         return consultar(inicioConsulta, fimConsulta, inicio, meio, indice << 1, resultadoEsquerda, resultadoDireita);
//     else if (inicioConsulta > meio)
//         return consultar(inicioConsulta, fimConsulta, meio + 1, fim, (indice << 1) | 1, resultadoEsquerda, resultadoDireita);
//     else {
//         int soma1, soma2, esquerda1, direita1, esquerda2, direita2, correspondencias;
//         soma1 = consultar(inicioConsulta, fimConsulta, inicio, meio, indice << 1, esquerda1, direita1);
//         soma2 = consultar(inicioConsulta, fimConsulta, meio + 1, fim, (indice << 1) | 1, esquerda2, direita2);
//         correspondencias = min(esquerda1, direita2);
//         resultadoEsquerda = esquerda1 + esquerda2 - correspondencias;
//         resultadoDireita = direita1 + direita2 - correspondencias;
//         return soma1 + soma2 + correspondencias * 2;
//     }
// }

// int main() {
//     int tamanho;
//     scanf("%s", sequencia);
//     tamanho = strlen(sequencia);
//     construir(1, tamanho, 1);

//     int numConsultas, inicioConsulta, fimConsulta, resultado;
//     scanf("%d", &numConsultas);

//     while (numConsultas--) {
//         scanf("%d%d", &inicioConsulta, &fimConsulta);
//         resultado = consultar(inicioConsulta, fimConsulta, 1, tamanho, 1, inicioConsulta, fimConsulta);
//         printf("%d\n", resultado);
//     }

//     return 0;
// }

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#define ALL(x) (x).begin(), (x).end()
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rep(i,x,n) for(int i=x;i<n;i++)
#define repd(i,x,n) for(int i=x;i<=n;i++)
#define pii pair<int,int>
#define pll pair<long long ,long long>
#define gbtb ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define MS0(X) memset((X), 0, sizeof((X)))
#define MSC0(X) memset((X), '\0', sizeof((X)))
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define eps 1e-6
#define gg(x) getInt(&x)
#define chu(x) cout<<"["<<#x<<" "<<(x)<<"]"<<endl
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll powmod(ll a, ll b, ll MOD) {ll ans = 1; while (b) {if (b % 2) { ans = ans * a % MOD; } a = a * a % MOD; b /= 2;} return ans;}
inline void getInt(int *p);
const int maxn = 1000010;
const int inf = 0x3f3f3f3f;
/*** TEMPLATE CODE * * STARTS HERE ***/
struct node {
    int l, r;
    int id;
} a[maxn];
char s[maxn];
int n;
int m;
bool cmp(node aa, node bb)
{
    return aa.r < bb.r;
}
int tree[maxn];
int lowbit(int x)
{
    return x & (-1 * x);
}
void add(int x, int val)
{
    while (x <= n) {
        tree[x] += val;
        x += lowbit(x);
    }
}
int ask(int x)
{
    int res = 0;
    while (x) {
        res += tree[x];
        x -= lowbit(x);
    }
    return res;
}
int ans[maxn];
int main()
{
    //freopen("D:\\code\\text\\input.txt","r",stdin);
    //freopen("D:\\code\\text\\output.txt","w",stdout);
    gbtb;
    cin >> s + 1;
    n=strlen(s+1);
    cin >> m;
    repd(i, 1, m ) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
    }
    sort(a + 1, a + 1 + m, cmp);
    stack<int> st;
    while (sz(st)) {
        st.pop();
    }
    int pos = 1;
    repd(i, 1, m) {
//        chu(pos);
        repd(j, pos, a[i].r) {
            if (s[j] == '(') {
                st.push(j);
            } else {
                if (sz(st)) {
                    add(st.top(), 2);
                    st.pop();
                }
            }
        }
        ans[a[i].id] = ask(a[i].r) - ask(a[i].l - 1);
        pos = a[i].r + 1;
    }
    repd(i,1,m)
    {
        printf("%d\n",ans[i] );
    }
 
    return 0;
}
 
inline void getInt(int *p)
{
    char ch;
    do {
        ch = getchar();
    } while (ch == ' ' || ch == '\n');
    if (ch == '-') {
        *p = -(getchar() - '0');
        while ((ch = getchar()) >= '0' && ch <= '9') {
            *p = *p * 10 - ch + '0';
        }
    } else {
        *p = ch - '0';
        while ((ch = getchar()) >= '0' && ch <= '9') {
            *p = *p * 10 + ch - '0';
        }
    }
}

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 1000005
using namespace std;

typedef pair<int, int> pii;
char str[MAX];

struct node
{
    int cs, o, c;       //cs - correct sequence, o - open bracket, c - close bracket
}tree[4*MAX];

node combine(node a, node b)
{
    node res;
    int temp = min(a.o, b.c);     //Minimum of open or close bracket
    res.cs = a.cs + b.cs + temp;     //increment correct sequence
    res.o = a.o + b.o - temp;        //subtract temp, as we've already taken this in correct sequence
    res.c = a.c + b.c - temp;

    return res;
}
void build(int nodeNo, int low, int high)
{
    if(low == high){
        if(str[low] == '('){
            tree[nodeNo].cs = tree[nodeNo].c = 0;
            tree[nodeNo].o = 1;
        }
        else{
            tree[nodeNo].cs = tree[nodeNo].o = 0;
            tree[nodeNo].c = 1;
        }
        return;
    }

    int mid = (low + high) >> 1;
    build(nodeNo * 2, low, mid);
    build(nodeNo * 2 + 1, mid + 1, high);

    tree[nodeNo] = combine(tree[nodeNo * 2], tree[nodeNo * 2 + 1]);
}

node query(int nodeNo, int low, int high, int l, int r)
{
    if(l == low && high == r)
        return tree[nodeNo];
    int mid = (low + high) >> 1;

    if(r <= mid){
        return query(nodeNo * 2, low, mid, l, r);
    }
    if(l > mid)
        return query(nodeNo * 2 + 1, mid + 1, high, l, r);

    return combine(query(nodeNo * 2, low, mid, l, mid), query(nodeNo * 2 + 1, mid + 1, high, mid + 1, r));
}

int main()
{
    int q;          //number of query
    scanf("%s", str);

    int n = strlen(str);

    scanf("%d", &q);

    int x,  y;

    build(1, 0, n - 1);

    for(int i = 0; i < q; i++){
        scanf("%d %d", &x, &y);
        x--, y--;           //0 based indexing
        node ans = query(1, 0, n - 1, x, y);
        printf("%d\n", ans.cs * 2);
    }

    return 0;
}
