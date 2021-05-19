#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// ��ȸ�ϸ鼭 �湮�� �ϸ鼭 ������ ũ�⸦ ���Ѵ�.
int DFS(int x, int y, int m, int n, vector<vector<int>>& picture, vector<vector<int>>& visited) {

    const int dx[] = { 0,0,1,-1 };
    const int dy[] = { 1,-1,0,0 };
    int number_of_area = 1;

    visited[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
            if (!visited[nx][ny] && picture[nx][ny] == picture[x][y]) {
                number_of_area += DFS(nx, ny, m, n, picture, visited);
            }
        }
    }

    return number_of_area;
}

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
vector<int> solution(int m, int n, vector<vector<int>> picture) {

    vector<vector<int>> visited(m, vector<int>(n, 0));
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (picture[i][j] != 0 && !visited[i][j]) {
                ++number_of_area;
                max_size_of_one_area = max(max_size_of_one_area, DFS(i, j, m, n, picture, visited));
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}