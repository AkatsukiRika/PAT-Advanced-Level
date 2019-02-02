#include <bits/stdc++.h>
using namespace std;

int N, M, C1, C2;
int cnt;
int team, dist;
int maxT, minD;
int c1, c2, L;
int roads[501][501];
int teams[501] = {0};
int flag[501] = {0};

void dfs(int k) {
    int i, j;
    if(k==C2) {
        if(dist<minD) {
            minD = dist;
            maxT = team;
            cnt = 1;
        }
        else if(dist==minD) {
            cnt++;
            if(team > maxT)
                maxT = team;
        }
    }
    flag[k] = true;
    for(int i=0; i<N; i++) {
        if(!flag[i] && roads[k][i]>0) {
            dist += roads[k][i];
            team += teams[i];
            dfs(i);
            team -= teams[i];
            dist -= roads[k][i];
        }
    }
    flag[k] = false;
}

int main() {
    memset(roads, -1, sizeof(roads));
    cin >> N >> M >> C1 >> C2;
    for(int i=0; i<N; i++) cin >> teams[i];
    for(int i=0; i<M; i++) {
        cin >> c1 >> c2 >> L;
        roads[c1][c2] = roads[c2][c1] = L;
    }
    maxT = 0;
    minD = INT_MAX;
    team = teams[C1];
    dist = 0;
    dfs(C1);
    cout << cnt << " " << maxT << endl;
    return 0;
}
