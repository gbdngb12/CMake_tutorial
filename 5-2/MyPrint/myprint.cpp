#include "myprint.h"

void MyPrint::myprint() {
    char buf[10] = { 0 };
    getlogin_r(buf, 10);
    std::cout << buf << std::endl;
    return;
}