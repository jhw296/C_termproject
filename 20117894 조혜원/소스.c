/*
2�� 4�ο� �÷��� �׽�Ʈ�� ����

[����ȭ��] -> 2�� �Է� -> ��������� 4�Է�
���� �ߴ� �޽����� ��ü �����ϸ� �÷��̾� 1-4���� ��� �Է� ��.

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
1 5 9 3 7 2 4 8 6 10 11 15 19 13 17 12 14 18 16 20 25 24 22 23 21
7 5 24 1 2 20 6 3 4 9 10 22 8 15 18 23 19 12 21 16 25 13 14 17 11
24 19 5 9 18 7 6 22 16 23 4 8 13 2 21 3 12 1 20 15 11 14 25 17 10
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h> //sleep �Լ�

void mainscreen();
void computerbingoboard(int size); //��ǻ�� ���� ���� �Լ�
void playerbingoboard(int size); //�÷��̾� ���� ���� �Լ�
void player2_bingoboard(int size);
void player3_bingoboard(int size);
void player4_bingoboard(int size);
void computerplay(); //��ǻ�Ϳ� 1:1�� �÷����ϴ� �Լ�
void playerplay(); //�÷��̾�� �÷����ϴ� �Լ�
int c_bingo(int size); //��ǻ�� ���� ���� ī��Ʈ �Լ�
int p_bingo(int size); //�÷��̾� ���� ���� ī��Ʈ �Լ�
int p2_bingo(int size);
int p3_bingo(int size);
int p4_bingo(int size);
void resultscreen(int size); //���� ���â ȭ��

int computerbingo[10][10] = { 0, };
int playerbingo[10][10] = { 0, };
int playerbingo2[10][10] = { 0, };
int playerbingo3[10][10] = { 0, };
int playerbingo4[10][10] = { 0, };
int size; //������ ������
int delete_num = 0; //�����ǿ��� ������ ����
int computer_randnum = 0; //��ǻ�Ͱ� �����ǿ��� ������ ����
int order = 0; //���� �Է��ϴ� ���� ����
int person_num = 1; //�÷��̾� ��
int computerbingocnt = 0; //��ǻ�� ���� ���� ī��Ʈ
int playerbingocnt = 0, player2bingocnt = 0, player3bingocnt = 0, player4bingocnt = 0; //�÷��̾� ���� ���� ī��Ʈ


int main() {
    mainscreen();

    int choosenum;

    printf("�÷��� �� ����(1, 2)�� �����ϼ���. > ");
    scanf_s("%d", &choosenum);

    switch (choosenum) {
    case 1:
        computerplay(); //��ǻ�Ϳ� 1:1�� �÷����ϴ� �Լ�
        break;
    case 2:
        playerplay(); //�÷��̾�� �÷����ϴ� �Լ�
        break;
    default:
        printf("�߸��Է��ϼ̽��ϴ�.");
    }
 
}

void mainscreen() {
    printf("\n");
    printf("  ########    ##   ##       ##    ########     ######## \n");
    printf("  ##     ##   ##   ####     ##   ##           ##      ##\n");
    printf("  ##     ##   ##   ## ##    ##   ##           ##      ##\n");
    printf("  #########   ##   ##  ##   ##   ##   ####    ##      ##\n");
    printf("  ##     ##   ##   ##   ##  ##   ##      ##   ##      ##\n");
    printf("  ##     ##   ##   ##     ####   ##      ##   ##      ##\n");
    printf("  ########    ##   ##       ##    #######      ######## \n");
    printf("\n");
    printf(" ----------------------------------------------------------\n");
    printf("|               1. ��ǻ�Ϳ� 1:1 �÷���                     |\n");
    printf("|               2. �÷��̾� 2~4�� �÷���                   |\n");
    printf(" ----------------------------------------------------------\n\n");
    printf("               * 1�� �÷��� �� ��ǻ�� ���ڰ�\n");
    printf("            �����µ� �ټ� �ð��� �ɸ� �� �ֽ��ϴ�.\n\n\n");
}

//��ǻ�Ϳ� 1:1�� �÷����ϴ� �Լ�
void computerplay() { 
    printf("\n������ ����� �Է��ϼ���(5~10) : ");
    scanf_s("%d", &size);

    computerbingoboard(size);
    playerbingoboard(size);
    while (1) {
        order++;
        computerbingocnt = c_bingo(size); //��ǻ�� ���� ���� ī��Ʈ �Լ�
        playerbingocnt = p_bingo(size); //�÷��̾� ���� ���� ī��Ʈ �Լ�

        //��ǻ�� ���� ���� ǥ��
        if (computerbingocnt == 0) printf("\nCOMPUTER BINGO : �� �� �� �� ��\n");
        else if (computerbingocnt == 1) printf("COMPUTER BINGO : �� �� �� �� ��\n");
        else if (computerbingocnt == 2) printf("COMPUTER BINGO : �� �� �� �� ��\n");
        else if (computerbingocnt == 3) printf("COMPUTER BINGO : �� �� �� �� ��\n");
        else if (computerbingocnt == 4) printf("COMPUTER BINGO : �� �� �� �� ��\n");
        else if (computerbingocnt == 5) {
            printf("COMPUTER BINGO : �� �� �� �� ��\n");
            printf("\nYOU LOSE\n");
            printf("\n����� ��ǻ�Ϳ� �÷��̾��� ���â�� �������ϴ�.");
            Sleep(5000);
            resultscreen(size);
            exit(0); //���� ����
        }

        //�÷��̾� ���� ���� ǥ��
        if (playerbingocnt == 0) printf("\nPLAYER BINGO : �� �� �� �� ��\n");
        else if (playerbingocnt == 1) printf("\nPLAYER BINGO : �� �� �� �� ��\n");
        else if (playerbingocnt == 2) printf("\nPLAYER BINGO : �� �� �� �� ��\n");
        else if (playerbingocnt == 3) printf("\nPLAYER BINGO : �� �� �� �� ��\n");
        else if (playerbingocnt == 4) printf("\nPLAYER BINGO : �� �� �� �� ��\n");
        else if (playerbingocnt == 5) {
            printf("\nPLAYER BINGO : �� �� �� �� ��\n");
            printf("\n!!! YOU WIN !!!\n");
            printf("\n����� ��ǻ�Ϳ� �÷��̾��� ���â�� �������ϴ�.");
            Sleep(5000);
            resultscreen(size);
            exit(0); //���� ����
        }


        //�����ǿ��� ������ ���� �Է�
        if (order % 2 == 1) {
            printf("\n�����ǿ� �����ϴ� ���ڸ� �Է��ϼ���. > ");
            scanf_s("%d", &delete_num);
        }
        else {
            while (1)
            {
                srand((long)time(NULL));

                computer_randnum = computerbingo[rand() % size + 1][rand() % size + 1];
                if (computer_randnum != 0) {
                    printf("\n��ǻ���� ���ڴ� %d�Դϴ�.", computer_randnum);
                    Sleep(2000);
                    break;
                }
            }
            
        }

        //������(��ǻ��, �÷��̾�)�� ���ڿ� �Է��� ���ڰ� ���� ��� 0���� �ʱ�ȭ
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

        /*
        //��ǻ�� ������ ���
        printf("Computer\n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                printf(" %3d", computerbingo[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        */

        //�÷��̾� ������ ���
        printf("\nPlayer\n\n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (playerbingo[i][j] == 0) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                    printf(" %3d", playerbingo[i][j]);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else {
                    printf(" %3d", playerbingo[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n");
    }
}

//�÷��̾�� �÷����ϴ� �Լ�
void playerplay() {
    printf("\n������ ����� �Է��ϼ���(5~10) : ");
    scanf_s("%d", &size);
    printf("\n�÷��̾��� ���� �Է��ϼ���(2-4) : ");
    scanf_s("%d", &person_num);

    if (person_num == 2) {
        playerbingoboard(size);
        player2_bingoboard(size);
    }
    else if (person_num == 3) {
        playerbingoboard(size);
        player2_bingoboard(size);
        player3_bingoboard(size);
    }
    else {
        playerbingoboard(size);
        player2_bingoboard(size);
        player3_bingoboard(size);
        player4_bingoboard(size);
    }

    printf("\n����� ȭ���� ������ϴ�. \n\n�ڽ��� ȭ���� Ȯ���ϼ���.\n");
    Sleep(5000);
    system("cls");

    while (1) {
        order++;
        playerbingocnt = p_bingo(size); //�÷��̾� ���� ���� ī��Ʈ �Լ�
        player2bingocnt = p2_bingo(size);
        player3bingocnt = p3_bingo(size);
        player4bingocnt = p4_bingo(size);

        //�÷��̾� ������ ���
        if (person_num == 2) {
            if (order % 2 == 1) {
                printf("\nPlayer 1\n\n");
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++) {
                        if (playerbingo[i][j] == 0) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                            printf(" %3d", playerbingo[i][j]);
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                        else {
                            printf(" %3d", playerbingo[i][j]);
                        }
                    }
                    printf("\n");
                }
                printf("\n");
            }
            else {
                printf("\nPlayer 2\n\n");
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++) {
                        if (playerbingo2[i][j] == 0) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                            printf(" %3d", playerbingo2[i][j]);
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                        else {
                            printf(" %3d", playerbingo2[i][j]);
                        }
                    }
                    printf("\n");
                }
                printf("\n");
            }
        }
        if (person_num == 3) {
            if (order % 3 == 1) {
                printf("\nPlayer 1\n\n");
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++) {
                        if (playerbingo[i][j] == 0) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                            printf(" %3d", playerbingo[i][j]);
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                        else {
                            printf(" %3d", playerbingo[i][j]);
                        }
                    }
                    printf("\n");
                }
                printf("\n");
            }
            else if (order % 3 == 2) {
                printf("\nPlayer 2\n\n");
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++) {
                        if (playerbingo2[i][j] == 0) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                            printf(" %3d", playerbingo2[i][j]);
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                        else {
                            printf(" %3d", playerbingo2[i][j]);
                        }
                    }
                    printf("\n");
                }
                printf("\n");
            }
            else {
                printf("\nPlayer 3\n\n");
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++) {
                        if (playerbingo3[i][j] == 0) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                            printf(" %3d", playerbingo3[i][j]);
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                        else {
                            printf(" %3d", playerbingo3[i][j]);
                        }
                    }
                    printf("\n");
                }
                printf("\n");
            }
        }
        if (person_num == 4) {
            if (order % 4 == 1) {
                printf("\nPlayer 1\n\n");
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++) {
                        if (playerbingo[i][j] == 0) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                            printf(" %3d", playerbingo[i][j]);
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                        else {
                            printf(" %3d", playerbingo[i][j]);
                        }
                    }
                    printf("\n");
                }
                printf("\n");
            }
            else if (order % 4 == 2) {
                printf("\nPlayer 2\n\n");
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++) {
                        if (playerbingo2[i][j] == 0) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                            printf(" %3d", playerbingo2[i][j]);
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                        else {
                            printf(" %3d", playerbingo2[i][j]);
                        }
                    }
                    printf("\n");
                }
                printf("\n");
            }
            else if (order % 4 == 3) {
                printf("\nPlayer 3\n\n");
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++) {
                        if (playerbingo3[i][j] == 0) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                            printf(" %3d", playerbingo3[i][j]);
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                        else {
                            printf(" %3d", playerbingo3[i][j]);
                        }
                    }
                    printf("\n");
                }
                printf("\n");
            }
            else {
                printf("\nPlayer 4\n\n");
                for (int i = 0; i < size; i++) {
                    for (int j = 0; j < size; j++) {
                        if (playerbingo4[i][j] == 0) {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                            printf(" %3d", playerbingo4[i][j]);
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                        }
                        else {
                            printf(" %3d", playerbingo4[i][j]);
                        }
                    }
                    printf("\n");
                }
                printf("\n");
            }
        }

        //�÷��̾� ���� ���� ǥ��
        if (playerbingocnt == 0) printf("\nPLAYER 1 BINGO : �� �� �� �� ��\n");
        else if (playerbingocnt == 1) printf("\nPLAYER 1 BINGO : �� �� �� �� ��\n");
        else if (playerbingocnt == 2) printf("\nPLAYER 1 BINGO : �� �� �� �� ��\n");
        else if (playerbingocnt == 3) printf("\nPLAYER 1 BINGO : �� �� �� �� ��\n");
        else if (playerbingocnt == 4) printf("\nPLAYER 1 BINGO : �� �� �� �� ��\n");
        else if (playerbingocnt == 5) printf("\nPLAYER 1 BINGO : �� �� �� �� ��\n");

        if (player2bingocnt == 0) printf("\nPLAYER 2 BINGO : �� �� �� �� ��\n");
        else if (player2bingocnt == 1) printf("\nPLAYER 2 BINGO : �� �� �� �� ��\n");
        else if (player2bingocnt == 2) printf("\nPLAYER 2 BINGO : �� �� �� �� ��\n");
        else if (player2bingocnt == 3) printf("\nPLAYER 2 BINGO : �� �� �� �� ��\n");
        else if (player2bingocnt == 4) printf("\nPLAYER 2 BINGO : �� �� �� �� ��\n");
        else if (player2bingocnt == 5) printf("\nPLAYER 2 BINGO : �� �� �� �� ��\n");

        if (player3bingocnt == 0) printf("\nPLAYER 3 BINGO : �� �� �� �� ��\n");
        else if (player3bingocnt == 1) printf("\nPLAYER 3 BINGO : �� �� �� �� ��\n");
        else if (player3bingocnt == 2) printf("\nPLAYER 3 BINGO : �� �� �� �� ��\n");
        else if (player3bingocnt == 3) printf("\nPLAYER 3 BINGO : �� �� �� �� ��\n");
        else if (player3bingocnt == 4) printf("\nPLAYER 3 BINGO : �� �� �� �� ��\n");
        else if (player3bingocnt == 5) printf("\nPLAYER 3 BINGO : �� �� �� �� ��\n");

        if (player4bingocnt == 0) printf("\nPLAYER 4 BINGO : �� �� �� �� ��\n");
        else if (player4bingocnt == 1) printf("\nPLAYER 4 BINGO : �� �� �� �� ��\n");
        else if (player4bingocnt == 2) printf("\nPLAYER 4 BINGO : �� �� �� �� ��\n");
        else if (player4bingocnt == 3) printf("\nPLAYER 4 BINGO : �� �� �� �� ��\n");
        else if (player4bingocnt == 4) printf("\nPLAYER 4 BINGO : �� �� �� �� ��\n");
        else if (player4bingocnt == 5) printf("\nPLAYER 4 BINGO : �� �� �� �� ��\n");

        if (playerbingocnt == 5 || player2bingocnt == 5 || player3bingocnt == 5 || player4bingocnt == 5) {
            printf("\n����� ��ǻ�Ϳ� �÷��̾��� ���â�� �������ϴ�.");
            Sleep(5000);
            resultscreen(size);
            exit(0);
        }

        //�����ǿ��� ������ ���� �Է�
        if (person_num == 2) {
            if (order % 2 == 1) printf("\nPlayer 1 - �����ǿ� �����ϴ� ���ڸ� �Է��ϼ���. > ");
            else printf("\nPlayer 2 - �����ǿ� �����ϴ� ���ڸ� �Է��ϼ���. > ");
            scanf_s("%d", &delete_num);
        }
        if (person_num == 3) {
            if (order % 3 == 1) printf("\nPlayer 1 - �����ǿ� �����ϴ� ���ڸ� �Է��ϼ���. > ");
            else if (order % 3 == 2)printf("\nPlayer 2 - �����ǿ� �����ϴ� ���ڸ� �Է��ϼ���. > ");
            else printf("\nPlayer 3 - �����ǿ� �����ϴ� ���ڸ� �Է��ϼ���. > ");
            scanf_s("%d", &delete_num);
        }
        if (person_num == 4) {
            if (order % 4 == 1) printf("\nPlayer 1 - �����ǿ� �����ϴ� ���ڸ� �Է��ϼ���. > ");
            else if (order % 4 == 2) printf("\nPlayer 2 - �����ǿ� �����ϴ� ���ڸ� �Է��ϼ���. > ");
            else if (order % 4 == 3) printf("\nPlayer 3 - �����ǿ� �����ϴ� ���ڸ� �Է��ϼ���. > ");
            else printf("\nPlayer 4 - �����ǿ� �����ϴ� ���ڸ� �Է��ϼ���. > ");
            scanf_s("%d", &delete_num);
        }

        //�������� ���ڿ� �Է��� ���ڰ� ���� ��� 0���� �ʱ�ȭ
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (playerbingo[i][j] == delete_num) {
                    playerbingo[i][j] = 0;
                }
                if (playerbingo2[i][j] == delete_num) {
                    playerbingo2[i][j] = 0;
                }
                if (playerbingo3[i][j] == delete_num) {
                    playerbingo3[i][j] = 0;
                }
                if (playerbingo4[i][j] == delete_num) {
                    playerbingo4[i][j] = 0;
                }
            }
        }
        system("cls");
    }
}

