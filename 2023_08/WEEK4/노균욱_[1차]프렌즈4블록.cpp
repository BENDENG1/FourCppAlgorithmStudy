/*
그냥 일단은 터트려주고 내려주고 이걸 반복하고 없으면 무한반복문을 끝내주는 형식으로 진행만 하면 될듯?
*/
#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;
int arr[30][30] = {0,}; //중첩 터진것에 대한 카운트를 위해 배열 선언
bool match = true;

void fourFriends(int i, int j,char block,vector<string> board);


int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(match){
        memset(arr,0,sizeof(arr));
        match = false;
        
        //일단 있는것들 다 터트림
        for(int i = 0; i < m - 1; i++){
            for(int j = 0; j < n - 1; j++){
                if(board[i][j] != ' '){
                    fourFriends(i,j,board[i][j],board);
                }
            }
        }
        
        //그다음에 다 끌어내려오게 진행
        for(int i = 0; i < m;i++){
            for(int j = 0; j < n;j++){
                if(arr[i][j] == 1){
                    answer++;
                    for(int k = i - 1; k >= 0; k--){
                        board[k + 1][j] = board[k][j];
                        board[k][j] = ' ';
                    }
                }
            }
        }
    }
    return answer;
}

void fourFriends(int i, int j,char block,vector<string> board){
    if(board[i + 1][j] == block && board[i][j + 1] == block && board[i + 1][j + 1] == block){
        arr[i][j] = 1;
        arr[i][j + 1] = 1;
        arr[i + 1][j] = 1;
        arr[i + 1][j + 1] = 1;
        match = true;
    }
}