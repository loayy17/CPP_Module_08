template <typename T>
typename T::iterator easyfind(T& container, int value) {
    typedef typename T::iterator iterType;
    iterType                     begin = container.begin();
    iterType                     end   = container.end();
    for (iterType it = begin; it != end; ++it) {
        if (*it == value)
            return it;
    }
    throw std::runtime_error("The value not found");
}
