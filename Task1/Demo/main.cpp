#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <locale>

/**
 * @brief Преобразует строку в число типа double.
 * @param str Строка, содержащая вещественное число.
 * @return Число, если преобразование успешно, иначе 0.0.
 */
double string_to_double(const std::string& str) {
    std::stringstream ss(str);  
    double num;
    return (ss >> num) ? num : 0.0; 
}

/**
 * @brief Подсчитывает количество положительных чисел в файле.
 * @param filename Имя файла, содержащего строковые представления чисел.
 * @return Количество положительных чисел в файле.
 * @throws Если файл не удаётся открыть.
 */
int count_positive_numbers(const std::string& filename) {
    std::ifstream file(filename);  
    if (!file)
        throw std::runtime_error("Ошибка: Не удалось открыть файл!");

    std::istream_iterator<std::string> it(file), end; 
    return std::count_if(it, end, [](const std::string& str) {
        return string_to_double(str) > 0; 
        });
}

/**
 * @brief Точка входа в программу. Запускает подсчёт положительных чисел в файле.
 * @return int Код возврата программы.
 */
int main() {
    setlocale(LC_ALL, "RU");
    try {
        std::cout << "Количество положительных чисел: "
            << count_positive_numbers("../Demo/name.txt") << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
