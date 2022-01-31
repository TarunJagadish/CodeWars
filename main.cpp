///all header files included
#include <iostream>///needed for input and output in general
#include <conio.h>///needed for console input and output
#include <windows.h>///needed for clearing the screen and keyboard inputs(GetAsyncKeyState(int vK))
#include <string.h>///needed for string manipulation
#include <fstream>///needed for creating and manipulating files
#include <stdio.h>///needed for standard functions like gets(char*) and puts(char*)

///for console output and console input
using namespace std;

///all global variables required for the program to work///

char intro[10][100]={"---------------------------------------------------------------","CCCCCC OOOOOO DDDD   EEEEEE W     W     A     RRRRRRR SSSSSS   ","CC     O    O D   D  E      W     W    A A    R     R S        ","CC     O    O D    D EEEEEE W  W  W   AAAAA   RRRRRRR SSSSSS   ","CC     O    O D   D  E      W  W  W  A     A  R   R        S   ","CCCCCC OOOOOO DDDD   EEEEEE WWWWWWW A       A R     R SSSSSS   ","-------------------------------------------------------------- "};
///used for moving logo around the screen
char space[100]=" ";///for moving logo left and right
char tempspace[100]="";///to reduce length of space

int k,i,r,j,u;///string loop variables

char map[20][50]={
"#################################################",
"# @                                             #",
"#                                               #",
"#                                               #",
"####################                 ############",
"#                  #                            #",
"#                  #                            #",
"#                  #                            #",
"#                  ################             #",
"#############                        ############",
"#                          O                    #",
"#                                               #",
"#                                               #",
"#########                      ########         #",
"#                                               #",
"#                                               #",
"#                  #########                    #",
"#                                               #",
"#                                               #",
"#################################################"} ;
///map of the game

int gamespeed=0;///alter this to make the game faster or slower (controls the delayLoop())

int x,y,xtemp,ytemp,cposx=27,cposy=10,pposx=2,pposy=1,initcposx=27,initcposy=10,initpposx=2,initpposy=1;///all position variables

bool stopgame=false;///to keep the game loop going

float chp=100.0;///computer hp, is 100 for easy, 150 for medium and 200 for expert.

int ammo;///300 for easy mode, 200 for medium, 100 for expert

float pdmg=4.0;///will be set by active codeBlaster, is 4.0 by default

float cdmg;///will be set by difficulty level, 4.0 for easy, 6.0 for medium and 10.0 for hard

int armor=0;///can buy from CodeStore, reduces 25% of computer bullet damage, can also be poison

int difficulty=1;///1 is easy, 2 is medium, 3 is expert

int score=0;///win a game, get a score! lose a game, get a 0 :P

int codeCoin=100;///increased by winning games

int victor=0;///by default is 0->lose. 1-> win

float php=100.0;///100.0 by default, can be increased by purchasing health packs

int temphp=0;///stores health packs inputted by user

int bombs=5;///5 by default, more can be purchased from the CodeStore

int tempbombs=0;///used for buying bombs from CodeStore

int numOfScores=0;///used to assign player number and to count number of scores in the Scores file.

int extrabombs=0;///stores the total number of extra bombs bought from the CodeStore

int healthpack=0;///stores the total number of health packs (each is 20 hp) bought from CodeStore

char blasterName[50]="Default";///stores the name of CodeBlaster, is Default by default

struct Player///Provides a blueprint for a Player object that stores all details of a particular player
{
    char playerName[50];///stores the player's name
    int playerScore;///stores the score of the particular player
    int playerDifficulty;///stores the difficulty of the particular player
    int playerNumber;///is used for unique identification of players
};

Player p;///object of player

///variables end here///

class StartUp///for the intro
{
    public:
    void moveRight()///to move logo right
    {
        for(k=1;k<100;k++)
        {
            for(i=0;i<7;i++)
            {
                cout<<space;
                cout<<intro[i];
                cout<<"\n";
            }
            cout<<endl;
            strcat(space," ");
            fastdelay();
            system("cls");
        }
    }

    void moveDown()///to move logo down
    {
        for(k=0;k<35;k++)
        {

            for(r=0;r<=k;r++)
            {
                cout<<"\n";
            }

            for(i=0;i<7;i++)
            {
                cout<<space;
                cout<<intro[i];
                cout<<"\n";
            }
            fastdelay();
            system("cls");
        }
        system("cls");
    }

    void moveLeft()///to move logo left
    {
        for(k=100;k>0;k--)
        {
            for(j=0;j<r;j++)
            {
                cout<<"\n";
            }
            for(i=0;i<7;i++)
            {
                cout<<space;
                cout<<intro[i];
                cout<<"\n";
            }
            if(strlen(space)!=1)
            {
                for(u=0;u<strlen(space)-1;u++)
                {
                    tempspace[u]=space[u];
                }
                tempspace[u]='\0';
                strcpy(space,tempspace);
            }
            fastdelay();
            system("cls");
        }
        system("cls");
    }

    void moveUp()///to move logo up
    {
        for(k=0;k<35;k++)
        {
            for(r=35;r>=k;r--)
            {
                cout<<"\n";
            }
            for(i=0;i<7;i++)
            {
                cout<<intro[i];
                cout<<"\n";
            }
            fastdelay();
            system("cls");
        }
    }

    void firstPrint()///as the first print of the logo
    {
        cout<<"-------------------------------------------------------------- \n";
        cout<<"CCCCCC OOOOOO DDDD   EEEEEE W     W     A     RRRRRRR SSSSSS   \n";
        cout<<"CC     O    O D   D  E      W     W    A A    R     R S        \n";
        cout<<"CC     O    O D    D EEEEEE W  W  W   AAAAA   RRRRRRR SSSSSS   \n";
        cout<<"CC     O    O D   D  E      W  W  W  A     A  R   R        S   \n";
        cout<<"CCCCCC OOOOOO DDDD   EEEEEE WWWWWWW A       A R     R SSSSSS   \n";
        cout<<"-------------------------------------------------------------- \n";
    }

