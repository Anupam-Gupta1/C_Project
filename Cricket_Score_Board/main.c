#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

int sumI = 0;
int cWI = 0;
int sumE = 0;
int cWE = 0;

void total1()
{
    FILE *fp;
    fp = fopen("F://Cricket_Score_Board//Data//team1_Score.txt","r");
    for(int i = 0; i < 11; i++)
    {
        char s[10];
        fscanf(fp,"%s",s);
        int r = atoi(s);
        sumI += r;
    }
}

void wicket1()
{

    FILE *fp;
    fp = fopen("F://Cricket_Score_Board//Data//team2_Bowl.txt","r");
    for(int i = 0; i < 6; i++)
    {
        char st[10];
        fscanf(fp,"%s",st);
        int l = strlen(st);
        char c = st[l-1];
        int w = c - '0';
        cWI += w;
    }
}

void total2()
{
    FILE *fp;
    fp = fopen("F://Cricket_Score_Board//Data//team2_Score.txt","r");
    for(int i = 0; i < 11; i++)
    {
        char s[10];
        fscanf(fp,"%s",s);
        int r = atoi(s);
        sumE += r;
    }
}

void wicket2()
{

    FILE *fp;
    fp = fopen("F://Cricket_Score_Board//Data//team1_Bowl.txt","r");
    for(int i = 0; i < 6; i++)
    {
        char st[10];
        fscanf(fp,"%s",st);
        int l = strlen(st);
        char c = st[l-1];
        int w = c - '0';
        cWE += w;
    }
}

void previous()
{
    system("cls");
    printf("\n\n\n\n\n\t\t\t\t\tWhat Would You like to See");
    printf("\n\n\n\n\n\t\t\t\t\t1.Show India Score Card\n\t\t\t\t\t2.Show England Score Card\n\t\t\t\t\t3.Show Result of the match\n\t\t\t\t\t4.Return To Main Menu\n\t\t\t\t\t5.Exit\n\n\n\n\t\t\t\t\tEnter Your Choice:");
    int c;
    scanf("%d",&c);
    switch(c)
    {
        case 1:
            India();
            break;
        case 2:
            England();
            break;
        case 3:
            Result();
            break;
        case 4:
            menu();
            break;
        case 5:
            exit(0);
            break;
    }
}
void India()
{
    FILE *fp1,*fp2,*fp3;
    fp1 = fopen("F://Cricket_Score_Board//Data//team1.txt","r");
    fp2 = fopen("F://Cricket_Score_Board//Data//team1_Score.txt","r");
    fp3 = fopen("F://Cricket_Score_Board//Data//team2_Bowl.txt","r");
    system("cls");
    total1();
    wicket1();
    printf("\t\tINDIA\t%d-%d\n",sumI,cWI);
    printf("------------------------------------------------------------------------\n");
    printf("Batsman\t\t|\tRuns\t\t|\tBowler-Runs-Wicket\t|\n");
    for(int i = 0; i < 11; i++)
    {
        char str[100],str1[10],str2[10],c;
        int r;
        fscanf(fp1,"%s",str);
        fscanf(fp2,"%s",str1);
        r = atoi(str1);
        fscanf(fp3,"%s",str2);
        if(c = getc(fp3) != EOF)
        {
            printf("------------------------------------------------------------------------\n");
            printf("%s\t\t|\t%d\t\t|\t%s\t\t|\n",str,r,str2);
        }
        else
        {
            printf("------------------------------------------------------------------------\n");
            printf("%s\t\t|\t%d\t\t|\t\t\t\t|\n",str,r);
        }
    }
    printf("------------------------------------------------------------------------\n");
    printf("\n\n\n\n\n\t\t\t\t\tWould You like to Return to the previous screen?");
    int n;
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            previous();
            break;
        case 0:
            exit(0);
            break;
    }
}

