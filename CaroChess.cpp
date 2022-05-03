#include "CaroChess.h"

CaroChess:: CaroChess(QObject *parent ):QObject(parent){}

QString CaroChess::caroXO(){
    if(getGameDataSize() == 0){
      return "X";
    }
    else if( (getGameDataSize() - 1) % 2 == 0 ){
      return "O";
    }
    else{
      return "X";
    }
}

void CaroChess::clearData(void){
    GameData.clear();
}

void CaroChess::clearBoard(){
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUM; j++)
        {
            caroBoard[i][j] = ' ';
        }
    }
}

int CaroChess::getValueX(const uint8_t x){
    return GameData[x].x;
}

int CaroChess::getValueY(const uint8_t y){
    return GameData[y].y;
}

int CaroChess::getGameDataSize(){
    return GameData.size();
}

void CaroChess::pushInVector(Point point){
    GameData.push_back(point);
}

void CaroChess :: caroToaDo(const int &index){
    int x;
    int y;
    x = index%20;
    y = index/20;
    playerTick(x, y);
};

void CaroChess::playerTick(int x, int y){
    if(getGameDataSize() == 0){
        Point temp;
        temp.x = x;
        temp.y = y;
        pushInVector(temp);
        caroBoard[x][y] = 'X';
    }
    else if( (getGameDataSize() - 1) % 2 == 0 ){
        Point temp;
        temp.x = x;
        temp.y = y;
        pushInVector(temp);
        caroBoard[x][y] = 'O';
    }
    else{
        Point temp;
        temp.x = x;
        temp.y = y;
        pushInVector(temp);
        caroBoard[x][y] = 'X';
    }
}

QString CaroChess::playerCheckWin(){
    QString result = "";
    if(checkWin(getValueX(getGameDataSize() - 1), getValueY(getGameDataSize() - 1), caroBoard)){
        int index = getGameDataSize() - 1;
        if(index % 2 == 0){
           result = "X win";
           return result;
           clearData();
        }else{
            result = "O win";
            return result;
            clearData();
        }
    }
    return 0;
//    if(checkGameOver(getGameDataSize())){
//        result = "Draw";
//        return result;
//    }
}

bool CaroChess::checkWinInRow(const int x, const int y, const char board[ROW][COLUM]){
    int xVal = x;
    int yVal = y;
    char temp = board[xVal][yVal];
    int counter = 1;
    int i = yVal;
    while(i > 0){
        i--;
        if(board[xVal][i]  == temp){
            counter++;
            if(counter >= GAME_WIN){
                return true;
            }
        }
        else{
            break;
        }
    }
    i = yVal;
    while(i < COLUM - 1){
        i++;
        if(board[xVal][i] == temp){
            counter++;
            if(counter >= GAME_WIN){
                return true;
            }
        }
        else{
            return false;
        }
    }
    return false;
}

bool CaroChess::checkWinInColum(const int x, const int y, const char board[ROW][COLUM]){
    int xVal = x;
    int yVal = y;
    char temp = board[xVal][yVal];
    int counter = 1;
    int i = xVal;
    while(i > 0){
        i--;
        if(board[i][yVal]  == temp){
            counter++;
            if(counter >= GAME_WIN){
                return true;
            }
        }
        else{
            break;
        }
    }
    i = xVal;
    while(i < COLUM - 1){
        i++;
        if(board[i][yVal] == temp){
            counter++;
            if(counter >= GAME_WIN){
                return true;
            }
        }
        else{
            return false;
        }
    }
    return false;
}

bool CaroChess::checkWinInCrossFirst(const int x, const int y, const char board[ROW][COLUM]){
    int xVal = x;
    int yVal = y;
    char temp = board[xVal][yVal];
    int counter = 1;
    int i = xVal;
    int j = yVal;
    while(i > 0 && j > 0){
        i--;
        j--;
        if(board[i][j] == temp){
            counter++;
            if(counter >= GAME_WIN){
                return true;
            }
        }
        else{
            break;
        }
    }
    i = xVal;
    j = yVal;
    while( (i < ROW - 1) && (j < COLUM - 1) ){
        i++;
        j++;
        if(board[i][j] == temp){
            counter++;
            if(counter >= GAME_WIN){
                return true;
            }
        }
        return false;
    }
    return false;
}

bool CaroChess::checkWinInCrossSecond(const int x, const int y, const char board[ROW][COLUM]){
    int xVal = x;
    int yVal = y;
    char temp = board[xVal][yVal];
    int counter = 1;
    int i = xVal;
    int j = yVal;
    while(i > 0 && (j < COLUM - 1)){
        i--;
        j++;
        if(board[i][j] == temp){
            counter++;
            if(counter >= GAME_WIN){
                return true;
            }
        }
        else{
            break;
        }
    }
    i = xVal;
    j = yVal;
    while( (i < ROW - 1) && j > 0 ){
        i++;
        j--;
        if(board[i][j] == temp){
            counter++;
            if(counter >= GAME_WIN){
                return true;
            }
        }
        return false;
    }
    return false;
}

bool CaroChess::checkGameOver(const uint8_t turn){
    if(turn == (ROW * COLUM)) return true;
    else return false;
}

bool CaroChess::checkWin(const int x, const int y, const char (*board)[COLUM]){
    if(checkWinInRow(x, y, board)) return true;
    else if(checkWinInColum(x,y, board)) return true;
    else if(checkWinInCrossFirst(x, y, board)) return true;
    else if(checkWinInCrossSecond(x, y, board)) return true;
    return false;
}

//-----------------------------------------------





