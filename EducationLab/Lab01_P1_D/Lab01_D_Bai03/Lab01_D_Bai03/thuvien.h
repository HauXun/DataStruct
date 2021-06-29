#define MAX 100

CHUYENTAU BangTau[MAX];

struct CHUYENTAU
{
	char gadi[20];
	char gaden[20];
	GIO_XP xp;
	THOI_GIAN tg;
	int gv;
};
struct GIO_XP
{
	int g;
	int p;
};
struct THOI_GIAN
{
	int gio;
	int phut;
};