//����Ǯ��: https://githubseob.tistory.com/349

#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

bool cmp(string& s1, string& s2) {
    int s1_start = stoi(s1.substr(0, 2)) * 60 + stoi(s1.substr(3, 2));
    int s1_end = stoi(s1.substr(6, 2)) * 60 + stoi(s1.substr(9, 2));

    int s2_start = stoi(s2.substr(0, 2)) * 60 + stoi(s2.substr(3, 2));
    int s2_end = stoi(s2.substr(6, 2)) * 60 + stoi(s2.substr(9, 2));

    return s1_end - s1_start > s2_end - s2_start;
}

int get_music_play_time(string& start, string& end) {
    int m_start = stoi(start.substr(0, 2)) * 60 + stoi(start.substr(3, 2));
    int m_end = stoi(end.substr(0, 2)) * 60 + stoi(end.substr(3, 2));

    return m_end - m_start;
}

string replace_sharp(string& s, string origin, string change) {
    int pos(0);
    while ((pos = s.find(origin, pos)) != -1)
        s.replace(pos, 2, change);

    return s;
}

string replace_all(string& s) {
    s = replace_sharp(s, "A#", "a");
    s = replace_sharp(s, "C#", "c");
    s = replace_sharp(s, "D#", "d");
    s = replace_sharp(s, "F#", "f");
    s = replace_sharp(s, "G#", "g");

    return s;
}


string solution(string m, vector<string> musicinfos) {
    string answer = "";
    sort(musicinfos.begin(), musicinfos.end(), cmp);

    m = replace_all(m);

    for (int idx = 0; idx < musicinfos.size(); ++idx) {
        string info = musicinfos[idx];
        info = replace_all(info);

        istringstream iss(info);
        vector<string>parsing;
        string substr("");

        string start(""), end(""), name(""), sheet("");

        while (getline(iss, substr, ',')) {
            parsing.push_back(substr);
        }

        start = parsing[0], end = parsing[1], name = parsing[2], sheet = parsing[3];

        int music_time = get_music_play_time(start, end);

        if (music_time < sheet.size()) {
            sheet.erase(music_time);
        }

        while (sheet.size() < music_time) {
            sheet += sheet;
        }
        
        if (music_time < sheet.size()) {
            sheet.erase(music_time);
        }

        if (sheet.find(m) != -1) return name;
    }

    return "(None)";
}