const long expand_em_size = 1294;
const unsigned char bin_expand_em[1294] = {
0xC3,0x6A,0xBA,0xC3,0x18,0xB8,0xC3,0x71,0xBA,0xC3,0x86,0xBA,0xC3,0x64,0xBB,0xC3,0x78,
0xBB,0xC3,0x46,0xB9,0xC3,0xE5,0xBB,0x21,0xAA,0xBB,0xCD,0x6A,0xBA,0xCD,0x92,0x5F,0xD8,
0x23,0x11,0x10,0x8C,0x01,0x20,0x00,0xED,0xB0,0xCD,0x82,0xBB,0xCD,0x3E,0xBA,0xCD,0x0E,
0x5F,0xAF,0x32,0xD4,0xBB,0xAF,0x32,0x90,0xBB,0xF3,0xCD,0x39,0x90,0x21,0x01,0x00,0x5E,
0x23,0x56,0x23,0xED,0x53,0xD8,0xBB,0x22,0xDC,0xBB,0x7B,0xB2,0xCA,0xFB,0xB8,0x5E,0x23,
0x56,0x23,0xED,0x53,0xDA,0xBB,0x22,0xE1,0xBB,0x23,0x23,0x23,0xEB,0x21,0x10,0x8C,0x06,
0x21,0xE5,0x2A,0xD8,0xBB,0x2B,0xA7,0xED,0x52,0xE1,0x28,0x0E,0x1A,0x13,0xBE,0x20,0xEB,
0x23,0x7E,0xB7,0x28,0x09,0x10,0xE9,0x18,0x05,0x2A,0xD8,0xBB,0x18,0xBE,0xFB,0xCD,0x36,
0x90,0xD5,0xCD,0x0E,0xB9,0xE5,0xED,0x5B,0xDA,0xBB,0xCD,0x71,0xBA,0x3E,0x20,0x00,0x21,
0x96,0xB8,0xDF,0x2A,0xDC,0xBB,0x23,0x23,0xCD,0xA4,0x44,0xCD,0x4C,0x19,0x21,0xB9,0xE9,
0xCD,0x6A,0xBA,0x21,0xD5,0xBB,0xCD,0x6A,0xBA,0x2A,0x86,0xEF,0x22,0xE3,0xBB,0xE1,0x22,
0x86,0xEF,0xCD,0x90,0x42,0xDB,0x09,0xCB,0x47,0x28,0x3D,0x21,0x90,0xBB,0x01,0x01,0x7F,
0xCD,0x78,0xBB,0x28,0x04,0xCB,0x7F,0x28,0x12,0x21,0x91,0xBB,0x01,0x09,0xBF,0xCD,0x78,
0xBB,0x28,0xDD,0xCB,0x77,0x20,0xD9,0xD1,0x18,0x08,0xD1,0x3A,0xD4,0xBB,0xB7,0xC4,0x86,
0xB9,0xD5,0xCD,0x0E,0x5F,0xD1,0xF3,0xCD,0x39,0x90,0xC3,0x62,0xB8,0xFB,0xCD,0x36,0x90,
0xCD,0xD9,0x35,0xC9,0xD1,0xED,0x5B,0xE3,0xBB,0xED,0x53,0x86,0xEF,0x18,0xED,0xD5,0xED,
0x5B,0xDA,0xBB,0xCD,0x79,0xBA,0x01,0xFF,0xFF,0x23,0x23,0x7E,0xB7,0x28,0x03,0x03,0x18,
0xF8,0x21,0x11,0x8C,0x7E,0xB7,0x28,0x04,0x0B,0x23,0x18,0xF8,0xD1,0xEB,0x09,0xEB,0x2A,
0xE1,0xBB,0xEB,0xA7,0xED,0x52,0x16,0x00,0x1E,0x50,0xCD,0x2D,0x90,0x53,0x5D,0x2A,0x86,
0xEF,0x19,0xC9,0x21,0xBF,0xBB,0xCD,0x6A,0xBA,0x21,0xAA,0xBB,0xCD,0x6A,0xBA,0xCD,0x92,
0x5F,0xD8,0x23,0x11,0x10,0x8C,0x01,0x20,0x00,0xED,0xB0,0xCD,0x82,0xBB,0xCD,0x3E,0xBA,
0x21,0xB0,0xBB,0xCD,0x6A,0xBA,0xCD,0x92,0x5F,0xD8,0x23,0x11,0x30,0x8C,0x01,0x20,0x00,
0xED,0xB0,0xCD,0x50,0xBA,0xCD,0x0E,0x5F,0x3E,0xFF,0x32,0xD4,0xBB,0xC3,0x38,0xB8,0xD5,
0x21,0x11,0x8C,0x0E,0x01,0x1B,0x7E,0xB7,0x28,0x04,0x23,0x0C,0x18,0xF7,0xED,0x53,0xDE,
0xBB,0x21,0x30,0x8C,0x06,0x00,0x7E,0xB7,0x28,0x04,0x04,0x23,0x18,0xF8,0x78,0xB7,0x20,
0x0A,0x32,0x31,0x8C,0x3E,0x20,0x32,0x30,0x8C,0x3E,0x01,0x32,0xE0,0xBB,0x91,0x30,0x46,
0xD1,0xD5,0xEB,0x5F,0x16,0xFF,0x19,0xE5,0x2A,0xD8,0xBB,0x19,0x22,0xD8,0xBB,0xE1,0xEB,
0xE1,0xE5,0xD9,0x2A,0x18,0xEB,0xD1,0xA7,0xED,0x52,0x4D,0x44,0xC5,0xD9,0xC1,0xD5,0xF3,
0xCD,0x39,0x90,0xED,0xB0,0xED,0x5B,0xDE,0xBB,0x21,0x30,0x8C,0x3A,0xE0,0xBB,0x4F,0x06,
0x00,0xED,0xB0,0xCD,0x36,0x90,0xFB,0xCD,0xBD,0x05,0x23,0xCD,0xD5,0x44,0x22,0x18,0xEB,
0xD1,0xC9,0xB7,0x28,0x24,0x2A,0xD8,0xBB,0x5F,0x16,0x00,0x19,0x22,0xD8,0xBB,0x2A,0x18,
0xEB,0xD1,0xD5,0xE5,0xA7,0xED,0x52,0x23,0x4D,0x44,0xE1,0xE5,0x5F,0x16,0x00,0x19,0xEB,
0xE1,0xF3,0xCD,0x39,0x90,0xED,0xB8,0xF3,0xCD,0x39,0x90,0xD1,0xED,0x5B,0xDE,0xBB,0x21,
0x30,0x8C,0x3A,0xE0,0xBB,0x4F,0x06,0x00,0xED,0xB0,0xD5,0x18,0xB2,0x21,0xAA,0xBB,0x11,
0xC8,0xF3,0x01,0x06,0x00,0xED,0xB0,0x21,0x10,0x8C,0xCD,0x62,0xBA,0xC9,0x21,0xB0,0xBB,
0x11,0xDF,0xF3,0x01,0x0F,0x00,0xED,0xB0,0x21,0x30,0x8C,0xCD,0x62,0xBA,0xC9,0x7E,0xB7,
0xC8,0x12,0x23,0x13,0x18,0xF8,0x7E,0xA7,0xC8,0xDF,0x23,0x18,0xF9,0xCD,0x79,0xBA,0x23,
0xCD,0x6A,0xBA,0xC9,0xED,0x53,0x41,0xEC,0x3E,0x02,0x32,0xBD,0xEA,0xCD,0xD0,0x28,0xC9,
0xD9,0x32,0xCA,0xBA,0xAF,0x32,0x63,0xBB,0x21,0x01,0xBF,0xD9,0x21,0x01,0x00,0x5E,0x23,
0x56,0x23,0xED,0x53,0xD8,0xBB,0x22,0xDC,0xBB,0x7B,0xB2,0xCA,0x61,0xBB,0x5E,0x23,0x56,
0x23,0xED,0x53,0xDA,0xBB,0x23,0x23,0x23,0x7E,0x23,0xFE,0x20,0x20,0x18,0x23,0x7E,0xFE,
0x40,0x20,0x12,0x23,0x7E,0xFE,0x25,0x20,0x04,0x23,0x32,0x63,0xBB,0xCD,0x27,0x90,0x3E,
0x00,0xBB,0x28,0x05,0x2A,0xD8,0xBB,0x18,0xC2,0x3A,0x63,0xBB,0xB7,0x28,0x23,0x3E,0x06,
0x32,0x38,0xBB,0x3E,0x04,0x32,0x49,0xBB,0xCD,0x37,0xBB,0x2A,0xD8,0xBB,0x11,0x09,0x00,
0x19,0xCD,0x27,0x90,0xCD,0xD0,0x95,0x7B,0xD9,0x77,0xD9,0xCD,0xD6,0x95,0xA7,0xC9,0x2A,
0xD8,0xBB,0x5E,0x23,0x56,0xED,0x53,0xD8,0xBB,0x11,0x08,0x00,0x19,0xCD,0x27,0x90,0xD5,
0x23,0xCD,0x27,0x90,0x7B,0xD1,0x57,0xD5,0x3E,0x04,0x32,0x38,0xBB,0x3E,0x09,0x32,0x49,
0xBB,0xCD,0x37,0xBB,0xCD,0xD0,0x95,0xD9,0xD1,0x73,0x23,0x72,0xD9,0xCD,0xD6,0x95,0x21,
0x01,0xBF,0xCD,0x06,0xDE,0xA7,0xC9,0x06,0x06,0xC5,0x2A,0xD8,0xBB,0x5E,0x23,0x56,0xED,
0x53,0xD8,0xBB,0x11,0x08,0x00,0x19,0x06,0x04,0xC5,0xCD,0x27,0x90,0x23,0xCD,0xD0,0x95,
0x7B,0xD9,0x77,0x23,0xD9,0xCD,0xD6,0x95,0xC1,0x10,0xED,0xC1,0x10,0xD9,0xC9,0x37,0xC9,
0x00,0xE5,0xD5,0xC5,0x4F,0x87,0x81,0x21,0x92,0xBB,0x5F,0x16,0x00,0x19,0xCD,0xC6,0x6E,
0xC1,0xD1,0xE1,0xC9,0xED,0x78,0xB0,0x46,0x77,0xFE,0xFF,0xC8,0xB8,0xC9,0x21,0xC8,0xF3,
0x11,0xC9,0xF3,0x01,0x77,0x00,0x36,0x00,0xED,0xB0,0xC9,0x00,0x00,0x20,0x30,0x00,0x20,
0x31,0x00,0x20,0x32,0x00,0x20,0x33,0x00,0x20,0x34,0x00,0x20,0x35,0x00,0x20,0x36,0x00,
0x20,0x37,0x00,0x46,0x69,0x6E,0x64,0x3A,0x00,0x52,0x65,0x70,0x6C,0x61,0x63,0x65,0x20,
0x77,0x68,0x69,0x63,0x68,0x3A,0x00,0x52,0x45,0x54,0x28,0x47,0x4F,0x29,0x2F,0x53,0x50,
0x41,0x43,0x45,0x28,0x53,0x4B,0x49,0x50,0x29,0x0A,0x00,0x00,0x0D,0x0A,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xED,0x5B,0x20,0xF3,0xD5,0xCD,
0x21,0x90,0xD1,0xED,0x53,0x20,0xF3,0x30,0x02,0x37,0xC9,0xE5,0x4F,0xCD,0x16,0xBC,0xF5,
0x3A,0x44,0xF3,0x5F,0x16,0x00,0xCD,0x2D,0x90,0x4B,0x42,0xEB,0xF1,0xE1,0xD0,0xE5,0x21,
0x00,0x00,0xA7,0xED,0x52,0xEB,0xE1,0xA7,0xC9,0x21,0x7A,0xBC,0x11,0x62,0xBC,0xD9,0x21,
0xDC,0xBC,0xD9,0x3A,0x30,0xF3,0xD6,0x03,0xFE,0x03,0x30,0x06,0xEB,0xD9,0x21,0xF4,0xBC,
0xD9,0x22,0x5B,0xBC,0xED,0x53,0x60,0xBC,0x79,0xD9,0x4F,0x3A,0x45,0xF3,0xE6,0x0F,0x87,
0x5F,0x16,0x00,0x19,0x5E,0x23,0x56,0xED,0x53,0x0C,0xBD,0x79,0xCD,0xC6,0xBC,0xF5,0x3A,
0x45,0xF3,0xCD,0xC6,0xBC,0x4F,0xF1,0x91,0xC8,0xD2,0x7A,0xBC,0xED,0x44,0xC3,0x62,0xBC,
0x21,0xBB,0xA1,0x22,0xA5,0xBC,0x21,0x71,0x80,0x22,0xAB,0xBC,0xCD,0x92,0xBC,0xEB,0x2A,
0x0C,0xBD,0xA7,0xED,0x52,0x37,0xC9,0x21,0x62,0x9C,0x22,0xA5,0xBC,0x21,0x07,0x81,0x22,
0xAB,0xBC,0xCD,0x92,0xBC,0xED,0x5B,0x0C,0xBD,0xA7,0xED,0x52,0xA7,0xC9,0xF5,0xCD,0x36,
0x90,0x2A,0x0C,0xBD,0xCD,0xFD,0x21,0xCD,0x2F,0x22,0xCD,0xE8,0x20,0xF1,0xF5,0x21,0xBB,
0xA1,0x22,0x41,0xEC,0x21,0x71,0x80,0x22,0x43,0xEC,0x3E,0x04,0x32,0xBD,0xEA,0xCD,0x53,
0x1F,0xCD,0xE8,0x20,0xF1,0x3D,0x20,0xE4,0xCD,0xA0,0x21,0xCD,0x39,0x90,0xC9,0x57,0xE6,
0xF0,0xCB,0x3F,0xCB,0x3F,0xCB,0x3F,0xCB,0x3F,0x87,0x87,0x5F,0x87,0x83,0x5F,0x7A,0xE6,
0x0F,0x83,0xC9,0x6A,0x02,0x8F,0x02,0xB6,0x02,0xDF,0x02,0x0B,0x03,0x39,0x03,0x6A,0x03,
0x9E,0x03,0xD5,0x03,0x10,0x04,0x4E,0x04,0x8F,0x04,0xE8,0x0E,0x12,0x0E,0x48,0x0D,0x89,
0x0C,0xD5,0x0B,0x2B,0x0B,0x8A,0x0A,0xF3,0x09,0x64,0x09,0xDD,0x08,0x5E,0x08,0xE6,0x07,
0x00,0x00
};
