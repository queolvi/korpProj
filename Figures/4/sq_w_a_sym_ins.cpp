#include <iostream>
#include <thread>
#include <chrono>
#include <string>


std::string square_out(char* nums, int size, const std::string& name);
std::string line_out(char* nums, int size, const std::string& name);

int main() {
    std::string figure;
    char* symbols = nullptr;
    int size = 0;

    std::cout << "Enter figure: \n";
    std::cin >> figure;

    std::cout << "Enter size of the figure: \n";
    std::cin >> size;

    symbols = new char[size];
    for (int i = 0; i < size; ++i) {
        symbols[i] = '*';
    }

    std::cout << "Enter in the line the figure you would like to see: \n";
    std::cin >> figure;
    std::cout << "Wait a minute...Process is working.. \n";

    std::thread th_f_sq(square_out, symbols, size, figure);
    th_f_sq.detach();

    for (int i = 0; i <= 10; ++i) {
        std::cout << "\r[";
        for (int j = 0; j < i; ++j) {
            std::cout << "#";
        }
        for (int j = i; j < 10; ++j) {
            std::cout << " ";
        }
        std::cout << "] " << i * 10 << "%";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    std::cout << "\n";
    std::cout << square_out(symbols, size, figure);
    std::cout << "Result !!! \n";

    delete[] symbols;
    return 0;
}

std::string square_out(char* nums, int size, const std::string& name) {
    std::string result = "";
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == size / 2 && j == size / 2) {
                result += name[0]; // Use the first character of the figure
            } else {
                result += nums[j];
            }
        }
        result += "\n";
    }
    return result;
}

std::string line_out(char* nums, int size, const std::string& name) {
    return "";
}
