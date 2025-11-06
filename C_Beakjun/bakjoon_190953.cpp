#include <iostream>

int main(void) {
    int r, a, b;
    std::cin >> r;
    while(r--){
        scanf("%d,%d", &a, &b);
        std::cout << a+b << std::endl;
    }
}