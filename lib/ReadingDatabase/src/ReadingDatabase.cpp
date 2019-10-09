// Implementation for ReadingDatabase
#include "ReadingDatabase.h"

// Public Constructor
ReadingDatabase::ReadingDatabase(int size)
{
    // Set database size and length
    this->size = size;
    lastIndex = -1;

    // Allocate SensorEvent array
    database = new SensorEvent[size];
}

// Add a SensorEvent to the database
bool ReadingDatabase::add(const SensorEvent event)
{
    if (isFull())
        return false;
    database[++lastIndex] = event;
    return true;
}

bool ReadingDatabase::contains(int idNumber)
{
    // Search array for idNumber
    for (int i = 0; i <= lastIndex; ++i)
    {
        // Return true on a match
        if (database[i].idNumber == idNumber)
        {
            return true;
        }
    }

    // If a match wasn't found, return false
    return false;
}

// Return a constant pointer to the SensorEvent with the idNumber, or nullptr
SensorEvent *ReadingDatabase::get(int idNumber)
{
    // Search array for idNumber
    for (int i = 0; i <= lastIndex; ++i)
    {
        // Return the first match
        if (database[i].idNumber == idNumber)
        {
            return &database[i];
        }
    }

    // If a match wasn't found, return nullptr
    return nullptr;
}

// Remove an entry from the array
bool ReadingDatabase::remove(int idNumber)
{
    // Search array for idNumber
    for (int i = 0; i <= lastIndex; ++i)
    {
        // If the entry is found
        if (database[i].idNumber == idNumber)
        {

            // Overwrite the index with the last entry, and decrease last index, return true for succcess
            database[i] = database[lastIndex];
            lastIndex -= 1;
            return true;
        }
    }

    // Return false for failure
    return false;
}