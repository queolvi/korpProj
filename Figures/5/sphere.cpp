#include<iostream>
#include<cmath>

void outSphere(int rad);

int main() {

int rad = 0;
std::cout << "Enter rad of the sphere: \n"; std::cin >> rad;

outSphere(rad);


    return 0;
}
void outSphere(int rad) {


    for(int y = -rad; y <= rad; ++y) {
        for(int x = - rad; x <= rad; ++x) {
            double dist = sqrt(x * x + y * y);

            if(dist <= rad) {
                std::cout << "*";
            } else {
                std::cout << " ";
            }
        }
        std::cout << "\n";
    }
}