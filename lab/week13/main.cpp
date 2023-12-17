#include "huffmanTree.h"

int main()
{
    char c[] = "abcdef";
    char code[] = "111";
    int w[] = {6, 3, 4, 8, 5, 5};
    int num = 6;
    htNode HT[2 * num - 1];
    hCode hc[num];
    // initiation
    for (int i = 0; i < num; i++)
    {
        HT[i].data = c[i];
        HT[i].weight = w[i];
    }
    createHT(HT, num);

    htEncode(HT, hc, num);

    // dispHcode(HT, hc, num);
    htDecode(HT, num, code);
}