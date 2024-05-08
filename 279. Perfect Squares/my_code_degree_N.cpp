#include <vector>
#include <algorithm> // Для использования функции min

class Solution {
public:
    const int DEGREE = 2;

    // Функция для вычисления возведения в степень
    size_t power(int base, int exponent) {
        size_t result = 1;
        for (int i = 0; i < exponent; ++i) {
            result *= base;
        }
        return result;
    }

    int numSquares(int N) {
        std::vector<int> DP(N + 1, 101); // DP[i] == наименьшее число слагаемых в квадратичном разложении числа i : i \in |N --> искомое == DP.back()
        DP[0] = 0;

        for (size_t sum = 1; sum <= N; sum++) {
            for (int first = 1; power(first, DEGREE) <= sum; first++) { // first * first <= sum <-->  0 <= sum - first * first -- что используется далее в nSq[sum - first * first]
                // min -- по условию задачи
                DP[sum] = std::min(DP[sum], DP[sum - power(first, DEGREE)] + 1); // "+ 1" обусловлен тем, что из "sum - first * first" можно получить "sum" 
                                                                                  // добавлением одного perfect square = first * first -- значит количество слагаемых увеличивается на 1
            }
        }
        return DP.back();
    }
};