#include <iostream>
#include <string>
#include <thread>
#include <chrono>

std::string line_out(char* nums, int size, const std::string& name);
std::string square_out(int size, const std::string& name); // Simplified function

int main() {
    std::string figure; 
    char* strings = nullptr;
    int size = 0;

    std::cout << "Enter string: "; 
    std::cin >> figure; 

    std::cout << "Enter size of square side: "; 
    std::cin >> size; 

    strings = new char[size * size]; // Allocate memory for the square
    for(int i = 0; i < size * size; ++i) {
        strings[i] = '*'; 
    }

    std::cout << "Wait a minute..Process is working \n";

    // Запускаем square_out в отдельном потоке
    std::thread thread(square_out, size, figure);
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

    std::cout << square_out(size, figure); // Print the square

    std::cout << "Result!! \n";

    delete[] strings; // Clean up memory
    return 0;
}

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

std::string square_out(int size, const std::string& name) { // Simplified function
    std::string result;
    if (name == "Square") { 
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result += '*';
            }
            result += '\n'; 
        }
    }
    return result;
}