//��ǻ�� ���� ���� �Լ�
void computerbingoboard(int size) {
    int temp[100] = { 0, };
    int randnum;

    //�Է��� ���� ũ�⿡ ���� ���� ����
    srand((long)time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            while (1)
            {
                randnum = rand() % (size * size) + 1;
                if (temp[randnum] == 0) { //temp�迭�� 0�϶��� ���� ����
                    computerbingo[i][j] = randnum;
                    temp[randnum] = 1;
                    break;
                }
            }
        }
    }
}

//�÷��̾� ���� ���� �Լ�
void playerbingoboard(int size) {
    printf("\n���ϴ� ����(1~%d)�� �ߺ����� �ʰ� �Է��ϼ���.(���μ�)\n", size * size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf_s("%d", &playerbingo[i][j]);
        }
    }

    system("cls");
    printf("\n");
    printf("Player 1\n\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf(" %3d", playerbingo[i][j]);
        }
        printf("\n");
    }
}

//�÷��̾�2 ���� ���� �Լ�
void player2_bingoboard(int size) {
    printf("\n���ϴ� ����(1~%d)�� �ߺ����� �ʰ� �Է��ϼ���.(���μ�)\n", size * size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf_s("%d", &playerbingo2[i][j]);
        }
    }
    printf("\n");
    printf("Player 2\n\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf(" %3d", playerbingo2[i][j]);
        }
        printf("\n");
    }
}

