#include <iostream>
using namespace std;
int main(){
    float eps = 1.0;
    while (1.0 + eps > 1.0) {
        eps *= 0.5;
    }
    cout << "Машинное эпсилон: " << eps << std::endl;
    return 0;
}
