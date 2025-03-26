#pragma once

#ifndef RFIDWrite_h
#define RFIDWrite_h

#include <Arduino.h>
#include <MFRC522v2.h>
#include <MFRC522DriverSPI.h>
#include <MFRC522DriverPinSimple.h>
#include <MFRC522Debug.h>

byte *stringToHex(String string);

bool write(byte block, byte *buffer, byte size);

bool writeToDataBlock(byte block, String data);

#endif