//�÷��̾�3 ���� ���� �Լ�
void player3_bingoboard(int size) {
    printf("\n���ϴ� ����(1~%d)�� �ߺ����� �ʰ� �Է��ϼ���.(���μ�)\n", size * size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf_s("%d", &playerbingo3[i][j]);
        }
    }
    printf("\n");
    printf("Player 3\n\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf(" %3d", playerbingo3[i][j]);
        }
        printf("\n");
    }
}

//�÷��̾�4 ���� ���� �Լ�
void player4_bingoboard(int size) {
    printf("\n���ϴ� ����(1~%d)�� �ߺ����� �ʰ� �Է��ϼ���.(���μ�)\n", size * size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf_s("%d", &playerbingo4[i][j]);
        }
    }
    printf("\n");
    printf("Player 4\n\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf(" %3d", playerbingo4[i][j]);
        }
        printf("\n");
    }
}

//��ǻ�� ���� ī��Ʈ �Լ�
int c_bingo(int size) {
    int bingo[100] = { 0, };
    int computerbingocnt = 0;
    
    //����
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            bingo[i] += computerbingo[i][j];
        }
    }
    //����
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            bingo[size+i] += computerbingo[j][i];
        }
    }
    //���ʴ밢��
    for (int i = 0; i < size; i++) {
        bingo[size*2] += computerbingo[i][i];
    }
    //�����ʴ밢��
    for (int i = 0; i < size; i++) {
        bingo[size*2+1] += computerbingo[i][size-(i+1)];
    }

    //��ǻ���� �� ���� ����
    for (int i = 0; i <= size * 2 + 1; i++) {
        if (bingo[i] == 0) {
            computerbingocnt++;
        }
    }

    return computerbingocnt;
}

