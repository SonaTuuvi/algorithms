#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    // Инициализация матрицы смежности размером n x n нулями
    std::vector<std::vector<int>> adj_matrix(n, std::vector<int>(n, 0));

    // Заполнение матрицы смежности
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        adj_matrix[u - 1][v - 1] = 1;
    }

    // Вывод матрицы смежности
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << adj_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
