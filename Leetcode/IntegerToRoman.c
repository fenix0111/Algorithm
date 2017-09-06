// Leetcode 12. Integer to Roman
// https://leetcode.com/problems/integer-to-roman/description/
// Runtime: 49ms

char* intToRoman(int num) {
    int decimal = num;
    char *res;
    
    char *ht = NULL;
    char *hh = NULL;
    char *hd = NULL;
    char *hs = NULL;
    
    char *at[4] = {"", "M", "MM", "MMM"};
    char *ah[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char *ad[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char *as[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    
    int mod = 1;
    int pos = 0;
    int overalllen = 0;
    
    while (decimal)
    {
        mod = decimal % 10;
        decimal = decimal / 10;
        pos++;
        switch(pos)
        {
            case 1:
            {
                int len = strlen(as[mod]);
                hs = (char*)malloc(sizeof(char) * len);
                strcpy(hs, as[mod]);
                overalllen += len;
                break;
            }
            case 2:
            {
                int len = strlen(ad[mod]);
                hd = (char*)malloc(sizeof(char) * len);
                strcpy(hd, ad[mod]);
                overalllen += len;

                break;
            }
                
            case 3:
            {
                int len = strlen(ah[mod]);
                hh = (char*)malloc(sizeof(char) * len);
                strcpy(hh, ah[mod]);
                overalllen += len;

                break;
            }
                
            case 4:
            {
                int len = strlen(at[mod]);
                ht = (char*)malloc(sizeof(char) * len);
                strcpy(ht, at[mod]);
                overalllen += len;

                break;
            }
                
            default:
            {
                break;
            }
        }
    }
    
    res = (char*)malloc(sizeof(char) * overalllen);
    if(ht != NULL)
        strcat(res, ht);
    if (hh != NULL)
        strcat(res, hh);
    
    if (hd != NULL)
        strcat(res, hd);
    
    if (hs != NULL)
        strcat(res, hs);
    
    return res;
}
