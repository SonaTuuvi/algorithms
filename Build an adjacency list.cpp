#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> adj_list(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj_list[u - 1].push_back(v);
    }

    for (int i = 0; i < n; ++i) {
        std::sort(adj_list[i].begin(), adj_list[i].end());
        std::cout << adj_list[i].size();
        for (int v : adj_list[i]) {
            std::cout << " " << v;
        }
        std::cout << std::endl;
    }

    return 0;
}
