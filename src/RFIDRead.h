#ifndef RFIDRead_h
#define RFIDRead_h

#include <Arduino.h>
#include <MFRC522v2.h>
#include <MFRC522DriverSPI.h>
#include <MFRC522DriverPinSimple.h>
#include <MFRC522Debug.h>

extern MFRC522 mfrc522;

bool read(byte block, byte *buffer, byte size);

#endif