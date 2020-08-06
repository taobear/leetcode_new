#include "minStickers.h"

#include <stdio.h>

void test1()
{
    char sticker1[] = "with";
    char sticker2[] = "example";
    char sticker3[] = "science";

    char *stickers[] = {sticker1, sticker2, sticker3};
    int stickersSize = sizeof(stickers) / sizeof(*stickers);

    char target[] = "thehat";
    printf("test1(): %d\n", minStickers(stickers, stickersSize, target));
}

void test2()
{
    char sticker1[] = "notice";
    char sticker2[] = "possible";

    char *stickers[] = {sticker1, sticker2};
    int stickersSize = sizeof(stickers) / sizeof(*stickers);

    char target[] = "basicbasic";
    printf("test2(): %d\n", minStickers(stickers, stickersSize, target));
}

void test3()
{
    char sticker1[] = "swim";
    char sticker2[] = "love";
    char sticker3[] = "father";
    char sticker4[] = "shape";
    char sticker5[] = "rich";
    char sticker6[] = "multiply";
    char sticker7[] = "new";
    char sticker8[] = "fill";
    char sticker9[] = "history";

    char *stickers[] = {sticker1, sticker2, sticker3, sticker4, sticker5, sticker6, sticker7, sticker8, sticker9};
    int stickersSize = sizeof(stickers) / sizeof(*stickers);

    char target[] = "operateform";
    printf("test3(): %d\n", minStickers(stickers, stickersSize, target));
}

void test4()
{
    char sticker1[] = "divide";
    char sticker2[] = "danger";
    char sticker3[] = "student";
    char sticker4[] = "share";
    char sticker5[] = "feet";
    char sticker6[] = "say";
    char sticker7[] = "expect";
    char sticker8[] = "chair";
    char sticker9[] = "special";
    char sticker10[] = "blue";

    char sticker11[] = "differ";
    char sticker12[] = "thank";
    char sticker13[] = "doctor";
    char sticker14[] = "top";
    char sticker15[] = "there";
    char sticker16[] = "ice";
    char sticker17[] = "mark";
    char sticker18[] = "note";
    char sticker19[] = "equate";
    char sticker20[] = "basic";

    char sticker21[] = "so";
    char sticker22[] = "hope";
    char sticker23[] = "happy";
    char sticker24[] = "draw";
    char sticker25[] = "evening";
    char sticker26[] = "star";
    char sticker27[] = "shall";
    char sticker28[] = "thousand";
    char sticker29[] = "mother";
    char sticker30[] = "quite";

    char sticker31[] = "letter";
    char sticker32[] = "atom";
    char sticker33[] = "baby";
    char sticker34[] = "such";
    char sticker35[] = "trouble";
    char sticker36[] = "stand";
    char sticker37[] = "day";
    char sticker38[] = "room";
    char sticker39[] = "third";
    char sticker40[] = "level";

    char sticker41[] = "salt";
    char sticker42[] = "thing";
    char sticker43[] = "shore";
    char sticker44[] = "truck";
    char sticker45[] = "block";
    char sticker46[] = "time";
    char sticker47[] = "fresh";
    char sticker48[] = "dream";
    char sticker49[] = "talk";
    char sticker50[] = "had";

    char *stickers[] = { sticker1,  sticker2,  sticker3,  sticker4,  sticker5,  sticker6,  sticker7,  sticker8,  sticker9, sticker10,
                        sticker11, sticker12, sticker13, sticker14, sticker15, sticker16, sticker17, sticker18, sticker19, sticker20,
                        sticker21, sticker22, sticker23, sticker24, sticker25, sticker26, sticker27, sticker28, sticker29, sticker30,
                        sticker31, sticker32, sticker33, sticker34, sticker35, sticker36, sticker37, sticker38, sticker39, sticker40,
                        sticker41, sticker42, sticker43, sticker44, sticker45, sticker46, sticker47, sticker48, sticker49, sticker50,};
    int stickersSize = sizeof(stickers) / sizeof(*stickers);

    char target[] = "distantcollect";
    printf("test4(): %d\n", minStickers(stickers, stickersSize, target));
}

int main(int argc, char **argv)
{
    test1();

    test2();

    test3();

    test4();

    return 0;
}