#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
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
        std::bind(std::minus<int>(), std::placeholders::_1, K)
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

/**
 * @brief Главная функция. Запрашивает ввод у пользователя, вызывает обработку и выводит результат.
 * @return int Код завершения программы.
 */
int main() {
    setlocale(LC_ALL, "RU");
    int K;
    int n;

    std::cout << "Введите количество элементов вектора: ";
    std::cin >> n;

    std::vector<int> V(n);
    std::cout << "Введите элементы вектора: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> V[i];
    }

    std::cout << "Введите число K, которое будет вычитаться из каждого элемента: ";
    std::cin >> K;

    std::vector<int> result = subtractKFromVector(V, K);

    printVector(result, "Результат: ");

    return 0;
}