//�÷��̾� ���� ī��Ʈ �Լ�
int p_bingo(int size) {
    int bingo[100] = { 0, };
    int playerbingocnt = 0;

    //����
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            bingo[i] += playerbingo[i][j];
        }
    }
    //����
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            bingo[size + i] += playerbingo[j][i];
        }
    }
    //���ʴ밢��
    for (int i = 0; i < size; i++) {
        bingo[size * 2] += playerbingo[i][i];
    }
    //�����ʴ밢��
    for (int i = 0; i < size; i++) {
        bingo[size * 2 + 1] += playerbingo[i][size - (i + 1)];
    }

    //�÷��̾��� �� ���� ����
    for (int i = 0; i <= size * 2 + 1; i++) {
        if (bingo[i] == 0) {
            playerbingocnt++;
        }
    }

    return playerbingocnt;
}

//�÷��̾�2 ���� ī��Ʈ �Լ�
int p2_bingo(int size) {
    int bingo[100] = { 0, };
    int player2bingocnt = 0;

    //����
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            bingo[i] += playerbingo2[i][j];
        }
    }
    //����
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            bingo[size + i] += playerbingo2[j][i];
        }
    }
    //���ʴ밢��
    for (int i = 0; i < size; i++) {
        bingo[size * 2] += playerbingo2[i][i];
    }
    //�����ʴ밢��
    for (int i = 0; i < size; i++) {
        bingo[size * 2 + 1] += playerbingo2[i][size - (i + 1)];
    }

    //�÷��̾�2�� �� ���� ����
    for (int i = 0; i <= size * 2 + 1; i++) {
        if (bingo[i] == 0) {
            player2bingocnt++;
        }
    }

    return player2bingocnt;
}

