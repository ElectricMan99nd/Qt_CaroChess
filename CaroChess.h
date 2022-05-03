#ifndef CaroChess_H
#define CaroChess_H

#include <QObject>
#include <QAbstractListModel>
#include <QDebug>
#include <vector>
#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

#define ROW 10
#define COLUM 10
#define GAME_WIN 4
enum PlayerType{
    PLAYER_1 = 0,
    PLAYER_2 = 1
};

typedef struct{
    int x;
    int y;
}Point;

class CaroChess: public QObject
{
    Q_OBJECT
private:
    vector <Point> GameData;
public:
    char caroBoard[ROW][COLUM];
    explicit CaroChess(QObject *parent = nullptr);

    Q_INVOKABLE QString caroXO();
    Q_INVOKABLE void caroToaDo(const int &index);
//    Q_INVOKABLE QString caroCheck();
//    Q_INVOKABLE void caroReset();
    Q_INVOKABLE int getValueX(const uint8_t x);
    Q_INVOKABLE int getValueY(const uint8_t y);
    Q_INVOKABLE int getGameDataSize(void);
    Q_INVOKABLE void pushInVector(Point point);

//    Q_INVOKABLE void playerInput(PlayerType type);
    Q_INVOKABLE void playerTick(int x, int y);
    Q_INVOKABLE QString playerCheckWin();

    Q_INVOKABLE bool checkWinInRow(const int x, const int y, const char board[ROW][COLUM]);
    Q_INVOKABLE bool checkWinInColum(const int x, const int y, const char board[ROW][COLUM]);
    Q_INVOKABLE bool checkWinInCrossFirst(const int x, const int y, const char board[ROW][COLUM]);
    Q_INVOKABLE bool checkWinInCrossSecond(const int x, const int y, const char board[ROW][COLUM]);
    Q_INVOKABLE bool checkGameOver(const uint8_t turn);
    Q_INVOKABLE bool checkWin(const int x, const int y, const char board[ROW][COLUM]);
    Q_INVOKABLE void clearData(void);

};



#endif // CaroChess_H
