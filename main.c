#define Info(P)  (P)->Info
#define Next(P)  (P)->Next
#define Top(S)   (S).Top
#define Max(S)   (S).Max
#define Count(S) (S).Count
#define Nil  NULL

#define bool unsigned short int
#define False 0
#define True  !False

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef int InfoType;

typedef struct tElmStack *Address;

typedef struct tElmStack {
    InfoType Info;
    Address  Next;
} ElmStack;

typedef struct {
    Address Top;
    int     Count;
} Stack;


void CreateStack(Stack *S)
{
    Top(*S) = Nil;
    Count(*S) = 0;
}

bool IsEmpty(Stack S)
{
    return Top(S) == Nil;
}

Address Allocate(InfoType X)
{
    Address P = (Address)malloc(sizeof(ElmStack));
    if (P != Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}

void DeAllocate(Address P)
{
    free(P);
}

void Push(Stack *S, Address P)
{
    Next(P) = Top(*S);
    Top(*S) = P;
    Count(*S)++;
}

void Pop(Stack *S, Address *P)
{
    *P = Top(*S);
    Top(*S) = Next(*P);
    Count(*S)--;
}

void ViewStack(Stack S)
{
    Address P;
    InfoType X[Count(S)];
    int i = 0;
    for (P = Top(S); P != Nil; P = Next(P))
    {
        X[i] = Info(P);
        i++;
    }
    for (i = Count(S) - 1; i >= 0; i--)
        printf("%d ", X[i]);
}

void ViewVisual(Stack S[3], int TotalDisk)
{
    int i, j, k;
    Address P;
    InfoType X[3][TotalDisk];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < TotalDisk - Count(S[i]); j++)
            X[i][j] = 0;
        for (P = Top(S[i]); P != Nil; P = Next(P))
        {
            X[i][j] = Info(P);
            j++;
        }
    }
    for (i = 0; i < TotalDisk; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf(" ");
            if (X[j][i] == 0)
                for (k = 0; k < 2 * TotalDisk - 1; k++)
                    printf(" ");
            else
            {
                for (k = 0; k < TotalDisk - X[j][i]; k++)
                    printf(" ");
                for (k = 0; k < 2 * X[j][i] - 1; k++)
                    printf("%c",170);
                for (k = 0; k < TotalDisk - X[j][i]; k++)
                    printf(" ");
            }
        }
        printf("\n");
    }
    for (i = 1; i <= 3; i++)
    {
        printf(" ");
        for (j = 0; j < TotalDisk - 1; j++)
            printf(" ");
        printf("%d", i);
        for (j = 0; j < TotalDisk - 1; j++)
            printf(" ");
    }
    printf("\n");
}

int main()
{
    int i;
    int CMain, TotalDisk, MFrom, MTo, MCount;
    Address P;

    // membuat 3 stack (tower)
    Stack Tower[3];
    for (i = 0; i < 3; i++)
        CreateStack(&Tower[i]);

    // membuat menu program
    do
    {
        system("cls");
        printf("|=======================================|\n");
        printf("|\t\tTOWER OF HANOI\t\t|\n");
        printf("|=======================================|\n");
        printf("|\t\t1.Mulai Bermain\t\t|\n");
        printf("|\t\t2.Cara Bermain\t\t|\n");
        printf("|\t\t3.Keluar\t\t|\n");
        printf("|=======================================|\n\n");
        printf(" Pilihan : ");
        scanf("%d", &CMain);
        switch (CMain)
        {
        case 1:
            do
            {
                x:
                system("cls");
                printf("================\n");
                printf("    NEW GAME\n");
                printf("================\n");
                printf(" Total Tumpukan: ");
                scanf("%d", &TotalDisk);
                if (TotalDisk <= 0)
                {
                    printf("\n inputan harus lebih besar dari 0.\n");
                    getch();
                }
            }
            while (TotalDisk <= 0);

            if(TotalDisk < 9)
            {// menyisipkan piringan yang telah diinput kedalam stack (tower) pertama
            for (i = 0; i < TotalDisk; i++)
                Push(&Tower[0], Allocate(TotalDisk - i));

            MCount = 0;
            do
            {
                system("cls");
                for (i = 0; i < 3; i++)
                {
                    printf("\n Tower %d: ", i + 1);
                    ViewStack(Tower[i]);
                }
                printf("\n\n");
                ViewVisual(Tower, TotalDisk);
                printf("\n\n Total Pergerakan: %d\n", MCount);
                printf("\n (bergerak) Dari : ");
                scanf("%d", &MFrom);
                printf("\n\t    Ke   : ");
                scanf("%d", &MTo);
                MFrom--;
                MTo--;

                if (MFrom >= 0 && MFrom <= 2 && MTo >= 0 && MTo <= 2)
                {
                    if (!IsEmpty(Tower[MFrom]))
                    {
                        if (IsEmpty(Tower[MTo]))
                        {
                            Pop(&Tower[MFrom], &P);
                            Push(&Tower[MTo], P);
                            MCount++;
                        }
                        else if (Info(Top(Tower[MTo])) > Info(Top(Tower[MFrom])))
                        {
                            Pop(&Tower[MFrom], &P);
                            Push(&Tower[MTo], P);
                            MCount++;
                        }
                        else
                        {
                            printf("\n Invalid move. Please input your move again.\n");
                            system("pause");
                        }
                    }
                }
                else
                {
                    printf("\n Invalid move. Please input move again.\n");
                    system("pause");
                }
            }while (Count(Tower[1]) != TotalDisk && Count(Tower[2]) != TotalDisk);
            system("cls");

            for (i = 0; i < 3; i++)
            {
                printf("\n Tower %d: ", i + 1);
                ViewStack(Tower[i]);
            }
            printf("\n\n");
            ViewVisual(Tower, TotalDisk);
            printf("\n\n Total Pergerakan: %d\n", MCount);
            printf("\n Congratulation, you win!\n\n");
            system("pause");

            while (!IsEmpty(Tower[1]))
            {
                Pop(&Tower[1], &P);
                DeAllocate(P);
            }
            while (!IsEmpty(Tower[2]))
            {
                Pop(&Tower[2], &P);
                DeAllocate(P);
            }
            }
            else {printf("\ninputan terlalu besar\n"); system("pause"); goto x;}
            break;
        case 2:
            system("cls");
            printf("==================================\n");
            printf("        TOWER OF HANOI\n");
            printf("==================================\n\n");
             system("pause");
            break;
        case 3:
            printf("\n Thanks for playing.\n");
             system("pause");
            break;
        default:
            printf("\n Pilihan Tidak Tersedia.\n");
            system("pause");
        }
    }
    while (CMain != 3);
    exit(0);
}
