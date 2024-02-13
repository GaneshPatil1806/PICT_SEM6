#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int i, j, f, time;
    node(int i, int j, int f, int time) : i(i), j(j), f(f), time(time) {}

    bool operator<(const node& other) const {
        return f > other.f;  // Assuming lower f-values have higher priority
    }
};

// bool cmp operator()(const node& a, const node& b) {
//         if (a.f == b.f)
//             return a.time > b.time;
//         else
//             return a.f > b.f;
// };

int main()
{
    int row, col;
    cout << "Enter the number of rows and columns" << endl;
    cin >> row >> col;

    // matrix
    vector<vector<node>> v(row, vector<node>(col));

    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            v[i][j] = node(i, j, 0, 0); 
        }
    }

    cout << "Enter the number of hurdles" << endl;
    int hurdle;
    cin >> hurdle;

    cout << "Enter the hurdles(a,b)" << endl;
    for (int i = 0; i < hurdle; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        v[a][b].time = -1;
    }

    priority_queue<node, vector<node>, decltype(cmp)> open(cmp);
    map<string,int> close;

    int total = 0;
    int cnt = row * col;
    node a(0, 0, 0, 0);
    open.push(a);

    vector<pair<int, int>> dist = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    while (total < cnt && !open.empty()) {
        node current = open.top();
        int row = current.i;
        int col = current.j;

        string mark_close = to_string(row) + "_" + to_string(col);
        open.pop();
        close[mark_close] = 1;

        if (current.i == row - 1 && current.j == col - 1) {
            cout << "Path found!" << endl;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nextR = row + dist[i].first;
            int nextC = col + dist[i].second;

            string check_close = to_string(nextR) + "_" + to_string(nextC);

            if (close.find(check_close)==close.end()) {
                int g = current.f + 1; 
                int h = abs(nextR - (row - 1)) + abs(nextC - (col - 1)); 
                int f = g + h;

                int time = total;
                open.push(node(nextR, nextC, f, time));
            }
        }

        total++;
    }

    return 0;
}
