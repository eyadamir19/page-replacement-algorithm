#include <stdio.h>


// First in First out
int FIFO() {
    int i, j, No_of_Pages, arr[50], f[10], No_of_Frames, k, rem, count = 0;
    printf("\n How Many Pages ? \n");
    scanf("%d", &No_of_Pages);
    printf("\n What are the Page numbers \n");
    for (i = 1; i <= No_of_Pages; i++)
        scanf("%d", &arr[i]);
    printf("\n How Many Frames ? :");
    scanf("%d", &No_of_Frames);
    for (i = 0; i < No_of_Frames; i++)
        f[i] = -1;
    j = 0;
    printf("\n ref   \t page frames ");
    for (i = 1; i <= No_of_Pages; i++)
    {
        printf("%d\t\t", arr[i]);
        rem = 0;
        for (k = 0; k < No_of_Frames; k++)
            if (f[k] == arr[i])
            {
                rem = 1;
                for (k = 0; k < No_of_Frames; k++)
                    printf("%d\t", f[k]);

            }
        if (rem == 0)
        {
            f[j] = arr[i];
            j = (j + 1) % No_of_Frames;
            count++;
            for (k = 0; k < No_of_Frames; k++)
                printf("%d\t", f[k]);

        }
        printf("\n");
    }
    printf("Total Page Pfaults = %d", count);
    return 0;
}
// Least Recently Used
int lru()
{
    int findLRU(int t[], int n) {
        int i, min = t[0], p = 0;

        for (i = 1; i < n; ++i) {
            if (t[i] < min) {
                min = t[i];
                p = i;
            }
        }
        return p;
    }


    int fno, pno, frames[10], pages[30], counter = 0, t[10], f1, f2, i, j, po, Pfaults = 0;

    printf("How many Pages ?");
    scanf("%d", &pno);
    printf("what are the page numbers ");
    for (i = 0; i < pno; ++i) {
        scanf("%d", &pages[i]);
    }
    printf("how many frames ? ");
    scanf("%d", &fno);


    for (i = 0; i < fno; ++i) {
        frames[i] = -1;
    }

    for (i = 0; i < pno; ++i) {
        f1 = f2 = 0;

        for (j = 0; j < fno; ++j) {
            if (frames[j] == pages[i]) {
                counter++;
                t[j] = counter;
                f1 = f2 = 1;
                break;
            }
        }

        if (f1 == 0) {
            for (j = 0; j < fno; ++j) {
                if (frames[j] == -1) {
                    counter++;
                    Pfaults++;
                    frames[j] = pages[i];
                    t[j] = counter;
                    f2 = 1;
                    break;
                }
            }
        }

        if (f2 == 0) {
            po = findLRU(t, fno);
            counter++;
            Pfaults++;
            frames[po] = pages[i];
            t[po] = counter;
        }

        printf("\n");

        for (j = 0; j < fno; ++j) {
            printf("%d\t", frames[j]);
        }
    }
    printf("\n\nNumber of PagePfaults = %d", Pfaults);

    return 0;
}
//Optimal Algorithm
int OPTIMAL()
{

    int fno, pno, frames[10], pages[30], te[10], f1, f2, f3, i, j, k, p, m, Pfaults = 0;

    printf("How Many Pages ?");
    scanf("%d", &pno);
    printf("What are the Page Numbers ?");
    for (i = 0; i < pno; ++i) {
        scanf("%d", &pages[i]);
    }
    printf("How Many Frames ? ");
    scanf("%d", &fno);


    for (i = 0; i < fno; ++i) {
        frames[i] = -1;
    }

    for (i = 0; i < pno; ++i) {
        f1 = f2 = 0;

        for (j = 0; j < fno; ++j) {
            if (frames[j] == pages[i]) {
                f1 = f2 = 1;
                break;
            }
        }

        if (f1 == 0) {
            for (j = 0; j < fno; ++j) {
                if (frames[j] == -1) {
                    Pfaults++;
                    frames[j] = pages[i];
                    f2 = 1;
                    break;
                }
            }
        }

        if (f2 == 0) {
            f3 = 0;

            for (j = 0; j < fno; ++j) {
                te[j] = -1;

                for (k = i + 1; k < fno; ++k) {
                    if (frames[j] == pages[k]) {
                        te[j] = k;
                        break;
                    }
                }
            }

            for (j = 0; j < fno; ++j) {
                if (te[j] == -1) {
                    p = j;
                    f3 = 1;
                    break;
                }
            }

            if (f3 == 0) {
                m = te[0];
                p = 0;

                for (j = 1; j < fno; ++j) {
                    if (te[j] > m) {
                        m = te[j];
                        p = j;
                    }
                }
            }
            frames[p] = pages[i];
            Pfaults++;
        }

        printf("\n");

        for (j = 0; j < fno; ++j) {
            printf("%d\t", frames[j]);
        }
    }

    printf("\n No of  Pagefaults = %d", Pfaults);

    return 0;


}
int main()
{
    int choice;
    printf("Enter your Choice");
    printf("\n1: FIFO\n");
    printf("2: LRU\n");
    printf("3: OPTIMAL\n");
    scanf("%d", &choice);


    switch (choice)
    {
    case 1:
        printf("You have chosen FIFO \n \n");
        FIFO();
        break;

    case 2:
        printf("You have chosen LRU \n \n");
        lru();
        break;


    case 3:
        printf("You have chosen OPTIMAL \n \n");
        OPTIMAL();
        break;

    default:
        printf("Error! operator is not correct");
    }

    return 0;
}