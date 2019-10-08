#include <bits/stdc++.h>
#define X dpat.first
#define Y dpat.second
using namespace std;

//30 50
//0 0 입력시 오류

bool visit[301][301];
int t, l;
pair<int, int> dpat;
pair<int, int> dst;
queue<pair<pair<int, int>, int>> q;

int dx[] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dy[] = {-2, 2, -2, 2, -1, 1, -1, 1};

void bfs(pair<pair<int, int>, int> p){
    int xpos = p.first.first;
    int ypos = p.first.second;
    if (xpos >= 0 && xpos < l && ypos >= 0 && ypos < l && !visit[xpos][ypos]){
        visit[xpos][ypos] = 1;
        q.push({{xpos, ypos}, p.second});
    }
}

int main(){
    cin >> t;
    while(t--){
        cin >> l;
        cin >> X >> Y;
        cin >> dst.first >> dst.second;

        visit[X][Y] = 1;
        q.push({{X, Y}, 0});
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            if (cur.first.first == dst.first && cur.first.second == dst.second){
                cout << cur.second << '\n';
                while(!q.empty())
                    q.pop();
                break;
            }
            for (int i = 0; i < 8; i++){
                bfs({{cur.first.first + dx[i], cur.first.second + dy[i]}, cur.second + 1});
            }

        }
        fill(&visit[0][0], &visit[0][0] + sizeof(visit)/sizeof(bool), 0);
    }
}