//�÷��̾�3 ���� ī��Ʈ �Լ�
int p3_bingo(int size) {
    int bingo[100] = { 0, };
    int player3bingocnt = 0;

    //����
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            bingo[i] += playerbingo3[i][j];
        }
    }
    //����
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            bingo[size + i] += playerbingo3[j][i];
        }
    }
    //���ʴ밢��
    for (int i = 0; i < size; i++) {
        bingo[size * 2] += playerbingo3[i][i];
    }
    //�����ʴ밢��
    for (int i = 0; i < size; i++) {
        bingo[size * 2 + 1] += playerbingo3[i][size - (i + 1)];
    }

    //�÷��̾�2�� �� ���� ����
    for (int i = 0; i <= size * 2 + 1; i++) {
        if (bingo[i] == 0) {
            player3bingocnt++;
        }
    }

    return player3bingocnt;
}

//�÷��̾�4 ���� ī��Ʈ �Լ�
int p4_bingo(int size) {
    int bingo[100] = { 0, };
    int player4bingocnt = 0;

    //����
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            bingo[i] += playerbingo4[i][j];
        }
    }
    //����
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            bingo[size + i] += playerbingo4[j][i];
        }
    }
    //���ʴ밢��
    for (int i = 0; i < size; i++) {
        bingo[size * 2] += playerbingo4[i][i];
    }
    //�����ʴ밢��
    for (int i = 0; i < size; i++) {
        bingo[size * 2 + 1] += playerbingo4[i][size - (i + 1)];
    }

    //�÷��̾�2�� �� ���� ����
    for (int i = 0; i <= size * 2 + 1; i++) {
        if (bingo[i] == 0) {
            player4bingocnt++;
        }
    }

    return player4bingocnt;
}

