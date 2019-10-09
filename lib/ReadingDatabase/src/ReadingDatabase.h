// Definitions for ReadingDatabase
#pragma once

struct SensorEvent
{
    int idNumber;
    int data1;
    int data2;
};

class ReadingDatabase
{

private:
    // Pointer to internal SensorEvent array
    SensorEvent *database;

    // Size of the internal SensorEvent array
    int size;

    // Last valid index
    int lastIndex;

    // Arbitrary maximum array size
    const int MAX_ARRAY_SIZE = 500;

public:
    ReadingDatabase(int size);

    bool add(const SensorEvent event);

    bool contains(int idNumber);

    SensorEvent *get(int idNumber);

    bool remove(int idNumber);

    bool isEmpty() { return lastIndex == -1; }
    bool isFull() { return lastIndex == size - 1; }

    int length() { return lastIndex + 1; }

    int capacity() {return size;}

    void clear() { lastIndex = -1; }
};