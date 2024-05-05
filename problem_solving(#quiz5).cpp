#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        
        vector<string> sentence(M);
        for (int i = 0; i < M; ++i) {
            cin >> sentence[i];
        }

       
        vector<unordered_map<string, int>> friendsNotes(N);

       
        for (int i = 0; i < N; ++i) {
            int K;
            cin >> K;
            for (int j = 0; j < K; ++j) {
                string word;
                cin >> word;
                friendsNotes[i][word] = j;
            }
        }

    
        vector<int> lastPosition(N, -1);
        bool canRestore = true;

        for (string& word : sentence) {
            bool found = false;
            for (int i = 0; i < N; ++i) {
                if (friendsNotes[i].count(word) && friendsNotes[i][word] > lastPosition[i]) {
                    lastPosition[i] = friendsNotes[i][word];
                    found = true;
                    break;
                }
            }
            if (!found) {
                canRestore = false;
                break;
            }
        }

        cout << (canRestore ? 1 : 0) << endl;
    }

    return 0;
}
