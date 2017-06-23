#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<termios.h>

#define Min 2
#define Max 20

void gotoxy(int x, int y);
void back_round();
int getch(void);

int end = 1;

void main(){
        system("clear");
        int turn = 1;
        end = 0;
        int x = 4, y = 4, i, j, k = 1, n;
        int nmap[5][5] = { 0, };
        int map1p[24] = { 0, }, map2p[24] = { 0, };
        unsigned char chr = 99; // chr move
        gotoxy(4,14);
        printf("game start\n");
        gotoxy(4,15);
        printf("1p turn");
        gotoxy(1, 1);
        back_round();  //map
        gotoxy(4, 2);
        printf("O");
        while (k++){
                for (i = 0; i<5; i++){
                        for (j = 0; j<5; j++){
                                nmap[i][j] = 0;
                                gotoxy((i + 1) * 4, (j + 1) * 2 + 2);
                                printf(" ");
                        }
                }
                n = 0;
                y = 4;
                if (turn == 1) x = 4;
                else x = 20;
                while (1){
                        gotoxy(x, y);
                        printf("x");
                        nmap[x / 4 - 1][(y - 2) / 2 - 1] = 1;
                        gotoxy(4, 17);
                        printf("                                            ");
                        gotoxy(4,17);
                        chr = getch();
                        if(chr == 'r') {
                                n=0;
                                for(i=0;i<5;i++) for(j=0;j<5;j++) nmap[i][j]=0;
                                k--;
                                break;
                        }
                        if(chr == 'q') {
                                end =1;
                                break;
                        }
                        //if (chr == 0 || chr == 0xe0){
                        //      chr = getch();
                        //}
                        if (chr == 'w'){ //up
                                if ((y != 4) && (nmap[x / 4 - 1][(y - 2) / 2 - 1 - 1] == 0)){
                                        if (k>3 && turn ==1 && map1p[n] !=chr){
                                                gotoxy(4, 15);
                                                printf("2p turn");
                                                gotoxy(20,2);
                                                printf("O");
                                                gotoxy(4,2);
                                                printf(" ");
                                                turn = 2;
                                                break;
                                        }
                                        if (k>3 && turn ==2 && map2p[n] !=chr){
                                                gotoxy(4, 15);
                                                printf("1p turn");
                                                gotoxy(4,2);
                                                printf("O");
                                                gotoxy(20,2);
                                                printf(" ");
                                                turn = 1;
                                                break;
                                        }
                                        y -= 2;
                                        gotoxy(x, y);
                                        nmap[x / 4 - 1][(y - 2) / 2 - 1] = 1;
                                        if (k<=3 && turn == 1) map1p[n] = 'w';
                                        else if (k<=3 && turn == 2) map2p[n] = 'w';
                                        n++;

                                }

                        }
                        else if (chr == 's'){ //down
                                if (y != 12 && (nmap[x / 4 - 1][(y - 2) / 2 - 1 + 1] == 0)){
                                        if (k>3 && turn ==1 && map1p[n] !=chr){
                                                gotoxy(4, 15);
                                                printf("2p turn");
                                                gotoxy(20,2);
                                                printf("O");
                                                gotoxy(4,2);
                                                printf(" ");
                                                turn =2;
                                                break;
                                        }
                                        if (k>3 && turn ==2 && map2p[n] !=chr){
                                                gotoxy(4, 15);
                                                printf("1p turn");
                                                gotoxy(4,2);
                                                printf("O");
                                                gotoxy(20,2);
                                                printf(" ");
                                                turn =1;
                                                break;
                                        }
                                        y += 2;
                                        gotoxy(x, y);
                                        nmap[x / 4 - 1][(y - 2) / 2 - 1] = 1;
                                        if (k<=3 && turn == 1) map1p[n] = 's';
                                        else if (k<=3 && turn == 2) map2p[n] = 's';
                                        n++;

                                }
                        }
                        else if (chr == 'a'){ //left
                                if (x != 4 && (nmap[x / 4 - 1 - 1][(y - 2) / 2 - 1] == 0)){
                                        if (k>3 && turn ==1 && map1p[n] !=chr){
                                                gotoxy(4, 15);
                                                printf("2p turn");
                                                gotoxy(20,2);
                                                printf("O");
                                                gotoxy(4,2);
                                                printf(" ");
                                                turn =2;
                                                break;
                                        }
                                        if (k>3 && turn ==2 && map2p[n] !=chr){
                                                gotoxy(4, 15);
                                                printf("1p turn");
                                                gotoxy(4,2);
                                                printf("O");
                                                gotoxy(20,2);
                                                printf(" ");
                                                turn =1;
                                                break;
                                        }
                                        x -= 4;
                                        gotoxy(x, y);
                                        nmap[x / 4 - 1][(y - 2) / 2 - 1] = 1;
                                        if (k<=3 && turn == 1) map1p[n] = 'a';
                                        else if (k<=3 && turn == 2) map2p[n] = 'a';
                                        n++;

                                }
                        }
                        else if (chr == 'd'){ //right
                                if (x != 20 && (nmap[x / 4 - 1 + 1][(y - 2) / 2 - 1] == 0)){
                                        if (k>3 && turn ==1 && map1p[n] !=chr){
                                                gotoxy(4, 15);
                                                printf("2p turn");
                                                gotoxy(20,2);
                                                printf("O");
                                                gotoxy(4,2);
                                                printf(" ");
                                                turn =2;
                                                break;
                                        }
                                        if (k>3 && turn ==2 && map2p[n] !=chr){
                                                gotoxy(4, 15);
                                                printf("1p turn");
                                                gotoxy(4,2);
                                                printf("O");
                                                gotoxy(20,2);
                                                printf(" ");
                                                turn =1;
                                                break;
                                        }
                                        x += 4;
                                        gotoxy(x, y);
                                        nmap[x / 4 - 1][(y - 2) / 2 - 1] = 1;
                                        if (k<=3 && turn == 1) map1p[n] = 'd';
                                        else if (k<=3 && turn == 2) map2p[n] = 'd';
                                        n++;

                                }
                        }

                        if (x == 20 && y == 4 && turn == 1){
                                gotoxy(4, 15);
                                if (k>3){
                                        gotoxy(4,16);
                                        printf("1p win\n");
                                        gotoxy(x,y);
                                        printf("o");
                                        gotoxy(0,20);
                                        end =1;
                                        break;
                                }
                                printf("2p turn");
                                gotoxy(20, 2);
                                printf("O");
                                gotoxy(4,2);
                                printf(" ");
                                turn = 2;
                                break;
                        }
                        else if (x == 4 && y == 4 && turn == 2){
                                gotoxy(4, 15);
                                if (k>3){
                                        gotoxy(4,16);
                                        printf("2p win\n");
                                        gotoxy(x,y);
                                        printf("o");
                                        gotoxy(0,20);
                                        end =1;
                                        break;
                                }
                                printf("1p turn");
                                gotoxy(4, 2);
                                printf("O");
                                gotoxy(20,2);
                                printf(" ");
                                turn = 1;
                                break;
                        }
                if(end == 1) break;
                }
        if(end == 1) break;
        }
}


