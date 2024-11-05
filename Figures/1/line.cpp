#include <iostream>
#include <string>
#include <thread>
#include <chrono>

std::string line_out(char* nums, int size, const std::string& name) { 
    std::string result;
    if (name == "Line") {
        for (int i = 0; i < size; ++i) {
            result += nums[i]; 
            result += " "; 
        }
        result += "\n"; 
    }
    return result;
}

int main() {
    std::string figure; 
    char* strings = nullptr;
    
    std::cout << "Enter string: "; // Вводим строку, например, "Line"
    std::cin >> figure; 

    int size = 0;
    std::cout << "Enter size of strings: "; 
    std::cin >> size;

    strings = new char[size]; 
    // Заполняем strings символами (например, 'a')
    for (int i = 0; i < size; ++i) {
        strings[i] = '.';
    }

    std::cout << "Enter in the line the figure you would like to see: \n"; // Нажимаем Enter
    std::cin >> figure; 

    std::cout << "Wait a minute..Process is working \n";

    // Запускаем line_out в отдельном потоке
    std::thread thread(line_out, strings, size, figure);
    thread.detach();

    // Индикатор прогресса
    for (int i = 0; i <= 10; ++i) {
        std::cout << "\r[";
        for (int j = 0; j < i; ++j) {
            std::cout << "#";
        }
        for (int j = i; j < 10; ++j) {
            std::cout << " ";
        }
        std::cout << "] " << i * 10 << "%";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    std::cout << "\n";

    std::cout  << line_out(strings, size, figure);

    std::cout << "Result!! \n";

    delete[] strings;
    return 0;
}
