#include <string>
#include <vector>

using namespace std;

int dx[] = { 0, 1, 1 };
int dy[] = { 1, 0, 1 };
int M, N;

bool Check(int x, int y, vector<string> board)
{
    for (int i = 0; i < 3; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= M || ny >= N) return false;
        if (board[x][y] != board[nx][ny]) return false;
    }
    return true;
}

int Delete(vector<pair<int, int>> v, vector<string> &board)
{
    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int x = v[i].first;
        int y = v[i].second;
        if (board[x][y] != '.')
        {
            board[x][y] = '.';
            cnt++;
        }
 
        for (int j = 0; j < 3; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (board[nx][ny] != '.')
            {
                cnt++;
                board[nx][ny] = '.';
            }
        }
    }
    return cnt;
}

void Arrange(vector<string> &board)
{
    for (int i = M - 1; i >= 0; i--)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == '.') continue;
            
            int nx = i + 1;
            while (nx < M && board[nx][j] == '.') nx++;
            nx--;
            if (nx != i)
            {
                board[nx][j] = board[i][j];
                board[i][j] = '.';
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool flag = true;
    M = m;
    N = n;
    
    while(flag == true){
        flag = false;
        vector<pair<int, int>> v;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '.') continue;
                if (Check(i, j, board) == true)
                {
                    v.push_back(make_pair(i, j));
                    flag = true;
                }
            }
        }
        if (flag == true)
        {
            answer = answer + Delete(v, board);
            Arrange(board);
        }
    }
    return answer;
}