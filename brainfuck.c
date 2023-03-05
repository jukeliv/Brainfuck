#include <stdio.h>

int main(int argc, char** argv)
{
    if(argc < 2){
        printf("Not enough arguments!!!\n");
        return 1;
    }
    unsigned char memory[30000] = {0};
    unsigned char p = 0;
    FILE *fp;
    char s[1000];
    if (!(fp = fopen(argv[1], "r"))) {
        printf("Couldn't to open file\n");
        return 1;
    }
    fseek(fp, 0, SEEK_END);
    size_t fs = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    if(!fread(s, 1, fs, fp)){
        printf("Can't read file!!!\n");
        return 1;
    }
    fclose(fp);
    unsigned char l = 0, ps = 0, pi = 0;
    for(int i = 0; i < fs; ++i){
        switch (s[i]){
        case '>':
            p++;
            break;
        case '<':
            p--;
            break;
        case '+':
            memory[p]++;
            break;
        case '-':
            memory[p]--;
            break;
        case '.':
            putchar(memory[p]);
            break;
        case ',':
            memory[p] = getchar();
            break;
        case '[':
            pi = p;
            
            l = (memory[pi]-1);
            if (l) ps = i-1;
            break;
        case ']':
            if(l) i = ps;
            break;
        default:
            break;
        }
    }
    return 0;
}