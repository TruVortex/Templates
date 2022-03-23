#include <stdio.h>
#include <deque>
#include <vector>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

using namespace std;

deque<int> montonic(vector<int> arr) {
    deque<int> q;
    for (int i = 0; i < arr.size(); i++) {
        while (!q.empty() && q.back() >= arr[i]) { // >= for increasing <= for decreasing
            q.pop_back();
        }
        q.push_back(arr[i]);
        deque<int> copy(q);
        while (!copy.empty()) {
            printf("%d ", copy.front());
            copy.pop_front();
        }
        printf("\n");
    }
    return q;
}

int main() {
    montonic({ 5, 3, 1, 2, 4 });
    return 0;
}
