#ifndef NEIGHBORHOODTYPE_H
#define NEIGHBORHOODTYPE_H

/** \brief Dictionary representing the neighborhood types.
 */
class NeighborhoodType
{

public:
    /** \brief Von Neumann - four neighbors (up, down, left, right).
     */
    static const int VON_NEUMANN = 0;

    /** \brief Moore - eight neighbors (up, down, left, right, diagonals).
     */
    static const int MOORE = 1;
};

#endif // NEIGHBORHOODTYPE_H