    void mainPrint()///used to beautify the main menu
    {
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\n";
        cout<<"                                                   -------------------------------------------------------------- \n";
        cout<<"                                                   CCCCCC OOOOOO DDDD   EEEEEE W     W     A     RRRRRRR SSSSSS   \n";
        cout<<"                                                   CC     O    O D   D  E      W     W    A A    R     R S        \n";
        cout<<"                                                   CC     O    O D    D EEEEEE W  W  W   AAAAA   RRRRRRR SSSSSS   \n";
        cout<<"                                                   CC     O    O D   D  E      W  W  W  A     A  R   R        S   \n";
        cout<<"                                                   CCCCCC OOOOOO DDDD   EEEEEE WWWWWWW A       A R     R SSSSSS   \n";
        cout<<"                                                   -------------------------------------------------------------- \n";
    }

    void mainEntrance()///calls functions to move logo around the screen
    {
        firstPrint();
        fastdelay();
        system("cls");
        moveRight();
        moveDown();
        moveLeft();
        moveUp();
    }

    void fastdelay()///provides a quick delay
    {
        long int l;
        for(l=0;l<=800000L;l++)
        {
            ;
        }
    }

    void mediumdelay()///provides a mediocre length delay
    {
        long L;
        for(L=0; L<=90000000L;L++)
        {
            ;
        }
    }

    void longdelay()///provides a long delay
    {
        long l;
        for(l=0; l<=599999999L;l++)
        {
            ;
        }
    }
};

class Outro///used for the outro
{
    public:
    void ending()///to display ending messages and erase them
    {
        system("cls");
        char kr[10][100]={ "\n\n\n\n\n\t\t\t\t\t\t *  Thank you for playing the Game!  *   ","\n\n\n\n\n\t\t\t\t\t\t  *       Hope you enjoyed it!       *   ","\n\n\n\n\n\t\t\t\t\t\t   *  Goodbye and have a nice day!  *    ","\n\n\n\n\n\t\t\t\t\t\t                :-)                   "};
        int i,j;
        char a[100];
        for(i=0;i<4;i++)
        {
            cout<<kr[i];
            delaySlow();
            kr[i][strlen(kr[i])-1]=' ';
            strcpy(a,kr[i]);
            for(j=0;j<strlen(kr[i]);j++)
            {
                a[strlen(a)-1-j]=' ';
                system("cls");
                cout<<a;
                delayFast();
            }
            system("cls");
        }
        system("cls");
        cout<<endl;
    }

    private:

    void delayFast()///for a quick delay
    {
        long l;
        for(l=0;l<=15000000L;l++)///15 million
        {
            ;
        }
    }

    void delaySlow()///for a long delay
    {
        long l;
        for(l=0;l<=59999999L;l++)///60 million-1
        {
            ;
        }
    }
};


class HighScores
{
public:
void countScores()
{
    Player y;
    fstream f("Scores.dat",ios::in|ios::binary);
    if(f!=NULL)
    {
        while(f.read((char*)&y,sizeof(y)))
        numOfScores++;
    }
    else
    numOfScores=0;
    f.close();
}

void displayScores()
{
    fstream f("Scores.dat",ios::in|ios::binary);
    Player q;
    cout<<"\n\n";
    cout<<"Player Number\tScore\t\tDifficulty\tPlayer Name\n\n";
    while(f.read((char*)&q,sizeof(q)))
    {
        cout<<q.playerNumber<<"\t\t";
        cout<<q.playerScore<<"\t\t";
        if(q.playerDifficulty==1)
        cout<<"Easy\t\t";
        else if(q.playerDifficulty==2)
        cout<<"Medium\t\t";
        else
        cout<<"Expert\t\t";
        cout<<q.playerName<<"\n";
    }
    f.close();
}

void deleteAllScores()
{
    fstream f("Scores.bak",ios::out|ios::binary);
    remove("Scores.dat");
    rename("Scores.bak","Scores.dat");
}

void addScore(Player p)
{
    int c=1,fileIndicator=1;
    Player r;
    fstream fout("Scores.bak",ios::out|ios::binary);
    fstream fin("Scores.dat",ios::in|ios::binary);
    if(fin!=NULL)
    {
        while(fin.read((char*)&r,sizeof(r)))
        {
            if(r.playerScore>p.playerScore)
            {
                fout.write((char*)&r,sizeof(r));
            }
            else
            {
                if(c==1)
                {
                    fout.write((char*)&p,sizeof(p));
                    c=0;
                    fout.write((char*)&r,sizeof(r));
                }
                else
                {
                    fout.write((char*)&r,sizeof(r));
                }
            }
        }
        if(c==1)
        fout.write((char*)&p,sizeof(p));
    }
    else
    {
        fout.write((char*)&p,sizeof(p));
        fileIndicator=0;
    }
    fout.close();
    fin.close();
    if(fileIndicator!=0)
    {
        remove("Scores.dat");
    }
    rename("Scores.bak","Scores.dat");
}

void deleteParticularScore(int no)
{
    Player x;
    fstream fout("Scores.bak",ios::out|ios::binary);
    fstream fin("Scores.dat",ios::in|ios::binary);
    if(fin!=NULL)
    {
        while(fin.read((char*)&x,sizeof(x)))
        {
            if(x.playerNumber!=no)
            {
                fout.write((char*)&x,sizeof(x));
            }
        }
    }
    else
    {
        cout<<"No Scores to delete...\n";
    }
    fin.close();
    fout.close();
    remove("Scores.dat");
    rename("Scores.bak","Scores.dat");
}

};


class CodeStore
{
    public:

