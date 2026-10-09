#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
  vector < int > rank;
  vector < int > parent;
  vector<int> size;
  public:
    DisjointSet(int s) {
      rank.resize(s + 1, 0);
      parent.resize(s + 1);
      size.resize(s+1, 1);

      for (int i = 0; i <= s; i++) {
        parent[i] = i;
      }
    }

  int findParent(int node) {
    if (node == parent[node])
      return node;

    return parent[node] = findParent(parent[node]);
  }

  void unionByRank(int u, int v) {
    int par_u = findParent(u), par_v = findParent(v);

    if (par_u == par_v) return;

    int rank_u = rank[par_u];
    int rank_v = rank[par_v];

    if (rank_u < rank_v) {
      parent[par_u] = par_v;
    } else if (rank_v < rank_u) {
      parent[par_v] = par_u;
    } else {
      parent[par_v] = par_u;
      rank[par_u]++;
    }
  }

  void unionBySize(int u, int v) {
    int par_u = findParent(u), par_v = findParent(v);

    if (par_u == par_v) return;

    int size_u = size[par_u];
    int size_v = size[par_v];

    if (size_u < size_v) {
      parent[par_u] = par_v;
    } else if (size_v < size_u) {
      parent[par_v] = par_u;
    } else {
      parent[par_v] = par_u;
      size[par_u] += size[par_v];
    }
  }

};

int main() {
  DisjointSet dsu(7);
  dsu.unionBySize(1, 2);
  dsu.unionBySize(2, 3);
  dsu.unionBySize(4, 5);
  dsu.unionBySize(6, 7);
  dsu.unionBySize(5, 6);
  if (dsu.findParent(3) != dsu.findParent(7)) {
    cout << "Not Same" << endl;
  }
  else{
    cout<<"Same"<<endl;
  }

  if (dsu.findParent(5) != dsu.findParent(6)) {
    cout << "Not Same" << endl;
  }
  else{
    cout<<"Same"<<endl;
  }
  dsu.unionBySize(3, 7);
  if (dsu.findParent(3) != dsu.findParent(7)) {
    cout << "Not Same" << endl;
  }
  else{
    cout<<"Same"<<endl;
  }
  return 0;
}