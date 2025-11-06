#include <iostream>

int main(void) {
    int i, r, a, b;
    std::cin >> r;
    i=0;
    while(i<r){
        scanf("%d %d", &a, &b);
        std::cout << "Case #" << i+1 << a+b << std::endl;
        i++;
    }
}