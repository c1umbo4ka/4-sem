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
std::vector<int> input_vector(int n) {
    std::vector<int> v(n);
    std::cout << "Введите элементы вектора:" << std::endl;
    std::copy_n(std::istream_iterator<int>(std::cin), n, v.begin());
    return v;
}

/**
 * @brief Функция для удаления трех средних элементов из вектора.
 * @param v Вектор, из которого нужно удалить элементы.
 * @return Вектор после удаления трех средних элементов.
 */
std::vector<int> remove_middle_elements(std::vector<int> v) {
    int n = v.size();
    int middle_index = n / 2;

    v.erase(v.begin() + middle_index - 1, v.begin() + middle_index + 2);

    return v;
}

/**
 * @brief Функция для вывода вектора.
 * @param v Вектор для вывода.
 */
void print_vector(const std::vector<int>& v) {
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
}

int main() {
    setlocale(LC_ALL, "RU");
    int n;

    std::cout << "Введите нечетное количество элементов (не меньше 5): ";
    std::cin >> n;

    if (n < 5 || n % 2 == 0) {
        std::cerr << "Количество элементов должно быть нечетным и не менее 5." << std::endl;
        return 1;
    }
        
    std::vector<int> v = input_vector(n);
    std::vector<int> result = remove_middle_elements(v);

    std::cout << "Вектор после удаления трех средних элементов:" << std::endl;
    print_vector(result);

    return 0;
}
