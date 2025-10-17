#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
    std::cout << "=== Case 1: Basic Triangle ===" << std::endl;
    {
        Point a(0, 0);
        Point b(10, 0);
        Point c(5, 10);

        Point p1(5, 5);    // 내부
        Point p2(10, 10);  // 외부
        Point p3(0, 0);    // 꼭짓점
        Point p4(5, 0);    // 변 위

        std::cout << "p1: " << (bsp(a, b, c, p1) ? "yes" : "no") << std::endl;
        std::cout << "p2: " << (bsp(a, b, c, p2) ? "yes" : "no") << std::endl;
        std::cout << "p3: " << (bsp(a, b, c, p3) ? "yes" : "no") << std::endl;
        std::cout << "p4: " << (bsp(a, b, c, p4) ? "yes" : "no") << std::endl;
    }

    std::cout << "\n=== Case 2: Negative Coordinates ===" << std::endl;
    {
        Point a(-3, -2);
        Point b(5, 1);
        Point c(2, 8);

        Point inside(1, 2);
        Point outside(4, 7);
        Point edge(2, 3);

        std::cout << "inside: " << (bsp(a, b, c, inside) ? "yes" : "no") << std::endl;
        std::cout << "outside: " << (bsp(a, b, c, outside) ? "yes" : "no") << std::endl;
        std::cout << "edge: " << (bsp(a, b, c, edge) ? "yes" : "no") << std::endl;
    }

    std::cout << "\n=== Case 3: Float Coordinates ===" << std::endl;
    {
        Point a(0.0f, 0.0f);
        Point b(3.5f, 0.0f);
        Point c(1.5f, 2.5f);

        Point p1(1.5f, 0.5f);   // 내부
        Point p2(3.5f, 2.5f);   // 외부
        Point p3(0.0f, 0.0f);   // 꼭짓점
        Point p4(1.75f, 1.25f); // 내부 (정중앙 부근)

        std::cout << "p1: " << (bsp(a, b, c, p1) ? "yes" : "no") << std::endl;
        std::cout << "p2: " << (bsp(a, b, c, p2) ? "yes" : "no") << std::endl;
        std::cout << "p3: " << (bsp(a, b, c, p3) ? "yes" : "no") << std::endl;
        std::cout << "p4: " << (bsp(a, b, c, p4) ? "yes" : "no") << std::endl;
    }

    return 0;
}