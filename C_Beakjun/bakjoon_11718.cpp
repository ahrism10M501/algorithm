#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string arr[100];
    unsigned int i = 0;
    while(true){
        cin >> arr[i];
        if(arr[i] == "" || arr[i] == "\n" || arr[i] == " ") {
            break;
        }
        i++;
    }

    for(int j=0;j<100;j++) {
        cout << arr[j] << endl;
    }

    return 0;
}