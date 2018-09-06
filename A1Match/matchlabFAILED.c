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
        // for (idx; idx < strlen(sequence); idx++)
        // {
        //     if(sequence[idx] == 'c')
        //     {
        //         cCount = cCount + 1;

        //         if (sequence[idx] == ',' && cCount >= 1)
        //         {
        //             commaCount = commaCount + 1;
        //             idx++;

        //             for (idx; idx < strlen(sequence); idx++)
        //             {
        //                 if (sequence[idx] == 'y' && commaCount == 1 && cCount >= 1)
        //                 {
        //                     yCount = yCount + 1;
        //                 }
        //             }
        //         }
        //     }
        //     else if (sequence[idx] == ',' && cCount >= 1)
        //     {
        //         commaCount = commaCount + 1;
        //     }
        //     else if (sequence[idx] == 'y' && commaCount == 1 && cCount >= 1)
        //     {
        //         yCount = yCount + 1;
        //     }
        //     else if (sequence[idx] == '=' && yCount >= 4 && yCount <= 5 && commaCount == 1 &&
        //                 cCount >=1)
        //     {
        //         equalCount = equalCount + 1;
        //     }
        //     else if (sequence[idx] >= 'A' && sequence[idx] <= 'Z' && equalCount == 2 && 
        //             yCount >= 4 && yCount <= 5 && commaCount == 1 && cCount >=1)
        //     {
        //         capitalCount = capitalCount + 1;
        //     }
        //     else if (idx == strlen(sequence) && capitalCount % 2 == 1 && equalCount == 2 && 
        //             yCount >= 4 && yCount <= 5 && commaCount == 1 && cCount >=1)
        //     {
        //         printf("yay\n");
        //         break;
        //     }
        //     else 
        //     {
        //         isValid = 0;
        //         printf("no\n");
        //         break;
        //     }

        //     idx++;
        // }