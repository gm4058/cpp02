#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);


int main()
{
    // 삼각형 꼭짓점
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);

    // 테스트할 점
    Point p1(5, 5);    // 내부
    Point p2(10, 10);  // 외부
    Point p3(0, 0);    // 꼭짓점
    Point p4(5, 0);    // 변 위

    std::cout << "p1 inside: " << (bsp(a, b, c, p1) ? "yes" : "no") << std::endl;
    std::cout << "p2 inside: " << (bsp(a, b, c, p2) ? "yes" : "no") << std::endl;
    std::cout << "p3 inside: " << (bsp(a, b, c, p3) ? "yes" : "no") << std::endl;
    std::cout << "p4 inside: " << (bsp(a, b, c, p4) ? "yes" : "no") << std::endl;

    return 0;
}