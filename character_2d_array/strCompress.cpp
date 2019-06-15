#include<iostream>
#include<string>

using namespace std;

char* strCompress(char str[]){
    char *s = str;
    char *r, *p;
    int count, i;

    while(*s)
    {
        count = 1;

        while(*s == *(s+1) && *s){
            count++;
            s++;
        }

        if(count > 1){
            8(s - count + 2) = count + '\0';

            for(i=0;i<count-2;i++){
                p = s+1;
                r=s;
                while(*r){
                    *r++ =  *p++;
                }

                s--;
            }
        }

        s++;

    }
    return str;
}


int main()
{
    char myStr[] = "AAAABBBCCCCCCDDDEFGHHIJJ";

    printf("Compressed String is : %s\n", StrCompress(myStr));

    return 0;
}