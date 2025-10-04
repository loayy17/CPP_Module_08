#include "Span.hpp"

Span::Span(unsigned int N) : _max_capacity(N){};

Span::Span(const Span& other) : _max_capacity(other._max_capacity), _numbers(other._numbers){};

Span& Span::operator=(const Span& other) {
    if (this == &other)
        return *this;
    _max_capacity = other._max_capacity;
    _numbers      = other._numbers;
    return *this;
};

Span::~Span(){};

void Span::addNumber(int valueToPush) {
    if (_numbers.size() >= _max_capacity)
        throw std::runtime_error("Span is full");
    _numbers.push_back(valueToPush);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");
    std::vector<int> casheVector(_numbers.begin(), _numbers.end());
    std::sort(casheVector.begin(), casheVector.end());
    int minSpan = casheVector[1] - casheVector[0];
    for (size_t i = 1; i < casheVector.size() - 1; ++i) {
        int shortSpan = casheVector[i + 1] - casheVector[i];
        if (shortSpan < minSpan)
            minSpan = shortSpan;
    }
    return minSpan;
};

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");
    std::vector<int> casheVector(_numbers.begin(), _numbers.end());
    std::sort(casheVector.begin(), casheVector.end());
    return casheVector[casheVector.size() - 1] - casheVector[0];
}