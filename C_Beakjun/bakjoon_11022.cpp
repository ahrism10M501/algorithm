#include <iostream>

int main(void) {
    int i, r, a, b;
    std::cin >> r;
    i=0;
    while(i<r){
        scanf("%d %d", &a, &b);
        printf("Case #%d: %d + %d = %d\n", i+1, a, b, a+b);
        i++;
    }
}