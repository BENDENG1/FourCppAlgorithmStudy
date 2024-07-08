#include <iostream>
#include <vector>

using namespace std;

int n, m, y, x, k;
int Map[21][21];
int Move[1001];
vector<int> dice(7); // index 1 윗면, 2 북쪽면, 3 동쪽면, 4 서쪽면, 5 남쪽면, 6 아랫면

// 0 원점, 1 동쪽, 2 서쪽, 3 북쪽, 4 남쪽
int dy[5] = { 0, 0, 0, -1, 1 };
int dx[5] = { 0, 1, -1, 0, 0 };

void Dice()
{
    for (int i = 0; i < k; i++)
    {
        int my = dy[Move[i]];
        int mx = dx[Move[i]];
        if (y + my >= n || y + my < 0 || x + mx >= m || x + mx < 0)
            continue;
        // 주사위 위치하는 칸 이동
        y += my;
        x += mx;

        // 명령에 따라 주사위 굴리기
        switch (Move[i])
        {
        case 1: // 동쪽으로 굴리기
            dice = { 0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3] };
            break;
        case 2: // 서쪽으로 굴리기
            dice = { 0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4] };
            break;
        case 3: // 북쪽으로 굴리기
            dice = { 0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2] };
            break;
        case 4: // 남쪽으로 굴리기
            dice = { 0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5] };
            break;
        }

        cout << dice[1] << '\n'; // 윗면 출력

        // 도착한 보드 칸이 0 이라면
        if (Map[y][x] == 0)
            Map[y][x] = dice[6]; // 주사위 아랫면 숫자를 위치한 칸에 복사
        else
        {
            dice[6] = Map[y][x];
            Map[y][x] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> y >> x >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> Map[i][j];
        }
    }

    for (int i = 0; i < k; i++)
    {
        cin >> Move[i];
    }
    Dice();

    return 0;
}
