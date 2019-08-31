typedef struct {
  void *addr;
  uint32_t length;
} __attribute__((packed)) region_t;

typedef struct {
  uint32_t unused_0[2];
  uint32_t use_lv2_mode_0; // if 1, use lv2 list
  uint32_t use_lv2_mode_1; // if 1, use lv2 list
  uint32_t unused_10[3];
  uint32_t list_count; // must be < 0x1F1
  uint32_t unused_20[4];
  uint32_t total_count; // only used in LV1 mode
  uint32_t unused_34[1];
  union {
    region_t lv1[0x1F1];
    region_t lv2[0x1F1];
  } list;
} __attribute__((packed)) cmd_0x50002_t;

typedef struct heap_hdr {
  void *data;
  uint32_t size;
  uint32_t size_aligned;
  uint32_t padding;
  struct heap_hdr *prev;
  struct heap_hdr *next;
} __attribute__((packed)) heap_hdr_t;

typedef struct SceSblSmCommPair {
    uint32_t unk_0;
    uint32_t unk_4;
} SceSblSmCommPair;

unsigned char get_xx_71[] = {
  0x06, 0xd3, 0x0a, 0x80, 0x01, 0xc2, 0x48, 0xd0, 0x39, 0x02, 0x01, 0xc2,
  0x7c, 0x80, 0x39, 0xc2, 0x02, 0x00, 0x01, 0xc2, 0x0f, 0x10, 0x0a, 0xd3,
  0x0a, 0x80, 0x39, 0x02, 0x01, 0xc2, 0x05, 0x51, 0x48, 0xd3, 0x7c, 0x80,
  0x39, 0x02, 0x4a, 0xd3, 0x7c, 0x80, 0x01, 0xc2, 0xea, 0xc1, 0x39, 0x02,
  0x01, 0xc2, 0x18, 0x80, 0x39, 0xc2, 0x02, 0x00, 0x4e, 0xd3, 0x7c, 0x80,
  0x01, 0xc2, 0x21, 0xc2, 0x39, 0x02, 0x01, 0xc2, 0x00, 0x1c, 0x39, 0xc2,
  0x02, 0x00, 0x52, 0xd3, 0x7c, 0x80, 0x01, 0xc2, 0x00, 0xd1, 0x39, 0x02,
  0x01, 0xc2, 0xb0, 0x80, 0x39, 0xc2, 0x02, 0x00, 0x01, 0xc2, 0x00, 0x53,
  0x56, 0xd3, 0x7c, 0x80, 0x39, 0x02, 0x21, 0xc3, 0xb2, 0x80, 0x34, 0xc3,
  0x23, 0xd4, 0x58, 0xd2, 0x7c, 0x80, 0x2a, 0x03, 0x01, 0xc2, 0x4b, 0x04,
  0x5c, 0xd3, 0x7c, 0x80, 0x39, 0x02, 0x5e, 0xd3, 0x7c, 0x80, 0x01, 0xc2,
  0xc4, 0xe4, 0x39, 0x02, 0x04, 0x52, 0x39, 0xc2, 0x02, 0x00, 0x62, 0xd3,
  0x7c, 0x80, 0x01, 0xc2, 0x00, 0xd3, 0x39, 0x02, 0x01, 0xc2, 0x8e, 0x00,
  0x39, 0xc2, 0x02, 0x00, 0x66, 0xd3, 0x7c, 0x80, 0x01, 0xc2, 0x16, 0xd0,
  0x39, 0x02, 0x01, 0xc2, 0x10, 0x80, 0x39, 0xc2, 0x02, 0x00, 0x01, 0xc2,
  0x0e, 0x10, 0x6a, 0xd3, 0x7c, 0x80, 0x39, 0x02, 0x8c, 0xd3, 0xbd, 0x80,
  0x3e, 0x10
};

size_t get_xx_71_sz = 0x8e00;

#define LOG(...) \
	do { \
		char buffer[256]; \
		snprintf(buffer, sizeof(buffer), ##__VA_ARGS__); \
		logg(buffer, strlen(buffer), LOG_LOC, 2); \
} while (0)
	
#define LOG_START(...) \
	do { \
		char buffer[256]; \
		snprintf(buffer, sizeof(buffer), ##__VA_ARGS__); \
		logg(buffer, strlen(buffer), LOG_LOC, 1); \
} while (0)

static int logg(void *buffer, int length, const char* logloc, int create)
{
	int fd;
	if (create == 0) {
		fd = ksceIoOpen(logloc, SCE_O_WRONLY | SCE_O_APPEND, 6);
	} else if (create == 1) {
		fd = ksceIoOpen(logloc, SCE_O_WRONLY | SCE_O_TRUNC | SCE_O_CREAT, 6);
	} else if (create == 2) {
		fd = ksceIoOpen(logloc, SCE_O_WRONLY | SCE_O_APPEND | SCE_O_CREAT, 6);
	}
	if (fd < 0)
		return 0;

	ksceIoWrite(fd, buffer, length);
	ksceIoClose(fd);
	return 1;
}