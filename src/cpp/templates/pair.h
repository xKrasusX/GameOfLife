#ifndef PAIR_H
#define PAIR_H

/** \brief Template representing pair of objects of the same type.
 */
template <typename T>
class Pair
{

public:
    /** \brief Constructor returning new Pair object with predefined objects.
     *
     * \param x T First object of the pair.
     * \param y T Second object of the pair.
     *
     */
    Pair<T>(T x, T y) {
        this->x = x;
        this->y = y;
    }

    /** \brief Returns first object of the pair.
     * \return T First object of the pair.
     */
    T getX() {
        return x;
    }

    /** \brief Returns second object of the pair.
     * \return T Second object of the pair.
     */
    T getY() {
        return y;
    }

private:
    T x, y;
};

#endif // PAIR_H
