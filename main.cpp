// Условие задачи №3
// Квадратные матрицы с целочисленными элементами
// 1. Обычный двумерный массив
// 2. Диагональная матрица на основе одномерного массива

// Организация контейнера №2
// Контейнер на основе однонаправленного линейного списка

// Модульная структура №2
// Разбиение на модули осуществляется по объектному принципу.
// То есть описание абстракций и функций их обработки группируются по виду абстракций.
// При этом проводится разделение описания типов, сигнатур и классов от их реализации.
// Клиентский модуль связан с основной частью программы только минимально необходимым интерфейсом.

#include <iostream>
#include <fstream>
#include <vector>

#include "container.hpp"

int main(int argc, char** argv) {
    if (argc != 3) {
        std::cerr << "Please specify input and output files" << std::endl;
        return EXIT_FAILURE;
    }
    auto input = std::ifstream(argv[1], std::ios::binary);
    if (!input.is_open()) {
        std::cerr << "Couldn't open the input file." << std::endl;
        return EXIT_FAILURE;
    }
    auto output = std::ofstream(argv[2]);
    if (!output.is_open()) {
        std::cerr << "Couldn't open the output file." << std::endl;
        return EXIT_FAILURE;
    }
    // #define output std::cout

    input.seekg(0, std::ios::end);
    size_t input_file_size = input.tellg();
    input.seekg(0, std::ios::beg);
    std::vector<int32_t> input_data(input_file_size / sizeof(int32_t));
    input.read((char*)input_data.data(), input_file_size);

    output << "Start" << std::endl;

    MatrixContainer container;
    container.read(input_data);
    output << "Filled container" << std::endl;
    output << container.format();
    output << "Written container" << std::endl;
    container.clear();
    output << "Cleared container" << std::endl;
    output << container.format();

    output << "Stop" << std::endl;

    return EXIT_SUCCESS;
}
