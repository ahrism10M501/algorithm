#include <iostream>

int main(void) {
    int r, A, B;
    std::cin >> r;
    for(int i=0;i<r;i++) {
        std::cin >> A >> B;
        std::cout << A+B;
    }
}