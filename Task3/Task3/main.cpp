#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <cmath>

/**
 * @brief Получает последнюю цифру целого числа.
 * @param number Целое число.
 * @return int Последняя цифра числа.
 */
int last_digit(int number) {
    return std::abs(number) % 10;
}

/**
 * @brief Группирует элементы вектора по последней цифре.
 * @param vec Входной вектор целых чисел.
 * @return std::multimap<int, int> Мультиотображение, сгруппированное по последней цифре.
 */
std::multimap<int, int> group_by_last_digit(const std::vector<int>& vec) {
    std::multimap<int, int> mmap;

    std::for_each(vec.begin(), vec.end(), [&mmap](int value) {
        mmap.insert({ last_digit(value), value });
        });

    return mmap;
}

/**
 * @brief Выводит содержимое `multimap` на экран.
 * @param mmap Мультиотображение для вывода.
 */
void print_multimap(const std::multimap<int, int>& mmap) {
    std::for_each(mmap.begin(), mmap.end(), [](const std::pair<const int, int>& entry) {
        std::cout << entry.first << " " << entry.second << std::endl;
        });
}

/**
 * @brief Точка входа в программу.
 * @return int Код завершения программы.
 */
int main() {
    std::vector<int> V = { 12, 25, 37, 48, 19, 22, 35, 45, 67, 78 };

    auto grouped = group_by_last_digit(V);

    print_multimap(grouped);

    return 0;
}
