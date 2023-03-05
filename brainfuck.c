#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        fprintf(stderr, "Not enough arguments!!!\n");
        return 1;
    }
    char memory[30000];
    unsigned short dp = 0;

    FILE *fp;
    char buffer[1000];
    
    fp = fopen(argv[1], "r");
    if (!fp) {
        printf("Couldn't to open file\n");
        return 1;
    }
    
    fseek(fp, 0, SEEK_END);

    size_t fsize = ftell(fp);
    
    fseek(fp, 0, SEEK_SET);
    
    if(fread(buffer, 1, fsize, fp) == fsize)
    {
        fprintf(stderr, "Can't read file!!!\n");
        return 1;
    }
    
    fclose(fp);
    
    unsigned char loop = 0;

    unsigned short pos = 0;
    unsigned short dp_c = 0;
    unsigned short index = 0;

    while(index < fsize)
    {
        char c = buffer[index];
        switch (c)
        {
        case '>':
            dp++;
            break;
        case '<':
            dp--;
            break;
        case '+':
            memory[dp]++;
            break;
        case '-':
            memory[dp]--;
            break;
        case '.':
            putchar(memory[dp]);
            break;
        case ',':
            memory[dp] = getchar();
            break;
        case '[':
            dp_c = dp;

            if ((memory[dp_c]-1))
            {
                loop = 1;
                pos = index-1;
            }
            else
                loop = 0;
            break;
        case ']':
            if(loop)
                index = pos;
            break;
        default:
            break;
        }
        ++index;
    }
    return 0;
}