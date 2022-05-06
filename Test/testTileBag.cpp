#include "../TileBag.h"
#include <iostream>
#include <string>

int main() {
    std::cout << "\n+++++++++++++++++TESTING GETSCRABBLETILES+++++++++++++++++" << std::endl;
    std::cout << "TileBag is scrambled in constructor." << std::endl;
    
    TileBag* tb = new TileBag();
    std::cout << "TileBag:" << std::endl;
    tb->printBag();
    std::cout << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    delete tb;
}