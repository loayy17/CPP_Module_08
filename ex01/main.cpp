#include "Span.hpp"
#include <vector>
#include <deque>
#include <list>
#include <iostream>

int main() {
    try {
        std::cout << "=== Test 1: Basic vector ===" << std::endl;
        Span sp(5);

        sp.addNumber(10);
        sp.addNumber(3);
        sp.addNumber(20);
        sp.addNumber(6);
        sp.addNumber(15);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        std::cout << "Adding one more number (should throw)..." << std::endl;
        sp.addNumber(99);
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n=== Test 2: Multiple numbers (deque) ===" << std::endl;
        std::deque<int> nums;
        for (int i = 1; i <= 10; ++i)
            nums.push_back(i * 2);

        Span sp2(15);
        sp2.addMultipleNumbers(nums.begin(), nums.end());

        std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl; // should be 2
        std::cout << "Longest span: " << sp2.longestSpan() << std::endl;   // should be 18
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n=== Test 3: Not enough numbers ===" << std::endl;
        Span sp3(3);
        sp3.addNumber(42);
        std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl; // should throw
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "\n=== Test 4: Using list ===" << std::endl;
        std::list<int> lst;
        for (int i = 100; i <= 105; ++i)
            lst.push_back(i);

        Span sp4(10);
        sp4.addMultipleNumbers(lst.begin(), lst.end());

        std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp4.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    Span sp5(1000000);
    for (int i = 0; i < 1000000; ++i)
        sp5.addNumber(i * 2);
    std::cout << "\n=== Test 5: Large Span with 1,000,000 numbers ===" << std::endl;
    try {
        std::cout << "Shortest span: " << sp5.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp5.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    Span sp6(500000 + 110005);
    for (int i = 1; i <= 110005; ++i)
        sp6.addNumber(i * 10);
    std::vector<int> v;
    for (int i = 1; i <= 500000; ++i)
        v.push_back(i * 10);
    typedef std::vector<int>::iterator vecIt;
    vecIt                              begin = v.begin();
    vecIt                              end   = v.end();
    sp6.addMultipleNumbers(begin, end);
    std::cout << "\n=== Test 6: Large addMultipleNumbers ===" << std::endl;
    try {
        std::cout << "Shortest span: " << sp6.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp6.longestSpan() << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    // Test not Enough space
    try {
        std::cout << "\n=== Test 7: Not enough space for addMultipleNumbers ===" << std::endl;
        Span             sp7(5);
        std::vector<int> smallVec(10);
        for (int i = 0; i < 10; ++i)
            smallVec.push_back(i + 3);
        sp7.addMultipleNumbers(smallVec.begin(), smallVec.end());
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
