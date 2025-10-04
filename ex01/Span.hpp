#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>

class Span {
   public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int valueToPush);
    int  shortestSpan() const;
    int  longestSpan() const;

    template <typename Iter>
    void addMultipleNumbers(Iter begin, Iter end) {
        for (; begin != end; ++begin)
            addNumber(*begin);
    }

   private:
    unsigned int     _max_capacity;
    std::vector<int> _numbers;
};

#endif