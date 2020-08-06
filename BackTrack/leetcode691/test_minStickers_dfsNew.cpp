#include "minStickers_dfsNew.h"

void test4()
{
    string sticker1 = "divide";
    string sticker2 = "danger";
    string sticker3 = "student";
    string sticker4 = "share";
    string sticker5 = "feet";
    string sticker6 = "say";
    string sticker7 = "expect";
    string sticker8 = "chair";
    string sticker9 = "special";
    string sticker10 = "blue";

    string sticker11 = "differ";
    string sticker12 = "thank";
    string sticker13 = "doctor";
    string sticker14 = "top";
    string sticker15 = "there";
    string sticker16 = "ice";
    string sticker17 = "mark";
    string sticker18 = "note";
    string sticker19 = "equate";
    string sticker20 = "basic";

    string sticker21 = "so";
    string sticker22 = "hope";
    string sticker23 = "happy";
    string sticker24 = "draw";
    string sticker25 = "evening";
    string sticker26 = "star";
    string sticker27 = "shall";
    string sticker28 = "thousand";
    string sticker29 = "mother";
    string sticker30 = "quite";

    string sticker31 = "letter";
    string sticker32 = "atom";
    string sticker33 = "baby";
    string sticker34 = "such";
    string sticker35 = "trouble";
    string sticker36 = "stand";
    string sticker37 = "day";
    string sticker38 = "room";
    string sticker39 = "third";
    string sticker40 = "level";

    string sticker41 = "salt";
    string sticker42 = "thing";
    string sticker43 = "shore";
    string sticker44 = "truck";
    string sticker45 = "block";
    string sticker46 = "time";
    string sticker47 = "fresh";
    string sticker48 = "dream";
    string sticker49 = "talk";
    string sticker50 = "had";

    vector<string> stickers = {
        sticker1,
        sticker2,
        sticker3,
        sticker4,
        sticker5,
        sticker6,
        sticker7,
        sticker8,
        sticker9,
        sticker10,
        sticker11,
        sticker12,
        sticker13,
        sticker14,
        sticker15,
        sticker16,
        sticker17,
        sticker18,
        sticker19,
        sticker20,
        sticker21,
        sticker22,
        sticker23,
        sticker24,
        sticker25,
        sticker26,
        sticker27,
        sticker28,
        sticker29,
        sticker30,
        sticker31,
        sticker32,
        sticker33,
        sticker34,
        sticker35,
        sticker36,
        sticker37,
        sticker38,
        sticker39,
        sticker40,
        sticker41,
        sticker42,
        sticker43,
        sticker44,
        sticker45,
        sticker46,
        sticker47,
        sticker48,
        sticker49,
        sticker50,
    };

    string target = "distantcollect";
    printf("test4(): %d\n", Solution().minStickers(stickers, target));
}

int main(int argc, char **argv)
{
    test4();

    return 0;
}