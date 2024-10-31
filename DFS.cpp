#include <iostream>
#include <vector>
#include <algorithm>

void dfs(int v, const std::vector<std::vector<int>>& graph, std::vector<bool>& visited, std::vector<int>& result) {
    visited[v] = true;
    result.push_back(v + 1);  // сохраняем вершину в результат (индексы сдвинуты на 1)
    
    for (int neighbor : graph[v]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, result);
        }
    }
}

int main() {
    int n, m;
    std::cin >> n >> m;

    // Инициализация графа в виде списка смежности
    std::vector<std::vector<int>> graph(n);
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;  // переводим вершины в 0-индексацию
        --v;
        graph[u].push_back(v);
        graph[v].push_back(u);  // так как граф неориентированный
    }

    // Сортируем списки смежности для каждой вершины
    for (int i = 0; i < n; ++i) {
        std::sort(graph[i].begin(), graph[i].end());
    }

    int start;
    std::cin >> start;
    --start;  // переводим в 0-индексацию

    // Массив для отслеживания посещённых вершин
    std::vector<bool> visited(n, false);
    std::vector<int> result;

    // Выполняем DFS начиная с вершины start
    dfs(start, graph, visited, result);

    // Выводим результат
    for (int v : result) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}
