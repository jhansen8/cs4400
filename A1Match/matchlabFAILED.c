#include <stdio.h>

void aMatch(char* sequence, int t)
{

}

void bMatch(char* sequence, int t)
{
    
}

void cMatch(char* sequence, int t)
{
    
}

void checkFlag(char* flag, int& a, int& b, int& c, int& t)
{
    if (flag == "-a")
        a = 1;
    else if (flag == "-b")
        b = 1;
    else if (flag == "-c")
        c = 1;
    else if (flag == "-t")
        t = 1;
}

int main(int argc, char* argv[])
{
    if (argc > 4)
        return 1;

    int a = 0;
    int b = 0; 
    int c = 0;
    int t = 0;

    int idx = 0;
    for (idx = 1; idx < argc - 1; idx++)
    {
        checkFlag(argv[idx], a, b, c);
    }

    char* sequence = argv[argc - 1];

    if (a == 1 | (a == 0 && b == 0 && c == 0))
    {
        aMatch(sequence, t);
    }
}