void resultscreen(int size) {
    system("cls");
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
    if (person_num != 1) {
        if (playerbingocnt == 5) printf("PLAYER 1�� �¸��Դϴ�.\n");
        if (player2bingocnt == 5) printf("PLAYER 2�� �¸��Դϴ�.\n");
        if (player3bingocnt == 5) printf("PLAYER 3�� �¸��Դϴ�.\n");
        if (player4bingocnt == 5) printf("PLAYER 4�� �¸��Դϴ�.\n");
    }
    if (person_num == 1) {
        //��ǻ�� ������ ���
        printf("\nComputer\n\n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (computerbingo[i][j] == 0) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                    printf(" %3d", computerbingo[i][j]);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else {
                    printf(" %3d", computerbingo[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n��ǻ���� ���� ������ %d�� �Դϴ�.\n", computerbingocnt);
        printf("\n");
    }

    //�÷��̾� ������ ���
    printf("\nPlayer 1\n\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (playerbingo[i][j] == 0) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                printf(" %3d", playerbingo[i][j]);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            }
            else {
                printf(" %3d", playerbingo[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n�÷��̾��� ���� ������ %d�� �Դϴ�.\n", playerbingocnt);
    printf("\n");

    if (person_num > 1){
        printf("\nPlayer 2\n\n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (playerbingo2[i][j] == 0) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                    printf(" %3d", playerbingo2[i][j]);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else {
                    printf(" %3d", playerbingo2[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n�÷��̾��� ���� ������ %d�� �Դϴ�.\n", player2bingocnt);
        printf("\n");

        printf("\nPlayer 3\n\n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (playerbingo3[i][j] == 0) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                    printf(" %3d", playerbingo3[i][j]);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else {
                    printf(" %3d", playerbingo3[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n�÷��̾��� ���� ������ %d�� �Դϴ�.\n", player3bingocnt);
        printf("\n");

        printf("\nPlayer 4\n\n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (playerbingo4[i][j] == 0) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
                    printf(" %3d", playerbingo4[i][j]);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                }
                else {
                    printf(" %3d", playerbingo4[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n�÷��̾��� ���� ������ %d�� �Դϴ�.\n", player4bingocnt);
        printf("\n");
    }

}