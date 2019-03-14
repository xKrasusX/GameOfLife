#ifndef PAIR_HPP
#define PAIR_HPP

template <typename T>
class Pair
{

public:
    Pair<T>(T x, T y) {
        this->x = x;
        this->y = y;
    }

    T getX() {
        return x;
    }

    T getY() {
        return y;
    }

private:
    T x, y;
};

#endif // PAIR_HPP
