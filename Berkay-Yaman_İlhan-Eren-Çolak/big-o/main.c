#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
char *remove_white_spaces(char *str)
{
    int i = 0, j = 0;
    while (str[i])
    {
        if (str[i] != ' ')
            str[j++] = str[i];
        i++;
    }
    str[j] = '\0';
    return str;
}
void trim(char *s)
{
    long i = strlen(s) - 1;
    while (i >= 0)
    {
        if (s[i] == ' ' || s[i] == '\n' ||
                s[i] == '\t') i--;
        else break;
    }
    s[i + 1] = '\0';
}
int main(int argc, const char * argv[])
{
    FILE *fptr;
    char *str = malloc(3000*sizeof(char));
    char bigOn[100];
    char bigOn2[100];
    char bigO2n[100];
    char chr;
    int k = 0;
    int i = 0,counter = 0;
    int counter3 = 0,counter4 = 0,counter5 = 0;
    fptr = fopen("/Users/ilhan/Desktop/myfile.txt","r");
    double timeSpent = 0.0;
    clock_t begin = clock();
    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    do
    {
        chr = getc(fptr);
        str[k] = chr;
        k++;
    }
    while (chr != EOF);
    printf("**%s**\n",str);
    int l = 0,m = 0;
    for(l=0; str[l]; l++)
    {
        str[l]=str[l+m];
        if(str[l]==' '|| str[l]=='\t')
        {
            m++;
            l--;
        }
    }
    printf("Without whitespaces : \n");

    printf("%s",str);
    //tek for döngüsü
    int counter2 = 0;
    int counterInt = 0;
    int numberOfArray = 0;
    char arrayIsim[100];
    char arrayIsimleri[10][100];
    // main icin
    while(i < 1000)
    {
        if(str[i] == 'f' && str[i + 1] == 'o' && str[i + 2] == 'r')
        {
            counter++;
//            sayac = i;
//            printf("***%d",sayac);
            char bigOncpy[100] = "o(n)\n";
            strcpy(bigOn,bigOncpy);
        }
        //iç içe for döngüsü
        if (str[i] == 'f' && str[i + 1] == 'o' && str[i + 2] == 'r' && str[i+16] == '{' && str[i + 18] == 'f' && str[i + 19] == 'o' && str[i + 20] == 'r') {
            counter2++;
            char bigOn2cpy[100] = "o(n^2)\n";
            strcpy(bigOn2,bigOn2cpy);
      }
        //do-while döngüsü
        if(str[i] == 'd' && str[i + 1] == 'o' && str[i + 2] == '{'){
            counter3++;
            char bigOncpy[100] = "o(n)\n";
            strcpy(bigOn,bigOncpy);
        }
        //while döngüsü
        if (str[i] == 'w' && str[i + 1] == 'h' && str[i + 2] == 'i' && str[i + 3] == 'l' && str[i + 4] == 'e') {
            counter4++;
            char bigOncpy[100] = "o(n)\n";
            strcpy(bigOn,bigOncpy);
        }
        //recursive fonskiyon
        if (str[i] == 'f' && str[i + 1] == 'i' && str[i+2] == 'b' && str[i + 3] == 'o' && str[i + 4] == 'n') {
            counter5++;
            char bigO2ncpy[100] = "o(2^n)\n";
            strcpy(bigO2n, bigO2ncpy);

        }

        if( str[i-1] != 'r' && str[i] == 'i' && str[i + 1] == 'n' && str[i + 2] == 't')
        {
            counterInt += 1;
            int control = i+3;

            while(str[control] != ';'  && str[control] != '(')
            {
                if(str[control] == '[')
                {
                    numberOfArray+=1;
                    int controlInArray = control+1;
                    int arrayControl = 0;
                    while(str[controlInArray] != ']')
                    {
                        //printf("%c", str[controlInArray]);

                        arrayIsim[arrayControl] = str[controlInArray];

                        arrayControl+=1;
                        controlInArray+=1;
                    }
                    printf("\nNumber of array : %d", numberOfArray);
                    strcpy(arrayIsimleri[numberOfArray-1], arrayIsim);
                    //strcpy(a[1], "hmm");
                    //arrayIsimleri[numberOfArray-1][0] = arrayIsim;
                    break;
                }
                else if(str[control] == ',')
                {
                    counterInt+=1;
                }
                else if(str[control+1] == ')' || str[control+1] == '(' )
                {
                    counterInt -=1;
                    break;
                }

                //printf("\nharfler : %c" , str[control]);
                control+=1;
            }
        }



        i++;
    }
    printf("\nFor sayisi : %d\n", counter);
    printf("Ic ice for sayisi : %d\n", counter2);
    printf("Do while dongu sayisi : %d\n",counter3);
    printf("While dongu sayisi : %d\n",counter4);
    clock_t end = clock();
    timeSpent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Spending time : %f seconds\n", timeSpent);

        if(counter5 > 0)
        {
            printf("Big o notasyonu : %s",bigO2n);
        }
        else if(counter2 > 0){
            printf("Big o notasyonu : %s",bigOn2);
        }
        else if (counter > 0)
        {
            printf("Big o notasyonu : %s",bigOn);
        }

    printf("Int degisken sayisi : %d\n", (counterInt - numberOfArray));
    printf("Int array sayisi : %d\n", numberOfArray);

    if(numberOfArray > 0)
        {
            printf("yer karmasikligi =  4 * (");
            for(int i = 0; i < numberOfArray; i++)
            {
//                printf("%s", arrayIsimleri[i]);
                if(i != numberOfArray-1)
                    printf(" + ");
            if(counter5 >0)
            {
                printf("2^n");
            }
            else if(counter2 > 0){
                printf("n^2");
            }
            else if(counter > 0){
                printf("n");
            }

            printf(") +  %d", (4 * (counterInt - numberOfArray)));
            }}
        else{
            printf("\nyer karmasikligi = n + %d", (4 * (counterInt - numberOfArray)));
        }
        fclose(fptr);

    return 0;

}
