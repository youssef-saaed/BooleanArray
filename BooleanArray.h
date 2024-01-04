/**
 * @file BooleanArray.h
 * @brief Header file for BooleanArray
 * @author Yousef Said
*/
#ifndef _BITSBOOLEANARRAY_H_
#define _BITSBOOLEANARRAY_H_

#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <stdexcept>

/**
 * @brief A global variable represents the size of datatype used in implementation
*/
extern const size_t CHUNK_SIZE;

/**
 * @brief An array of booleans class
 * @details This class is intended to be used for storing array of boolean with minimum loss
*/
class BooleanArray
{
private:
    /**
     * @brief A private member variable which is the pointer used to point to dynamic memory allocated for the array
    */
    uint8_t *arr;
    /**
     * @brief A private member variable stores the max number of booleans stored in array
    */
    size_t MAX_SIZE;
public:
    /**
     * @brief Constructor for BooleanArray
     * @param MAX_SIZE intializer for internal array size and MAX_SIZE
    */
    BooleanArray(size_t MAX_SIZE);
    /**
     * @brief Destructor for BooleanArray
     * @details This destructor is used to deallocte internal array
    */
    ~BooleanArray();
    /**
     * @brief Overloaded [] operator for BooleanArray
     * @param index index of the boolean item to get
     * @return the boolean value in the requested index
    */
    bool operator[](size_t index);
    /**
     * @brief Public method to set value at an index in array
     * @param index index specifiy the (index) in array
     * @param val (val) is the new value we want to set it
    */
    void set(size_t index, bool val);
};

#endif // _BITSBOOLEANARRAY_H_