    void storeMenu()
    {
        int storech;
        do
        {
            cout<<"                                               CODESTORE\n\n\n";
            cout<<"                                         1.CodeBlasters\n";
            cout<<"                                         2.Armor\n";
            cout<<"                                         3.Bombs\n";
            cout<<"                                         4.HealthPack\n";
            cout<<"                                         5.EXIT\n\n\n";
            cout<<"YOU HAVE  "<<codeCoin<< " CodeCoins "<<endl;
            cout<<"ENTER YOUR CHOICE:"<<endl;
            cin>>storech;
            switch(storech)
            {
                case 1:
                blasterShop();
                break;

                case 2:
                system("cls");
                cout<<"Enter 1 to purchase armor (damage received reduced by 25%) for 200 CodeCoins.\nEnter 0 to go back to the store: "<<endl;
                cout<<"You have "<<codeCoin<<" CodeCoins "<<endl;
                cin>>armor;
                if(armor!=0&&armor!=1)
                {
                    armor=2;
                    cout<<"Poison armor has been activated for not choosing a valid option >:). Enter anything to continue:"<<endl;
                }
                else if(armor==0)
                {
                    cout<<"No armor? Enter anything to continue: \n";
                }
                else if(armor==1&&codeCoin>200)
                {
                    codeCoin-=200;
                    cout<<"Armor has been activated. Enter anything to continue: \n";
                }
                else if(armor==1&&codeCoin<200)
                {
                    cout<<"You have made an unacceptable mistake however you shall be pardoned. You need to FOCUS. Enter anything to continue: "<<endl;
                }
                _getch();
                break;

                case 3:
                system("cls");
                cout<<"You have "<<codeCoin<<"CodeCoins\n";
                cout<<"One Bomb : 20 CodeCoins\n";
                cout<<"Enter number of bombs you wish to purchase \n";
                cin>>tempbombs;
                if(codeCoin>=tempbombs*20)
                {
                    extrabombs+=tempbombs;
                    bombs=5+extrabombs;
                    codeCoin=codeCoin-(20*tempbombs);
                    cout<<"You have successfully purchased "<<tempbombs<<" extra bomb(s). Enter anything to continue: \n";
                    _getch();
                }
                else
                {cout<<"You have made an unacceptable mistake however you shall be pardoned. You need to FOCUS. Enter anything to continue: "<<endl;
                _getch();}
                break;

                case 4:
                system("cls");
                cout<<"You have "<<codeCoin<<"CodeCoins\n";
                cout<<"One Health Pack (20 HP): 100 CodeCoins\n";
                cout<<"Enter number of health packs you wish to purchase\n";
                cin>>temphp;
                fflush(stdin);
                if(codeCoin>=temphp*100)
                {
                    healthpack+=temphp;
                    php=100.0+(20.0*healthpack);
                    codeCoin-=(100*temphp);
                    cout<<"You have successfully purchased "<<temphp<<" health pack(s). Enter anything to continue: \n";
                    _getch();
                }
                else
                {cout<<"You have made an unacceptable mistake however you shall be pardoned. You need to FOCUS. Enter anything to continue: "<<endl;
                _getch();}
                break;

                case 5:
                cout<<"Returning to Game ..."<<endl;
                break;

                default:
                cout<<"You have committed an unpardonable sin. Penalty -10 CodeCoins "<<endl;
                codeCoin-=10;
            }
            system("cls");
        }while(storech!=5);
    }


    void blasterShop()
    {
        system("cls");
        int gunch;
        do
        {
            cout<<"                                               WELCOME TO THE CODEBLASTER SHOP\n\n\n";
            cout<<"                                  1.CODEBLASTER GX-21(75 codeCoins)\n";
            cout<<"                                  2.CODEBLASTER UX-420(100 codeCoins)\n";
            cout<<"                                  3.CODEBLASTER ZX-782(125 codeCoins)\n";
            cout<<"                                  4.EXIT\n\n\n";
            cout<<"YOU HAVE  "<<codeCoin<< " CodeCoins "<<endl;
            cout<<"Enter your choice: "<<endl;
            cin>>gunch;
            switch(gunch)
            {
                case 1:
                if(codeCoin>=75)
                {
                    strcpy(blasterName,"CODEBLASTER GX-21");
                    pdmg=6;
                    codeCoin-=75;
                    cout<<"You have successfully purchased "<<blasterName<<". Enter anything to continue: \n";
                    _getch();
                }
                else
                cout<<"You have made an unacceptable mistake however you shall be pardoned. You need to FOCUS "<<endl;
                break;

                case 2:
                if(codeCoin>=100)
                {
                    strcpy(blasterName,"CODEBLASTER UX-420");
                    pdmg=8;
                    codeCoin-=100;
                    cout<<"You have successfully purchased "<<blasterName<<". Enter anything to continue: \n";
                    _getch();
                }
                else
                cout<<"You have made an unacceptable mistake however you shall be pardoned. You need to FOCUS "<<endl;
                break;

                case 3:
                if(codeCoin>=125)
                {
                    strcpy(blasterName,"CODEBLASTER ZX-782");
                    pdmg=10;
                    codeCoin-=125;
                    cout<<"You have successfully purchased "<<blasterName<<". Enter anything to continue: \n";
                    _getch();
                }
                else
                cout<<"You have made an unacceptable mistake however you shall be pardoned. You need to FOCUS "<<endl;
                break;

                case 4:
                cout<<"Redirecting to CodeStore ..."<<endl;
                break;

                default:
                cout<<"You have committed an unpardonable sin. Penalty: -10 codeCoins "<<endl;
                codeCoin-=10;
            }
            system("cls");
        }while(gunch!=4);
    }
};


