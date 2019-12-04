#include <stdio.h>
#include <string.h>

int main()
{
    char line[100000];
    gets(line);
    int length=strlen(line);
    int i;
    for(i=0;i<length;i++)
        {
            if(line[i]==' ') printf(" ");
            else {
            switch (line[i])
            {
                case 'E':
                case 'e':
                    printf("q");
                    break;
                case 'R':
                case 'r':
                    printf("w");
                    break;
                case 'T':
                case 't':
                    printf("e");
                    break;
                case 'Y':
                case 'y':
                    printf("r");
                    break;
                case 'U':
                case 'u':
                    printf("t");
                    break;
                case 'I':
                case 'i':
                    printf("y");
                    break;
                case 'O':
                case 'o':
                    printf("u");
                    break;
                case 'P':
                case 'p':
                    printf("i");
                    break;
                case '[':
                    printf("o");
                    break;
                case ']':
                    printf("p");
                    break;


                case 'D':
                case 'd':
                    printf("a");
                    break;
                case 'F':
                case 'f':
                    printf("s");
                    break;
                case 'G':
                case 'g':
                    printf("d");
                    break;
                case 'H':
                case 'h':
                    printf("f");
                    break;
                case 'J':
                case 'j':
                    printf("g");
                    break;
                case 'K':
                case 'k':
                    printf("h");
                    break;
                case 'L':
                case 'l':
                    printf("j");
                    break;
                case ';':
                    printf("k");
                    break;
                case '\'':
                    printf("l");
                    break;

                case 'C':
                case 'c':
                    printf("z");
                    break;
                case 'V':
                case 'v':
                    printf("x");
                    break;
                case 'B':
                case 'b':
                    printf("c");
                    break;
                case 'N':
                case 'n':
                    printf("v");
                    break;
                case 'M':
                case 'm':
                    printf("b");
                    break;
                case ',':
                    printf("n");
                    break;
                case '.':
                    printf("m");
                    break;
                case '/':
                    printf(",");
                    break;

                case '2':
                    printf("`");
                    break;
                case '3':
                    printf("1");
                    break;
                case '4':
                    printf("2");
                    break;
                case '5':
                    printf("3");
                    break;
                case '6':
                    printf("4");
                    break;
                case '7':
                    printf("5");
                    break;
                case '8':
                    printf("6");
                    break;
                case '9':
                    printf("7");
                    break;
                case '0':
                    printf("8");
                    break;
                case '-':
                    printf("9");
                    break;
                case '=':
                    printf("0");
                    break;
                case '\\':
                    printf("-");
                    break;
            }}
        }
    printf("\n");
    return 0;
}
