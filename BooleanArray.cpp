/**
 * @file BooleanArray.h
 * @brief Implementation file for BooleanArray
 * @author Yousef Said
*/
#include "BooleanArray.h"

/**
 * @brief A global variable represents the size of datatype used in implementation
*/
const size_t CHUNK_SIZE = sizeof(uint8_t) * 8;

/**
 * @brief Constructor for BooleanArray
 * @param MAX_SIZE intializer for internal array size and MAX_SIZE
*/
BooleanArray::BooleanArray(size_t MAX_SIZE)
{
    // Intializing MAX_SIZE which represents the max number of elements in the boolean array 
    // and intialize the internal array with size equal to the ceil of max numbers of elements in the boolean array divided by the uint8_t size
    this->MAX_SIZE = MAX_SIZE;
    arr = new uint8_t[static_cast<size_t>(ceil((double)MAX_SIZE / CHUNK_SIZE))];
}

/**
 * @brief Destructor for BooleanArray
 * @details This destructor is used to deallocte internal array
*/
BooleanArray::~BooleanArray()
{
    // Free arr allocated memory
    delete[] arr;
}

/**
 * @brief Public method to set value at an index in array
 * @param index index specifiy the (index) in array
 * @param val (val) is the new value we want to set it
*/
void BooleanArray::set(size_t index, bool val)
{
    // Check if the index within the range and if not it throws an error
    if (index < 0 || index >= MAX_SIZE)
    {
        throw std::range_error("Index out of the range");
    }

    // Calculate the internal index and the bit location
    // index / CHUNK_SIZE will give us the internal array index
    // CHUNK_SIZE - index % CHUNK_SIZE - 1 will give us the bit index 0-based from right to left 
    size_t loc = index / CHUNK_SIZE;
    size_t bitLoc = CHUNK_SIZE - index % CHUNK_SIZE - 1;

    // Set the bit new value in the internal array
    uint8_t temp;
    if (val)
    {
        // If the val that will be set is 1 (true) then the setting will be as following
        // For example we want to set third bit from the right to 1 and the internal array bits in this location is as following 10110010
        // The first step, we will start with 00000001 then make left binary shift by bit location index which will be in this case 2 so it will be 00000100 and store it in temp
        // The second step, we will make OR binary operation between bits in this location and temp so it will be 10110010 | 00000100 and the new bits in this location will be 10110110
        temp = 1 << bitLoc;
        arr[loc] = arr[loc] | temp;
        
    }
    else
    {
        // If the val that will be set is 0 (false) then the setting will be as following
        // For example we want to set fifth bit from the right to 0 and the internal array bits in this location is as following 10110010
        // The first step, we will start with 00000001 then make left binary shift by CHUNK_SIZE which will be 8 so it will be 100000000 and then subtract 1 so it will be 11111111
        // And then, make XOR operation between 11111111 and 00000001 left shifted by bit location index which will be in this case 4 so it will be 00010000 and then make the XOR operation of 11111111 ^ 00010000 so the result will be 11101111 which is stored in temp
        // The second step, we will make AND binary operation between bits in this location and temp so it will be 10110010 & 11101111 and the new bits in this location will be 10100110
        temp = ((1 << CHUNK_SIZE) - 1) ^ (1 << bitLoc);
        arr[loc] = arr[loc] & temp;
    }
}

/**
 * @brief Overloaded [] operator for BooleanArray
 * @param index index of the boolean item to get
 * @return the boolean value in the requested index
*/
bool BooleanArray::operator[](size_t index)
{
    // Check if the index within the range and if not it throws an error 
    if (index < 0 || index >= MAX_SIZE)
    {
        throw std::invalid_argument("Index out of the range");
    }

    // Calculate the internal index and the bit location
    // index / CHUNK_SIZE will give us the internal array index
    // CHUNK_SIZE - index % CHUNK_SIZE - 1 will give us the bit index 0-based from right to left 
    size_t loc = index / CHUNK_SIZE;
    size_t bitLoc = CHUNK_SIZE - index % CHUNK_SIZE - 1;

    // Get the bit from internal array and return its value
    // For example we want to get the boolean value of the fifth bit from the right and the internal array bits in this location is as following 10110010
    // The first step, we will start with 00000001 then make left binary shift by bit location index which will be in this case 4 so it will be 00010000 and store it in temp
    // The second step, we will return the result of the AND binary operation between bits in this location and temp so it will be 10110010 & 00010000 so the result returned will be 00010000 which is true
    uint8_t temp = (1 << bitLoc);
    return static_cast<bool>(arr[loc] & temp);
}