void England()
{
    FILE *fp1,*fp2,*fp3;
    fp1 = fopen("F://Cricket_Score_Board//Data//team2.txt","r");
    fp2 = fopen("F://Cricket_Score_Board//Data//team2_Score.txt","r");
    fp3 = fopen("F://Cricket_Score_Board//Data//team1_Bowl.txt","r");
    system("cls");
    total2();
    wicket2();
    printf("\t\tENGLAND\t%d-%d\n",sumE,cWE);
    printf("------------------------------------------------------------------------\n");
    printf("Batsman\t\t|\tRuns\t\t|\tBowler-Runs-Wicket\t|\n");
    for(int i = 0; i < 11; i++)
    {
        char str[100],str1[10],str2[10],c;
        int r;
        fscanf(fp1,"%s",str);
        fscanf(fp2,"%s",str1);
        r = atoi(str1);
        fscanf(fp3,"%s",str2);
        if(c = getc(fp3) != EOF)
        {
            printf("------------------------------------------------------------------------\n");
            printf("%s\t\t|\t%d\t\t|\t%s\t\t|\n",str,r,str2);
        }
        else
        {
            printf("------------------------------------------------------------------------\n");
            printf("%s\t\t|\t%d\t\t|\t\t\t\t|\n",str,r);
        }
    }
    printf("------------------------------------------------------------------------\n");
    printf("\n\n\n\n\n\t\t\t\t\tWould You like to Return to the previous screen?");
    int n;
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            previous();
            break;
        case 0:
            exit(0);
            break;
    }
}

void Result()
{
    system("cls");
    printf("------------------------------------------------------------------------\n");
    printf("\t\tINDIA\t%d-%d\n",sumI,cWI);
    printf("------------------------------------------------------------------------\n");
    printf("\t\tENGLAND\t%d-%d\n",sumE,cWE);
    printf("------------------------------------------------------------------------\n");
    if(sumI > sumE)
    {
        printf("\n\n\n\n\t\t!!!!!!!!!!INDIA WON!!!!!!!!!!!!!!\n");
    }
    else if(sumI == sumE)
    {
        if(cWI < cWE)
        {
            printf("\n\n\n\n\t\t!!!!!!!!!!INDIA WON!!!!!!!!!!!!!!\n");
        }
        else if(cWE < cWI)
        {
            printf("\n\n\n\n\t\t!!!!!!!!!!ENGLAND WON!!!!!!!!!!!!!!\n");
        }
        else
        {
            printf("\n\n\n\n\t\t!!!!!!!!!!THE MATCH IS A TIE!!!!!!!!!!!!!!\n");
        }
    }
    else
    {
        printf("\n\n\n\n\t\t!!!!!!!!!!ENGLAND WON!!!!!!!!!!!!!!\n\n\n\n");
    }
    printf("\n\n\n\n\t\t\t\t\tWould You like to Return to the previous screen?");
    int n;
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            previous();
            break;
        case 0:
            exit(0);
            break;
    }
}

void delay(int i)
{
    int j,k;
    for(j = 0; j < i; j++)
        k = j;
}

void menu()
{
    int a;
    printf("\n\t\t\t\t\tPRESS ANY KEY TO CONTINUE...");
    getchar();
    delay(100000000);
    system("cls");
    printf("\n\n\n\n\n\t\t\t\t\tWELCOME TO MAIN MENU");
    printf("\n\n\n\n\n\t\t\t\t\t1.Show Previous Score\n\t\t\t\t\t2.Input New Score\n\t\t\t\t\t3.Exit\n\n\n\n\t\t\t\t\tEnter Your Choice:");
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        previous();
        break;
    /**case 2:
        new_input();
        break;*/
    case 3:
        exit(0);
        break;
    }
}

int main()
{
    int i;
    printf("\n\n\n\n\n\n\n\n\n\t\t\t\t\tWelcome");
    for(i = 0;i <= 6; i++)
    {
    delay(200000000);
    printf(".");
    }
    printf("\n\n\n\n\t\t\t\t\tTo");
    printf("\n\t\t\t\t\tCricket Score Board");
    printf("\n\t\t\t\t\tOf T20 Match Between India and England");

    menu();
    return 0;
}
