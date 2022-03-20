import heapq


def dijkstra(adj, src):
    dist = [-1] * len(adj)
    pq = []
    dist[src] = 0
    heapq.heappush(pq, (0, src))
    while pq:
        cur_pair = heapq.heappop(pq)
        cur = cur_pair[1]
        for edge in adj[cur]:
            if dist[edge[0]] == -1 or dist[cur] + edge[1] < dist[edge[0]]:
                dist[edge[0]] = dist[cur] + edge[1]
                heapq.heappush(pq, (dist[edge[0]], edge[0]))
    return dist


graph_adj = [[(1, 2), (2, 5)], [(2, 2)], [], []]
ans = dijkstra(graph_adj, 0)
for i in range(4):
    print(ans[i])
