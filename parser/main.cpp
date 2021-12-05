
#include "Parser.h"

void test1() {
    unsigned char Input1[]={"053F80000009011C40000000"};
    Parser parser1(Input1);
}

void test2() {
    unsigned char Input2[]={"4C41A400004B3F91BCD8"};
    Parser parser2(Input2);
}

void test3() {
    unsigned char Input3[]={"0741A40000053F91BCD819413547AE"};
    Parser parser3(Input3);
}

void test4() {
    unsigned char Input4[]={"05430D083B183F91BCD8193EDF4DE94D422869E241F8F5C341DEC28F3C594D0E"};
    Parser parser4(Input4);
}

void test5() {
    unsigned char Input5[]={"05430D083B183F91BCD8193EDF4DE94F00080015BCA408C0163BFB4DAB173F80F5081BC16EA4371CC12D31271D42513D4F4A000000004B000000004C00000000"};
    Parser parser5(Input5);
}

void testsRun() {
    test1();
    test2();
    test3();
    test4();
    test5();

}

int main()
{
    testsRun();
    return 0;
}
