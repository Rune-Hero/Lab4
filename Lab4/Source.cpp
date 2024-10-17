#include <iostream>
#include <Windows.h>
#include <fstream>

using namespace std;

class SPORT_GAME {
protected:
    string name;
    int numberOfPlayers;
public:
    SPORT_GAME(string gameName, int players) : name(gameName), numberOfPlayers(players) {};

    ~SPORT_GAME() {
        cout << "������ ����������� SPORT_GAME\n"; 
    };

    virtual void displayInfo(ofstream &file)
    {
        file << "\n����� ���: " << name << endl;
        file << "\nʳ������ �������: " << numberOfPlayers << endl;
    }
};

class FOOTBALL : public SPORT_GAME {
private:
    int duration;
public:
    FOOTBALL(int matchDuration, int players) : duration(matchDuration), SPORT_GAME("������", players)
    {
        cout << "\n�������� " << name << " �� ��������� ����� " << matchDuration << " ������";
    }

    ~FOOTBALL() {
        cout << "������ ����������� FOOTBALL\n";
    };

    void displayInfo(ofstream &file) override
    {
        SPORT_GAME::displayInfo(file);
        file << "��������� �����: " << duration << " ������" << endl;
    }

};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    FOOTBALL footballGame(90, 11);
    
    ofstream OutputFile("D:/sport_game_info.txt");
    if (OutputFile.is_open())
    {
        footballGame.displayInfo(OutputFile);
        OutputFile.close();
        cout << "���������� ��� ��� �������� � ���� sport_game_info.txt\n";
    }
    else cout << "�� ������� ������� ���� ��� ������.\n";

    return 0;
}

