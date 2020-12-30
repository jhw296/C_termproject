/*
2번 4인용 플레이 테스트용 숫자

[메인화면] -> 2번 입력 -> 빙고사이즈 4입력
이후 뜨는 메시지에 전체 복붙하면 플레이어 1-4까지 모두 입력 됨.

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
1 5 9 3 7 2 4 8 6 10 11 15 19 13 17 12 14 18 16 20 25 24 22 23 21
7 5 24 1 2 20 6 3 4 9 10 22 8 15 18 23 19 12 21 16 25 13 14 17 11
24 19 5 9 18 7 6 22 16 23 4 8 13 2 21 3 12 1 20 15 11 14 25 17 10
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h> //sleep 함수

void mainscreen();
void computerbingoboard(int size); //컴퓨터 빙고 설정 함수
void playerbingoboard(int size, int playerbingo[10][10]); //플레이어 빙고 설정 함수
void playerbingoprint(int size, int playerbingo[10][10]); //플레이어 빙고 출력 함수
void computerplay(); //컴퓨터와 1:1로 플레이하는 함수
void playerplay(); //플레이어끼리 플레이하는 함수
int c_bingo(int size); //컴퓨터 빙고 개수 카운트 함수
int p_bingo(int size, int playerbingo[10][10]); //플레이어 빙고 개수 카운트 함수
void moveresult(); //결과창으로 이동하는 함수
void resultscreen(int size); //최종 결과창 화면

int computerbingo[10][10] = { 0, };
int playerbingo[10][10] = { 0, }, playerbingo2[10][10] = { 0, }, playerbingo3[10][10] = { 0, }, playerbingo4[10][10] = { 0, };
int size; //빙고판 사이즈
int delete_num = 0; //빙고판에서 삭제할 숫자
int computer_randnum = 0; //컴퓨터가 빙고판에서 삭제할 숫자
int order = 0; //숫자 입력하는 순서 구분
int person_num = 1; //플레이어 수
int computerbingocnt = 0; //컴퓨터 빙고 개수 카운트
int playerbingocnt = 0, player2bingocnt = 0, player3bingocnt = 0, player4bingocnt = 0; //플레이어 빙고 개수 카운트

int main() {
    system("title ★☆빙고☆★");
    system("mode con cols=60 lines=30");
    mainscreen();
    int choosenum;

    if (getch() == 27) exit(0); //esc 누를 경우 종료
    else {
        printf("플레이 할 게임(1, 2)를 선택하세요. > ");
        scanf_s("%d", &choosenum);

        switch (choosenum) {
        case 1:
            computerplay(); //컴퓨터와 1:1로 플레이하는 함수
            break;
        case 2:
            playerplay(); //플레이어끼리 플레이하는 함수
            break;
        default:
            printf("잘못입력하셨습니다.");
            exit(0);
        }
    }
}

void mainscreen() {
    printf("컴퓨터소프트웨어학부 20117894 조혜원\n\n\n");
    printf("  ########    ##   ##       ##    ########     ######## \n");
    printf("  ##     ##   ##   ####     ##   ##           ##      ##\n");
    printf("  ##     ##   ##   ## ##    ##   ##           ##      ##\n");
    printf("  #########   ##   ##  ##   ##   ##   ####    ##      ##\n");
    printf("  ##     ##   ##   ##   ##  ##   ##      ##   ##      ##\n");
    printf("  ##     ##   ##   ##     ####   ##      ##   ##      ##\n");
    printf("  ########    ##   ##       ##    #######      ######## \n");
    printf("\n");
    printf(" ----------------------------------------------------------\n");
    printf("|                 1. 컴퓨터와 1:1 플레이                   |\n");
    printf("|                 2. 플레이어 2~4명 플레이                 |\n");
    printf(" ----------------------------------------------------------\n\n");
    printf("               * 1번 플레이 시 컴퓨터 숫자가\n");
    printf("            나오는데 다소 시간이 걸릴 수 있습니다.\n\n\n");
    printf("          게임 플레이를 원한다면 아무키나 누르시고\n");
    printf("               종료를 원한다면 ESC를 누르세요.\n\n\n");
}

//컴퓨터와 1:1로 플레이하는 함수
void computerplay() {
    printf("\n빙고판 사이즈를 입력하세요(5~10) > ");
    scanf_s("%d", &size);
    printf("\n플레이어 수가 한 명임으로 1을 입력하세요 > ");
    scanf_s("%d", &person_num);

    int order = 0;
    int delete_num = 0; //빙고판에서 삭제할 숫자
    int computer_randnum = 0; //컴퓨터가 빙고판에서 삭제할 숫자
    
    computerbingoboard(size);
    playerbingoboard(size, playerbingo);
    system("cls");
    playerbingoprint(size, playerbingo);
    while (1) {
        order++;
        computerbingocnt = c_bingo(size); //컴퓨터 빙고 개수 카운트 함수
        playerbingocnt = p_bingo(size, playerbingo); //플레이어 빙고 개수 카운트 함수

        //컴퓨터 빙고 개수 표시
        if (computerbingocnt == 0) printf("\nCOMPUTER BINGO : ○ ○ ○ ○ ○\n");
        else if (computerbingocnt == 1) printf("COMPUTER BINGO : ● ○ ○ ○ ○\n");
        else if (computerbingocnt == 2) printf("COMPUTER BINGO : ● ● ○ ○ ○\n");
        else if (computerbingocnt == 3) printf("COMPUTER BINGO : ● ● ● ○ ○\n");
        else if (computerbingocnt == 4) printf("COMPUTER BINGO : ● ● ● ● ○\n");
        else if (computerbingocnt == 5 && playerbingocnt != 5) {
            printf("COMPUTER BINGO : ● ● ● ● ●\n");
            printf("\nYOU LOSE\n");
            moveresult();
        }

        //플레이어 빙고 개수 표시
        if (playerbingocnt == 0) printf("\nPLAYER BINGO : ○ ○ ○ ○ ○\n");
        else if (playerbingocnt == 1) printf("\nPLAYER BINGO : ● ○ ○ ○ ○\n");
        else if (playerbingocnt == 2) printf("\nPLAYER BINGO : ● ● ○ ○ ○\n");
        else if (playerbingocnt == 3) printf("\nPLAYER BINGO : ● ● ● ○ ○\n");
        else if (playerbingocnt == 4) printf("\nPLAYER BINGO : ● ● ● ● ○\n");
        else if (playerbingocnt == 5 && computerbingocnt != 5) {
            printf("\nPLAYER BINGO : ● ● ● ● ●\n");
            printf("\n!!! YOU WIN !!!\n");
            moveresult();
        }

        if (computerbingocnt == 5 && playerbingocnt == 5) {
            printf("\n무승부입니다.\n");
            moveresult();
        }

        //빙고판에서 삭제할 숫자 입력
        if (order % 2 == 1) { //플레이어 순서일 경우
            printf("\n빙고판에 존재하는 숫자를 입력하세요. > ");
            scanf_s("%d", &delete_num);
        }
        else {
            while (1)
            {
                //컴퓨터 빙고 숫자 출력
                srand((long)time(NULL));
                computer_randnum = computerbingo[rand() % size + 1][rand() % size + 1];
                if (computer_randnum != 0) {
                    printf("\n컴퓨터의 숫자는 %d입니다.", computer_randnum);
                    Sleep(1500);
                    break;
                }
            }

        }

        //빙고판(컴퓨터, 플레이어)의 숫자와 입력한 숫자가 같을 경우 0으로 초기화
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (playerbingo[i][j] == delete_num || playerbingo[i][j] == computer_randnum) {
                    playerbingo[i][j] = 0;
                }
                if (computerbingo[i][j] == delete_num || computerbingo[i][j] == computer_randnum) {
                    computerbingo[i][j] = 0;
                }
            }
        }
        system("cls");

        //플레이어 빙고판 출력
        playerbingoprint(size, playerbingo);
    }
}

//플레이어끼리 플레이하는 함수
void playerplay() {
    int order = 0;
    printf("\n빙고판 사이즈를 입력하세요(5~10) > ");
    scanf_s("%d", &size);
    printf("\n플레이어의 수를 입력하세요(2-4) > ");
    scanf_s("%d", &person_num);

    if (person_num == 2) {
        playerbingoboard(size, playerbingo);
        playerbingoboard(size, playerbingo2);
    }
    else if (person_num == 3) {
        playerbingoboard(size, playerbingo);
        playerbingoboard(size, playerbingo2);
        playerbingoboard(size, playerbingo3);
    }
    else {
        playerbingoboard(size, playerbingo);
        playerbingoboard(size, playerbingo2);
        playerbingoboard(size, playerbingo3);
        playerbingoboard(size, playerbingo4);
    }
    printf("\n잠시후 게임이 시작됩니다. \n\n");
    Sleep(5000);
    system("cls");

    while (1) {
        order++;
        playerbingocnt = p_bingo(size, playerbingo); //플레이어 빙고 개수 카운트 함수
        player2bingocnt = p_bingo(size, playerbingo2);
        player3bingocnt = p_bingo(size, playerbingo3);
        player4bingocnt = p_bingo(size, playerbingo4);

        //플레이어 빙고판 출력
        if (person_num == 2) {
            if (order % 2 == 1) playerbingoprint(size, playerbingo);
            else playerbingoprint(size, playerbingo2);
        }
        if (person_num == 3) {
            if (order % 3 == 1) playerbingoprint(size, playerbingo);
            else if (order % 3 == 2) playerbingoprint(size, playerbingo2);
            else playerbingoprint(size, playerbingo3);
        }
        if (person_num == 4) {
            if (order % 4 == 1) playerbingoprint(size, playerbingo);
            else if (order % 4 == 2) playerbingoprint(size, playerbingo2);
            else if (order % 4 == 3) playerbingoprint(size, playerbingo3);
            else playerbingoprint(size, playerbingo4);
        }

        //플레이어 빙고 개수 표시
        if (person_num == 2) {
            if (playerbingocnt == 5 || player2bingocnt == 5) {
                printf("\n승리자가 존재합니다.");
                moveresult();
            }
        }
        if (person_num == 3) {
            if (playerbingocnt == 5 || player2bingocnt == 5 || player3bingocnt == 5) {
                printf("\n승리자가 존재합니다.");
                moveresult();
            }
        }
        if (person_num == 4) {
            if (playerbingocnt == 5 || player2bingocnt == 5 || player3bingocnt == 5 || player4bingocnt == 5) {
                printf("\n승리자가 존재합니다.");
                moveresult();
            }
        }
        if (playerbingocnt == 0) printf("\nPLAYER 1 BINGO : ○ ○ ○ ○ ○\n");
        else if (playerbingocnt == 1) printf("\nPLAYER 1 BINGO : ● ○ ○ ○ ○\n");
        else if (playerbingocnt == 2) printf("\nPLAYER 1 BINGO : ● ● ○ ○ ○\n");
        else if (playerbingocnt == 3) printf("\nPLAYER 1 BINGO : ● ● ● ○ ○\n");
        else if (playerbingocnt == 4) printf("\nPLAYER 1 BINGO : ● ● ● ● ○\n");
        else if (playerbingocnt == 5) printf("\nPLAYER 1 BINGO : ● ● ● ● ●\n");

        if (person_num == 2 || person_num == 3 || person_num == 4) {
            if (player2bingocnt == 0) printf("\nPLAYER 2 BINGO : ○ ○ ○ ○ ○\n");
            else if (player2bingocnt == 1) printf("\nPLAYER 2 BINGO : ● ○ ○ ○ ○\n");
            else if (player2bingocnt == 2) printf("\nPLAYER 2 BINGO : ● ● ○ ○ ○\n");
            else if (player2bingocnt == 3) printf("\nPLAYER 2 BINGO : ● ● ● ○ ○\n");
            else if (player2bingocnt == 4) printf("\nPLAYER 2 BINGO : ● ● ● ● ○\n");
            else if (player2bingocnt == 5) printf("\nPLAYER 2 BINGO : ● ● ● ● ●\n");
        }
        if (person_num == 3 || person_num == 4) {
            if (player3bingocnt == 0) printf("\nPLAYER 3 BINGO : ○ ○ ○ ○ ○\n");
            else if (player3bingocnt == 1) printf("\nPLAYER 3 BINGO : ● ○ ○ ○ ○\n");
            else if (player3bingocnt == 2) printf("\nPLAYER 3 BINGO : ● ● ○ ○ ○\n");
            else if (player3bingocnt == 3) printf("\nPLAYER 3 BINGO : ● ● ● ○ ○\n");
            else if (player3bingocnt == 4) printf("\nPLAYER 3 BINGO : ● ● ● ● ○\n");
            else if (player3bingocnt == 5) printf("\nPLAYER 3 BINGO : ● ● ● ● ●\n");
        }
        if (person_num == 4) {
            if (player4bingocnt == 0) printf("\nPLAYER 4 BINGO : ○ ○ ○ ○ ○\n");
            else if (player4bingocnt == 1) printf("\nPLAYER 4 BINGO : ● ○ ○ ○ ○\n");
            else if (player4bingocnt == 2) printf("\nPLAYER 4 BINGO : ● ● ○ ○ ○\n");
            else if (player4bingocnt == 3) printf("\nPLAYER 4 BINGO : ● ● ● ○ ○\n");
            else if (player4bingocnt == 4) printf("\nPLAYER 4 BINGO : ● ● ● ● ○\n");
            else if (player4bingocnt == 5) printf("\nPLAYER 4 BINGO : ● ● ● ● ●\n");
        }

        //빙고판에서 삭제할 숫자 입력
        if (person_num == 2) {
            if (order % 2 == 1) printf("\nPlayer 1 - 빙고판에 존재하는 숫자를 입력하세요. > ");
            else printf("\nPlayer 2 - 빙고판에 존재하는 숫자를 입력하세요. > ");
            scanf_s("%d", &delete_num);
        }
        if (person_num == 3) {
            if (order % 3 == 1) printf("\nPlayer 1 - 빙고판에 존재하는 숫자를 입력하세요. > ");
            else if (order % 3 == 2)printf("\nPlayer 2 - 빙고판에 존재하는 숫자를 입력하세요. > ");
            else printf("\nPlayer 3 - 빙고판에 존재하는 숫자를 입력하세요. > ");
            scanf_s("%d", &delete_num);
        }
        if (person_num == 4) {
            if (order % 4 == 1) printf("\nPlayer 1 - 빙고판에 존재하는 숫자를 입력하세요. > ");
            else if (order % 4 == 2) printf("\nPlayer 2 - 빙고판에 존재하는 숫자를 입력하세요. > ");
            else if (order % 4 == 3) printf("\nPlayer 3 - 빙고판에 존재하는 숫자를 입력하세요. > ");
            else printf("\nPlayer 4 - 빙고판에 존재하는 숫자를 입력하세요. > ");
            scanf_s("%d", &delete_num);
        }

        //빙고판의 숫자와 입력한 숫자가 같을 경우 0으로 초기화
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (playerbingo[i][j] == delete_num) playerbingo[i][j] = 0;
                if (playerbingo2[i][j] == delete_num) playerbingo2[i][j] = 0;
                if (playerbingo3[i][j] == delete_num) playerbingo3[i][j] = 0;
                if (playerbingo4[i][j] == delete_num) playerbingo4[i][j] = 0;
            }
        }
        system("cls");
    }
}

//컴퓨터 빙고 설정 함수
void computerbingoboard(int size) {
    int temp[100] = { 0, };
    int randnum;

    //입력한 빙고 크기에 따라 난수 생성
    srand((long)time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            while (1)
            {
                randnum = rand() % (size * size) + 1;
                if (temp[randnum] == 0) { //temp배열이 0일때만 난수 생성
                    computerbingo[i][j] = randnum;
                    temp[randnum] = 1;
                    break;
                }
            }
        }
    }
}

//플레이어 빙고 설정 함수
void playerbingoboard(int size, int playerbingo[10][10]) {
    printf("\n원하는 숫자(1~%d)를 중복되지 않게 입력하세요.(가로순)\n", size * size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf_s("%d", &playerbingo[i][j]);
        }
    }
}

//플레이어 빙고 출력 함수
void playerbingoprint(int size, int playerbingo[10][10]) {
    printf("\nPlayer bingoboard\n\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (playerbingo[i][j] == 0) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                printf(" %3d", playerbingo[i][j]);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            else printf(" %3d", playerbingo[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//컴퓨터 빙고 카운트 함수
int c_bingo(int size) {
    int bingo[100] = { 0, };
    int computerbingocnt = 0;

    //가로
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            bingo[i] += computerbingo[i][j];
        }
    }
    //세로
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            bingo[size + i] += computerbingo[j][i];
        }
    }
    //왼쪽대각선
    for (int i = 0; i < size; i++) {
        bingo[size * 2] += computerbingo[i][i];
    }
    //오른쪽대각선
    for (int i = 0; i < size; i++) {
        bingo[size * 2 + 1] += computerbingo[i][size - (i + 1)];
    }
    //컴퓨터의 총 빙고 개수
    for (int i = 0; i <= size * 2 + 1; i++) {
        if (bingo[i] == 0) {
            computerbingocnt++;
        }
    }
    return computerbingocnt;
}

//플레이어 빙고 카운트 함수
int p_bingo(int size, int playerbingo[10][10]) {
    int bingo[100] = { 0, };
    int playerbingocnt = 0;

    //가로
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            bingo[i] += playerbingo[i][j];
        }
    }
    //세로
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            bingo[size + i] += playerbingo[j][i];
        }
    }
    //왼쪽대각선
    for (int i = 0; i < size; i++) {
        bingo[size * 2] += playerbingo[i][i];
    }
    //오른쪽대각선
    for (int i = 0; i < size; i++) {
        bingo[size * 2 + 1] += playerbingo[i][size - (i + 1)];
    }
    //플레이어의 총 빙고 개수
    for (int i = 0; i <= size * 2 + 1; i++) {
        if (bingo[i] == 0) {
            playerbingocnt++;
        }
    }
    return playerbingocnt;
}

//결과창으로 이동하는 함수
void moveresult() {
    printf("\n잠시후 결과창이 보여집니다.");
    Sleep(1500);
    resultscreen(size);
    printf("\n10초 후 메인으로 돌아갑니다.\n");
    Sleep(10000);
    system("cls");
    main();
}

void resultscreen(int size) {
    system("cls");
    system("mode con cols=60 lines=40");
    printf("\n\n");
    printf("  ########    ##   ##       ##    ########     ######## \n");
    printf("  ##     ##   ##   ####     ##   ##           ##      ##\n");
    printf("  ##     ##   ##   ## ##    ##   ##           ##      ##\n");
    printf("  #########   ##   ##  ##   ##   ##   ####    ##      ##\n");
    printf("  ##     ##   ##   ##   ##  ##   ##      ##   ##      ##\n");
    printf("  ##     ##   ##   ##     ####   ##      ##   ##      ##\n");
    printf("  ########    ##   ##       ##    #######      ######## \n");
    printf("\n");
    printf(" ----------------------------------------------------------\n\n");
    printf("             결과 확인 후 승리자를 정하세요.\n");

    if (person_num == 1) {
        //컴퓨터 빙고판 출력
        printf("\nComputer\n\n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (computerbingo[i][j] == 0) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                    printf(" %3d", computerbingo[i][j]);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else printf(" %3d", computerbingo[i][j]);
            }
            printf("\n");
        }
        printf("\n컴퓨터의 빙고 개수는 %d줄 입니다.\n\n", computerbingocnt);
    }

    //플레이어 빙고판 출력
    playerbingoprint(size, playerbingo);
    printf("\n플레이어1의 빙고 개수는 %d줄 입니다.\n\n", playerbingocnt);

    if (person_num == 2 || person_num == 3 || person_num == 4) {
        playerbingoprint(size, playerbingo2);
        printf("\n플레이어2의 빙고 개수는 %d줄 입니다.\n\n", player2bingocnt);
    }
    if (person_num == 3 || person_num == 4) {
        playerbingoprint(size, playerbingo3);
        printf("\n플레이어3의 빙고 개수는 %d줄 입니다.\n\n", player3bingocnt);
    }
    if (person_num == 4) {
        playerbingoprint(size, playerbingo4);
        printf("\n플레이어4의 빙고 개수는 %d줄 입니다.\n\n", player4bingocnt);
    }
}