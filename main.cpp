#include <iostream>
#include "hello.h"
#include "caculate.h"




int main() {

    hello();
    int a = 1 ;
    int b = 2 ;
    int c = caculate(a,b);
    std::cout << "ret :" <<  c << std::endl ;
    return 0;
}
