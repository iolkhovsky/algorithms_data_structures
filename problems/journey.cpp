#include <algorithm>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

struct Coord {
    int x;
    int y;
};

bool operator!=(const Coord& a, const Coord& b) {
    return a.x != b.x || a.y != b.y;
}

bool operator==(const Coord& a, const Coord& b) {
    return !(a!=b);
}

istream& operator>>(istream& is, Coord& c) {
    is >> c.x >> c.y;
    return is;
}

int distance(const Coord& a, const Coord& b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

struct Graph {
    Graph(int n) {
        adjacentList.resize(n);
    }
    vector<vector<int>> adjacentList;
    void add(int from, int to) {
        adjacentList[from].push_back(to);
        adjacentList[to].push_back(from);
    }
    int bfs(int from, int to) {
        queue<pair<int, int>> fifo;
        unordered_set<int> explored;
        fifo.push({from, 0});
        int distance = -1;
        while(!fifo.empty()) {
            auto f = fifo.front();
            auto vertex = f.first;
            auto d = f.second;
            fifo.pop();
            if (vertex == to) {
                distance = d;
                break;
            }
            for (auto adjacentVertices: adjacentList[vertex]) {
                if (explored.count(vertex) == 0)
                    fifo.push({adjacentVertices, d + 1});
            }
            explored.insert(vertex);
        }
        return distance;
    }
};


int main(int argc, char** argv) {
    int n;
    cin >> n;
    vector<Coord> cities(n);
    for (auto& city : cities)
        cin >> city; 
    int k, startId, destId;
    cin >> k >> startId >> destId;
    startId--;
    destId--;

    Graph g(n);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int d = distance(cities[i], cities[j]);
            if (d <= k)
                g.add(i, j);
        }
    }
    int res = g.bfs(startId, destId);
    cout << res << endl;
    return 0;
}
