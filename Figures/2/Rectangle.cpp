#include <iostream>
#include <string>
#include <thread>
#include <chrono>

std::string line_out(char* nums, int size, const std::string& name);
std::string Rec_out(char* nums, int size, const std::string& name); 

int main() {
    std::string figure; 
    char* strings = nullptr;
    
    std::cout << "Enter symbol: "; 
    std::cin >> figure; 

    int size = 0;
    std::cout << "Enter size of strings: "; 
    std::cin >> size;

    strings = new char[size]; 
    for(int i = 0; i < size; ++i) {
        strings[i] = '*';
    }

    std::cout << "Enter in the line the figure you would like to see: \n";
    std::cin >> figure; 

    std::cout << "Wait a minute..Process is working \n";

    // Запускаем line_out в отдельном потоке
    std::thread thread(Rec_out, strings, size, figure);
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

    std::cout  << Rec_out(strings, size, figure);

    std::cout << "Result!! \n";

    delete[] strings;
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

std::string Rec_out(char* nums, int size, const std::string& name) {

    std::string result;
    if (name == "Rectangle") {

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result += '*';
            }
            result += '\n';
        }
    }
    return result;
}
