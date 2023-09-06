beeseo
beeseo
오프라인 표시

멀린밴댕이 — 2023.07.10. 오후 7:50
#include <string>
#include <vector>
using namespace std;
int gcd(int a, int b){
    while(b!=0){
        int r = a%b;
확장
N_.cpp
1KB
괄호 회전하기
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string s) {
확장
4b6d4ecdfd9f598b.cpp
2KB
멀리뛰기
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
확장
c029f95ca1cd37a6.cpp
1KB
멀린밴댕이 — 2023.07.10. 오후 8:20
귤 고르기
#include <string>
#include <vector>
#include <algorithm>
#include<map>
using namespace std;

확장
d6d6529cf5438961.cpp
1KB
멀린밴댕이 — 2023.07.14. 오후 6:44
#1 연속 부분 수열 합의 개수
멀린밴댕이 — 2023.07.14. 오후 7:35
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

확장
de01b81d82681c05.cpp
1KB
#2 n^2 배열 자르기
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right)
확장
n2_.cpp
1KB
#3 행렬의 곱셈
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
확장
d8abccc764ec5e40.cpp
1KB
#4 [1차] 캐시
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <cctype>
using namespace std;
확장
1_.cpp
2KB
멀린밴댕이 — 2023.07.20. 오후 8:11
#1 의상
#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
확장
0f5bf6d53aa1bbca.cpp
1KB
#2 튜플
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

vector<int> solution(string s) {
확장
062f200f0c37098a.cpp
3KB
#3 할인 행사
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
확장
8ca04f9352ada596.cpp
2KB
#4 기능개발
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
확장
54ea76c073cfc9f0.cpp
2KB
멀린밴댕이 — 2023.07.27. 오후 5:58
#1 프로세스
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

확장
820914c1b9620418.cpp
1KB
#2 [1차] 뉴스 클러스터링
#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
확장
1_.cpp
2KB
#3 피로도
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<vector<int>> dungeons)
확장
3db048425d1abfdc.cpp
1KB
#4 타겟 넘버
#include <string>
#include <vector>

using namespace std;

void dfs(int n, int sum, vector<int> numbers, int target, int &answer)
확장
48d851906b21ab8a.cpp
1KB
멀린밴댕이 — 2023.08.21. 오후 10:44
1.더 맵게
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

확장
458f7ce7db37944f.cpp
1KB
2.땅 따먹기
#include <vector>
#include <set>
#include <cmath>

using namespace std;
// 'v'에서 'idx'를 제외한 요소 중 최댓값을 찾는 함수
확장
f50b021ea582ec2b.cpp
1KB
3.오픈채팅방
#include <string>
#include <vector>
#include <sstream>
#include <map>
using namespace std;

확장
3be74840b1d56805.cpp
2KB
주차요금은 다음기회에 ㅅㅂ;
멀린밴댕이 — 2023.08.24. 오후 9:56
#2 방문 길이
#include <string>
#include <set>
using namespace std;

int solution(string dirs) {
    int answer = 0;
확장
79887cbc6a703329.cpp
2KB
#게임맵최단거리
#include <vector>
#include <queue>
using namespace std;

int dirX[] = {1, -1, 0, 0};  // 행 방향 변화량 (x-좌표)
int dirY[] = {0, 0, 1, -1};  // 열 방향 변화량 (y-좌표)
확장
f26ab6d35178b45d.cpp
2KB
#주식가격
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
확장
5d8a2fe98301d1d3.cpp
1KB
멀린밴댕이 — 2023.09.04. 오후 9:06
2 x n 타일링
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
확장
2_x_n_.cpp
1KB
2 숫자 변환하기
#include <string>
#include <vector>
#define max 1000000
using namespace std;

int solution(int x, int y, int n) {
확장
354d9e247cb7aca2.cpp
1KB
#3 롤케이크 자르기
#include <string>
#include <vector>
#include<map>
using namespace std;

int solution(vector<int> topping) {
확장
acf405dcba5698ac.cpp
1KB
﻿
#include <vector>
#include <queue>
using namespace std;

int dirX[] = {1, -1, 0, 0};  // 행 방향 변화량 (x-좌표)
int dirY[] = {0, 0, 1, -1};  // 열 방향 변화량 (y-좌표)

int solution(vector<vector<int>> maps) {
    int n = maps.size();  // 미로의 행 개수
    int m = maps[0].size();  // 미로의 열 개수

    queue<pair<int, int>> q;  // BFS에 사용할 큐
    q.push({0, 0});  // 시작 지점을 큐에 넣음

    int answer = 1;  // 경로 길이 초기화

    while (!q.empty()) {
        int qSize = q.size();  // 현재 큐에 들어있는 지점의 개수

        for (int i = 0; i < qSize; ++i) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            if (row == n - 1 && col == m - 1) {
                return answer;  // 목적지에 도달한 경우 경로 길이 반환
            }

            for (int j = 0; j < 4; ++j) {
                int newRow = row + dirX[j];
                int newCol = col + dirY[j];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && maps[newRow][newCol] == 1) {
                    q.push({newRow, newCol});
                    maps[newRow][newCol] = 0;  // 방문한 지점으로 표시
                }
            }
        }

        answer++;  // 경로 길이 증가
    }

    return -1;  // 목적지에 도달하지 못한 경우 -1 반환
}
