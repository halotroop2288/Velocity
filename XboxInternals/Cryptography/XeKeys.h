#ifndef XEKEYS_H
#define XEKEYS_H

#include "winnames.h"
#include "XeCrypt.h"

#include <botan/botan.h>
#include <botan/pubkey.h>
#include <botan/rsa.h>
#include <botan/emsa.h>
#include <botan/sha160.h>
#include <botan/emsa3.h>
#include <botan/look_pk.h>

#include <iostream>

#include "XboxInternals_global.h"

enum XeKeysRsaKeys
{
    PIRSKey = 0,
    LIVEKey = 1,
    DeviceKey = 2,
    UnknownKey = 3
};

BYTE Pirs1N[0x80] =
{
    0xC9, 0x1C, 0x35, 0x77, 0xC8, 0xBF, 0xA0, 0x6B, 0x64, 0x2F, 0x4E, 0x6C,
    0x73, 0x99, 0xAC, 0xE5, 0x84, 0xE7, 0xAB, 0x2E, 0xE4, 0xDB, 0xAE, 0x1E,
    0x3E, 0x06, 0x70, 0x62, 0x4A, 0xA2, 0xAD, 0x99, 0xE1, 0x76, 0x70, 0x61,
    0xE6, 0xBE, 0x93, 0x27, 0x6D, 0x5D, 0x97, 0xFD, 0x73, 0x30, 0x76, 0x3A,
    0xB8, 0x70, 0x5C, 0xC0, 0xBE, 0x8F, 0x1B, 0x3D, 0x4C, 0x5D, 0x85, 0x65,
    0x98, 0x8C, 0x4C, 0x6B, 0xCC, 0xBE, 0xD0, 0xC5, 0xA7, 0x43, 0xAA, 0x6C,
    0x56, 0x91, 0x0F, 0xF8, 0xE8, 0xBD, 0x90, 0x4D, 0xB8, 0xD9, 0xA3, 0xF1,
    0x3B, 0x6E, 0x71, 0xDB, 0xB0, 0xE0, 0xF5, 0x1A, 0x8E, 0x80, 0x39, 0xC2,
    0x4E, 0x3A, 0x81, 0x42, 0xC5, 0x6E, 0xB9, 0x49, 0x44, 0xF4, 0x8D, 0xC5,
    0x84, 0x51, 0xC8, 0x1B, 0x7D, 0xBC, 0x45, 0x59, 0xD0, 0xE3, 0xF2, 0x97,
    0xEF, 0xA0, 0x39, 0xEA, 0x1C, 0xF9, 0x48, 0x66
};
BYTE Live1N[0x80] =
{
    0xF2, 0xE5, 0x3E, 0x3F, 0x03, 0x75, 0xC2, 0xB3, 0x20, 0xB6, 0xAB, 0x41,
    0x90, 0x78, 0x9D, 0xA1, 0x04, 0x4E, 0x58, 0x6D, 0xFC, 0xFF, 0x16, 0x1C,
    0x9E, 0x01, 0x1D, 0xDA, 0x5D, 0x16, 0x7E, 0x54, 0xCB, 0x2A, 0xF2, 0xA7,
    0x02, 0x83, 0xE8, 0xAD, 0xCD, 0xA1, 0x00, 0xF8, 0x9C, 0xC4, 0xAD, 0x2D,
    0x4C, 0xAF, 0x2E, 0x18, 0x01, 0x9F, 0x38, 0xB1, 0x3D, 0xFA, 0xC9, 0xA6,
    0xCF, 0x2A, 0xA8, 0x4E, 0xE0, 0x7E, 0x17, 0x23, 0x61, 0xFB, 0xFD, 0x36,
    0x2E, 0x22, 0x17, 0xFA, 0x75, 0x71, 0xA0, 0x74, 0xF9, 0xF7, 0x10, 0x85,
    0x7E, 0xEC, 0x5C, 0x35, 0xF5, 0xB0, 0xAC, 0xAB, 0xC1, 0x0B, 0x09, 0x1D,
    0x9A, 0x7A, 0xBE, 0xB9, 0xB7, 0x91, 0x78, 0x0A, 0x5D, 0xCA, 0xCB, 0xF9,
    0x98, 0x4B, 0x68, 0x15, 0x75, 0x77, 0x1C, 0xB0, 0xCC, 0xFA, 0x04, 0xA3,
    0xEC, 0x08, 0xDD, 0x68, 0x5F, 0xEA, 0x69, 0xAF
};
BYTE Device1N[0x80] =
{
    0xF4, 0x30, 0xE3, 0x52, 0x4D, 0x53, 0x1C, 0xA1, 0x82, 0xAB, 0x58, 0x9D,
    0x83, 0x1E, 0xD8, 0xF7, 0x18, 0x9A, 0x4E, 0x07, 0x72, 0xCE, 0xDF, 0x24,
    0xDC, 0x6E, 0x0D, 0x6F, 0x8E, 0x52, 0x76, 0x35, 0xC6, 0xD0, 0x60, 0xBE,
    0x8E, 0xB5, 0x55, 0x90, 0xBC, 0x93, 0xC0, 0xA8, 0x92, 0xAB, 0xFD, 0xC8,
    0x24, 0x0E, 0x8F, 0xF1, 0xC0, 0x1B, 0xA4, 0xE2, 0xD5, 0x36, 0x21, 0xB7,
    0xC8, 0x5B, 0x01, 0x5E, 0xDB, 0x8C, 0xEC, 0x34, 0x5B, 0x28, 0xEA, 0x20,
    0xFA, 0x12, 0xB9, 0xD6, 0x95, 0xE7, 0x1E, 0x4B, 0xD7, 0x13, 0xCB, 0x12,
    0xA7, 0xB4, 0x59, 0xD0, 0xD9, 0x90, 0xCC, 0xAC, 0x83, 0x33, 0xE1, 0x21,
    0x84, 0x2A, 0x5A, 0x8D, 0x15, 0x14, 0xF4, 0xC3, 0xAE, 0x29, 0x7F, 0xAC,
    0x16, 0xC4, 0x68, 0x66, 0x7E, 0x3F, 0x72, 0x7B, 0x7C, 0x04, 0xFE, 0x28,
    0x57, 0x67, 0xC4, 0xEA, 0x8D, 0xC2, 0xFA, 0x64
};
BYTE Unknown1N[0x80] =
{
    0x7E, 0x17, 0xD7, 0x46, 0xE2, 0x47, 0x38, 0xDB, 0xC5, 0xA0, 0xCF, 0x1C,
    0xFE, 0x10, 0x73, 0x1F, 0x72, 0x49, 0x2E, 0xEC, 0x08, 0x26, 0xBE, 0x96,
    0x6B, 0x85, 0xEC, 0xBE, 0xEC, 0xD5, 0xE6, 0xDD, 0xB4, 0x45, 0x5E, 0x98,
    0x75, 0x65, 0x1F, 0xA3, 0xFA, 0x7F, 0x65, 0xBD, 0xC7, 0xC8, 0xA1, 0x3D,
    0x72, 0x89, 0x57, 0x02, 0x30, 0xEC, 0x2A, 0x2C, 0x78, 0x7F, 0x9E, 0xE4,
    0x65, 0xF8, 0x7B, 0x1F, 0x35, 0x26, 0x59, 0xE0, 0xAA, 0x44, 0x54, 0x1C,
    0x73, 0x0E, 0xCA, 0xB0, 0xD2, 0x92, 0xF6, 0x2F, 0xBE, 0x1D, 0xCC, 0x56,
    0x96, 0xBE, 0x66, 0xF0, 0x21, 0xF2, 0xF9, 0xC2, 0x1C, 0xCE, 0xF9, 0x93,
    0x38, 0x7E, 0x6A, 0x95, 0x61, 0xEF, 0x5F, 0xE3, 0x4F, 0x30, 0x86, 0xF6,
    0x17, 0x9E, 0xC1, 0x83, 0xF4, 0x0D, 0xEF, 0xDB, 0x70, 0x09, 0x33, 0x6D,
    0x12, 0x3C, 0xE3, 0x2F, 0x9C, 0x48, 0x9F, 0x27
};

class XBOXINTERNALSSHARED_EXPORT XeKeys
{
public:
    static bool VerifyRSASignature(XeKeysRsaKeys key, BYTE *hash, BYTE *signature);
};

#endif
