#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <locale>

/**
 * @brief Функция для ввода вектора с клавиатуры.
 * @param n Количество элементов в векторе.
 * @return Вектор, заполненный пользователем.
 */
std::vector<int> inputVector(int n) {
    std::vector<int> V(n);
    std::cout << "Введите элементы вектора:" << std::endl;
    std::copy_n(std::istream_iterator<int>(std::cin), n, V.begin());
    return V;
}

/**
 * @brief Функция для удаления трех средних элементов из вектора.
 * @param V Вектор, из которого нужно удалить элементы.
 * @return Вектор после удаления трех средних элементов.
 */
std::vector<int> removeMiddleElements(const std::vector<int>& V) {
    int n = V.size();
    int middleIndex = n / 2;
    std::vector<int> result;

    std::copy(V.begin(), V.begin() + middleIndex - 1, std::back_inserter(result));
    std::copy(V.begin() + middleIndex + 2, V.end(), std::back_inserter(result));

    return result;
}

/**
 * @brief Функция для вывода вектора.
 * @param V Вектор для вывода.
 */
void printVector(const std::vector<int>& V) {
    std::copy(V.begin(), V.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    int n;

    std::cout << "Введите нечетное количество элементов (≥ 5): ";
    std::cin >> n;

    if (n >= 5 && n % 2 != 0) {
        std::vector<int> V = inputVector(n);
        std::vector<int> result = removeMiddleElements(V);

        std::cout << "Вектор после удаления трех средних элементов:" << std::endl;
        printVector(result);
    }
    else {
        std::cerr << "Количество элементов должно быть нечетным и не менее 5." << std::endl;
        return 1;
    }

    return 0;
}
