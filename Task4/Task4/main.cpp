#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <locale>

/**
 * @brief Вычитает заданное число K из всех элементов входного вектора.
 * @param input Входной вектор целых чисел.
 * @param K Число, которое нужно вычесть из каждого элемента.
 * @return Новый вектор, содержащий результат вычитания.
 */
std::vector<int> subtractKFromVector(const std::vector<int>& input, int K) {
    std::vector<int> result(input.size());

    std::transform(
        input.begin(), input.end(),
        result.begin(),
        [K](int x) { return x - K; }
    );

    return result;
}

/**
 * @brief Печатает вектор целых чисел с необязательным сообщением.
 * @param vec Вектор для вывода.
 * @param message Сообщение перед выводом значений.
 */
void printVector(const std::vector<int>& vec, const std::string& message = "") {
    if (!message.empty()) std::cout << message;
    for (int x : vec) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    std::cout << "Введите элементы вектора (через пробел, завершите Ctrl+D / Ctrl+Z): ";

    std::vector<int> V((std::istream_iterator<int>(std::cin)), std::istream_iterator<int>());

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    int K;
    std::cout << "Введите число K, которое будет вычитаться из каждого элемента: ";
    std::cin >> K;

    std::vector<int> result = subtractKFromVector(V, K);

    printVector(result, "Результат: ");

    return 0;
}