class Game
{
public:
HighScores H;
void delayLoop()
{
    long int i;
    for(i=0;i<=10000000-(gamespeed*100000);i++)
    {
        ;
    }
}

void computerMovement()
{
    int compMove=0;
    switch(map[y-1][x])
    {
        case 'X':
        case '#':
        case (char)(219):
        case '@':
        case '<':
        case '>':
        case 'v':
        case '^':
            {
                switch(map[y][x-1])
                {
                    case 'X':
                    case '#':
                    case (char)(219):
                    case '@':
                    case '<':
                    case '>':
                    case 'v':
                    case '^':
                        {
                            switch(map[y+1][x])
                            {
                                case 'X':
                                case '#':
                                case (char)(219):
                                case '@':
                                case '<':
                                case '>':
                                case 'v':
                                case '^':
                                    {
                                        switch(map[y][x+1])
                                        {
                                            case 'X':
                                            case '#':
                                            case (char)(219):
                                            case '@':
                                            case '<':
                                            case '>':
                                            case 'v':
                                            case '^':
                                            {break;}
                                            case ' ':///can guaranteed move right
                                                {
                                                    map[y][x]=' ';
                                                    x++;
                                                    map[y][x]='O';
                                                    break;
                                                }
                                        }
                                        break;
                                    }
                                case ' ':///can guaranteed move down
                                    {
                                        switch(map[y][x+1])
                                        {
                                            case 'X':
                                            case '#':
                                            case (char)(219):
                                            case '@':
                                            case '<':
                                            case '>':
                                            case 'v':
                                            case '^':///cannot move right
                                            {
                                                map[y][x]=' ';
                                                y++;
                                                map[y][x]='O';
                                                break;
                                            }
                                            case ' ':///can move right or down
                                                {
                                                    compMove=rand()%2;
                                                    if(compMove==0)///moving down
                                                    {
                                                        map[y][x]=' ';
                                                        y++;
                                                        map[y][x]='O';
                                                    }
                                                    else//moving right
                                                    {
                                                        map[y][x]=' ';
                                                        x++;
                                                        map[y][x]='O';
                                                    }
                                                    break;
                                                }
                                        }
                                        break;
                                    }
                            }
                            break;
                        }
                    case ' ':///can guaranteed move left
                        {
                            switch(map[y+1][x])
                            {
                                case 'X':
                                case '#':
                                case (char)(219):
                                case '@':
                                case '<':
                                case '>':
                                case 'v':
                                case '^':
                                    {
                                        switch(map[y][x+1])
                                        {
                                            case 'X':
                                            case '#':
                                            case (char)(219):
                                            case '@':
                                            case '<':
                                            case '>':
                                            case 'v':
                                            case '^':///can only move left
                                            {
                                                map[y][x]=' ';
                                                x--;
                                                map[y][x]='O';
                                                break;
                                            }
                                            case ' ':///can move right or left
                                                {
                                                    compMove=rand()%2;
                                                    if(compMove==0)///moving left
                                                    {
                                                    map[y][x]=' ';
                                                    x--;
                                                    map[y][x]='O';
                                                    }
                                                    else///moving right
                                                    {
                                                    map[y][x]=' ';
                                                    x++;
                                                    map[y][x]='O';
                                                    }
                                                    break;
                                                }
                                        }
                                        break;
                                    }
                                case ' ':///can guaranteed move down
                                    {
                                        switch(map[y][x+1])
                                        {
                                            case 'X':
                                            case '#':
                                            case (char)(219):
                                            case '@':
                                            case '<':
                                            case '>':
                                            case 'v':
                                            case '^':///can move down or left
                                            {
                                                compMove=rand()%2;
                                                if(compMove==0)///moving left
                                                {
                                                    map[y][x]=' ';
                                                    x--;
                                                    map[y][x]='O';
                                                }
                                                else///moving down
                                                {
                                                    map[y][x]=' ';
                                                    y++;
                                                    map[y][x]='O';
                                                }
                                                break;
                                            }
                                            case ' ':///can move right, down or left
                                                {
                                                    compMove=rand()%3;
                                                    if(compMove==0)///moving down
                                                    {
                                                        map[y][x]=' ';
                                                        y++;
                                                        map[y][x]='O';
                                                    }
                                                    else if(compMove==1)///moving right
                                                    {
                                                        map[y][x]=' ';
                                                        x++;
                                                        map[y][x]='O';
                                                    }
                                                    else///moving left
                                                    {
                                                        map[y][x]=' ';
                                                        x--;
                                                        map[y][x]='O';
                                                    }
                                                    break;
                                                }
                                        }
                                        break;
                                    }
                            }
                            break;
                        }

                }
                break;
            }
        case ' ':///can guaranteed move up
            {
                switch(map[y][x-1])
                {
                    case 'X':
                    case '#':
                    case (char)(219):
                    case '@':
                    case '<':
                    case '>':
                    case 'v':
                    case '^':
                        {
                            switch(map[y+1][x])
                            {
                                case 'X':
                                case '#':
                                case (char)(219):
                                case '@':
                                case '<':
                                case '>':
                                case 'v':
                                case '^':
                                    {
                                        switch(map[y][x+1])
                                        {
                                            case 'X':
                                            case '#':
                                            case (char)(219):
                                            case '@':
                                            case '<':
                                            case '>':
                                            case 'v':
                                            case '^':///can only move up
                                            {
                                                map[y][x]=' ';
                                                y--;
                                                map[y][x]='O';
                                                break;
                                            }
                                            case ' ':///can move right or up
                                                {
                                                    compMove=rand()%2;
                                                    if(compMove==0)///moving right
                                                    {
                                                        map[y][x]=' ';
                                                        x++;
                                                        map[y][x]='O';
                                                    }
                                                    else///moving up
                                                    {
                                                        map[y][x]=' ';
                                                        y--;
                                                        map[y][x]='O';
                                                    }
                                                    break;
                                                }
                                        }
                                        break;
                                    }
                                case ' ':///can guaranteed move down or up
                                    {
                                        switch(map[y][x+1])
                                        {
                                            case 'X':
                                            case '#':
                                            case (char)(219):
                                            case '@':
                                            case '<':
                                            case '>':
                                            case 'v':
                                            case '^':///can move down or up
                                            {
                                                compMove=rand()%2;
                                                if(compMove==0)///moving down
                                                {
                                                    map[y][x]=' ';
                                                    y++;
                                                    map[y][x]='O';
                                                }
                                                else///moving up
                                                {
                                                    map[y][x]=' ';
                                                    y--;
                                                    map[y][x]='O';
                                                }
                                                break;
                                            }
                                            case ' ':///can move right, down or up
                                                {
                                                    compMove=rand()%3;
                                                    if(compMove==0)///moving down
                                                    {
                                                        map[y][x]=' ';
                                                        y++;
                                                        map[y][x]='O';
                                                    }
                                                    else if(compMove==1)///moving right
                                                    {
                                                        map[y][x]=' ';
                                                        x++;
                                                        map[y][x]='O';
                                                    }
                                                    else
                                                    {
                                                        map[y][x]=' ';
                                                        y--;
                                                        map[y][x]='O';
                                                    }
                                                    break;
                                                }
                                        }
                                        break;
                                    }
                            }
                            break;
                        }
                    case ' ':///can guaranteed move left or up
                        {
                            switch(map[y+1][x])
                            {
                                case 'X':
                                case '#':
                                case (char)(219):
                                case '@':
                                case '<':
                                case '>':
                                case 'v':
                                case '^':
                                    {
                                        switch(map[y][x+1])
                                        {
                                            case 'X':
                                            case '#':
                                            case (char)(219):
                                            case '@':
                                            case '<':
                                            case '>':
                                            case 'v':
                                            case '^':///can move left or up
                                            {
                                                compMove=rand()%2;
                                                if(compMove==0)
                                                {
                                                    map[y][x]=' ';
                                                    x--;
                                                    map[y][x]='O';
                                                }
                                                else
                                                {
                                                    map[y][x]=' ';
                                                    y--;
                                                    map[y][x]='O';
                                                }
                                                break;
                                            }
                                            case ' ':///can move right, left or up
                                                {
                                                    compMove=rand()%3;
                                                    if(compMove==0)///moving left
                                                    {
                                                        map[y][x]=' ';
                                                        x--;
                                                        map[y][x]='O';
                                                    }
                                                    else if(compMove==1)///moving right
                                                    {
                                                        map[y][x]=' ';
                                                        x++;
                                                        map[y][x]='O';
                                                    }
                                                    else
                                                    {
                                                        map[y][x]=' ';
                                                        y--;
                                                        map[y][x]='O';
                                                    }
                                                    break;
                                                }
                                        }
                                        break;
                                    }
                                case ' ':///can guaranteed move down
                                    {
                                        switch(map[y][x+1])
                                        {
                                            case 'X':
                                            case '#':
                                            case (char)(219):
                                            case '@':
                                            case '<':
                                            case '>':
                                            case 'v':
                                            case '^':///can move down, left or up
                                            {
                                                compMove=rand()%3;
                                                if(compMove==0)///moving left
                                                {
                                                    map[y][x]=' ';
                                                    x--;
                                                    map[y][x]='O';
                                                }
                                                else if(compMove==1)///moving down
                                                {
                                                    map[y][x]=' ';
                                                    y++;
                                                    map[y][x]='O';
                                                }
                                                else
                                                {
                                                    map[y][x]=' ';
                                                    y--;
                                                    map[y][x]='O';
                                                }
                                                break;
                                            }
                                            case ' ':///can move in any direction
                                                {
                                                    compMove=rand()%4;
                                                    if(compMove==0)///moving down
                                                    {
                                                        map[y][x]=' ';
                                                        y++;
                                                        map[y][x]='O';
                                                    }
                                                    else if(compMove==1)///moving right
                                                    {
                                                        map[y][x]=' ';
                                                        x++;
                                                        map[y][x]='O';
                                                    }
                                                    else if(compMove==2)///moving left
                                                    {
                                                        map[y][x]=' ';
                                                        x--;
                                                        map[y][x]='O';
                                                    }
                                                    else
                                                    {
                                                        map[y][x]=' ';
                                                        y--;
                                                        map[y][x]='O';
                                                    }
                                                    break;
                                                }
                                        }
                                        break;
                                    }
                            }
                            break;
                        }

                }
                break;
            }
    }
}

void playGame()
{
    if(armor==1)
    {
        cdmg*=0.75;
    }
    while(1)
    {
        system("cls");
        if(armor==2)
        {
            php-=0.05;
        }
        for(y=0;y<20;y++)
        {
                cout<<map[y]<<endl;
        }
        cout<<"Player HP: "<<php<<"\t\t\tComputer HP: "<<chp<<endl;
        cout<<"Ammo left: "<<ammo<<endl;
        cout<<"Bombs left: "<<bombs<<endl;
        for(y=0;y<20;y++)
        {
            for(x=0;x<50;x++)
            {
                switch(map[y][x])
                {
                    case '#':
                    map[y][x]=219;
                    break;

                    case '@':
                    {
                        pposx=x;
                        pposy=y;
                        if(GetAsyncKeyState(0x57)!=0)///W to move up
                        {
                            ytemp=y-1;
                            switch(map[ytemp][x])
                            {
                                case ' ':
                                map[y][x]=' ';
                                y--;
                                map[ytemp][x]='@';
                                break;

                                case 'O':
                                php-=1.0;
                                break;
                            }
                        }
                        if(GetAsyncKeyState(0x53)!=0)///S to move down
                        {
                            ytemp=y+1;
                            switch(map[ytemp][x])
                            {
                                case ' ':
                                map[y][x]=' ';
                                y++;
                                map[ytemp][x]='@';
                                break;

                                case 'O':
                                php-=1.0;
                                break;
                            }
                        }
                        if(GetAsyncKeyState(0x44)!=0)///D to move right
                        {
                            xtemp=x+1;
                            switch(map[y][xtemp])
                            {
                                case ' ':
                                map[y][x]=' ';
                                x++;
                                map[y][xtemp]='@';
                                break;

                                case 'O':
                                php-=1.0;
                                break;
                            }
                        }
                        if(GetAsyncKeyState(0x41)!=0)///A to move left
                        {
                            xtemp=x-1;
                            switch(map[y][xtemp])
                            {
                                case ' ':
                                map[y][x]=' ';
                                x--;
                                map[y][xtemp]='@';
                                break;

                                case 'O':///hit computer, lose hp
                                php-=1.0;
                                break;
                            }
                        }
                        if(GetAsyncKeyState(0x49)!=0)///I to shoot up
                        {
                            ytemp=y-1;
                            switch(map[ytemp][x])
                            {
                                case ' ':
                                map[ytemp][x]='^';
                                ammo--;
                                break;
                            }
                        }
                        if(GetAsyncKeyState(0x4A)!=0)///J to shoot left
                        {
                            xtemp=x-1;
                            switch(map[y][xtemp])
                            {
                                case ' ':
                                map[y][xtemp]='<';
                                ammo--;
                                break;
                            }
                        }
                        if(GetAsyncKeyState(0x4B)!=0)///K to shoot left
                        {
                            ytemp=y+1;
                            switch(map[ytemp][x])
                            {
                                case ' ':
                                map[ytemp][x]='v';
                                ammo--;
                                break;
                            }
                        }
                        if(GetAsyncKeyState(0x4C)!=0)///L to shoot right
                        {
                            xtemp=x+1;
                            switch(map[y][xtemp])
                            {
                                case ' ':
                                map[y][xtemp]='>';
                                ammo--;
                                break;
                            }
                        }
                        if(GetAsyncKeyState(0x4F)!=0)///O to place a bomb behind you
                        {
                            if(bombs!=0)
                            {
                                xtemp=x-1;
                                switch(map[y][xtemp])
                                {
                                    case ' ':
                                    map[y][xtemp]='X';
                                    bombs--;
                                    break;
                                }
                            }
                        }
                    }
                    break;

                    case '^':///shootUp
                    {
                        ytemp=y-1;
                        switch(map[ytemp][x])
                        {
                            case (char)(174):
                            case (char)(175):
                            case '!':
                            case ' ':
                            map[y][x]=' ';
                            y--;
                            map[ytemp][x]='^';
                            break;

                            case 'X':
                            case '#':
                            case (char)(219):
                            map[y][x]=' ';
                            break;

                            case (char)(173):
                            map[y][x]=(char)(173);
                            map[ytemp][x]='^';
                            break;

                            case 'O':
                            chp-=pdmg;
                            map[y][x]=' ';
                            break;
                        }
                    }
                    break;

                    case '<':///shootLeft
                    {
                        xtemp=x-1;
                        switch(map[y][xtemp])
                        {
                            case (char)(174):
                            case (char)(173):
                            case '!':
                            case ' ':
                            map[y][x]=' ';
                            x--;
                            map[y][xtemp]='<';
                            break;

                            case 'X':
                            case '#':
                            case (char)(219):
                            map[y][x]=' ';
                            break;

                            case (char)(175):
                            map[y][x]=(char)(175);
                            map[y][xtemp]='<';
                            break;

                            case 'O':
                            chp-=pdmg;
                            map[y][x]=' ';
                            break;
                        }
                    }
                    break;

                    case '>':///shootRight
                    {
                        xtemp=x+1;
                        switch(map[y][xtemp])
                        {
                            case (char)(175):
                            case (char)(173):
                            case '!':
                            case ' ':
                            map[y][x]=' ';
                            x++;
                            map[y][xtemp]='>';
                            break;

                            case 'X':
                            case '#':
                            case (char)(219):
                            map[y][x]=' ';
                            break;

                            case (char)(174):
                            map[y][x]=(char)(174);
                            map[y][xtemp]='>';
                            break;

                            case 'O':
                            chp-=pdmg;
                            map[y][x]=' ';
                            break;
                        }
                    }
                    break;

                    case 'v':///shootDown
                    {
                        ytemp=y+1;
                        switch(map[ytemp][x])
                        {
                            case (char)(173):
                            case (char)(174):
                            case (char)(175):
                            case ' ':
                            map[y][x]=' ';
                            y++;
                            map[ytemp][x]='v';
                            break;

                            case 'X':
                            case '#':
                            case (char)(219):
                            map[y][x]=' ';
                            break;

                            case '!':
                            map[y][x]='!';
                            map[ytemp][x]='v';
                            break;

                            case 'O':
                            chp-=pdmg;
                            map[y][x]=' ';
                            break;
                        }
                    }
                    break;

                    case 'O':///Computer
                    {
                        cposx=x;
                        cposy=y;
                        computerMovement();
                        if((cposx==pposx)&&(cposy<pposy))
                        {
                            ytemp=cposy+1;
                            switch(map[ytemp][x])
                            {
                                case ' ':
                                map[ytemp][x]=(char)(173);
                                break;
                            }
                        }
                        else if((cposx==pposx)&&(cposy>pposy))
                        {
                            ytemp=cposy-1;
                            switch(map[ytemp][x])
                            {
                                case ' ':
                                map[ytemp][x]='!';
                                break;
                            }
                        }
                        else if((cposy==pposy)&&(cposx<pposx))
                        {
                            xtemp=cposx+1;
                            switch(map[y][xtemp])
                            {
                                case ' ':
                                map[y][xtemp]=(char)(175);
                                break;
                            }
                        }
                        else if((cposy==pposy)&&(cposx>pposx))
                        {
                            xtemp=cposx-1;
                            switch(map[y][xtemp])
                            {
                                case ' ':
                                map[y][xtemp]=(char)(174);
                                break;
                            }
                        }
                        break;
                    }
                    case (char)(173):///shootDown
                    {
                        ytemp=y+1;
                        switch(map[ytemp][x])
                        {
                            case 'v':
                            case '>':
                            case '<':
                            case ' ':
                            map[y][x]=' ';
                            y++;
                            map[ytemp][x]=(char)(173);
                            break;

                            case '^':
                            map[y][x]='^';
                            map[ytemp][x]=(char)(173);
                            break;

                            case 'X':
                            case '#':
                            case (char)(219):
                            map[y][x]=' ';
                            break;

                            case '@':
                            php-=cdmg;
                            map[y][x]=' ';
                            break;
                        }
                        break;
                    }
                    case (char)(174):///shootLeft
                    {
                        xtemp=x-1;
                        switch(map[y][xtemp])
                        {
                            case 'v':
                            case '^':
                            case '<':
                            case ' ':
                            map[y][x]=' ';
                            x--;
                            map[y][xtemp]=(char)(174);
                            break;

                            case '>':
                            map[y][x]='>';
                            map[y][xtemp]=(char)(174);
                            break;

                            case 'X':
                            case '#':
                            case (char)(219):
                            map[y][x]=' ';
                            break;

                            case '@':
                            php-=cdmg;
                            map[y][x]=' ';
                            break;
                        }
                        break;
                    }
                    case (char)(175):///shootRight
                    {
                        xtemp=x+1;
                        switch(map[y][xtemp])
                        {
                            case 'v':
                            case '>':
                            case '^':
                            case ' ':
                            map[y][x]=' ';
                            x++;
                            map[y][xtemp]=(char)(175);
                            break;

                            case '<':
                            map[y][x]='<';
                            map[y][xtemp]=(char)(175);
                            break;

                            case 'X':
                            case '#':
                            case (char)(219):
                            map[y][x]=' ';
                            break;

                            case '@':
                            php-=cdmg;
                            map[y][x]=' ';
                            break;
                        }
                        break;
                    }
                    case '!':///shootUp
                    {
                        ytemp=y-1;
                        switch(map[ytemp][x])
                        {
                            case '^':
                            case '>':
                            case '<':
                            case ' ':
                            map[y][x]=' ';
                            y--;
                            map[ytemp][x]='!';
                            break;

                            case 'v':
                            map[y][x]='v';
                            map[ytemp][x]='!';
                            break;

                            case 'X':
                            case '#':
                            case (char)(219):
                            map[y][x]=' ';
                            break;

                            case '@':
                            php-=cdmg;
                            map[y][x]=' ';
                            break;
                        }
                        break;
                    }
                    case 'X':
                    {
                        if(GetAsyncKeyState(0x50)!=0)///P to explode
                        {
                            if(map[y][x+1]=='O'||map[y][x+2]=='O'||map[y][x-1]=='O'||map[y][x-2]=='O'||map[y+1][x]=='O'||map[y+2][x]=='O'||map[y-1][x]=='O'||map[y-2][x]=='O'||map[y-2][x-2]=='O'||map[y-2][x-1]=='O'||map[y-2][x+1]=='O'||map[y-2][x+2]=='O'||map[y-1][x-2]=='O'||map[y-1][x-1]=='O'||map[y-1][x+1]=='O'||map[y-1][x+2]=='O'||map[y+1][x-2]=='O'||map[y+1][x-1]=='O'||map[y+1][x+1]=='O'||map[y+1][x+2]=='O'||map[y+2][x-2]=='O'||map[y+2][x-1]=='O'||map[y+2][x+1]=='O'||map[y+2][x+2]=='O')
                            {
                                map[y][x]=' ';
                                chp-=10;
                            }
                        }
                        break;
                    }
                }
            }
        }
        if((chp<=0 && php>0) && (ammo>0))
        {
            victor=1;
            break;
        }
        else if((php<=0 && chp>0)||(ammo<0))
        {
            victor=0;
            break;
        }
        else if(php<=0 && chp<=0)
        {
            victor=2;
            break;
        }
        delayLoop();
    }
    if(victor==0)
    {
        system("cls");
        score=0;
        fflush(stdin);
        p.playerScore=score;
        H.addScore(p);
        cout<<"You Lost!\n";
        cout<<"Your score is: "<<score<<endl;
        cout<<"Your new CodeCoin balance is: "<<codeCoin<<" CodeCoins.\n";
        system("pause");
    }
    else if(victor==1)
    {
        system("cls");
        cout<<"Congratulations on winning!\n";
        if(difficulty==1)
        {
            score=(ammo*100)+1000;
            cout<<"Your score is: "<<score<<endl;
            codeCoin+=score/100;
            cout<<"Your new CodeCoin balance is: "<<codeCoin<<" CodeCoins.\n";
            p.playerScore=score;
            H.addScore(p);
            p.playerNumber++;
        }
        else if(difficulty==2)
        {
            score=(ammo*400)+5000;
            cout<<"Your score is: "<<score<<endl;
            codeCoin+=score/100;
            cout<<"Your new CodeCoin balance is: "<<codeCoin<<" CodeCoins.\n";
            p.playerScore=score;
            H.addScore(p);
            p.playerNumber++;
        }
        else if(difficulty==3&&armor==2)///expert difficulty with poison armor
        {
            cout<<"You are unimaginably good...You beat the game on its hardest difficulty with poison armor! You now get free armor :-)\n";
            score=(ammo*10000)+50000;
            armor=1;
            cout<<"Your score is: "<<score<<endl;
            codeCoin+=score/100;
            cout<<"Your new CodeCoin balance is: "<<codeCoin<<" CodeCoins.\n";
            p.playerScore=score;
            H.addScore(p);
            p.playerNumber++;
        }
        else if(difficulty==3)
        {
            cout<<"Commendable job...You beat the game on its hardest difficulty!\n";
            score=(ammo*1000)+60000;
            cout<<"Your score is: "<<score<<endl;
            codeCoin+=score/100;
            cout<<"Your new CodeCoin balance is: "<<codeCoin<<" CodeCoins.\n";
            p.playerScore=score;
            H.addScore(p);
            p.playerNumber++;
        }
        system("pause");
    }
    else if(victor==2)
    {
        system("cls");
        score=42069;
        p.playerScore=score;
        H.addScore(p);
        cout<<"Why you breaking my game? :( Enter anything to continue\n";
        _getch();
    }
}

void resetGame()
{
    if(difficulty==1)
    {
        ammo=300;
        php=100.0+(20.0*healthpack);
        chp=100.0;
        bombs=5+extrabombs;
        cdmg=4.0;
    }
    else if(difficulty==2)
    {
        ammo=200;
        php=100.0+(20.0*healthpack);
        chp=150.0;
        bombs=5+extrabombs;
        cdmg=6.0;
    }
    else if(difficulty==3)
    {
        ammo=100;
        php=100.0+(20.0*healthpack);
        chp=200.0;
        bombs=5+extrabombs;
        cdmg=10.0;
    }
    for(y=0;y<20;y++)
    {
        for(x=0;x<50;x++)
        {
            switch(map[y][x])
            {
                case '@':
                case 'O':
                case 'X':
                case '^':
                case 'v':
                case '>':
                case '<':
                case '!':
                case (char)(173):
                case (char)(174):
                case (char)(175):
                map[y][x]=' ';
                break;
            }
        }
    }
    map[initcposy][initcposx]='O';
    map[initpposy][initpposx]='@';
}
};


