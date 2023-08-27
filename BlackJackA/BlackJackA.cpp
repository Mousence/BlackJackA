#include <iostream>
#include <conio.h>

using namespace std;

int DealerCountCard = 2, ScoreDL = 0, OpenScoreDL = 0; bool EndDL = false;

int PlayerCountCard = 2, ScorePL = 0, OpenScorePL = 0; bool EndPL = false;

bool EndG = false;

void StartGame(char* Player, char* Dealer, char* PlayerSuit, char* DealerSuit) {
    int temp;
    for (int i = 0; i < 2; i++) {
    back:
        Player[i] = 50 + rand() % (81 - 50 + 1);
        if (!((Player[i] >= 50 && Player[i] <= 58) || Player[i] == 74 || Player[i] == 75 || Player[i] == 81 || Player[i] == 65)) {
            goto back;
        }
    back2:
        Dealer[i] = 50 + rand() % (81 - 50 + 1);
        if (!((Dealer[i] >= 50 && Dealer[i] <= 58) || Dealer[i] == 74 || Dealer[i] == 75 || Dealer[i] == 81 || Dealer[i] == 65))
            goto back2;
    backSuit:
        PlayerSuit[i] = 3 + rand() % (6 - 3);
        temp = PlayerSuit[i - 1];
        if ((i >= 1) && (PlayerSuit[i] == temp)) {
            goto backSuit;
        }
        temp = 0;
    backSuit1:
        DealerSuit[i] = 3 + rand() % (6 - 3);
        temp = DealerSuit[i - 1];
        if ((i >= 1) && (DealerSuit[i] == temp)) {
            goto backSuit1;
        }

        if (Dealer[i] == 74 || Dealer[i] == 75 || Dealer[i] == 81) { ScoreDL += 10, OpenScoreDL = 10; }
        else if (Dealer[i] == 65) { ScoreDL += 11, OpenScoreDL = 11; }
        else { ScoreDL += int(Dealer[i]) - 48, OpenScoreDL = int(Dealer[i]) - 48; }


        if (Player[i] == 74 || Player[i] == 75 || Player[i] == 81) { ScorePL += 10, OpenScorePL = 10; }
        else if (Player[i] == 65) { ScorePL += 11, OpenScorePL = 10; }
        else { ScorePL += (int(Player[i]) - 48), OpenScorePL = int(Player[i]) - 48; }



        if ((Player[0] == 'A' && Player[1] == 'A'))
            ScorePL = 21;
        if ((Dealer[0] == 'A' && Dealer[1] == 'A'))
            ScoreDL = 21;
    }
} //функция для начала игры и присваивания начальных очков

int GetCardPlayer(char* Player, char* PlayerSuit) {
    char* px = Player;
    int* pCount = &PlayerCountCard;
back:
    Player[PlayerCountCard] = 50 + rand() % (81 - 50 + 1);
    if (!((*(px + *pCount) >= 50 && *(px + *pCount) <= 58) || *(px + *pCount) == 74 || *(px + *pCount) == 75 || *(px + *pCount) == 81 || *(px + *pCount) == 65))
        goto back;
    PlayerSuit[PlayerCountCard] = 3 + rand() % (6 - 3);
    PlayerCountCard++;
    return (*(px + *pCount - 1) == 74 || *(px + *pCount - 1) == 75 || *(px + *pCount - 1) == 81 || *(px + *pCount - 1) == 65) ? 10 : *(px + *pCount - 1) - 48;

} //функция для взятия карты и сразу его возвращения в нормальные очки

int GetCardDealer(char* Dealer, char* DealerSuit) {
    char* px1 = Dealer;
    int* pCount1 = &DealerCountCard;
back:
    Dealer[DealerCountCard] = 50 + rand() % (81 - 50 + 1);
    if (!((*(px1 + *pCount1) >= 50 && *(px1 + *pCount1) <= 58) || *(px1 + *pCount1) == 74 || *(px1 + *pCount1) == 75 || *(px1 + *pCount1) == 81 || *(px1 + *pCount1) == 65))
        goto back;
    DealerSuit[DealerCountCard] = 3 + rand() % (6 - 3);
    DealerCountCard++;
    return (*(px1 + *pCount1 - 1) == 74 || *(px1 + *pCount1 - 1) == 75 || *(px1 + *pCount1 - 1) == 81 || *(px1 + *pCount1 - 1) == 65) ? 10 : *(px1 + *pCount1 - 1) - 48;

} //функция для взятия карты и сразу его возвращения в нормальные очки

