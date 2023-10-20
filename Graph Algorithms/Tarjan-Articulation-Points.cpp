#include <stdio.h>
#include <vector>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

int vis[100001], depth[100001], low[100001], parent[100001];
vector<int> adj[100001];

void tarjanArticulationPoints(int v, int d) {
    vis[v] = 1;
    depth[v] = d;
    low[v] = d;
    int children = 0, articulation = 0;
    for (int x : adj[v]) {
        if (!vis[x]) {
            children++;
            parent[x] = v;
            tarjanArticulationPoints(x, d + 1);
            if (low[x] >= depth[v]) {
                articulation = 1;
            }
            low[v] = min(low[v], low[x]);
        } else if (x != parent[v]) {
            low[v] = min(low[v], depth[x]);
        }
    }
    if ((v != 1 && articulation) || (v == 1 && children >= 2)) {
        printf("%d\n", v);
    }
}

int main() {
    int n, m;
    scan(n);
    scan(m);
    for (int i = 0, x, y; i < m; i++) {
        scan(x);
        scan(y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    tarjanArticulationPoints(1, 0);
    return 0;
}