void back_round(){
        unsigned char a = 0xa6;
        int i, j;
        int x = 7;
        int y = 7;
        /************* up space*********************/
        printf("%c%c%c%c%c%c          %c%c%c%c%c%c\n", a, 0xa3, a, 0xa1, a, 0xa4, a, 0xa3, a, 0xa1, a, 0xa4);
        /************* mid space************************/
        printf("%c%c  %c%c          %c%c  %c%c\n", a, 0xa2, a, 0xa2, a, 0xa2, a, 0xa2);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", a, 0xa7, a, 0xa1, a, 0xab, a, 0xa1, a, 0xa8, a, 0xa1, a, 0xa8, a, 0xa1, a, 0xab, a, 0xa1, a, 0xa9);

        printf("%c%c  %c%c  %c%c  %c%c  %c%c  %c%c\n", a, 0xa2, a, 0xa2, a, 0xa2, a, 0xa2, a, 0xa2, a, 0xa2);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", a, 0xa7, a, 0xa1, a, 0xab, a, 0xa1, a, 0xab, a, 0xa1, a, 0xab, a, 0xa1, a, 0xab, a, 0xa1, a, 0xa9);

        printf("%c%c  %c%c  %c%c  %c%c  %c%c  %c%c\n", a, 0xa2, a, 0xa2, a, 0xa2, a, 0xa2, a, 0xa2, a, 0xa2);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", a, 0xa7, a, 0xa1, a, 0xab, a, 0xa1, a, 0xab, a, 0xa1, a, 0xab, a, 0xa1, a, 0xab, a, 0xa1, a, 0xa9);

        printf("%c%c  %c%c  %c%c  %c%c  %c%c  %c%c\n", a, 0xa2, a, 0xa2, a, 0xa2, a, 0xa2, a, 0xa2, a, 0xa2);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", a, 0xa7, a, 0xa1, a, 0xab, a, 0xa1, a, 0xab, a, 0xa1, a, 0xab, a, 0xa1, a, 0xab, a, 0xa1, a, 0xa9);

        printf("%c%c  %c%c  %c%c  %c%c  %c%c  %c%c\n", a, 0xa2, a, 0xa2, a, 0xa2, a, 0xa2, a, 0xa2, a, 0xa2);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", a, 0xa7, a, 0xa1, a, 0xab, a, 0xa1, a, 0xab, a, 0xa1, a, 0xab, a, 0xa1, a, 0xab, a, 0xa1, a, 0xa9);
        printf("%c%c  %c%c  %c%c  %c%c  %c%c  %c%c\n", a, 0xa2, a, 0xa2, a, 0xa2, a, 0xa2, a, 0xa2, a, 0xa2);

        /************* down space*********************/
        printf("%c%c", a, 0xa6);
        printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", a, 0xa1, a, 0xaa, a, 0xa1, a, 0xaa, a, 0xa1, a, 0xaa, a, 0xa1, a, 0xaa, a, 0xa1);
        printf("%c%c\n", a, 0xa5);
        gotoxy(24,3);
        printf("*************");
        gotoxy(24,4);
        printf("* about key *");
        gotoxy(24,5);
        printf("* up    : w *");
        gotoxy(24,6);
        printf("* down  : s *");
        gotoxy(24,7);
        printf("* left  : a *");
        gotoxy(24,8);
        printf("* right : d *");
        gotoxy(24,9);
        printf("* retry : r *");
        gotoxy(24,10);
        printf("* exit  : q *");
        gotoxy(24,11);
        printf("*************");
}

int getch(void) {
  int ch;
  struct termios buf;
  struct termios save;

  tcgetattr(0, &save);
  buf = save;
  buf.c_lflag &= ~(ICANON|ECHO);
  buf.c_cc[VMIN] = 1;
  buf.c_cc[VTIME] = 0;
  tcsetattr(0, TCSAFLUSH, &buf);
  ch = getchar();
  tcsetattr(0, TCSAFLUSH, &save);
  return ch;
}


void gotoxy(int x, int y){
        printf("%c[%d;%df",0x1B,y,x);
}