void ShowField(char* Player, char* Dealer, char* PlayerSuit, char* DealerSuit) {
    //////////////////////////////////////////////////////////////////////// dealer
    cout << " ___________________" << "  ";
    for (int i = 1; i < DealerCountCard; i++)
        cout << " ____________________" << "   ";
    cout << endl;
    for (int j = 1; j < 14; j++) {
        cout << "|";
        if (j == 2)
            cout << "     ΘΘΘΘΘΘΘΘ      ";
        else if (j == 3)
            cout << "    Θ        Θ     ";
        else if (j == 4)
            cout << "    Θ        Θ     ";
        else if (j == 5)
            cout << "    Θ        Θ     ";
        else if (j == 6)
            cout << "            Θ      ";
        else if (j == 7)
            cout << "           Θ       ";
        else if (j == 8)
            cout << "          Θ        ";
        else if (j == 9)
            cout << "         Θ         ";
        else if (j == 10)
            cout << "        Θ          ";
        else if (j == 12)
            cout << "        Θ          ";
        else if (j == 13)
            cout << "___________________";
        else
            cout << "                   ";
        cout << "|";
        cout << "  ";
        for (int i = 1; i < DealerCountCard; i++) {
            cout << "|";
            if (j == 3)
                if (Dealer[i] == 58) {
                    cout << "     " << "10" << DealerSuit[i] << "           ";
                }
                else
                    cout << "     " << Dealer[i] << DealerSuit[i] << "            ";
            else if (j == 12)
                if (Dealer[i] == 58) {
                    cout << "           " << "10" << DealerSuit[i] << "     ";
                }
                else
                    cout << "           " << Dealer[i] << DealerSuit[i] << "      ";
            else if (j == 13)
                cout << "___________________";
            else
                cout << "                   ";
            cout << "|";
            cout << "   ";
        }
        cout << endl;
    }
    //////////////////////////////////////////////////////////////////////// показ очков
    if (!EndG) {
        cout << endl; cout << "Dealer: " << "\t" << "?";
    }
    else {
        if (Dealer[0] == 58)
            cout << "Dealer: " << "\t" << "10";
        else
            cout << "Dealer: " << "\t" << Dealer[0];
    }
    for (int i = 1; i < DealerCountCard; i++) {
        if (Dealer[i] == 58)
            cout << " + " << "10";
        else
            cout << " + " << Dealer[i];
    }
    cout << " = " << OpenScoreDL << endl;
    if (Player[0] == 58)
        cout << "Player: " << "\t" << "10";
    else
        cout << "Player: " << "\t" << Player[0];
    for (int i = 1; i < PlayerCountCard; i++) {
        if (Player[i] == 58)
            cout << " + " << "10";
        else
            cout << " + " << Player[i];
    } cout << " = " << ScorePL;
    cout << endl;
    //////////////////////////////////////////////////////////////////////// player
    for (int i = 0; i < PlayerCountCard; i++)
        cout << " ____________________" << "   ";
    cout << endl;
    for (int j = 0; j < 14; j++) {
        for (int i = 0; i < PlayerCountCard; i++) {
            cout << "|";
            if (j == 3)
                if (Player[i] == 58) {
                    cout << "     " << "10" << PlayerSuit[i] << "           ";
                }
                else
                    cout << "     " << Player[i] << PlayerSuit[i] << "            ";
            else if (j == 12)
                if (Player[i] == 58) {
                    cout << "           " << "10" << PlayerSuit[i] << "     ";
                }
                else
                    cout << "           " << Player[i] << PlayerSuit[i] << "      ";
            else if (j == 13)
                cout << "___________________";
            else
                cout << "                   ";
            cout << "|";
            cout << "   ";
        }
        cout << endl;
    }
    cout << endl;
} // показ стола

int CheckWinner(int ScoreDL, int ScorePL) {
    cout << endl;
    if (ScoreDL == ScorePL) {
        cout << "Ничья!";
        return 0;
    }
    //если перебор
    if (ScorePL > 21 || ScoreDL > 21) {
        if (ScorePL > 21 && ScoreDL > 21) {
            if (ScorePL > ScoreDL)
                cout << "Вы выйграли!";
            else
                cout << "Вы проиграли!";
            return 0;
        }
        if (ScorePL > ScoreDL)
            cout << "Вы проиграли!";
        else
            cout << "Вы выйграли!";
        return 0;
    }

    if (ScorePL > ScoreDL)
        cout << "Вы выйграли!";
    else
        cout << "Вы проиграли!";
    return 0;
}


int main()
{
    setlocale(LC_ALL, "");
    srand(time(NULL));
    const int size = 10;
    char Player[10], Dealer[10];
    char PlayerSuit[10], DealerSuit[10];
    StartGame(Player, Dealer, PlayerSuit, DealerSuit);

    cout << "Игра BlackJack" << endl;
    system("pause");

    for (;;) {
        int choice = 0, temp = 0;
        ShowField(Player, Dealer, PlayerSuit, DealerSuit);
        if (ScorePL >= 21) {
            EndDL = 1;
            EndPL = 1;
            goto end;
        }
        if (ScoreDL >= 21) {
            EndDL = 1;
            EndPL = 1;
            goto end;
        }

        cout << "Взять карту(1), Пас(0): " << endl; cout << "Ваш выбор: "; choice = static_cast<int> (_getch());

        switch (choice)
        {
        case 49:
            temp = GetCardPlayer(Player, PlayerSuit);
            OpenScorePL += temp;
            ScorePL += temp;
            break;
        case 48:
            EndPL = true;
            break;
        default:
            cout << "Ошибка!" << endl;
            break;
        }

        if (ScoreDL >= 5 && ScoreDL <= 8)
        {
            temp = GetCardDealer(Dealer, DealerSuit);
            OpenScoreDL += temp;
            ScoreDL += temp;
        }
        if ((ScoreDL >= 12 && ScoreDL <= 16) && (OpenScorePL >= 2 && OpenScorePL <= 6))
        {
            temp = GetCardDealer(Dealer, DealerSuit);
            OpenScoreDL += temp;
            ScoreDL += temp;
        }
        if (ScoreDL >= 17)
            EndDL = true;
        if (ScoreDL <= 17) {
            temp = GetCardDealer(Dealer, DealerSuit);
            OpenScoreDL += temp;
            ScoreDL += temp;
        }

    end:
        if (EndDL == true && EndPL == true) {
            EndG = true;
            OpenScoreDL = ScoreDL;
            ShowField(Player, Dealer, PlayerSuit, DealerSuit);
            CheckWinner(ScoreDL, ScorePL);
            break;
        }
    }
}