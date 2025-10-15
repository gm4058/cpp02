#include "Fixed.hpp"
#include <iostream>

int main(void)
{
    Fixed a;                // 기본 생성자
    Fixed const b(10);      // int 생성자
    Fixed const c(42.42f);  // float 생성자
    Fixed const d(b);       // 복사 생성자

    a = Fixed(1234.55f);    // 대입 연산자 + 임시 객체


    std::cout << "\n--- 입력 값 출력 ---\n";
    std::cout << "a input(float): 1234.55f" << std::endl;
    std::cout << "b input(int): 10" << std::endl;
    std::cout << "c input(float): 42.42f" << std::endl;
    std::cout << "d input(int): 10" << std::endl;

    std::cout << "\n--- fp 값 출력 ---\n";
    std::cout << "a raw bits: " << a.getRawBits() << std::endl;
    std::cout << "b raw bits: " << b.getRawBits() << std::endl;
    std::cout << "c raw bits: " << c.getRawBits() << std::endl;
    std::cout << "d raw bits: " << d.getRawBits() << std::endl;

    std::cout << "\n--- float 변환 테스트 ---\n";
    std::cout << "a to float: " << a << std::endl;
    std::cout << "b to float: " << b << std::endl;
    std::cout << "c to float: " << c << std::endl;
    std::cout << "d to float: " << d << std::endl;

    std::cout << "\n--- int 변환 테스트 ---\n";
    std::cout << "a as int: " << a.toInt() << std::endl;
    std::cout << "b as int: " << b.toInt() << std::endl;
    std::cout << "c as int: " << c.toInt() << std::endl;
    std::cout << "d as int: " << d.toInt() << std::endl;


    std::cout << "\n--- setter 테스트 ---\n";
    a.setRawBits(5000);
    std::cout << "a raw bits: " << a.getRawBits() << std::endl;
    std::cout << "a to float: " << a << std::endl;
    std::cout << "a as int after setRawBits: " << a.toInt() << std::endl;


    std::cout << "\n--- setter fp와 실제 값 비교---\n";
    Fixed const e(19.5312565622f);
    std::cout << "e 실제 입력값(float): " << "19.5312565622f" << std::endl;
    std::cout << "실제값의 float 출력" << 19.5312565622f << std::endl;
    std::cout << "e raw bits: " << e.getRawBits() << std::endl;
    std::cout << "e to float: " << e << std::endl;
    std::cout << "e as int: " << e.toInt() << std::endl;

    return 0;
}
