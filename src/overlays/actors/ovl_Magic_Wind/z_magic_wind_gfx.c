#include "global.h"

static Vtx sCylinderVtx[] = {
    VTX(0, 0, -6000, 1024, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-4243, 12800, -4243, 1280, 0, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(0, 12800, -6000, 1024, 0, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(-4243, 0, -4243, 1280, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 0, 6000, 0, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(4243, 12800, 4243, 256, 0, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(0, 12800, 6000, 0, 0, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(4243, 0, 4243, 256, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-6000, 12800, 0, 1536, 0, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(-6000, 0, 0, 1536, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(4243, 0, -4243, 768, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(4243, 12800, -4243, 768, 0, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(-4243, 12800, 4243, 1792, 0, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(-4243, 0, 4243, 1792, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(6000, 12800, 0, 512, 0, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(6000, 0, 0, 512, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 12800, 6000, 2048, 0, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(0, 0, 6000, 2048, 2048, 0xFF, 0xFF, 0xFF, 0xFF),

    // 2nd Set
    VTX(0, 0, -6000, 1024, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-4243, 12800, -4243, 1280, 0, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(0, 12800, -6000, 1024, 0, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(-4243, 0, -4243, 1280, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 0, 6000, 0, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(4243, 12800, 4243, 256, 0, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(0, 12800, 6000, 0, 0, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(4243, 0, 4243, 256, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(-6000, 12800, 0, 1536, 0, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(-6000, 0, 0, 1536, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(4243, 0, -4243, 768, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(4243, 12800, -4243, 768, 0, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(-4243, 12800, 4243, 1792, 0, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(-4243, 0, 4243, 1792, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(6000, 12800, 0, 512, 0, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(6000, 0, 0, 512, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
    VTX(0, 12800, 6000, 2048, 0, 0xFF, 0xFF, 0xFF, 0x00),
    VTX(0, 0, 6000, 2048, 2048, 0xFF, 0xFF, 0xFF, 0xFF),
};

static char sWindEffTexture[] = {
    0x06, 0x19, 0x28, 0x43, 0x66, 0x82, 0xA0, 0xAE, 0xA3, 0x93, 0x76, 0x56, 0x32, 0x12, 0x00, 0x00, 0x03, 0x15, 0x25,
    0x39, 0x57, 0x81, 0xAD, 0xBC, 0xA4, 0x7B, 0x5D, 0x45, 0x33, 0x20, 0x24, 0x38, 0x33, 0x1F, 0x26, 0x4F, 0x71, 0x8C,
    0xB2, 0xC9, 0xC7, 0xAE, 0x87, 0x57, 0x33, 0x24, 0x11, 0x00, 0x00, 0x05, 0x1C, 0x3B, 0x5E, 0x7D, 0x90, 0x93, 0x85,
    0x76, 0x78, 0x81, 0x70, 0x3E, 0x14, 0x01, 0x16, 0x27, 0x33, 0x4F, 0x6C, 0x84, 0x96, 0x9A, 0x9B, 0x8C, 0x70, 0x4F,
    0x27, 0x09, 0x00, 0x00, 0x05, 0x15, 0x29, 0x43, 0x68, 0x96, 0xB9, 0xB7, 0x99, 0x6E, 0x4C, 0x34, 0x2A, 0x20, 0x26,
    0x31, 0x2B, 0x20, 0x2F, 0x4D, 0x66, 0x8F, 0xB5, 0xC0, 0xB4, 0x97, 0x6B, 0x46, 0x31, 0x1E, 0x07, 0x00, 0x00, 0x0C,
    0x27, 0x4C, 0x6B, 0x8C, 0x9E, 0x9A, 0x8B, 0x7A, 0x7A, 0x7C, 0x66, 0x42, 0x1E, 0x0B, 0x27, 0x30, 0x3E, 0x61, 0x7C,
    0x8F, 0x97, 0xA0, 0xA2, 0x87, 0x6F, 0x51, 0x2A, 0x0C, 0x00, 0x00, 0x09, 0x1D, 0x35, 0x59, 0x83, 0xAC, 0xC0, 0xB5,
    0x8E, 0x5E, 0x3E, 0x2E, 0x28, 0x25, 0x24, 0x27, 0x26, 0x28, 0x39, 0x4D, 0x6C, 0xA0, 0xB8, 0xB3, 0xA0, 0x7A, 0x58,
    0x40, 0x2E, 0x13, 0x00, 0x00, 0x06, 0x1B, 0x3B, 0x5D, 0x84, 0xA9, 0xB2, 0xAD, 0x99, 0x8B, 0x8F, 0x87, 0x67, 0x43,
    0x25, 0x1C, 0x2D, 0x3A, 0x4F, 0x73, 0x8D, 0x9D, 0xA8, 0xAB, 0x9F, 0x85, 0x72, 0x5B, 0x36, 0x16, 0x03, 0x00, 0x11,
    0x29, 0x48, 0x72, 0xA0, 0xC6, 0xC7, 0xAC, 0x80, 0x52, 0x36, 0x28, 0x27, 0x23, 0x1B, 0x1E, 0x24, 0x2E, 0x3A, 0x50,
    0x7B, 0xA6, 0xB3, 0xA6, 0x8F, 0x68, 0x4D, 0x39, 0x24, 0x08, 0x00, 0x00, 0x11, 0x2D, 0x4F, 0x73, 0xA2, 0xC1, 0xC8,
    0xBD, 0xAF, 0xB2, 0xB4, 0x95, 0x65, 0x40, 0x2B, 0x25, 0x30, 0x48, 0x5E, 0x7D, 0x96, 0xA9, 0xB4, 0xAC, 0x9B, 0x8A,
    0x79, 0x60, 0x3A, 0x1B, 0x0B, 0x0A, 0x1A, 0x35, 0x5C, 0x8B, 0xBC, 0xD6, 0xC9, 0xA0, 0x73, 0x4D, 0x2F, 0x1E, 0x20,
    0x1D, 0x11, 0x19, 0x28, 0x31, 0x38, 0x53, 0x83, 0xA2, 0xA9, 0x9D, 0x81, 0x5B, 0x42, 0x30, 0x1D, 0x02, 0x00, 0x06,
    0x1D, 0x3C, 0x61, 0x8D, 0xBA, 0xD8, 0xDB, 0xC7, 0xC7, 0xCE, 0xC1, 0x8C, 0x5C, 0x44, 0x35, 0x27, 0x3A, 0x58, 0x6C,
    0x84, 0x9B, 0xAF, 0xB4, 0xAE, 0xA3, 0x91, 0x78, 0x52, 0x2E, 0x17, 0x11, 0x14, 0x26, 0x48, 0x72, 0xA4, 0xD4, 0xDF,
    0xC7, 0x99, 0x72, 0x53, 0x32, 0x1C, 0x1F, 0x1B, 0x19, 0x2A, 0x39, 0x3C, 0x46, 0x63, 0x8A, 0xA0, 0xA3, 0x96, 0x73,
    0x51, 0x3D, 0x30, 0x1C, 0x02, 0x00, 0x10, 0x2A, 0x4D, 0x79, 0xA6, 0xD5, 0xEF, 0xE6, 0xD5, 0xD0, 0xC8, 0xAB, 0x77,
    0x57, 0x4F, 0x3F, 0x2E, 0x44, 0x63, 0x77, 0x87, 0x9F, 0xAD, 0xB3, 0xB7, 0xAF, 0x90, 0x64, 0x39, 0x1C, 0x11, 0x14,
    0x1F, 0x38, 0x5C, 0x8A, 0xBF, 0xE8, 0xE7, 0xC6, 0x9E, 0x7F, 0x64, 0x48, 0x31, 0x2B, 0x31, 0x3F, 0x4C, 0x4E, 0x53,
    0x66, 0x80, 0x96, 0xA4, 0xA3, 0x8E, 0x66, 0x4F, 0x47, 0x3B, 0x1F, 0x06, 0x06, 0x1C, 0x3A, 0x63, 0x93, 0xC2, 0xEF,
    0xFC, 0xED, 0xDD, 0xC2, 0xA4, 0x85, 0x64, 0x5A, 0x5A, 0x43, 0x38, 0x48, 0x66, 0x7A, 0x8A, 0xA0, 0xAA, 0xB2, 0xBC,
    0xAB, 0x78, 0x45, 0x21, 0x10, 0x0D, 0x19, 0x2F, 0x4D, 0x72, 0xA3, 0xD7, 0xF7, 0xED, 0xCC, 0xAE, 0x94, 0x7F, 0x69,
    0x53, 0x52, 0x63, 0x65, 0x5E, 0x5C, 0x69, 0x80, 0x97, 0xA4, 0xAA, 0xA1, 0x80, 0x60, 0x5B, 0x5E, 0x4C, 0x27, 0x0D,
    0x12, 0x2B, 0x4E, 0x7B, 0xAB, 0xDE, 0xFF, 0xFD, 0xEC, 0xD2, 0xA5, 0x7A, 0x69, 0x62, 0x66, 0x61, 0x45, 0x40, 0x4D,
    0x62, 0x79, 0x8D, 0xA3, 0xAB, 0xB3, 0xB0, 0x89, 0x52, 0x28, 0x12, 0x0A, 0x10, 0x25, 0x43, 0x63, 0x8C, 0xBE, 0xEA,
    0xFF, 0xF7, 0xDE, 0xC4, 0xB0, 0x9F, 0x8B, 0x7C, 0x8B, 0x89, 0x6F, 0x62, 0x66, 0x77, 0x8C, 0xA3, 0xB2, 0xAF, 0x99,
    0x73, 0x67, 0x73, 0x72, 0x58, 0x33, 0x1C, 0x23, 0x3D, 0x65, 0x91, 0xC4, 0xF2, 0xFF, 0xF5, 0xDD, 0xBA, 0x8A, 0x66,
    0x6E, 0x79, 0x79, 0x66, 0x4A, 0x47, 0x57, 0x65, 0x7D, 0x95, 0xAA, 0xB5, 0xB3, 0x94, 0x5C, 0x2E, 0x16, 0x0B, 0x0B,
    0x1B, 0x39, 0x59, 0x7D, 0xA6, 0xD5, 0xF9, 0xFF, 0xFF, 0xF5, 0xE0, 0xCC, 0xB8, 0xAC, 0xAB, 0xA9, 0x8D, 0x6F, 0x66,
    0x71, 0x86, 0x9D, 0xAE, 0xBC, 0xAE, 0x8E, 0x76, 0x80, 0x8A, 0x7C, 0x60, 0x44, 0x33, 0x38, 0x52, 0x7B, 0xAA, 0xDD,
    0xFE, 0xFF, 0xE7, 0xC9, 0xA4, 0x7F, 0x76, 0x90, 0x9B, 0x86, 0x6B, 0x52, 0x50, 0x63, 0x76, 0x8B, 0xA1, 0xB9, 0xC0,
    0xAA, 0x75, 0x3A, 0x19, 0x12, 0x12, 0x19, 0x2E, 0x50, 0x75, 0x9B, 0xC1, 0xE7, 0xFF, 0xFF, 0xFF, 0xFF, 0xF5, 0xDF,
    0xCC, 0xC7, 0xB6, 0x9A, 0x7D, 0x67, 0x69, 0x85, 0xA0, 0xB0, 0xC0, 0xC1, 0xA8, 0x8C, 0x87, 0x99, 0x96, 0x7B, 0x65,
    0x5B, 0x52, 0x52, 0x6B, 0x90, 0xC2, 0xEC, 0xFF, 0xFB, 0xDD, 0xBD, 0xA1, 0x90, 0x9B, 0xB2, 0xA9, 0x82, 0x68, 0x61,
    0x5E, 0x6B, 0x81, 0x9E, 0xB4, 0xCA, 0xC4, 0x9D, 0x5C, 0x28, 0x15, 0x1C, 0x27, 0x30, 0x47, 0x6E, 0x96, 0xB8, 0xD7,
    0xF2, 0xFB, 0xF9, 0xFA, 0xFF, 0xF9, 0xE7, 0xD6, 0xBF, 0x9E, 0x7F, 0x67, 0x5D, 0x75, 0xA1, 0xB0, 0xBE, 0xCC, 0xC0,
    0xA3, 0x94, 0x9B, 0xA8, 0x96, 0x78, 0x70, 0x78, 0x73, 0x71, 0x80, 0xA6, 0xD6, 0xF1, 0xF6, 0xF2, 0xDD, 0xC4, 0xB7,
    0xB4, 0xBD, 0xB9, 0xA0, 0x79, 0x6D, 0x6F, 0x6B, 0x6D, 0x87, 0xAC, 0xCA, 0xD5, 0xC0, 0x8E, 0x4F, 0x28, 0x23, 0x31,
    0x3F, 0x4C, 0x69, 0x93, 0xB5, 0xCE, 0xE3, 0xED, 0xEA, 0xE5, 0xE6, 0xEC, 0xF1, 0xE5, 0xCD, 0xAA, 0x8A, 0x6F, 0x5E,
    0x67, 0x8D, 0xB2, 0xB7, 0xC8, 0xD1, 0xBF, 0xA4, 0x99, 0xA1, 0xA4, 0x8E, 0x7D, 0x86, 0x95, 0x8F, 0x87, 0x94, 0xBD,
    0xDF, 0xE6, 0xE7, 0xE9, 0xE1, 0xDD, 0xD6, 0xD0, 0xC8, 0xAC, 0x98, 0x7B, 0x76, 0x75, 0x69, 0x6E, 0x8E, 0xB7, 0xDD,
    0xDB, 0xB9, 0x84, 0x54, 0x39, 0x39, 0x45, 0x53, 0x68, 0x8D, 0xB6, 0xCB, 0xD6, 0xDF, 0xDE, 0xD7, 0xD3, 0xD4, 0xDE,
    0xE2, 0xD7, 0xBD, 0x9F, 0x80, 0x69, 0x6C, 0x87, 0xA3, 0xBA, 0xC4, 0xD4, 0xD6, 0xC2, 0xA9, 0x96, 0x93, 0x90, 0x87,
    0x8D, 0x9E, 0xAA, 0xA0, 0x96, 0xA6, 0xC9, 0xD8, 0xD1, 0xD2, 0xDC, 0xE5, 0xE9, 0xE1, 0xD4, 0xBD, 0xA0, 0x94, 0x82,
    0x77, 0x67, 0x5E, 0x71, 0x95, 0xC7, 0xEB, 0xDC, 0xB0, 0x87, 0x69, 0x54, 0x4E, 0x51, 0x63, 0x84, 0xAE, 0xD0, 0xD1,
    0xD0, 0xD3, 0xCE, 0xC9, 0xC7, 0xC7, 0xCE, 0xD0, 0xC7, 0xAF, 0x96, 0x79, 0x6F, 0x82, 0x9F, 0xB5, 0xC7, 0xD7, 0xE3,
    0xDD, 0xC8, 0xA9, 0x87, 0x76, 0x77, 0x89, 0x9F, 0xB0, 0xB4, 0xA5, 0xA0, 0xB2, 0xC7, 0xC8, 0xB8, 0xBC, 0xCA, 0xD8,
    0xDB, 0xD8, 0xC8, 0xAC, 0x97, 0x86, 0x76, 0x62, 0x51, 0x59, 0x73, 0xA1, 0xDF, 0xF7, 0xD3, 0xA8, 0x95, 0x86, 0x73,
    0x5C, 0x59, 0x71, 0x9F, 0xC8, 0xD3, 0xCA, 0xC9, 0xCA, 0xC2, 0xBA, 0xB8, 0xB7, 0xBA, 0xBF, 0xB7, 0xA3, 0x90, 0x76,
    0x7B, 0x94, 0xAA, 0xC3, 0xD3, 0xE1, 0xF0, 0xE2, 0xC6, 0xA2, 0x73, 0x58, 0x65, 0x8C, 0xAB, 0xB7, 0xB3, 0xA5, 0xA9,
    0xB4, 0xBC, 0xAF, 0xA0, 0xA4, 0xB3, 0xC1, 0xD0, 0xD1, 0xB7, 0x99, 0x85, 0x70, 0x53, 0x40, 0x47, 0x5A, 0x7B, 0xB8,
    0xF6, 0xF6, 0xC8, 0xA3, 0xA0, 0x9F, 0x85, 0x65, 0x63, 0x85, 0xB6, 0xCE, 0xCB, 0xC9, 0xCC, 0xC4, 0xB0, 0xA2, 0xA1,
    0xA4, 0xAA, 0xB2, 0xAD, 0x9D, 0x8E, 0x79, 0x89, 0xA5, 0xBC, 0xCB, 0xCE, 0xDE, 0xF2, 0xDE, 0xBD, 0x96, 0x61, 0x46,
    0x60, 0x8D, 0xAE, 0xB3, 0xAE, 0xAB, 0xB4, 0xB5, 0xAA, 0x90, 0x86, 0x8D, 0xA0, 0xBA, 0xD2, 0xCA, 0xA4, 0x82, 0x70,
    0x5B, 0x36, 0x30, 0x46, 0x5C, 0x8D, 0xD2, 0xFC, 0xEC, 0xC4, 0xA8, 0xA5, 0xA4, 0x8B, 0x71, 0x75, 0x9E, 0xC1, 0xCC,
    0xCA, 0xCD, 0xCD, 0xB6, 0x91, 0x80, 0x85, 0x93, 0xA0, 0xAB, 0xAA, 0x9A, 0x90, 0x85, 0x97, 0xB7, 0xC6, 0xBD, 0xB9,
    0xD6, 0xEB, 0xD8, 0xB4, 0x86, 0x5A, 0x45, 0x62, 0x8D, 0xA6, 0xAB, 0xB2, 0xB9, 0xBF, 0xB3, 0x8E, 0x72, 0x6E, 0x7D,
    0xA2, 0xCA, 0xD0, 0xB5, 0x8E, 0x70, 0x65, 0x50, 0x38, 0x34, 0x43, 0x5D, 0xA0, 0xE0, 0xF4, 0xE6, 0xCA, 0xAE, 0xA3,
    0x9A, 0x8D, 0x83, 0x90, 0xB2, 0xC9, 0xCC, 0xCC, 0xCD, 0xBF, 0x98, 0x6B, 0x5D, 0x6F, 0x85, 0xA1, 0xB2, 0xAC, 0x9B,
    0x95, 0x8F, 0x9F, 0xAE, 0xA5, 0x97, 0xA5, 0xCE, 0xE5, 0xD4, 0xAC, 0x83, 0x63, 0x56, 0x6B, 0x8C, 0x9E, 0xAC, 0xBF,
    0xCA, 0xC3, 0x9F, 0x70, 0x5A, 0x62, 0x86, 0xBF, 0xD7, 0xBD, 0x9A, 0x80, 0x6D, 0x65, 0x54, 0x4C, 0x3F, 0x40, 0x63,
    0xAD, 0xDD, 0xEA, 0xE2, 0xCE, 0xAC, 0x9A, 0x93, 0x90, 0x9A, 0xAF, 0xC1, 0xCC, 0xC8, 0xC8, 0xBF, 0x9E, 0x70, 0x48,
    0x47, 0x63, 0x84, 0xB0, 0xB9, 0xAD, 0x9A, 0x91, 0x8E, 0x8D, 0x7D, 0x6F, 0x76, 0x99, 0xC4, 0xDE, 0xD4, 0xAF, 0x8D,
    0x73, 0x70, 0x7C, 0x91, 0xA2, 0xB7, 0xCB, 0xD0, 0xB0, 0x7F, 0x5A, 0x52, 0x6D, 0xAA, 0xDC, 0xCA, 0xA1, 0x8D, 0x7D,
    0x71, 0x6F, 0x68, 0x5C, 0x40, 0x42, 0x71, 0xB6, 0xD8, 0xE2, 0xDB, 0xC4, 0x9F, 0x95, 0x94, 0x98, 0xB3, 0xC9, 0xC9,
    0xC3, 0xBE, 0xB8, 0xA1, 0x76, 0x4D, 0x33, 0x3D, 0x66, 0x96, 0xC0, 0xB6, 0xA5, 0x97, 0x82, 0x77, 0x60, 0x42, 0x46,
    0x65, 0x91, 0xBD, 0xD5, 0xD9, 0xBD, 0x9E, 0x8D, 0x8B, 0x97, 0xA6, 0xB4, 0xC6, 0xCD, 0xBA, 0x90, 0x66, 0x52, 0x5D,
    0x8C, 0xCB, 0xD7, 0xAD, 0x93, 0x8A, 0x80, 0x76, 0x7B, 0x7B, 0x5B, 0x3C, 0x4A, 0x80, 0xC2, 0xDF, 0xD9, 0xC6, 0xA0,
    0x8E, 0x9A, 0x9E, 0xA4, 0xC7, 0xD4, 0xC2, 0xB7, 0xB0, 0xA2, 0x80, 0x52, 0x34, 0x2E, 0x47, 0x7F, 0xAB, 0xBF, 0xAC,
    0x94, 0x7C, 0x5E, 0x4E, 0x30, 0x1D, 0x35, 0x60, 0x8D, 0xB6, 0xCE, 0xDD, 0xCD, 0xB6, 0xA8, 0xA4, 0xB4, 0xC4, 0xCC,
    0xCD, 0xBC, 0x9A, 0x76, 0x5A, 0x57, 0x73, 0xA8, 0xCA, 0xBF, 0x9E, 0x8F, 0x89, 0x7D, 0x7B, 0x81, 0x71, 0x4A, 0x3B,
    0x58, 0x8D, 0xD0, 0xE1, 0xC9, 0x99, 0x72, 0x87, 0xA9, 0xB0, 0xB3, 0xD1, 0xD2, 0xB7, 0xAC, 0xA2, 0x8C, 0x65, 0x3B,
    0x29, 0x3C, 0x6C, 0x9B, 0xB4, 0xB0, 0x9B, 0x72, 0x4C, 0x38, 0x2A, 0x15, 0x11, 0x33, 0x5D, 0x8A, 0xB3, 0xC7, 0xDB,
    0xE2, 0xD0, 0xBE, 0xB6, 0xCE, 0xDE, 0xD8, 0xC3, 0xA2, 0x81, 0x65, 0x56, 0x5E, 0x85, 0xA5, 0xAD, 0xAE, 0x9B, 0x8D,
    0x86, 0x82, 0x7D, 0x70, 0x51, 0x36, 0x3B, 0x63, 0x99, 0xD0, 0xD1, 0xA1, 0x64, 0x58, 0x89, 0xB7, 0xBD, 0xBA, 0xD0,
    0xC9, 0xB0, 0xA2, 0x95, 0x79, 0x52, 0x2F, 0x2F, 0x5E, 0x91, 0xA5, 0xA9, 0x9A, 0x79, 0x4C, 0x2D, 0x25, 0x1C, 0x0F,
    0x12, 0x30, 0x59, 0x87, 0xAB, 0xBF, 0xDC, 0xF5, 0xE3, 0xC9, 0xC0, 0xE1, 0xE7, 0xD3, 0xB3, 0x8F, 0x71, 0x59, 0x4F,
    0x5E, 0x80, 0x8D, 0x95, 0xA3, 0x97, 0x86, 0x83, 0x85, 0x6F, 0x50, 0x39, 0x26, 0x3B, 0x6F, 0xA2, 0xB9, 0xA0, 0x67,
    0x46, 0x54, 0x8C, 0xB6, 0xB9, 0xC1, 0xD0, 0xBF, 0xA9, 0x99, 0x84, 0x63, 0x42, 0x30, 0x44, 0x79, 0x99, 0x9A, 0x93,
    0x80, 0x58, 0x38, 0x27, 0x23, 0x1A, 0x12, 0x16, 0x25, 0x52, 0x7B, 0x9B, 0xB8, 0xDB, 0xFE, 0xEB, 0xD0, 0xCA, 0xDF,
    0xD6, 0xC4, 0xA4, 0x82, 0x64, 0x4A, 0x42, 0x54, 0x6C, 0x77, 0x86, 0x96, 0x89, 0x79, 0x77, 0x75, 0x5B, 0x39, 0x28,
    0x20, 0x47, 0x7F, 0xA3, 0x8D, 0x5A, 0x3D, 0x45, 0x5C, 0x85, 0xA3, 0xB2, 0xCE, 0xD1, 0xB3, 0xA0, 0x8F, 0x71, 0x4E,
    0x3A, 0x3E, 0x56, 0x7A, 0x83, 0x7C, 0x78, 0x66, 0x4E, 0x3D, 0x2D, 0x20, 0x1A, 0x1C, 0x20, 0x23, 0x45, 0x67, 0x8A,
    0xAF, 0xD3, 0xF6, 0xE7, 0xD7, 0xCD, 0xC8, 0xBC, 0xAE, 0x99, 0x72, 0x56, 0x3A, 0x31, 0x45, 0x58, 0x6C, 0x7B, 0x82,
    0x75, 0x66, 0x62, 0x58, 0x4C, 0x35, 0x24, 0x2D, 0x5E, 0x8B, 0x9D, 0x60, 0x29, 0x2D, 0x4F, 0x5D, 0x70, 0x8D, 0xB5,
    0xDC, 0xC4, 0xA8, 0x9A, 0x83, 0x5D, 0x40, 0x42, 0x4C, 0x59, 0x65, 0x60, 0x5D, 0x60, 0x54, 0x50, 0x47, 0x32, 0x1C,
    0x1A, 0x2D, 0x3E, 0x34, 0x33, 0x51, 0x79, 0xA4, 0xC3, 0xE3, 0xE1, 0xD6, 0xC3, 0xAB, 0x9D, 0x97, 0x8B, 0x62, 0x44,
    0x27, 0x1F, 0x34, 0x49, 0x61, 0x6C, 0x6C, 0x64, 0x5C, 0x50, 0x44, 0x43, 0x43, 0x3A, 0x4A, 0x75, 0x90, 0x8E, 0x48,
    0x17, 0x28, 0x51, 0x50, 0x5A, 0x8C, 0xBC, 0xD3, 0xB3, 0xA0, 0x98, 0x77, 0x50, 0x46, 0x4F, 0x4E, 0x4F, 0x4C, 0x47,
    0x4C, 0x4F, 0x4D, 0x4D, 0x46, 0x32, 0x1B, 0x26, 0x50, 0x66, 0x4A, 0x2A, 0x42, 0x73, 0x9D, 0xB2, 0xD4, 0xD9, 0xCB,
    0xB2, 0x8C, 0x7F, 0x84, 0x7A, 0x52, 0x32, 0x1B, 0x10, 0x23, 0x3B, 0x4C, 0x53, 0x59, 0x5D, 0x5B, 0x48, 0x40, 0x4C,
    0x5D, 0x66, 0x6B, 0x81, 0x8D, 0x80, 0x42, 0x16, 0x24, 0x44, 0x3B, 0x58, 0x94, 0xB3, 0xC1, 0xAA, 0xA2, 0x94, 0x6F,
    0x54, 0x54, 0x56, 0x47, 0x3D, 0x3D, 0x3C, 0x43, 0x45, 0x47, 0x4A, 0x45, 0x36, 0x2D, 0x52, 0x7C, 0x79, 0x53, 0x29,
    0x3F, 0x73, 0x99, 0xAB, 0xC7, 0xCD, 0xBD, 0x98, 0x70, 0x6C, 0x73, 0x6B, 0x47, 0x27, 0x14, 0x08, 0x11, 0x28, 0x32,
    0x39, 0x4D, 0x5D, 0x5A, 0x4F, 0x51, 0x68, 0x8D, 0x8E, 0x80, 0x81, 0x85, 0x71, 0x38, 0x13, 0x1C, 0x2F, 0x33, 0x62,
    0x8F, 0xA6, 0xBD, 0xB0, 0xA8, 0x8C, 0x77, 0x64, 0x5E, 0x56, 0x3F, 0x2F, 0x2E, 0x31, 0x3F, 0x43, 0x45, 0x4D, 0x4E,
    0x50, 0x6B, 0x99, 0x9B, 0x7D, 0x5A, 0x2D, 0x3F, 0x71, 0x9B, 0xAB, 0xBC, 0xC0, 0xA3, 0x80, 0x5D, 0x5E, 0x63, 0x5C,
    0x44, 0x2A, 0x1C, 0x0B, 0x0B, 0x19, 0x21, 0x2D, 0x44, 0x60, 0x63, 0x67, 0x71, 0x97, 0xB4, 0x9D, 0x84, 0x79, 0x73,
    0x5B, 0x21, 0x10, 0x17, 0x24, 0x34, 0x62, 0x86, 0xA3, 0xC2, 0xBD, 0xA8, 0x8D, 0x86, 0x75, 0x6B, 0x58, 0x3C, 0x21,
    0x15, 0x24, 0x42, 0x4C, 0x4E, 0x57, 0x65, 0x8A, 0xC3, 0xCB, 0xAB, 0x84, 0x60, 0x31, 0x3E, 0x6E, 0x98, 0xAD, 0xB3,
    0xB2, 0x8C, 0x71, 0x50, 0x54, 0x5A, 0x58, 0x4D, 0x3E, 0x2F, 0x1E, 0x15, 0x15, 0x1E, 0x2F, 0x45, 0x62, 0x7A, 0x87,
    0xA0, 0xBD, 0xAA, 0x8D, 0x7B, 0x69, 0x52, 0x3C, 0x11, 0x15, 0x1E, 0x1E, 0x32, 0x5B, 0x82, 0xA4, 0xC8, 0xBE, 0xA5,
    0x97, 0x91, 0x83, 0x79, 0x5D, 0x3C, 0x1A, 0x0F, 0x25, 0x4C, 0x60, 0x61, 0x65, 0x8C, 0xCA, 0xF7, 0xDE, 0xB9, 0x8D,
    0x64, 0x36, 0x3B, 0x66, 0x90, 0xAA, 0xA8, 0x9F, 0x81, 0x62, 0x46, 0x50, 0x5A, 0x64, 0x61, 0x52, 0x42, 0x35, 0x25,
    0x19, 0x20, 0x38, 0x4F, 0x68, 0x8D, 0xAC, 0xC3, 0xAB, 0x77, 0x6B, 0x67, 0x4E, 0x30, 0x1D, 0x14, 0x23, 0x25, 0x17,
    0x32, 0x58, 0x7C, 0xA3, 0xC0, 0xB3, 0xA1, 0x9A, 0x97, 0x8D, 0x82, 0x60, 0x3C, 0x1E, 0x1E, 0x39, 0x5C, 0x7A, 0x76,
    0x82, 0xBA, 0xE5, 0xFF, 0xEB, 0xC2, 0x94, 0x68, 0x3D, 0x32, 0x5C, 0x82, 0x9E, 0x9B, 0x8C, 0x69, 0x48, 0x44, 0x56,
    0x6E, 0x81, 0x76, 0x63, 0x57, 0x4A, 0x2F, 0x1F, 0x2A, 0x44, 0x5B, 0x78, 0xA0, 0xC6, 0xAF, 0x72, 0x42, 0x42, 0x44,
    0x2E, 0x11, 0x0A, 0x21, 0x2A, 0x21, 0x13, 0x32, 0x53, 0x79, 0x9A, 0xB0, 0xA5, 0x96, 0x97, 0x9D, 0x91, 0x83, 0x5C,
    0x43, 0x33, 0x39, 0x4F, 0x73, 0x90, 0x90, 0xAC, 0xD3, 0xE6, 0xFF, 0xF4, 0xC4, 0x98, 0x6B, 0x40, 0x28, 0x4F, 0x6F,
    0x8E, 0x8B, 0x6C, 0x39, 0x30, 0x4E, 0x6C, 0x93, 0x9B, 0x87, 0x79, 0x6F, 0x56, 0x31, 0x26, 0x38, 0x51, 0x68, 0x87,
    0xB2, 0xB3, 0x7B, 0x47, 0x1F, 0x19, 0x1E, 0x0F, 0x00, 0x0F, 0x2A, 0x27, 0x16, 0x0B, 0x30, 0x51, 0x77, 0x8C, 0xA0,
    0x98, 0x8E, 0x96, 0xA2, 0x99, 0x7F, 0x5E, 0x54, 0x50, 0x51, 0x61, 0x8A, 0x9E, 0xAE, 0xC8, 0xD9, 0xF0, 0xFF, 0xF9,
    0xC7, 0x93, 0x67, 0x44, 0x1C, 0x3C, 0x60, 0x7F, 0x6E, 0x36, 0x14, 0x35, 0x67, 0x87, 0xA8, 0xA2, 0x9D, 0x96, 0x7A,
    0x4D, 0x2D, 0x2E, 0x45, 0x61, 0x76, 0x96, 0xAA, 0x87, 0x5D, 0x39, 0x12, 0x00, 0x03, 0x00, 0x0D, 0x21, 0x27, 0x19,
    0x08, 0x06, 0x2E, 0x52, 0x71, 0x80, 0x95, 0x91, 0x8F, 0x9A, 0xAA, 0xA0, 0x80, 0x6B, 0x6F, 0x6B, 0x65, 0x70, 0x97,
    0xAB, 0xC3, 0xD4, 0xE9, 0xFE, 0xFF, 0xFB, 0xC2, 0x89, 0x66, 0x44, 0x0D, 0x2B, 0x50, 0x64, 0x38, 0x0F, 0x1D, 0x58,
    0x84, 0x94, 0x9F, 0xA0, 0xB3, 0xA2, 0x69, 0x38, 0x29, 0x39, 0x58, 0x6F, 0x81, 0x9D, 0x95, 0x77, 0x5D, 0x3F, 0x17,
    0x00, 0x00, 0x11, 0x2D, 0x35, 0x17, 0x05, 0x01, 0x06, 0x2F, 0x52, 0x6B, 0x7A, 0x8F, 0x94, 0x99, 0xA4, 0xAF, 0xA3,
    0x8B, 0x80, 0x85, 0x7D, 0x75, 0x7F, 0xA5, 0xBA, 0xD1, 0xE5, 0xFC, 0xFF, 0xFF, 0xF6, 0xBA, 0x8C, 0x6C, 0x39, 0x06,
    0x1C, 0x3B, 0x33, 0x0C, 0x15, 0x42, 0x79, 0x91, 0x8C, 0x95, 0xA9, 0xB8, 0x8F, 0x4F, 0x2F, 0x34, 0x4F, 0x6E, 0x7B,
    0x89, 0x9A, 0x91, 0x81, 0x68, 0x4A, 0x23, 0x06, 0x1A, 0x3B, 0x4D, 0x3D, 0x07, 0x00, 0x05, 0x0B, 0x2E, 0x50, 0x6B,
    0x7B, 0x8F, 0x9A, 0xA5, 0xAB, 0xAD, 0xA8, 0xA2, 0x96, 0x8C, 0x89, 0x81, 0x90, 0xB4, 0xC3, 0xDE, 0xF4, 0xFF, 0xFF,
    0xFF, 0xEF, 0xC0, 0x9E, 0x6B, 0x29, 0x02, 0x11, 0x19, 0x0A, 0x11, 0x34, 0x5B, 0x7F, 0x8C, 0x87, 0x9E, 0xB3, 0xA0,
    0x70, 0x46, 0x3A, 0x51, 0x70, 0x83, 0x85, 0x8B, 0xA1, 0xA1, 0x8F, 0x6E, 0x50, 0x31, 0x29, 0x51, 0x6C, 0x60, 0x33,
    0x08, 0x07, 0x10, 0x12, 0x29, 0x50, 0x73, 0x81, 0x93, 0xA4, 0xA9, 0xA9, 0xAC, 0xB9, 0xB8, 0x98, 0x8C, 0x8C, 0x8D,
    0xA2, 0xB9, 0xC8, 0xE3, 0xF6, 0xFF, 0xFF, 0xF3, 0xF4, 0xD1, 0xA2, 0x5C, 0x17, 0x01, 0x06, 0x02, 0x0D, 0x30, 0x45,
    0x5E, 0x70, 0x81, 0x8E, 0xA8, 0xA9, 0x7F, 0x63, 0x4F, 0x59, 0x7D, 0x97, 0x97, 0x8D, 0x90, 0xB2, 0xB4, 0x91, 0x6C,
    0x58, 0x54, 0x66, 0x8F, 0x89, 0x5E, 0x27, 0x23, 0x24, 0x21, 0x16, 0x29, 0x59, 0x7D, 0x85, 0x97, 0xA8, 0xA0, 0xA4,
    0xB8, 0xCC, 0xBD, 0x93, 0x8C, 0x8C, 0x95, 0xA6, 0xBA, 0xCE, 0xE3, 0xFA, 0xFF, 0xFA, 0xF5, 0xFF, 0xD5, 0x94, 0x48,
    0x0C, 0x00, 0x00, 0x09, 0x2A, 0x44, 0x44, 0x5B, 0x66, 0x81, 0x9B, 0xA4, 0x93, 0x72, 0x67, 0x66, 0x82, 0xAB, 0xB5,
    0xA5, 0x98, 0xA0, 0xBE, 0xB5, 0x8B, 0x6C, 0x6C, 0x8F, 0xAD, 0xB6, 0x8E, 0x5A, 0x2E, 0x4F, 0x49, 0x31, 0x1E, 0x34,
    0x64, 0x82, 0x87, 0x94, 0xA0, 0x99, 0xAD, 0xC8, 0xD1, 0xB9, 0x99, 0x8D, 0x8D, 0x91, 0xA2, 0xB9, 0xD4, 0xEB, 0xFD,
    0xFA, 0xF5, 0xFF, 0xFF, 0xC6, 0x7D, 0x3E, 0x11, 0x05, 0x0D, 0x21, 0x3A, 0x44, 0x44, 0x5C, 0x69, 0x8B, 0xA2, 0x9A,
    0x8B, 0x78, 0x78, 0x85, 0xAA, 0xC7, 0xC0, 0xAF, 0xA8, 0xAD, 0xB7, 0xAA, 0x85, 0x77, 0x94, 0xCE, 0xE1, 0xC0, 0x8F,
    0x65, 0x4F, 0x7B, 0x62, 0x3E, 0x2F, 0x48, 0x6D, 0x7D, 0x81, 0x8F, 0x96, 0x9F, 0xBC, 0xCC, 0xCE, 0xBF, 0xA8, 0x93,
    0x87, 0x89, 0x9E, 0xBA, 0xDC, 0xF2, 0xF4, 0xEC, 0xF5, 0xFF, 0xFA, 0xB0, 0x73, 0x48, 0x30, 0x31, 0x3C, 0x3D, 0x39,
    0x40, 0x47, 0x5E, 0x72, 0x96, 0xA0, 0x98, 0x93, 0x89, 0x90, 0xA4, 0xC0, 0xC8, 0xC2, 0xB8, 0xB4, 0xAD, 0xAA, 0xA2,
    0x8A, 0x97, 0xCC, 0xFC, 0xF6, 0xC4, 0x9D, 0x87, 0x82, 0x94, 0x68, 0x4E, 0x49, 0x5D, 0x72, 0x70, 0x7C, 0x90, 0x9A,
    0xB2, 0xC3, 0xCD, 0xD6, 0xCD, 0xB4, 0x97, 0x83, 0x87, 0xA3, 0xC6, 0xE3, 0xEF, 0xE9, 0xDF, 0xEF, 0xFF, 0xE7, 0xA8,
    0x7F, 0x67, 0x68, 0x70, 0x6B, 0x53, 0x39, 0x3F, 0x49, 0x5E, 0x7F, 0x9B, 0xA0, 0xA2, 0x9F, 0x9A, 0xA9, 0xB3, 0xBD,
    0xBF, 0xBD, 0xBC, 0xB7, 0xA5, 0xA2, 0xA4, 0xA4, 0xCB, 0xFB, 0xFF, 0xFB, 0xD4, 0xBE, 0xB7, 0xAF, 0x97, 0x6C, 0x62,
    0x67, 0x72, 0x76, 0x6D, 0x80, 0x95, 0xAB, 0xC1, 0xCA, 0xD9, 0xE7, 0xD7, 0xB9, 0x9A, 0x87, 0x91, 0xB2, 0xD2, 0xE5,
    0xE7, 0xDB, 0xD1, 0xE7, 0xFE, 0xE0, 0xB4, 0x9D, 0x97, 0xA0, 0x99, 0x7B, 0x5D, 0x3B, 0x3F, 0x4A, 0x63, 0x8E, 0x9F,
    0xAA, 0xAE, 0xA6, 0xA8, 0xB2, 0xAD, 0xB3, 0xB4, 0xB6, 0xBE, 0xB6, 0xA2, 0xA2, 0xB8, 0xD0, 0xFB, 0xFF, 0xFF, 0xFE,
    0xEC, 0xE5, 0xDF, 0xC8, 0x96, 0x78, 0x7D, 0x87, 0x7D, 0x7C, 0x7B, 0x8B, 0x9F, 0xB3, 0xC9, 0xDB, 0xEF, 0xF1, 0xDB,
    0xBA, 0x9F, 0x91, 0xA2, 0xC3, 0xD9, 0xDC, 0xD3, 0xBF, 0xC0, 0xDE, 0xFB, 0xEC, 0xD5, 0xC9, 0xC6, 0xBD, 0xA2, 0x79,
    0x5B, 0x38, 0x3C, 0x54, 0x76, 0x9E, 0xA5, 0xB7, 0xB8, 0xAC, 0xAC, 0xAD, 0xA8, 0xAC, 0xAD, 0xB6, 0xBE, 0xB4, 0xA5,
    0xAF, 0xD7, 0xF0, 0xFF, 0xFF, 0xFF, 0xFB, 0xFC, 0xFF, 0xF3, 0xCA, 0x9E, 0x90, 0x9D, 0x96, 0x81, 0x86, 0x8A, 0x9D,
    0xAA, 0xB7, 0xD4, 0xF2, 0xFF, 0xF5, 0xD9, 0xBA, 0xA4, 0xA1, 0xB7, 0xD5, 0xD6, 0xBD, 0xA6, 0x9F, 0xAF, 0xD0, 0xEF,
    0xFB, 0xFA, 0xED, 0xDF, 0xC1, 0x9B, 0x70, 0x51, 0x32, 0x44, 0x6E, 0x94, 0xA6, 0xA9, 0xBF, 0xC1, 0xB3, 0xAC, 0xA8,
    0xA5, 0xA9, 0xAF, 0xBC, 0xBE, 0xB7, 0xB5, 0xC8, 0xE0, 0xF2, 0xFF, 0xFF, 0xF3, 0xEA, 0xF7, 0xFF, 0xF3, 0xC7, 0xB0,
    0xB0, 0xAB, 0x8A, 0x81, 0x89, 0x91, 0xA2, 0xAC, 0xC6, 0xE5, 0xFF, 0xFF, 0xF7, 0xD9, 0xBD, 0xAD, 0xB3, 0xCC, 0xD8,
    0xB9, 0x86, 0x76, 0x81, 0x9D, 0xBC, 0xDB, 0xF9, 0xFF, 0xF7, 0xE0, 0xBA, 0x8E, 0x65, 0x45, 0x34, 0x61, 0x94, 0xA4,
    0x9F, 0xA6, 0xC4, 0xCC, 0xC0, 0xAF, 0xA9, 0xAA, 0xB2, 0xBE, 0xC0, 0xBF, 0xC2, 0xCB, 0xCD, 0xCC, 0xDE, 0xF3, 0xEA,
    0xD2, 0xD5, 0xE5, 0xF1, 0xEA, 0xC7, 0xC8, 0xC0, 0x9D, 0x79, 0x78, 0x7F, 0x8A, 0x93, 0xA5, 0xD2, 0xF5, 0xFF, 0xFF,
    0xF7, 0xD9, 0xC3, 0xBC, 0xC4, 0xCD, 0xBA, 0x83, 0x52, 0x52, 0x68, 0x85, 0xA4, 0xC9, 0xEB, 0xFB, 0xED, 0xD7, 0xAE,
    0x80, 0x59, 0x40, 0x48, 0x87, 0xA9, 0x93, 0x8F, 0xA5, 0xCE, 0xDE, 0xD0, 0xBA, 0xB3, 0xBA, 0xC7, 0xCB, 0xC2, 0xC3,
    0xCD, 0xCE, 0xB8, 0xB0, 0xC2, 0xCB, 0xBD, 0xB7, 0xC1, 0xD2, 0xE0, 0xE1, 0xCC, 0xCA, 0xAB, 0x84, 0x6C, 0x66, 0x69,
    0x72, 0x80, 0xA1, 0xD5, 0xFF, 0xFF, 0xFF, 0xF6, 0xDD, 0xCE, 0xCA, 0xC2, 0xAC, 0x86, 0x50, 0x2E, 0x36, 0x4F, 0x6E,
    0x94, 0xBD, 0xE1, 0xF3, 0xE1, 0xCC, 0x9F, 0x70, 0x54, 0x50, 0x6E, 0x98, 0x97, 0x7C, 0x89, 0xAD, 0xE0, 0xF0, 0xDC,
    0xCB, 0xC8, 0xD4, 0xD9, 0xD0, 0xC7, 0xC8, 0xC8, 0xB8, 0x9A, 0x93, 0x98, 0x97, 0x9A, 0xA1, 0xB3, 0xC7, 0xD5, 0xDC,
    0xD0, 0xAA, 0x81, 0x6B, 0x5A, 0x51, 0x51, 0x5B, 0x76, 0xA2, 0xD5, 0xFC, 0xFF, 0xFF, 0xF6, 0xE5, 0xD9, 0xC7, 0xA5,
    0x80, 0x58, 0x30, 0x16, 0x1C, 0x36, 0x5C, 0x8A, 0xB8, 0xDC, 0xEC, 0xD9, 0xC0, 0x8D, 0x67, 0x60, 0x6E, 0x86, 0x85,
    0x7A, 0x7B, 0x90, 0xBF, 0xF4, 0xFD, 0xEA, 0xE1, 0xE3, 0xE8, 0xDF, 0xD2, 0xCB, 0xC3, 0xB4, 0x9A, 0x7F, 0x70, 0x6B,
    0x71, 0x83, 0x94, 0xAD, 0xC2, 0xD0, 0xD2, 0xC4, 0x7B, 0x5B, 0x4A, 0x3E, 0x38, 0x3A, 0x4D, 0x73, 0xA4, 0xD1, 0xEF,
    0xFF, 0xFF, 0xF9, 0xEA, 0xD7, 0xAF, 0x85, 0x5E, 0x3C, 0x1F, 0x09, 0x08, 0x25, 0x51, 0x84, 0xB5, 0xD7, 0xE7, 0xD1,
    0xAF, 0x80, 0x67, 0x6E, 0x85, 0x7F, 0x6B, 0x70, 0x89, 0xA6, 0xD9, 0xFF, 0xFF, 0xFB, 0xFA, 0xFB, 0xEF, 0xDD, 0xD4,
    0xCB, 0xB4, 0x98, 0x7F, 0x65, 0x50, 0x50, 0x5D, 0x73, 0x91, 0xAD, 0xC1, 0xCA, 0xC0, 0xA3, 0x58, 0x3F, 0x2F, 0x21,
    0x1B, 0x27, 0x46, 0x76, 0xA4, 0xC6, 0xE3, 0xFF, 0xFF, 0xFB, 0xE8, 0xC4, 0x97, 0x70, 0x4D, 0x2E, 0x15, 0x02, 0x00,
    0x1B, 0x4E, 0x83, 0xB3, 0xD4, 0xDC, 0xC2, 0xA2, 0x7A, 0x6C, 0x7B, 0x87, 0x70, 0x66, 0x78, 0x9B, 0xC4, 0xF1, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xEB, 0xD6, 0xD0, 0xC1, 0xA1, 0x7C, 0x62, 0x48, 0x3D, 0x47, 0x57, 0x73, 0x96, 0xAE, 0xC0,
    0xBF, 0xA6, 0x7B, 0x3F, 0x2D, 0x1F, 0x13, 0x0B, 0x1A, 0x43, 0x76, 0x9F, 0xC1, 0xE3, 0xFF, 0xFF, 0xF7, 0xDB, 0xAE,
    0x84, 0x61, 0x42, 0x26, 0x0F, 0x00, 0x00, 0x17, 0x4D, 0x84, 0xB6, 0xD0, 0xCC, 0xB3, 0x98, 0x79, 0x75, 0x83, 0x82,
    0x73, 0x72, 0x8B, 0xB8, 0xE1, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFB, 0xE0, 0xC8, 0xC1, 0xAF, 0x89, 0x5B, 0x3F, 0x31,
    0x35, 0x44, 0x5A, 0x7D, 0xA0, 0xB3, 0xBA, 0xAD, 0x86, 0x5C, 0x31, 0x23, 0x19, 0x0D, 0x08, 0x13, 0x40, 0x71, 0x9F,
    0xC9, 0xF3, 0xFF, 0xFF, 0xEF, 0xC8, 0x9A, 0x73, 0x53, 0x39, 0x21, 0x0C, 0x02, 0x06, 0x1C, 0x51, 0x8B, 0xB7, 0xC7,
    0xBC, 0xA2, 0x8E, 0x7F, 0x7C, 0x85, 0x85, 0x84, 0x86, 0xA5, 0xD6, 0xF4, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xCB,
    0xB2, 0xAC, 0x96, 0x66, 0x35, 0x20, 0x25, 0x31, 0x47, 0x67, 0x91, 0xB3, 0xB6, 0xAF, 0x94, 0x69, 0x48, 0x2A, 0x1F,
    0x13, 0x09, 0x08, 0x19, 0x3E, 0x73, 0xAD, 0xE3, 0xFF, 0xFF, 0xFD, 0xDE, 0xB2, 0x87, 0x64, 0x48, 0x32, 0x1F, 0x0C,
    0x08, 0x14, 0x27, 0x5B, 0x8F, 0xB3, 0xBC, 0xAA, 0x8F, 0x87, 0x82, 0x81, 0x86, 0x91, 0x98, 0xA0, 0xC3, 0xEB, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xDD, 0xAD, 0x96, 0x8E, 0x71, 0x3E, 0x17, 0x0F, 0x1D, 0x32, 0x52, 0x7C, 0xAA, 0xC3,
    0xB5, 0xA0, 0x7C, 0x56, 0x3C, 0x28, 0x1C, 0x0B, 0x05, 0x0C, 0x21, 0x45, 0x83, 0xCB, 0xFF, 0xFF, 0xFF, 0xF2, 0xCA,
    0x9B, 0x73, 0x54, 0x3D, 0x2D, 0x1C, 0x10, 0x16, 0x28, 0x3A, 0x64, 0x94, 0xAF, 0xAF, 0x9B, 0x82, 0x82, 0x81, 0x82,
    0x89, 0x9D, 0xAA, 0xBC, 0xDF, 0xFA, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF1, 0xC1, 0x8F, 0x76, 0x69, 0x48, 0x1D, 0x05,
    0x06, 0x1A, 0x3B, 0x65, 0x95, 0xBE, 0xC7, 0xAB, 0x8E, 0x69, 0x46, 0x33, 0x28, 0x15, 0x00, 0x01, 0x13, 0x2F, 0x57,
    0xA1, 0xED, 0xFF, 0xFF, 0xFF, 0xDF, 0xB2, 0x83, 0x60, 0x46, 0x35, 0x27, 0x1D, 0x1C, 0x29, 0x3C, 0x49, 0x6E, 0x97,
    0xA9, 0xA5, 0x8E, 0x79, 0x7A, 0x7B, 0x7C, 0x89, 0xA5, 0xBD, 0xD4, 0xEF, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xDB,
    0xA4, 0x77, 0x58, 0x44, 0x25, 0x08, 0x00, 0x02, 0x1E, 0x4A, 0x7C, 0xA9, 0xC7, 0xBC, 0x9D, 0x7C, 0x5A, 0x3B, 0x2F,
    0x27, 0x0C, 0x00, 0x02, 0x1A, 0x3F, 0x73, 0xC3, 0xFE, 0xFF, 0xFF, 0xF4, 0xC9, 0x97, 0x6B, 0x4E, 0x3B, 0x2D, 0x23,
    0x25, 0x2D, 0x3C, 0x48, 0x57, 0x7C, 0x9A, 0xA6, 0x9B, 0x81, 0x71, 0x6D, 0x70, 0x73, 0x85, 0xB2, 0xCE, 0xDC, 0xE5,
    0xF3, 0xFF, 0xFF, 0xFF, 0xFF, 0xEF, 0xBD, 0x8B, 0x62, 0x3E, 0x26, 0x0F, 0x00, 0x00, 0x07, 0x2B, 0x5E, 0x91, 0xB4,
    0xC0, 0xAC, 0x8D, 0x6D, 0x4E, 0x38, 0x32, 0x26, 0x03, 0x00, 0x06, 0x21, 0x52, 0x94, 0xD6, 0xFF, 0xFF, 0xFF, 0xE1,
    0xAE, 0x7B, 0x56, 0x3F, 0x2E, 0x23, 0x24, 0x30, 0x3D, 0x47, 0x50, 0x67, 0x8C, 0xA3, 0xA6, 0x8F, 0x73, 0x64, 0x5E,
    0x65, 0x6D, 0x87, 0xBA, 0xCD, 0xC7, 0xCE, 0xEB, 0xFF, 0xFF, 0xFF, 0xFE, 0xD3, 0xA1, 0x77, 0x4E, 0x2B, 0x13, 0x02,
    0x00, 0x00, 0x10, 0x3A, 0x72, 0x9F, 0xB3, 0xB4, 0x9D, 0x7B, 0x60, 0x4A, 0x43, 0x3E, 0x20, 0x00, 0x00, 0x0A, 0x2A,
    0x66, 0xA4, 0xD9, 0xFF, 0xFF, 0xF4, 0xCB, 0x93, 0x65, 0x45, 0x32, 0x21, 0x1B, 0x28, 0x3A, 0x46, 0x4D, 0x5A, 0x78,
    0x9E, 0xAF, 0xA2, 0x81, 0x64, 0x54, 0x52, 0x5D, 0x6F, 0x8D, 0xB3, 0xB0, 0xA8, 0xBF, 0xE3, 0xFF, 0xFF, 0xFF, 0xE9,
    0xB8, 0x8D, 0x67, 0x3F, 0x1D, 0x07, 0x00, 0x00, 0x02, 0x1D, 0x48, 0x82, 0xA0, 0xAD, 0xAB, 0x8D, 0x6F, 0x59, 0x57,
    0x5A, 0x48, 0x11, 0x00, 0x00, 0x0D, 0x35, 0x72, 0xAA, 0xDE, 0xFF, 0xFF, 0xE0, 0xAC, 0x79, 0x51, 0x34, 0x24, 0x16,
    0x16, 0x2A, 0x3D, 0x47, 0x50, 0x66, 0x8B, 0xAF, 0xB4, 0x9D, 0x71, 0x52, 0x48, 0x45, 0x53, 0x6E, 0x83, 0x8F, 0x87,
    0x8F, 0xB3, 0xD9, 0xFB, 0xFF, 0xF6, 0xCC, 0xA0, 0x7D, 0x5D, 0x32, 0x10, 0x00, 0x00, 0x00, 0x0D, 0x2A, 0x5A, 0x86,
    0x9E, 0xA6, 0x9D, 0x7D, 0x65, 0x62, 0x70, 0x6E, 0x45, 0x00, 0x00, 0x03, 0x15, 0x3D, 0x77, 0xAF, 0xDD, 0xF0, 0xE6,
    0xBA, 0x86, 0x5E, 0x39, 0x23, 0x14, 0x0C, 0x14, 0x2A, 0x3C, 0x46, 0x54, 0x72, 0x9E, 0xB6, 0xAF, 0x8C, 0x63, 0x49,
    0x3A, 0x35, 0x47, 0x5B, 0x61, 0x61, 0x68, 0x7F, 0xA6, 0xD0, 0xE9, 0xED, 0xD7, 0xAC, 0x89, 0x71, 0x4A, 0x21, 0x07,
    0x00, 0x00, 0x05, 0x1A, 0x3A, 0x62, 0x87, 0x9A, 0x97, 0x87, 0x6D, 0x66, 0x76, 0x7D, 0x60, 0x26, 0x00, 0x01, 0x0B,
    0x25, 0x4A, 0x7F, 0xB0, 0xD3, 0xDB, 0xC1, 0x95, 0x6B, 0x49, 0x2A, 0x14, 0x06, 0x07, 0x14, 0x2A, 0x39, 0x46, 0x5E,
    0x83, 0xAD, 0xB7, 0x9F, 0x75, 0x5D, 0x49, 0x2D, 0x29, 0x3B, 0x46, 0x3E, 0x3C, 0x54, 0x76, 0xA0, 0xC1, 0xD5, 0xD7,
    0xBF, 0x9B, 0x7C, 0x5C, 0x31, 0x17, 0x05, 0x00, 0x00, 0x0C, 0x26, 0x45, 0x69, 0x8B, 0x91, 0x8B, 0x78, 0x69, 0x76,
    0x85, 0x6D, 0x30, 0x02, 0x00, 0x09, 0x1A, 0x35, 0x5D, 0x85, 0xA9, 0xC6, 0xBF, 0xA1, 0x80, 0x5E, 0x3D, 0x1F, 0x07,
    0x00, 0x05, 0x16, 0x27, 0x35, 0x4C, 0x6D, 0x99, 0xB9, 0xB2, 0x8A, 0x68, 0x58, 0x42, 0x25, 0x24, 0x39, 0x3C, 0x28,
    0x29, 0x4E, 0x77, 0x98, 0xB5, 0xCC, 0xD0, 0xB7, 0x98, 0x70, 0x40, 0x26, 0x15, 0x05, 0x00, 0x02, 0x14, 0x30, 0x51,
    0x78, 0x8C, 0x8F, 0x86, 0x73, 0x72, 0x82, 0x83, 0x4E, 0x12, 0x00,
};

static Gfx sInnerCylinderDList[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureBlock(sWindEffTexture, G_IM_FMT_I, G_IM_SIZ_8b, 64, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsDPLoadMultiBlock(sWindEffTexture, 0x0100, 1, G_IM_FMT_I, G_IM_SIZ_8b, 64, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                       G_TX_NOMIRROR | G_TX_WRAP, 6, 6, 14, 14),
    gsDPSetCombineLERP(TEXEL1, PRIMITIVE, PRIM_LOD_FRAC, TEXEL0, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, PRIMITIVE,
                       ENVIRONMENT, COMBINED, ENVIRONMENT, COMBINED, 0, SHADE, 0),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
    gsSPClearGeometryMode(G_CULL_BACK | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR),
    gsDPSetPrimColor(0, 0x80, 255, 255, 170, 255),
    gsDPSetEnvColor(150, 255, 0, 0),
    gsSPDisplayList(0x08000000),
    gsSPVertex(&sCylinderVtx[0], 18, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 7, 5, 0),
    gsSP2Triangles(3, 8, 1, 0, 3, 9, 8, 0),
    gsSP2Triangles(10, 2, 11, 0, 10, 0, 2, 0),
    gsSP2Triangles(9, 12, 8, 0, 9, 13, 12, 0),
    gsSP2Triangles(7, 14, 5, 0, 7, 15, 14, 0),
    gsSP2Triangles(15, 11, 14, 0, 15, 10, 11, 0),
    gsSP2Triangles(13, 16, 12, 0, 13, 17, 16, 0),
    gsSPEndDisplayList(),
};

static Gfx sOuterCylinderDList[] = {
    gsDPPipeSync(),
    gsDPSetTextureLUT(G_TT_NONE),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPLoadTextureBlock(sWindEffTexture, G_IM_FMT_I, G_IM_SIZ_8b, 64, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                         G_TX_NOMIRROR | G_TX_WRAP, 6, 6, G_TX_NOLOD, G_TX_NOLOD),
    gsDPLoadMultiBlock(sWindEffTexture, 0x0100, 1, G_IM_FMT_I, G_IM_SIZ_8b, 64, 64, 0, G_TX_NOMIRROR | G_TX_WRAP,
                       G_TX_NOMIRROR | G_TX_WRAP, 6, 6, 15, 15),
    gsDPSetCombineLERP(TEXEL1, PRIMITIVE, PRIM_LOD_FRAC, TEXEL0, TEXEL1, TEXEL0, PRIM_LOD_FRAC, TEXEL0, PRIMITIVE,
                       ENVIRONMENT, COMBINED, ENVIRONMENT, COMBINED, 0, SHADE, 0),
    gsDPSetRenderMode(G_RM_PASS, G_RM_AA_ZB_XLU_SURF2),
    gsSPClearGeometryMode(G_CULL_BACK | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR),
    gsDPSetPrimColor(0, 0x80, 255, 255, 170, 255),
    gsDPSetEnvColor(0, 150, 0, 0),
    gsSPDisplayList(0x09000000),
    gsSPVertex(&sCylinderVtx[18], 18, 0),
    gsSP2Triangles(0, 1, 2, 0, 0, 3, 1, 0),
    gsSP2Triangles(4, 5, 6, 0, 4, 7, 5, 0),
    gsSP2Triangles(3, 8, 1, 0, 3, 9, 8, 0),
    gsSP2Triangles(10, 2, 11, 0, 10, 0, 2, 0),
    gsSP2Triangles(9, 12, 8, 0, 9, 13, 12, 0),
    gsSP2Triangles(7, 14, 5, 0, 7, 15, 14, 0),
    gsSP2Triangles(15, 11, 14, 0, 15, 10, 11, 0),
    gsSP2Triangles(13, 16, 12, 0, 13, 17, 16, 0),
    gsSPEndDisplayList(),
};
