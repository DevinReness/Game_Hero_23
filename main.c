#include <stdio.h>
#include <stdlib.h>

struct charakter
{
    int pow;
    int att;
    int def;
};

int main()
{
    struct charakter hero[2];
    int a,b,c;
    char x[2],z[2];
    printf("\t||Hero  |  A  |  B  |  C  |  D  |  E  ||\n");
    printf("\t||------|-----|-----|-----|-----|-----||\n");
    printf("\t||Power | 200 | 200 | 200 | 200 | 200 ||\n");
    printf("\t||Attack|  50 |  40 |  60 |  90 |  20 ||\n");
    printf("\t||Def   |  20 |  40 |  30 |  10 |  90 ||\n\n");
    printf("START GAME\n\nPilih Hero dan Enemy \n\n");
    for(a=0;a<2;a++)
    {
        fflush(stdin);
        if(a==0)
        printf("Hero  :%d)",a+1);
        else
        printf("Enemy :%d)",a+1);
        scanf("%c",&x[a]);
        if(x[a]=='a'||x[a] == 'A'){hero[a].pow=200;hero[a].att=50;hero[a].def=20; }
        if(x[a]=='b'||x[a] == 'B'){hero[a].pow=200;hero[a].att=40;hero[a].def=40; }
        if(x[a]=='c'||x[a] == 'C'){hero[a].pow=200;hero[a].att=60;hero[a].def=30; }
        if(x[a]=='d'||x[a] == 'D'){hero[a].pow=200;hero[a].att=90;hero[a].def=10; }
        if(x[a]=='e'||x[a] == 'E'){hero[a].pow=200;hero[a].att=20;hero[a].def=90; }
    }
    do
    {
        v:
        system("cls");
        printf("\n\t\t\t PLAY GAME \n");
        printf("\t\t_________________________\n\n");
        printf("\t-----------------------------------------\n");
        printf("\tCarakter |\tHero %c\t|\tEnemy %c\t|\n",x[0],x[1]);
        printf("\tPower\t |\t%d\t|\t%d\t|\n",hero[0].pow,hero[1].pow);
        printf("\tAttack\t |\t%d\t|\t%d\t|\n",hero[0].att,hero[1].att);
        printf("\tDefense\t |\t%d\t|\t%d\t|\n",hero[0].def,hero[1].def);
        printf("\t-----------------------------------------\n");
        printf("Choice : \nAttack = (a)\nDefend = (d) \n\n");
        for(a=0;a<2;a++)
        {
           fflush(stdin);
                if(a==0)
                    printf("Hero  %c :",x[a]);
                else
                    printf("Enemy %c :",x[a]);
                scanf("%c",&z[a]);
        }
        if((z[0]=='a'||z[0]=='A')&& (z[1]=='d'||z[1]=='D'))
          {
            b = hero[1].def - hero[0].att;
            if(b<0)
                hero[1].pow += b;
            else
                hero[0].pow -= b;

                hero[0].pow -= 10;
                hero[1].pow -= 10;
          }

          else if ((z[0]=='d'||z[0]=='D')&& (z[1]=='a'||z[1]=='A'))
            {
                b = hero[0].def - hero[1].att;
                if(b<0)
                    hero[0].pow += b;
                else

                    hero[1].pow -= b;

                hero[0].pow -= 10;
                hero[1].pow -= 10;

            }

           else if ((z[0]=='a'||z[0]=='A')&& (z[1]=='a'||z[1]=='A'))
            {
                hero[0].pow = hero[0].pow - hero[1].att;
                hero[1].pow = hero[1].pow - hero[0].att;

                hero[0].pow -= 10;
                hero[1].pow -= 10;
            }

            else if ((z[0]=='d'||z[0]=='D')&& (z[1]=='d'||z[1]=='D'))
            {
                hero[0].pow -= 10;
                hero[1].pow -= 10;
            }

            else
            {
                goto v;
            }
          printf("power Hero  %c :%d\n",x[0],hero[0].pow);
          printf("power Enemy %c :%d\n\n",x[1],hero[1].pow);
          system("pause");

    }while(hero[0].pow >= 0 && hero[1].pow >= 0);

    if(hero[0].pow > hero[1].pow)
        printf("\nHero %c Menang!!",x[0]);
    else if(hero[1].pow > hero[0].pow)
         printf("\nEnemy %c Menang!!",x[1]);
    exit(0);
}

