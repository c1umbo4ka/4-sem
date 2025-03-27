#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <sstream>
#include <locale>

/**
 * @brief ����������� ������ � ����� ���� double.
 * @param str ������, ���������� ������������ �����.
 * @return �����, ���� �������������� �������, ����� 0.0.
 */
double string_to_double(const std::string& str) {
    std::stringstream ss(str);  
    double num;
    return (ss >> num) ? num : 0.0; 
}

/**
 * @brief ������������ ���������� ������������� ����� � �����.
 * @param filename ��� �����, ����������� ��������� ������������� �����.
 * @return ���������� ������������� ����� � �����.
 * @throws ���� ���� �� ������ �������.
 */
int count_positive_numbers(const std::string& filename) {
    std::ifstream file(filename);  
    if (!file)
        throw std::runtime_error("������: �� ������� ������� ����!");

    std::istream_iterator<std::string> it(file), end; 
    return std::count_if(it, end, [](const std::string& str) {
        return string_to_double(str) > 0; 
        });
}

/**
 * @brief ����� ����� � ���������. ��������� ������� ������������� ����� � �����.
 * @return int ��� �������� ���������.
 */
int main() {
    setlocale(LC_ALL, "RU");
    try {
        std::cout << "���������� ������������� �����: "
            << count_positive_numbers("../Demo/name.txt") << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}
