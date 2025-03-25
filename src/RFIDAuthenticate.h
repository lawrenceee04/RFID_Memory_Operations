#pragma once

#ifndef RFIDAuthenticate_h
#define RFIDAuthenticate_h

#include <Arduino.h>
#include <MFRC522v2.h>
#include <MFRC522DriverSPI.h>
#include <MFRC522DriverPinSimple.h>
#include <MFRC522Debug.h>

bool authenticate(bool authenticateKeyAOrKeyB, byte *key, byte sectorTrailer);

#endif
