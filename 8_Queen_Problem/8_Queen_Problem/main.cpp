//
//  main.cpp
//  8_Queen_Problem
//
//  Created by Peter Ingalsbe on 12/1/25.
//

#include <iostream>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

bool isPlaceAttacked(int x, int y, vector<vector<bool>>&board) {
    int _x = x;
    int _y = y;
    _x = 0;
    while(_x < 8) {
        if (board[_x][_y] == true && (_x != x || _y != y)) {
            return true;
        }
        _x ++;
    }
    _x = x;
    _y = 0;
    while(_y < 8) {
        if (board[_x][_y] == true && (_x != x || _y != y)) {
            return true;
        }
        _y ++;
    }
    int minSpot = min(x, y);
    _x = x-minSpot;
    _y = y-minSpot;
    while(_x < 8 && _y < 8) {
        if (board[_x][_y] == true && (_x != x || _y != y)) {
            return true;
        }
        _x ++;
        _y ++;
    }
    minSpot = min(x, 7-y);
    _x = x-minSpot;
    _y = y+minSpot;
    while(_x < 8 && _y < 8) {
        if (board[_x][_y] == true && (_x != x || _y != y)) {
            return true;
        }
        _x ++;
        _y --;
    }
    return false;
}

bool placeQueen(int y, vector<vector<bool>>&board) {
    if (y == 8) {
        return true;
    }
    vector<int> todo = {0, 1, 2, 3, 4, 5, 6, 7};
    for (int i = 0;  i < 8; i++) {
        int _rand = (rand() % todo.size());
        int x = todo[_rand];
        todo.erase(todo.begin() + _rand);
        if (!isPlaceAttacked(x, y, board)) {
            board[x][y] = true;
            if (placeQueen(y+1, board)) {
                return true;
            }
            else {
                board[x][y] = false;
            }
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    unsigned int seed = static_cast<unsigned int>(
        std::chrono::duration_cast<std::chrono::seconds>(duration).count()
    );
    srand(seed);
    vector<vector<bool>> board(8, vector<bool>(8, false));;
    if (placeQueen(0, board)) {
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                if (board[x][y] == true) {
                    cout << "Q ";
                }
                else {
                    cout << "X ";
                }
            }
            cout << endl;
        }
    }
   
    
}
