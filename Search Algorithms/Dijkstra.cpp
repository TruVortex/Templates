#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> adj, int src) {
    vector<int> dist(adj.size(), -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({ 0, src });
    while (!pq.empty()) {
        pair<int, int> curPair = pq.top();
        pq.pop();
        int cur = curPair.second;
        for (const pair<int, int>& edge : adj[cur]) {
            if (dist[edge.first] == -1 || dist[cur] + edge.second < dist[edge.first]) {
                dist[edge.first] = dist[cur] + edge.second;
                pq.push({ dist[edge.first], edge.first });
            }
        }
    }
    return dist;
}

int main() {
    vector<vector<pair<int, int>>> adj(4);
    adj[0].push_back({ 1, 2 });
    adj[0].push_back({ 2, 5 });
    adj[1].push_back({ 2, 2 });
    vector<int> dist = dijkstra(adj, 0);
    for (int i = 0; i < 4; i++) {
        printf("%d\n", dist[i]);
    }
    return 0;
}
