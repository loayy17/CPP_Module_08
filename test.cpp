#include <vector>
#include <iostream>
int main() {
    std::vector<int> x(5);
    x[0] = 1;
    x[1] = 2;
    x[2] = 3;
    x[3] = 4;
    x[4] = 5;

    for(int i = 0; i < 5; i++) {
        x.push_back(i);
    }
    for(std::vector<int>::iterator it = x.begin(); it != x.end();it++) {
       if(*it == 3) {
           x.erase(it); 
       }
    }
    for(std::vector<int>::size_type i = 0; i < x.size(); i++) {
        std::cout << x[i] << std::endl;
    }
    return 0;
}