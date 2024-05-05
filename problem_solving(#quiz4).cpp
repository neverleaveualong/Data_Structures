#include <iostream>
#include <stack>
#include <limits>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        stack<int> block_stack;
        int min_val = numeric_limits<int>::max();
        int max_val = numeric_limits<int>::min();

        for (int i = 0; i < N; ++i) {
            int type;
            cin >> type;

            if (type == 1) {
                int x;
                cin >> x;

                
                block_stack.push(x);

                
                if (x < min_val) min_val = x;
                if (x > max_val) max_val = x;

                
                cout << min_val << " " << max_val << "\n";
            }
            else if (type == 2) {
                if (!block_stack.empty()) {
                    int top = block_stack.top();
                    block_stack.pop();

                    
                    if (block_stack.empty()) {
                        min_val = numeric_limits<int>::max();
                        max_val = numeric_limits<int>::min();
                    }
                    else if (top == min_val || top == max_val) {
                        
                        stack<int> temp_stack;
                        min_val = numeric_limits<int>::max();
                        max_val = numeric_limits<int>::min();

                        while (!block_stack.empty()) {
                            int val = block_stack.top();
                            block_stack.pop();
                            temp_stack.push(val);
                            if (val < min_val) min_val = val;
                            if (val > max_val) max_val = val;
                        }

                        while (!temp_stack.empty()) {
                            int val = temp_stack.top();
                            temp_stack.pop();
                            block_stack.push(val);
                        }
                    }
                }
            }
        }
    }

    return 0;
}
