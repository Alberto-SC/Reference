#include <algorithm>
#include <array>
#include <cstdarg>
#include <cstdio>
#include <cstdint>
#include <limits>
#include <stack>
#include <string>
#include <vector>

using LL = long long; 
using Partial = std::pair<int, LL>;

static bool trace;

static void log(const char *fmt, ...) {
    if (trace) {
        va_list va;
        va_start(va, fmt);
        vfprintf(stderr, fmt, va);
        va_end(va);
    }
}

int main(int argc, char *argv[]){
    int n = 1;
    if (n < argc && std::string(argv[1]) == "-t") {
        trace = true;
        n++;
    }

    if (n < argc) {
        freopen(argv[n], "r", stdin);
    }

    int rows, cols;
    LL target;
    scanf("%d %d %lld", &rows, &cols, &target);
    
    std::vector<int> matrix_ {};
    matrix_.resize(rows * cols);

    auto matrix = [&](int row, int col) -> int& {
        return matrix_[row * cols + col]; 
    };

    if (rows < cols) {
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                scanf("%d", &matrix(r,c));
            }
        }
    } else {
        std::swap(rows, cols);
        for (int c = 0; c < cols; c++) {
            for (int r = 0; r < rows; r++) {
                scanf("%d", &matrix(r,c));
            }
        }
    }

    std::vector<LL> sum_ {};
    sum_.resize((rows + 1) * cols);

    std::vector<LL> slice {};
    slice.resize(cols);

    std::vector<Partial> partials {};
    partials.resize(cols);

    auto sum = [&](int row, int col) -> LL& {
        return sum_[row * cols + col]; 
    };

    for (int col = 0; col < cols; col++) {
        sum(0, col) = 0;
        for (int row = 0; row < rows; row++) {
            sum(row + 1, col) = sum(row, col) + matrix(row, col);
        }
    }

    const int MAX = std::numeric_limits<int>::max();

    int answer = MAX;

    for (int h = 1; h <= rows; h++) {
        for (int row = 0; row + h <= rows; row++) {
            for (int col = 0; col < cols; col++) {
                slice[col] = sum(row + h, col) - sum(row, col);
            }

            LL sum = 0;
            int ptr = 0;
            int best = MAX;

            auto valueAt = [&](int i) { return sum + partials[i].second; };
            
            for (int col = 0; col < cols; col++) {
                sum += slice[col];
                LL delta = slice[col] - sum;

                while (ptr > 0 && partials[ptr-1].second <= delta) {
                    ptr--;
                }

                partials[ptr++] = Partial(col, delta);

                if (valueAt(0) < target) {
                    continue;
                }

                int l = 0;
                int h = ptr-1;
                int m;
                while (h - l > 1) {
                    m = (h + l) / 2;
                    if (valueAt(m) >= target) {
                        l = m;
                    } else {
                        h = m;
                    }
                }

                if (valueAt(h) < target) {
                    h--;
                }
                
                best = std::min(best, col - partials[h].first + 1);
            }

            if (best == MAX) {
                continue;
            }

            answer = std::min(answer, best * h);
        }
    }
    printf("%d\n", answer == MAX ? -1 : answer);
}
