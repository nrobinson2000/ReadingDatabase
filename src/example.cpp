/*
 * Project ReadingDatabase
 * Description:
 * Author: Nathan Robinson
 * Date:
 */

#include "Particle.h"

#include "ReadingDatabase.h"

SYSTEM_MODE(MANUAL);

// Create a database that can store 100 entries
ReadingDatabase myDatabase(100);

void setup()
{

  Serial.begin(115200);

  delay(3000);

  Serial.println("Testing:");

  SensorEvent event1 = {123456, 10, 20};

  bool ret = myDatabase.add(event1);

  Serial.printlnf("Add to database: %s", ret ? "SUCCESS" : "FAILED");

  ret = myDatabase.contains(123456);

  Serial.printlnf("Contains?: %s", ret ? "SUCCESS" : "FAILED");

  SensorEvent *retrievedEvent = myDatabase.get(123456);

  if (retrievedEvent != nullptr)
  {
    Serial.printlnf("%d, %d, %d", retrievedEvent->idNumber, retrievedEvent->data1, retrievedEvent->data2);
  }

  Serial.printlnf("length: %d", myDatabase.length());

  myDatabase.clear();

  Serial.printlnf("length: %d", myDatabase.length());

  ret = myDatabase.contains(123456);

  Serial.printlnf("Contains?: %s", ret ? "SUCCESS" : "FAILED");

  uint32_t start = micros();

  // Stress test add
  for (int i = 1; i <= myDatabase.capacity(); ++i)
  {
    SensorEvent event;
    event.idNumber = i * 100;
    event.data1 = i * 10;
    event.data2 = i * 20;

    if (!myDatabase.add(event))
    {
      Serial.printlnf("Failed for i = %d", i);
    }
  }

  uint32_t end = micros();

  Serial.printlnf("add test: %u micros", end - start);

  // Stress test get

  start = micros();
  for (int i = 1; i <= myDatabase.capacity(); ++i)
  {
    SensorEvent *event = myDatabase.get(i * 100);

    if (event == nullptr)
    {
      Serial.printlnf("Failed for i = %d", i);
    }
  }
  end = micros();

  Serial.printlnf("get test: %u micros", end - start);

// Get and print
  for (int i = 1; i <= myDatabase.capacity(); ++i)
  {
    SensorEvent *event = myDatabase.get(i * 100);

    if (event == nullptr)
    {
      Serial.printlnf("Failed for i = %d", i);
    }
    else {
      Serial.printlnf("%d, %d, %d", event->idNumber, event->data1, event->data2);
    }
  }


}

void loop()
{
}