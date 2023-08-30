#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct fileName{
  int idx;
  string head;
  int number;
};

vector<fileName> f;

void setFileName(int idx, string head, int number) {
    fileName fileName_;
    fileName_.idx = idx;
    fileName_.head = head;
    fileName_.number = number;
    
    f.push_back(fileName_);
}

bool compare(const fileName& f1, const fileName& f2) {
    if (f1.head == f2.head) {
        if (f1.number == f2.number) {
            return f1.idx < f2.idx;
        }
        else {
            return f1.number < f2.number;
        }
    }
    else {
        return f1.head < f2.head;
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    int size = files.size();
    for(int i = 0; i < size; i++) {
        string file = files[i];
        string head = "";
        string number = "";

        int index = 0;
        for(int j = 0; j < file.length(); j++) {       
            if(!isdigit(file[j])) {
                head.push_back(tolower(file[j]));
            }
            else {
                index = j;
                break;
            }
        }
        for(int k = index; k < file.length(); k++) {
            if(isdigit(file[k])) {
                number.push_back(file[k]);
            }
            else {
                break;
            }
        }
        setFileName(i, head, stoi(number));
    }
    sort(f.begin(), f.end(), compare);
    
    for (int i = 0; i < f.size(); i++) {
        answer.push_back(files[f[i].idx]);
    }
    
    return answer;
}