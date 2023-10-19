#include <string>
#include <vector>

using namespace std;

int map[101][101];

int rotate(int x1, int y1, int x2, int y2){
    int num = map[x1 - 1][y1 - 1];
    int minVal = num;
    
    for(int i = x1 - 1; i < x2 - 1; i++)
    {
        map[i][y1 - 1] = map[i + 1][y1 - 1]; 
        minVal = min(minVal, map[i + 1][y1 - 1]);
    }
    for(int i = y1 - 1; i < y2 - 1; i++) 
    {
        map[x2 - 1][i] = map[x2 - 1][i + 1]; 
        minVal = min(minVal, map[x2 - 1][i + 1]);
    }
    for(int i = x2 - 1; i > x1 - 1; i--)
    {
        map[i][y2 - 1] = map[i - 1][y2 - 1]; 
        minVal = min(minVal, map[i - 1][y2 - 1]);
    }
    for(int i = y2 - 1; i > y1 - 1; i--) 
    {
        map[x1 - 1][i] = map[x1 - 1][i - 1]; 
        minVal = min(minVal, map[x1 - 1][i - 1]);
    }
    
    map[x1 - 1][y1] = num;
    
    return minVal;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int num = 1;
    
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
            map[i][j] = num++;
    
    for(int i = 0; i < queries.size(); i++){
        int n = rotate(queries[i][0], queries[i][1], queries[i][2], queries[i][3]);
        answer.push_back(n);
    }
    
    return answer;
}