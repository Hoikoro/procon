#include <bits/stdc++.h>
using namespace std;
#define DBG(...) ;

using LL = long long;
constexpr LL LINF = 334ll << 53;
constexpr int INF = 15 << 26;
constexpr LL MOD = 1E9 + 7;

// to all edges
// verified
// https://beta.atcoder.jp/contests/soundhound2018-summer-qual/tasks/soundhound2018_summer_qual_d
using pii = pair<LL, LL>;
struct Edge {
  int from, to;
  LL cost;
  Edge(int from, int to, LL cost) : from(from), to(to), cost(cost){};
};
typedef vector<vector<Edge>> Graph;

LL dijkstra(const int start, const vector<vector<Edge>> &graph,
            vector<pii> &prev) {
  int visited = 0, N = graph.size();
  // vector<char> visited(N,false);
  // <<cost , place>, prev>
  priority_queue<pair<pii, int>, vector<pair<pii, int>>,
                 greater<pair<pii, int>>>
      Q;
  fill(prev.begin(), prev.end(), make_pair(-2, 0));
  Q.push(make_pair(make_pair(0, start), -1));
  while (!Q.empty()) {
    LL cost;
    int place, from;
    cost = Q.top().first.first;
    place = Q.top().first.second;
    from = Q.top().second;
    Q.pop();
    if (prev[place].first != -2) continue;
    prev[place] = {from, cost};
    visited++;
    if (visited == N) return 1;
    for (int j = 0; j < (int)graph[place].size(); j++) {
      if (dist[graph[place][j].to] <= graph[place][j].cost + cost) continue;
      Q.push(make_pair(
          make_pair(graph[place][j].cost + cost, graph[place][j].to), place));
    }
  }
  return -1;
}

// to one vertex
struct Edge {
  int from, to;
  LL cost;
  Edge(int from, int to, LL cost) : from(from), to(to), cost(cost){};
};
typedef vector<vector<Edge>> Graph;

LL dijkstra(const int start, const int goal, const vector<vector<Edge>> &graph,
            vector<int> &prev) {
  // start, goal, graph, previous vertex on the shortest pass (prev[start]=-1)
  // <<cost , place>, prev>
  typedef tuple<LL, int, int> T;
  int N = graph.size();
  vector<LL> dist(N, LINF);
  vector<char> visited(N, false);
  priority_queue<T, vector<T>, greater<T>> Q;
  Q.push(make_tuple(0, start, -1));
  while (!Q.empty()) {
    LL cost;
    int place, from;
    tie(cost, place, from) = Q.top();
    Q.pop();
    if (visited[place]) continue;
    prev[place] = from;
    if (place == goal) return cost;
    dist[place] = cost;
    visited[place] = true;
    for (int j = 0; j < (int)graph[place].size(); j++) {
      if (dist[graph[place][j].to] <= graph[place][j].cost + cost) continue;
      Q.push(
          make_tuple(graph[place][j].cost + cost, graph[place][j].to, place));
    }
  }
  return -1;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n, m, s, t;  // vertex,edge
  cin >> n >> m;
  Graph G(n);
  vector<int> prev(n);

  for (int i = 0; i < m; i++) {
    int a, b, cost;
    cin >> a >> b >> cost;
    G[a].push_back(Edge(a, b, cost));
    // G[b].push_back(Edge(b,a,cost));
  }

  cout << dijkstra(s, t, G, prev) << endl;

  return 0;
}
