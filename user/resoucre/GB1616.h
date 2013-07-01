#define GB1616_MAXSIZE		91
#define GB1616_SIZE			32

typedef struct                 // 汉字字模数据结构			
{
	uint8_t Index[2];               // 汉字内码索引
    char Msk[32];                       // 点阵码数据
} typFNT_GB1616;

extern const typFNT_GB1616 tGB_16[GB1616_MAXSIZE] = {
"西", 0x04,0xC4,0x44,0x44,0x44,0xFC,0x44,0x44,0x44,0xFC,0x44,0x44,0x44,0xE6,0x44,0x00,
	  0x00,0xFF,0x40,0x50,0x48,0x47,0x40,0x40,0x40,0x47,0x48,0x48,0x40,0xFF,0x00,0x00,

"安", 0x00,0x00,0xB8,0x88,0x88,0x88,0xC8,0xBE,0x88,0x88,0x88,0x88,0x88,0xB8,0x80,0x00,
	  0x00,0x00,0x40,0x40,0x46,0x65,0x28,0x28,0x18,0x18,0x16,0x23,0x20,0x40,0x00,0x00,

"维", 0x00,0x60,0x50,0xCE,0x62,0x70,0x60,0xFC,0x92,0x90,0x92,0xFC,0x90,0x90,0x90,0x00,
	  0x00,0x24,0x26,0x25,0x14,0x14,0x00,0x7F,0x24,0x24,0x24,0x3F,0x24,0x24,0x24,0x20,

"纳", 0x00,0x20,0x38,0xA6,0x62,0x30,0x08,0xF8,0x08,0x88,0x7E,0x88,0x08,0x08,0xF8,0x00,
	  0x00,0x22,0x22,0x23,0x12,0x12,0x10,0x7F,0x04,0x03,0x00,0x00,0x43,0x42,0x7F,0x00,

"测", 0x00,0x20,0x42,0x44,0x04,0xFC,0x04,0xE4,0x04,0x04,0xFC,0x00,0xF8,0x00,0xFE,0x00,
	  0x00,0x60,0x38,0x0E,0x40,0x67,0x30,0x0F,0x08,0x10,0x27,0x00,0x8F,0x80,0xFF,0x00,

"控", 0x00,0x10,0x10,0xFE,0x10,0x90,0x38,0x88,0x48,0x0A,0x0C,0x28,0x48,0x88,0x38,0x00,
	  0x00,0x42,0x42,0x7F,0x01,0x40,0x41,0x42,0x42,0x42,0x7E,0x42,0x42,0x43,0x40,0x40,

"返", 0x40,0x42,0x44,0xCC,0x00,0x00,0xFC,0x04,0xA4,0x24,0x24,0xA2,0x63,0x02,0x00,0x00, 
	  0x00,0x40,0x20,0x1F,0x20,0x58,0x87,0x90,0x88,0x85,0x82,0x85,0x88,0xD8,0x40,0x00,

"回", 0x00,0xFC,0x04,0x04,0x04,0xE4,0x24,0x24,0x24,0xF4,0x24,0x04,0x04,0xFE,0x04,0x00,
	  0x00,0x7F,0x20,0x20,0x20,0x2F,0x24,0x24,0x24,0x2F,0x20,0x20,0x20,0x7F,0x00,0x00,

"信", 0x80,0x40,0x20,0xF8,0x07,0x24,0x24,0x24,0x25,0x26,0x24,0x24,0xB4,0x26,0x04,0x00,
	  0x00,0x00,0x00,0xFF,0x00,0x01,0xFD,0x45,0x45,0x45,0x45,0x45,0xFD,0x01,0x00,0x00,

"息" ,0x00,0x00,0x00,0xFC,0xA4,0xA6,0xA5,0xA4,0xA4,0xA4,0xA4,0xFE,0x04,0x00,0x00,0x00,
	  0x40,0x30,0x00,0x77,0x84,0x84,0x8C,0x94,0xB4,0x84,0x84,0xE7,0x00,0x10,0x60,0x00,

"查" ,0x84,0x84,0x44,0xE4,0x54,0x4C,0x44,0x7F,0x44,0x4C,0x54,0xE4,0x44,0xC6,0x44,0x00,
      0x40,0x40,0x40,0x5F,0x52,0x52,0x52,0x52,0x52,0x52,0x52,0x5F,0x40,0x60,0x40,0x00,

"询" ,0x40,0x42,0x44,0xCC,0x20,0x18,0x07,0xE4,0x24,0x24,0x24,0xE4,0x04,0xFE,0x04,0x00,
  	  0x00,0x00,0x00,0x7F,0x20,0x10,0x08,0x1F,0x09,0x09,0x09,0x5F,0x80,0x7F,0x00,0x00,

"人" ,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x7F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	  0x00,0x80,0x40,0x20,0x10,0x0C,0x03,0x00,0x03,0x0C,0x10,0x20,0x40,0xC0,0x40,0x00,

"工" ,0x00,0x04,0x04,0x04,0x04,0x04,0x04,0xFC,0x04,0x04,0x04,0x04,0x06,0x04,0x00,0x00,
	  0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x3F,0x20,0x20,0x20,0x20,0x20,0x30,0x20,0x00,

"模" ,0x10,0x10,0xD0,0xFF,0x94,0x14,0xE4,0xBF,0xA4,0xA4,0xA4,0xBF,0xF4,0x26,0x04,0x00,
      0x04,0x03,0x00,0xFF,0x08,0x89,0x8B,0x4A,0x2A,0x1E,0x2A,0x2A,0x4B,0xC8,0x48,0x00,

"式" ,0x10,0x10,0x90,0x90,0x90,0x90,0x90,0x10,0xFF,0x10,0x12,0x14,0x10,0x18,0x10,0x00,
	  0x00,0x20,0x60,0x20,0x1F,0x10,0x10,0x08,0x01,0x06,0x18,0x20,0x40,0x80,0x70,0x00,

"参" ,0x20,0x20,0x20,0x28,0xA8,0x6C,0x3B,0x28,0xA8,0x6A,0xAC,0x28,0x20,0x30,0x20,0x00,
	  0x04,0x84,0x82,0x81,0x4A,0x4A,0x49,0x25,0x24,0x12,0x10,0x09,0x02,0x06,0x02,0x00,

"数" ,0x10,0x92,0x54,0x30,0xFF,0x50,0x94,0x32,0xD8,0x17,0x10,0x10,0xF0,0x18,0x10,0x00,
	  0x02,0x82,0x4E,0x33,0x22,0x52,0x8E,0x40,0x23,0x14,0x08,0x16,0x61,0xC0,0x40,0x00,

"设" ,0x40,0x40,0x42,0xCC,0x00,0x40,0xA0,0x9F,0x81,0x81,0x81,0x9F,0xA0,0x20,0x20,0x00,
	  0x00,0x00,0x00,0x7F,0xA0,0x90,0x40,0x43,0x2C,0x10,0x28,0x26,0x41,0xC0,0x40,0x00,

"置" ,0x00,0x10,0x17,0xD5,0x55,0x57,0x55,0x7D,0x55,0x57,0x55,0xD5,0x17,0x10,0x00,0x00,
	  0x40,0x40,0x40,0x7F,0x55,0x55,0x55,0x55,0x55,0x55,0x55,0x7F,0x40,0x60,0x40,0x00,

"系" ,0x00,0x02,0x22,0x22,0x32,0x2E,0xA2,0x62,0x22,0x22,0x91,0x09,0x01,0x00,0x00,0x00,
	  0x00,0x00,0x42,0x22,0x1A,0x43,0x82,0x7E,0x02,0x02,0x0A,0x13,0x66,0x00,0x00,0x00,

"统" ,0x20,0x30,0xAC,0x63,0x30,0x88,0xC8,0xA8,0x99,0x8E,0x88,0xA8,0xCC,0x88,0x00,0x00,
	  0x22,0x67,0x22,0x12,0x92,0x40,0x30,0x0F,0x00,0x00,0x3F,0x40,0x40,0x41,0x70,0x00,

"校" ,0x10,0x10,0xD0,0xFF,0x90,0x10,0x88,0x48,0xA8,0x09,0x0A,0x08,0xA8,0x4C,0xC8,0x00,
	  0x04,0x03,0x00,0xFF,0x80,0x81,0x40,0x40,0x21,0x16,0x08,0x16,0x61,0xC0,0x40,0x00,

"准" ,0x00,0x02,0x04,0xEC,0x40,0x20,0xF8,0x4F,0x48,0x49,0xFE,0x48,0x68,0x4C,0x08,0x00,
	  0x02,0x02,0x7F,0x00,0x00,0x00,0xFF,0x22,0x22,0x22,0x3F,0x22,0x23,0x32,0x20,0x00,

"零" ,0x10,0x0C,0x04,0x55,0x55,0x55,0x85,0x7F,0x85,0x55,0x55,0x55,0x04,0x14,0x0C,0x00,
	  0x04,0x04,0x02,0x02,0x09,0x09,0x2A,0x4C,0xA8,0x19,0x09,0x02,0x02,0x04,0x04,0x00,

"点" ,0x00,0x00,0xC0,0x40,0x40,0x40,0x7F,0x48,0x48,0x48,0x48,0xE8,0x4C,0x08,0x00,0x00,
   	  0x80,0x40,0x37,0x04,0x14,0x64,0x04,0x14,0x24,0x64,0x04,0x17,0x20,0xC0,0x00,0x00,

"满" ,0x10,0x21,0x62,0x06,0x24,0x24,0x24,0xEF,0x24,0x24,0xEF,0x24,0x34,0xA6,0x04,0x00,
	  0x04,0x04,0xFE,0x01,0xFF,0x11,0x09,0x07,0x09,0x09,0x07,0x49,0x91,0x7F,0x01,0x00,

"度" ,0x00,0x00,0xFC,0x24,0x24,0x24,0xFC,0xA5,0xA6,0xA4,0xFC,0x24,0x34,0x26,0x04,0x00,
	  0x40,0x20,0x9F,0x80,0x42,0x42,0x26,0x2A,0x12,0x2A,0x26,0x42,0x40,0xC0,0x40,0x00,

"浮" ,0x10,0x21,0x62,0x06,0x80,0x04,0xB4,0x84,0x84,0xB4,0x82,0xA2,0x9B,0x02,0x00,0x00,
	  0x04,0x04,0xFE,0x01,0x04,0x04,0x04,0x44,0x84,0x7E,0x05,0x04,0x04,0x06,0x04,0x00,

"球" ,0x04,0x44,0x44,0xFC,0x46,0x44,0x28,0xC8,0x08,0xFF,0x08,0x8A,0x4C,0x68,0x08,0x00,
	  0x10,0x10,0x10,0x0F,0x08,0x18,0x08,0x44,0x82,0x7F,0x01,0x06,0x08,0x18,0x08,0x00,

"于" ,0x40,0x40,0x42,0x42,0x42,0x42,0x42,0xFE,0x42,0x42,0x42,0x43,0x42,0x60,0x40,0x00,
	  0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x7F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

"位" ,0x80,0x40,0x20,0xF8,0x07,0x10,0xD0,0x10,0x11,0x16,0x10,0x10,0xD8,0x10,0x00,0x00,
	  0x00,0x00,0x00,0xFF,0x20,0x20,0x20,0x23,0x2C,0x20,0x38,0x27,0x20,0x30,0x20,0x00,

"按" ,0x10,0x10,0x90,0xFF,0x90,0xA0,0x98,0x88,0x88,0xE9,0x8A,0x88,0x88,0xA8,0x98,0x00,
	  0x01,0x41,0x80,0x7F,0x00,0x00,0x80,0x84,0x4B,0x30,0x10,0x28,0x47,0xC0,0x00,0x00,

"键" ,0x10,0x28,0xE7,0x24,0x24,0xC2,0xB2,0x8E,0x10,0x54,0x54,0xFF,0x54,0x7C,0x10,0x00,
	  0x01,0x01,0x7F,0x21,0x51,0x24,0x18,0x27,0x48,0x89,0x89,0xFF,0x89,0xCD,0x48,0x00,

"显" ,0x00,0x00,0x00,0xFE,0x92,0x92,0x92,0x92,0x92,0x92,0x92,0xFF,0x02,0x00,0x00,0x00,
	  0x40,0x42,0x44,0x4D,0x40,0x7F,0x40,0x40,0x40,0x7F,0x40,0x49,0x44,0x66,0x40,0x00,

"示" ,0x40,0x40,0x42,0x42,0x42,0x42,0x42,0xC2,0x42,0x42,0x42,0x43,0x42,0x60,0x40,0x00,
	  0x00,0x10,0x08,0x04,0x06,0x40,0x80,0x7F,0x00,0x00,0x02,0x04,0x0C,0x18,0x00,0x00,

"基" ,0x00,0x04,0x04,0x04,0xFF,0x54,0x54,0x54,0x54,0x54,0xFF,0x04,0x06,0x84,0x00,0x00,
	  0x11,0x11,0x89,0x89,0x95,0x93,0x91,0xFD,0x91,0x9B,0x95,0xC5,0x89,0x19,0x09,0x00,

"本" ,0x00,0x10,0x10,0x10,0x10,0xF0,0x10,0xFF,0x10,0xF0,0x10,0x10,0x18,0x10,0x00,0x00,
	  0x10,0x10,0x08,0x04,0x0B,0x08,0x08,0xFF,0x08,0x08,0x0B,0x04,0x08,0x18,0x08,0x00,

"运" ,0x40,0x42,0x44,0xCC,0x00,0x20,0x22,0x22,0xE2,0x22,0x22,0x23,0x32,0x20,0x00,0x00,
	  0x00,0x40,0x20,0x1F,0x20,0x48,0x4C,0x4B,0x48,0x48,0x4A,0x4C,0x58,0x60,0x20,0x00,

"行" ,0x00,0x10,0x88,0xC4,0x23,0x40,0x42,0x42,0x42,0x42,0x42,0xC2,0x43,0x62,0x40,0x00,
	  0x02,0x01,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x7F,0x00,0x00,0x00,0x00,

"继" ,0x20,0x30,0xAC,0x63,0x30,0x00,0xFE,0x88,0x90,0xA0,0xFF,0xA0,0x90,0x98,0x00,0x00,
	  0x22,0x67,0x22,0x12,0x12,0x00,0x7F,0x48,0x44,0x42,0x7F,0x42,0x44,0x6C,0x40,0x00,

"电" ,0x00,0xF8,0x48,0x48,0x48,0x48,0xFF,0x48,0x48,0x48,0x48,0xFC,0x08,0x00,0x00,0x00,
	  0x00,0x07,0x02,0x02,0x02,0x02,0x3F,0x42,0x42,0x42,0x42,0x47,0x40,0x70,0x00,0x00,

"器" ,0x80,0x80,0x9F,0x91,0x91,0x91,0x9F,0xE0,0x9F,0x91,0xB1,0xD1,0x9F,0xC0,0x80,0x00,
	  0x08,0x08,0xFC,0x8C,0x8A,0x8A,0xF9,0x00,0xF9,0x8A,0x8A,0x8C,0xFC,0x08,0x08,0x00,

"控" ,0x10,0x10,0x10,0xFF,0x90,0x50,0x0C,0x44,0x24,0x15,0x06,0x14,0x24,0x54,0x0C,0x00,
	  0x02,0x42,0x81,0x7F,0x00,0x40,0x42,0x42,0x42,0x42,0x7E,0x42,0x43,0x62,0x40,0x00,

"制" ,0x40,0x60,0x5E,0x48,0x48,0xFF,0x48,0x4C,0x68,0x40,0xF8,0x00,0x00,0xFF,0x00,0x00,
	  0x00,0x00,0x3F,0x01,0x01,0xFF,0x11,0x21,0x1F,0x00,0x07,0x40,0x80,0x7F,0x00,0x00,

"阀" ,0x00,0xF8,0x01,0x86,0xE0,0x9A,0x82,0xFA,0x42,0x4A,0x52,0x42,0x02,0xFF,0x02,0x00,
	  0x00,0xFF,0x01,0x00,0x7F,0x00,0x10,0x09,0x06,0x1A,0x21,0x30,0x80,0xFF,0x00,0x00,

"门" ,0x00,0xFC,0x01,0x02,0x06,0x00,0x02,0x02,0x02,0x02,0x02,0x02,0x02,0xFF,0x02,0x00,
	  0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0x80,0x7F,0x00,0x00,

"输" ,0x88,0x68,0x1F,0xC8,0x0C,0x28,0x90,0xA8,0xA6,0xA1,0x26,0x28,0x10,0xB0,0x10,0x00,
	  0x09,0x09,0x05,0xFF,0x05,0x00,0xFF,0x0A,0x8A,0xFF,0x00,0x1F,0x80,0xFF,0x00,0x00,

"出" ,0x00,0x00,0xFC,0x40,0x40,0x40,0x40,0xFF,0x40,0x40,0x40,0x40,0xFC,0x00,0x00,0x00,
	  0x00,0xFE,0x40,0x40,0x40,0x40,0x40,0x7F,0x40,0x40,0x40,0x40,0x40,0xFE,0x00,0x00,

"模" ,0x10,0x10,0xD0,0xFF,0x94,0x14,0xE4,0xBF,0xA4,0xA4,0xA4,0xBF,0xF4,0x26,0x04,0x00,
	  0x04,0x03,0x00,0xFF,0x08,0x89,0x8B,0x4A,0x2A,0x1E,0x2A,0x2A,0x4B,0xC8,0x48,0x00,

"式" ,0x10,0x10,0x90,0x90,0x90,0x90,0x90,0x10,0xFF,0x10,0x12,0x14,0x10,0x18,0x10,0x00,
	  0x00,0x20,0x60,0x20,0x1F,0x10,0x10,0x08,0x01,0x06,0x18,0x20,0x40,0x80,0x70,0x00,

"量" ,0x20,0x20,0x20,0xBE,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xBF,0x22,0x30,0x20,0x00,
	  0x00,0x80,0x80,0xAF,0xAA,0xAA,0xAA,0xFF,0xAA,0xAA,0xAA,0xAF,0x80,0x80,0x00,0x00,

"程" ,0x24,0x24,0xA4,0xFE,0xA3,0x22,0x20,0x7E,0x42,0x42,0x42,0x42,0x42,0x7F,0x02,0x00,
	  0x08,0x06,0x01,0xFF,0x00,0x43,0x41,0x49,0x49,0x49,0x7F,0x49,0x4D,0x69,0x41,0x00,

"上" ,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x20,0x20,0x20,0x30,0x20,0x00,0x00,0x00,
	  0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x7F,0x40,0x40,0x40,0x40,0x40,0x60,0x40,0x00,

"限" ,0x00,0xFE,0x02,0x22,0xDA,0x06,0x00,0xFE,0x92,0x92,0x92,0x92,0xFF,0x02,0x00,0x00,
	  0x00,0xFF,0x08,0x10,0x08,0x07,0x00,0xFF,0x42,0x24,0x08,0x14,0x22,0x61,0x20,0x00,

"下" ,0x02,0x02,0x02,0x02,0x02,0x02,0xFE,0x02,0x22,0x42,0x82,0x82,0x02,0x03,0x02,0x00,
	  0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00,

"告" ,0x80,0x80,0xA0,0x9E,0x88,0x88,0x88,0xFF,0x88,0x88,0x88,0x8C,0x88,0xC0,0x80,0x00,
	  0x00,0x00,0x00,0xFE,0x42,0x42,0x42,0x42,0x42,0x42,0x42,0xFF,0x02,0x00,0x00,0x00,

"警" ,0x80,0x92,0x8A,0xBF,0xAA,0xBB,0xCA,0xFA,0x84,0xA7,0xAA,0x92,0xAE,0xE2,0xA0,0x00,
	  0x00,0x00,0x00,0xEA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xAA,0xEA,0x00,0x00,0x00,0x00,

"定" ,0x10,0x0C,0x04,0x24,0x24,0x24,0x25,0xE6,0x24,0x24,0x34,0x24,0x04,0x14,0x0C,0x00,
	  0x80,0x40,0x20,0x1F,0x20,0x40,0x40,0x7F,0x42,0x42,0x43,0x42,0x40,0x60,0x20,0x00,

"液" ,0x10,0x22,0x64,0x0C,0x80,0x04,0xC4,0x34,0x05,0xC6,0xBC,0x24,0x24,0xE6,0x04,0x00,
	  0x04,0x04,0xFE,0x01,0x02,0x01,0xFF,0x42,0x21,0x16,0x08,0x15,0x23,0x60,0x20,0x00,

"正" ,0x00,0x02,0x02,0xC2,0x02,0x02,0x02,0xFE,0x82,0x82,0x82,0xC2,0x83,0x02,0x00,0x00,
	  0x40,0x40,0x40,0x7F,0x40,0x40,0x40,0x7F,0x40,0x40,0x40,0x40,0x40,0x60,0x40,0x00,

"反" ,0x00,0x00,0xFC,0x24,0x24,0xE4,0x24,0x24,0x24,0x22,0x22,0xA3,0x62,0x00,0x00,0x00,
	  0x40,0x30,0x0F,0x80,0x80,0x40,0x23,0x14,0x08,0x14,0x22,0x21,0x40,0xC0,0x40,0x00,

"向" ,0x00,0xF8,0x08,0x08,0xCC,0x4A,0x49,0x48,0x48,0x48,0xE8,0x48,0x08,0xFC,0x08,0x00,
	  0x00,0xFF,0x00,0x00,0x1F,0x08,0x08,0x08,0x08,0x08,0x1F,0x40,0x80,0x7F,0x00,0x00,

"阻" ,0x00,0xFE,0x02,0x22,0xDA,0x06,0x00,0xFC,0x44,0x44,0x44,0x44,0xFE,0x04,0x00,0x00,
	  0x00,0xFF,0x08,0x10,0x08,0x47,0x40,0x7F,0x44,0x44,0x44,0x44,0x7F,0x40,0x40,0x00,

"尼" ,0x00,0x00,0xFE,0x22,0x22,0xE2,0x22,0x22,0x22,0x22,0x22,0xA2,0x3F,0x02,0x00,0x00,
	  0x80,0x60,0x1F,0x00,0x00,0x3F,0x44,0x44,0x42,0x42,0x41,0x41,0x40,0x40,0x70,0x00,

"比" ,0x00,0x00,0xFE,0x40,0x40,0x60,0x40,0x00,0xFF,0x80,0x40,0x20,0x30,0x00,0x00,0x00,
	  0x00,0x40,0x7F,0x20,0x20,0x10,0x10,0x00,0x3F,0x40,0x40,0x40,0x40,0x40,0x78,0x00,

"例" ,0x40,0x20,0xF8,0x07,0x84,0x64,0x3C,0x24,0x24,0xE6,0x04,0xF0,0x00,0xFF,0x00,0x00,
	  0x00,0x00,0xFF,0x01,0x20,0x11,0x0A,0x04,0x03,0x00,0x00,0x47,0x80,0x7F,0x00,0x00,

"增" ,0x20,0x20,0xFF,0x20,0x20,0xF0,0x11,0x52,0x14,0xF0,0x14,0x52,0x11,0xF8,0x10,0x00,
	  0x08,0x18,0x0F,0x04,0x04,0x01,0xFD,0x55,0x55,0x55,0x55,0x55,0xFF,0x05,0x00,0x00,

"益" ,0x00,0x08,0x08,0x88,0x49,0x2A,0x08,0x08,0x08,0x2A,0x49,0xC8,0x0C,0x08,0x00,0x00,
	  0x40,0x40,0x7E,0x42,0x42,0x7E,0x42,0x42,0x42,0x7E,0x42,0x42,0x7E,0x40,0x40,0x00,

"积" ,0x20,0x24,0x24,0xA4,0xFE,0x23,0x22,0x00,0xFC,0x04,0x04,0x04,0x04,0xFE,0x04,0x00,
	  0x10,0x08,0x06,0x01,0xFF,0x01,0x42,0x20,0x1B,0x11,0x01,0x01,0x09,0x33,0x60,0x00,

"分" ,0x00,0x80,0x40,0x20,0x98,0x86,0x80,0x80,0x83,0x8C,0x90,0x20,0xC0,0x80,0x80,0x00,
	  0x01,0x00,0x80,0x40,0x20,0x1F,0x00,0x40,0x80,0x40,0x3F,0x00,0x00,0x01,0x00,0x00,

"时" ,0x00,0xFC,0x84,0x84,0x84,0xFE,0x14,0x10,0x90,0x10,0x10,0x10,0xFF,0x10,0x10,0x00,
	  0x00,0x3F,0x10,0x10,0x10,0x3F,0x00,0x00,0x00,0x23,0x40,0x80,0x7F,0x00,0x00,0x00,

"间" ,0x00,0xF8,0x01,0x02,0xF6,0x10,0x12,0x12,0x12,0x12,0xFA,0x12,0x02,0xFF,0x02,0x00,
	  0x00,0xFF,0x00,0x00,0x3F,0x11,0x11,0x11,0x11,0x11,0x3F,0x40,0x80,0x7F,0x00,0x00,

"微" ,0x10,0x88,0xC4,0xA3,0xBC,0xA0,0xBF,0xA0,0xBC,0x20,0xD8,0x17,0x90,0x78,0x10,0x00,
	  0x01,0x00,0xFF,0x40,0x3E,0x02,0x02,0x3E,0x90,0x48,0x33,0x0C,0x33,0xC0,0x40,0x00,

"厂" ,0x00,0x00,0x00,0xFC,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x06,0x04,0x00,0x00,
	  0x40,0x20,0x18,0x07,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

"商" ,0x04,0x04,0xE4,0x24,0x2C,0xB4,0x25,0x26,0x24,0xB4,0x2C,0x24,0xF4,0x26,0x04,0x00,
	  0x00,0x00,0xFF,0x02,0x01,0x3E,0x22,0x22,0x22,0x3E,0x41,0x82,0x7F,0x00,0x00,0x00,

"日" ,0x00,0x00,0x00,0xFE,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0xFF,0x02,0x00,0x00,0x00,
	  0x00,0x00,0x00,0x7F,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x7F,0x00,0x00,0x00,0x00,

"期" ,0x00,0x08,0xFF,0xA8,0xA8,0xA8,0xFF,0x08,0x00,0xFE,0x22,0x22,0x22,0xFF,0x02,0x00,
	  0x84,0x44,0x37,0x04,0x04,0x14,0xA7,0x44,0x24,0x1F,0x02,0x42,0x82,0x7F,0x00,0x00,

"检" ,0x10,0x10,0xD0,0xFF,0x10,0x50,0x20,0x50,0x4C,0x43,0x4C,0x50,0x20,0x60,0x20,0x00,
	  0x04,0x03,0x00,0xFF,0x41,0x42,0x42,0x5C,0x40,0x5F,0x40,0x50,0x4E,0x64,0x40,0x00,

"验" ,0x02,0xFA,0x02,0x02,0xFF,0x42,0x20,0x50,0x4C,0x43,0x4C,0x50,0x20,0x60,0x20,0x00,
	  0x10,0x31,0x11,0x49,0x89,0x7F,0x42,0x5C,0x40,0x4F,0x60,0x58,0x47,0x60,0x40,0x00,

"大" ,0x20,0x20,0x20,0x20,0x20,0x20,0xA0,0x7F,0xA0,0x20,0x20,0x20,0x20,0x30,0x20,0x00,
	  0x00,0x40,0x40,0x20,0x10,0x0C,0x03,0x00,0x01,0x06,0x08,0x10,0x20,0x60,0x20,0x00,

"小" ,0x00,0x00,0x00,0x00,0x80,0x60,0x00,0xFF,0x00,0x20,0x40,0x80,0x00,0x00,0x00,0x00,
	  0x00,0x08,0x04,0x02,0x01,0x40,0x80,0x7F,0x00,0x00,0x00,0x00,0x01,0x06,0x00,0x00,

"米" ,0x40,0x40,0x42,0x44,0x4C,0x58,0xC0,0xFF,0x40,0x50,0x48,0x44,0x46,0x60,0x40,0x00,
	  0x20,0x20,0x10,0x08,0x04,0x02,0x01,0xFF,0x01,0x02,0x04,0x08,0x10,0x30,0x10,0x00,

"年" ,0x00,0x20,0x10,0xCC,0x47,0x44,0x44,0xFC,0x44,0x44,0x44,0x64,0x46,0x04,0x00,0x00,
	  0x04,0x04,0x04,0x07,0x04,0x04,0x04,0xFF,0x04,0x04,0x04,0x04,0x04,0x06,0x04,0x00,

"月" ,0x00,0x00,0x00,0x00,0xFE,0x22,0x22,0x22,0x22,0x22,0x22,0xFF,0x02,0x00,0x00,0x00,
	  0x00,0x80,0x40,0x30,0x0F,0x02,0x02,0x02,0x02,0x42,0x82,0x7F,0x00,0x00,0x00,0x00,

"日" ,0x00,0x00,0x00,0xFE,0x82,0x82,0x82,0x82,0x82,0x82,0x82,0xFF,0x02,0x00,0x00,0x00,
	  0x00,0x00,0x00,0x7F,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x7F,0x00,0x00,0x00,0x00,

"压" ,0x00,0x00,0xFE,0x02,0x82,0x82,0x82,0x82,0xFE,0x82,0x82,0x82,0xC3,0x82,0x00,0x00,
	  0x40,0x30,0x0F,0x40,0x40,0x40,0x40,0x40,0x7F,0x40,0x42,0x44,0x4C,0x60,0x40,0x00,

"流" ,0x10,0x22,0x64,0x0C,0x80,0x44,0x44,0x64,0x55,0x4E,0x44,0x54,0x66,0xC4,0x00,0x00,
	  0x04,0x04,0xFE,0x01,0x00,0x80,0x40,0x3F,0x00,0xFF,0x00,0x3F,0x40,0x40,0x70,0x00,

"入" ,0x00,0x00,0x00,0x00,0x00,0x01,0xE2,0x1C,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
	  0x80,0x40,0x20,0x10,0x0C,0x03,0x00,0x00,0x00,0x03,0x0C,0x30,0x40,0xC0,0x40,0x00,

"型" ,0x20,0x22,0x22,0xFE,0x22,0x22,0xFE,0x23,0x22,0x00,0xFC,0x00,0x00,0xFF,0x00,0x00,
	  0x40,0x4C,0x4A,0x49,0x48,0x48,0x4B,0x7E,0x48,0x48,0x48,0x4A,0x4C,0x6B,0x40,0x00,

"号" ,0x80,0x80,0x80,0xBE,0xA2,0xA2,0xA2,0xA2,0xA2,0xA2,0xA2,0xBF,0x82,0xC0,0x80,0x00,
	  0x00,0x00,0x00,0x04,0x06,0x05,0x04,0x04,0x44,0x84,0x44,0x3E,0x04,0x00,0x00,0x00,

};