class MainMenu///for displaying the main menu
{
    public:

    StartUp su;///object for intro
    HighScores hs;///object for high scores (file handling)
    CodeStore cs;///object for CodeStore
    Outro o;///object for outro
    Game g;///object to play the game

    void displayMenu()///provides intro and prints the main menu
    {
        int mainch;///stores choice of the user for the main menu
        int hsch;///stores choice of the user for the high scores menu
        char dch;///stores choice of the user for deleting scores
        system("cls");
        su.mainEntrance();
        su.mainPrint();
        cout<<"Enter player's name: \n";
        gets(p.playerName);
        system("cls");
        cout<<"READ CAREFULLY!\n\n\n\n";
        cout<<"\t\t\t\t-------RULES-------\n\n";
        cout<<"You, the player, are indicated by @. The computer is an O\n\n";
        cout<<"Movement Controls:\n\n";
        cout<<"W- To move player up\n";
        cout<<"A- To move player left\n";
        cout<<"S- To move player down\n";
        cout<<"D- To move player right\n\n";
        cout<<"Shooting Controls:\n\n";
        cout<<"I- To shoot up\n";
        cout<<"J- To shoot left\n";
        cout<<"K- To shoot down\n";
        cout<<"L- To shoot right\n\n";
        cout<<"Bomb Controls:\n\n";
        cout<<"O- To deploy bomb behind player\n";
        cout<<"P- To detonate only bombs near the computer\n\n";
        cout<<"CodeStore:\n\n";
        cout<<"There is a virtual currency known as CodeCoins used in the following game.\n";
        cout<<"You can use CodeCoins to purchase CodeBlasters(guns), Armor, Health Packs or Bombs.\n\n";
        cout<<"Earning CodeCoins and High Scores:\n\n";
        cout<<"On playing and winning games, you get a score which automatically gets added to the high scores file.\n";
        cout<<"This score also converts to extra CodeCoins for you to spend!\n\n";
        cout<<"Enjoy yourself :-)\n\n";
        cout<<"When you are done reading rules, type anything to continue. Do this for all future continues :-)\n";
        _getch();
        hs.countScores();
        p.playerNumber=++numOfScores;
        do
        {
            su.mainPrint();///has a system("cls") in it
            fflush(stdin);
            cout<<"\n\n\n\n\n";
            cout<<"                                                 MAIN MENU                                                 \n";
            cout<<"                                            1. Hop Into A New Game                                         \n";
            cout<<"                                            2. Code Store                                                  \n";
            cout<<"                                            3. See High Scores                                             \n";
            cout<<"                                            4. Exit The Game                                           \n\n\n";
            cout<<"                                        Please Enter Your Choice:                                          \n";
            cin>>mainch;
            system("cls");
            switch(mainch)
            {
                case 1:
                cout<<"\n\nEnter 1 to play easy difficulty.";
                cout<<"\n\n\nEnter 2 to play medium difficulty.";
                cout<<"\n\n\nEnter 3 to play expert difficulty.";
                cout<<"\n\n\nEnter 4 to go back to main menu";
                cout<<"\n\nPlease enter the difficulty at which you would like to play: \n";
                cin>>difficulty;
                p.playerDifficulty=difficulty;
                if(difficulty!=4)
                {
                    system("cls");
                    cs.storeMenu();
                    fflush(stdin);
                    g.resetGame();
                    g.playGame();
                }
                else
                {difficulty=1;}
                break;

                case 2:
                cs.storeMenu();
                break;

                case 3:
                do
                {
                    system("cls");
                    cout<<"\t\t\t\tHigh Scores Menu\n\n";
                    cout<<"\t\t\t1.Display Scores\n";
                    cout<<"\t\t\t2.Delete all Scores\n";
                    cout<<"\t\t\t3.Return to Main Menu\n";
                    cout<<"\t\t\tEnter your choice:\n\n";
                    cin>>hsch;
                    fflush(stdin);
                    switch(hsch)
                    {
                        case 1:
                        hs.displayScores();
                        cout<<"\n\nEnter anything to continue:\n";
                        _getch();
                        fflush(stdin);
                        break;

                        case 2:
                        cout<<"Are you sure you want to do this? Scores lost are irretrievable..\n";
                        cout<<"Enter y if you'd like to delete, else file will not be deleted.\n";
                        cin>>dch;
                        if(dch=='y'||dch=='Y')
                        {
                            hs.deleteAllScores();
                            cout<<"All scores have been deleted. Enter anything to continue:\n";
                            _getch();
                            fflush(stdin);
                        }
                        else
                        {
                            cout<<"Scores have not been deleted. Enter anything to continue:\n";
                            _getch();
                        }
                        break;

                        case 3:
                        cout<<"Exiting...\n";
                        break;

                        default:
                        cout<<"Invalid choice...Enter anything to continue:\n";
                        _getch();
                    }
                }while(hsch!=3);
                break;

                case 4:
                o.ending();
                break;

                default:
                cout<<"Invalid choice, please try again! Enter anything to continue: \n";
                _getch();
            }
        }while(mainch!=4);
    }
};



int main()
{
    MainMenu m;
    system("cls");
    m.displayMenu();
    return 0;
}

