#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[])
{
    char mode = '\0';
    int translation = 0;
    int isValid = 1;
    char* sequence = "";
    int i = 0;
    
    for (i = 1; i < argc ; i++)
    {
        if (argv[i][0] == '-')
        {
            if (argv[i][1] == 'a' || argv[i][1] == 'b' || argv[i][1] == 'c')
            {
                mode = argv[i][1];
            }
            else if ( argv[i][1] == 't')
            {
                translation = 1;
            } 
        }
        else
        {
            sequence = argv[i];
        }
    }

    if (mode == 'a' || mode == '\0')
    {
        int yCount = 0;
        int capitalCount = 0;
        int idx = 0;

        if (sequence[idx++] != 'c')
        {
            isValid = 0;
        }

        while(isValid && sequence[idx] == 'c')
        {
            ++idx;
        }

        if (isValid && sequence[idx++] != ',')
        {
            isValid = 0;
        }

        while (1)
        {
            if (isValid == 0)
            {
                break;
            }

            if (sequence[idx] == 'y')
            {
                ++idx;
                ++yCount;
            } else {
                break;
            }
        }

        if (isValid && (yCount < 4 || yCount > 5))
        {
            isValid = 0;
        }

        if (isValid && sequence[idx++] != '=')
        {
            isValid = 0;
        }

        if (isValid && sequence[idx++] != '=')
        {
            isValid = 0;
        }

        while (1)
        {
            if (isValid == 0)
            {
                break;
            }

            if (sequence[idx] >= 'A' && sequence[idx] <= 'Z')
            {
                ++capitalCount;
                ++idx;
            } else {
                break;
            }
        }

        if (isValid && capitalCount % 2 == 0)
        {
            isValid = 0;
        }

        if (idx != strlen(sequence))
        {
            isValid = 0;
        }

        if (isValid)
        {
            if (translation == 1)
            {
                int iter = strlen(sequence);
                for (iter; iter >= 0; iter--)
                {
                    printf("%c", sequence[iter]);
                }
                
                printf("\n");
            }
            else
            {
                printf("yes\n");
            }
        }
        else if (isValid == 0)
        {
            printf("no\n");
        }
    }
    else if (mode == 'b')
    {
        int aCount = 0;
        int Xcount = 0;
        char X[1024];
        char reversedX[1024];
        int decimalCount = 0;
        int idx = 0;

        if (sequence[idx++] != 'a')
        {
            isValid = 0;
        }

        while (1)
        {
            if (isValid == 0)
            {
                break;
            }

            if (sequence[idx] == 'a')
            {
                ++idx;
                ++aCount;
            } else {
                break;
            }
        }

        if (isValid && (aCount < 4 || aCount > 5))
        {
            isValid = 0;
        }

        if (isValid && (sequence[idx++] != ':' || sequence[idx++] != ':'))
        {
            isValid = 0;
        }

        while (1)
        {
            if (isValid == 0)
            {
                break;
            }

            if (sequence[idx] >= 'A' && sequence[idx] <= 'Z')
            {
                X[Xcount++] = sequence[idx];
                ++idx;
            } else {
                break;
            }
        }

        if (isValid && strlen(X) % 2 == 0)
        {
            isValid = 0;
        }

        if (sequence[idx++] != 'r')
        {
            isValid = 0;
        }

        while(isValid && sequence[idx] == 'r')
        {
            ++idx;
        }

        if (isValid && (sequence[idx++] != '_' || sequence[idx++] != '_'))
        {
            isValid = 0;
        }

        while (1)
        {
            if (isValid == 0)
            {
                break;
            }

            int reverseIdx = 0;

            if (sequence[idx] == X[Xcount-1])
            {
                reversedX[reverseIdx] = X[Xcount-1];
                ++idx;
                ++reverseIdx;
                if (Xcount != 0)
                {
                    --Xcount;
                }
            } else {
                break;
            }
        }

        if (isValid && sizeof(X)/sizeof(X[0]) != sizeof(reversedX)/sizeof(reversedX[0]))
        {
            isValid = 0;
        }

        while (1)
        {
            if (isValid == 0)
            {
                break;
            }

            if (sequence[idx] >= '0' && sequence[idx] <= '9')
            {
                ++idx;
                ++decimalCount;
            } else {
                break;
            }
        }

        if (isValid && (decimalCount < 1 || decimalCount > 3))
        {
            isValid = 0;
        }

                if (isValid)
        {
            if (translation == 1)
            {
                int iter = 0;
                for (iter; iter < strlen(sequence); iter++)
                {
                    printf("%c", sequence[iter]);

                    if (sequence[iter] == 'C')
                    {
                        printf("%c", 'D');
                    }
                }
                
                printf("\n");
            }
            else
            {
                printf("yes\n");
            }
        }
        else if (isValid == 0)
        {
            printf("no\n");
        }
    }
    else if (mode == 'c')
    {

    }
}