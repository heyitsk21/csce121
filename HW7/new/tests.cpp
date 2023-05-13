#include <iostream>
#include "logic.h"

using std::cout, std::endl;

void fetusDeletus(const std::string& fileName){
    int maxRow;
    int maxCol;
    Player player;
    char** map = loadLevel(fileName, maxRow, maxCol, player);
    bool doesHeAttack = doMonsterAttack(map, maxRow, maxCol, player);
    ////////////////////
    // this is required to prevent memory leaks on part 1 (test first)
    if (map) {
        for (int row = 0; row < maxRow; row++) {
            delete[] map[row];
        }
        delete[] map;
    }
    ////////////////////
    if(doesHeAttack){
        int i = 0;
        i += 0;
    }
}

// TODO(student): Write unit tests for the functions in logic.h
//                You should end up with at least 500 lines of test code

int main() {
    
    // example
    /*
    example.txt
    -----------
    5 3
    3 0
    M + -
    - + -
    - + !
    - - -
    @ - $
    */
    ////////////////////
    // this is the only code _required_ to get coverage points on part 1 (test first)
    //   invocation --> coverage
    int maxRow;
    int maxCol;
    Player player;
    cout<<endl<<"-------loadLevel-------"<<endl<<endl;
    cout << endl<<"[START] loadLevel() happy path"<<endl;
    char** level = loadLevel("example.txt", maxRow, maxCol, player);
    ////////////////////
    /*
    {
        ////////////////////
        // this is optional but STRONGLY recommended for preparing for part 2 (development)
        //   coverage -/-> correctness
        // note: there are _many_ ways to do this part, including ways that are more elegant and efficient than this way demonstrated here
        if (level == nullptr) {
            cout << "FAIL: level is nullptr" << endl;
        } else {
            cout << " OK : level is not nullptr" << endl;
            if (maxRow == 5) {
                cout << " OK : maxRow is 5" << endl;
            } else {
                cout << "FAIL: expected maxRow to be 5, got " << maxRow << endl; 
            }
            if (maxCol == 3) {
                cout << " OK : maxCol is 3" << endl;
            } else {
                cout << "FAIL: expected maxCol to be 3, got " << maxCol << endl; 
            }
            if (player.row == 3) {
                cout << " OK : player.row is 3" << endl;
            } else {
                cout << "FAIL: expected player.row to be 3, got " << player.row << endl; 
            }
            if (player.col == 0) {
                cout << " OK : player.col is 0" << endl;
            } else {
                cout << "FAIL: expected player.col to be 0, got " << player.col << endl; 
            }
            if (level[0][0] == 'M') {
                cout << " OK : level[0][0] is M" << endl;
            } else {
                cout << "FAIL: expected level[0][0] to be M, got " << level[0][0] << endl; 
            }
            if (level[0][1] == '+') {
                cout << " OK : level[0][1] is +" << endl;
            } else {
                cout << "FAIL: expected level[0][1] to be +, got " << level[0][1] << endl; 
            }
            if (level[0][2] == '-') {
                cout << " OK : level[0][2] is -" << endl;
            } else {
                cout << "FAIL: expected level[0][2] to be -, got " << level[0][2] << endl; 
            }
            if (level[1][0] == '-') {
                cout << " OK : level[1][0] is -" << endl;
            } else {
                cout << "FAIL: expected level[1][0] to be -, got " << level[1][0] << endl; 
            }
            if (level[1][1] == '+') {
                cout << " OK : level[1][1] is +" << endl;
            } else {
                cout << "FAIL: expected level[1][1] to be +, got " << level[1][1] << endl; 
            }
            if (level[1][2] == '-') {
                cout << " OK : level[1][2] is -" << endl;
            } else {
                cout << "FAIL: expected level[1][2] to be -, got " << level[1][2] << endl; 
            }
            if (level[2][0] == '-') {
                cout << " OK : level[2][0] is -" << endl;
            } else {
                cout << "FAIL: expected level[2][0] to be -, got " << level[2][0] << endl; 
            }
            if (level[2][1] == '+') {
                cout << " OK : level[2][1] is +" << endl;
            } else {
                cout << "FAIL: expected level[2][1] to be +, got " << level[2][1] << endl; 
            }
            if (level[2][2] == '!') {
                cout << " OK : level[2][2] is !" << endl;
            } else {
                cout << "FAIL: expected level[2][2] to be !, got " << level[2][2] << endl; 
            }
            if (level[3][0] == 'o') {
                cout << " OK : level[3][0] is o" << endl;
            } else {
                cout << "FAIL: expected level[3][0] to be o, got " << level[3][0] << endl; 
            }
            if (level[3][1] == '-') {
                cout << " OK : level[3][1] is -" << endl;
            } else {
                cout << "FAIL: expected level[3][1] to be -, got " << level[3][1] << endl; 
            }
            if (level[3][2] == '-') {
                cout << " OK : level[3][2] is -" << endl;
            } else {
                cout << "FAIL: expected level[3][2] to be -, got " << level[3][2] << endl; 
            }
            if (level[4][0] == '@') {
                cout << " OK : level[4][0] is @" << endl;
            } else {
                cout << "FAIL: expected level[4][0] to be @, got " << level[4][0] << endl; 
            }
            if (level[4][1] == '-') {
                cout << " OK : level[4][1] is -" << endl;
            } else {
                cout << "FAIL: expected level[4][1] to be -, got " << level[4][1] << endl; 
            }
            if (level[4][2] == '$') {
                cout << " OK : level[4][2] is $" << endl;
            } else {
                cout << "FAIL: expected level[4][2] to be $, got " << level[4][2] << endl; 
            }
        }
        ////////////////////
    }
    */
    ////////////////////
    // this is required to prevent memory leaks on part 1 (test first)
    if (level) {
        for (int row = 0; row < 5; row++) {
            delete[] level[row];
        }
        delete[] level;
    }
    ////////////////////
    cout<<endl<<"[START] loadLevel() nonexistent file"<<endl;
    level = loadLevel("example2.txt", maxRow, maxCol, player);
    cout<<endl<<"[START] loadLevel() nonnumeric maxRow"<<endl;
    level = loadLevel("loadLevel_1.txt", maxRow, maxCol, player);
    cout<<endl<<"[START] loadLevel() maxRow < 1"<<endl;
    level = loadLevel("loadLevel_3.txt", maxRow, maxCol, player);
    cout<<endl<<"[START] loadLevel() nonnumeric maxCol"<<endl;
    level = loadLevel("loadLevel_2.txt", maxRow, maxCol, player);
    cout<<endl<<"[START] loadLevel() maxCol < 1"<<endl;
    level = loadLevel("loadLevel_4.txt", maxRow, maxCol, player);

    cout<<endl<<"[START] loadLevel() more than 214748367 tiles"<<endl;
    level = loadLevel("loadLevel_5.txt", maxRow, maxCol, player);

    cout<<endl<<"[START] loadLevel() player row nonnumeric"<<endl;
    level = loadLevel("loadLevel_6.txt", maxRow, maxCol, player);
    cout<<endl<<"[START] loadLevel() player row < 0"<<endl;
    level = loadLevel("loadLevel_7.txt", maxRow, maxCol, player);
    cout<<endl<<"[START] loadLevel() player row is more than maxRow"<<endl;
    level = loadLevel("loadLevel_8.txt", maxRow, maxCol, player);

    cout<<endl<<"[START] loadLevel() player col nonnumeric"<<endl;
    level = loadLevel("loadLevel_9.txt", maxRow, maxCol, player);
    cout<<endl<<"[START] loadLevel() player col < 0"<<endl;
    level = loadLevel("loadLevel_10.txt", maxRow, maxCol, player);
    cout<<endl<<"[START] loadLevel() player col is more than maxCol"<<endl;
    level = loadLevel("loadLevel_11.txt", maxRow, maxCol, player);

    cout<<endl<<"[START] loadLevel() a way out does not exist"<<endl;
    level = loadLevel("loadLevel_12.txt", maxRow, maxCol, player);
    cout<<endl<<"[START] loadLevel() has an invalid symbol"<<endl;
    level = loadLevel("loadLevel_13.txt", maxRow, maxCol, player);
    cout<<endl<<"[START] loadLevel() has not enough tiles"<<endl;
    level = loadLevel("loadLevel_14.txt", maxRow, maxCol, player);
    cout<<endl<<"[START] loadLevel() has too many tiles"<<endl;
    level = loadLevel("loadLevel_15.txt", maxRow, maxCol, player);
    /*
    cout<<endl<<"[START] loadLevel() player position starts bottom left"<<endl;
    level = loadLevel("loadLevel_16.txt", maxRow, maxCol, player);
    cout<<endl<<"[START] loadLevel() player position starts top right"<<endl;
    level = loadLevel("loadLevel_17.txt", maxRow, maxCol, player);
    cout<<endl<<"[START] loadLevel() zero dimensions?"<<endl;
    level = loadLevel("loadLevel_18.txt", maxRow, maxCol, player);
    */

    cout<<endl<<"-------getDirection-------"<<endl<<endl;
    //GET DIRECTION
    char input;
    int nextRow;
    int nextCol;
    
    cout<<endl<<"[START] getDirection() wasdeq"<<endl;
    input = 'w';
    getDirection(input, nextRow, nextCol);
    input = 'a';
    getDirection(input, nextRow, nextCol);
    input = 's';
    getDirection(input, nextRow, nextCol);
    input = 'd';
    getDirection(input, nextRow, nextCol);
    input = 'e';
    getDirection(input, nextRow, nextCol);
    input = 'q';
    getDirection(input, nextRow, nextCol);

    cout<<endl<<"[START] getDirection() WASDEQ"<<endl;
    input = 'W';
    getDirection(input, nextRow, nextCol);
    input = 'A';
    getDirection(input, nextRow, nextCol);
    input = 'S';
    getDirection(input, nextRow, nextCol);
    input = 'D';
    getDirection(input, nextRow, nextCol);
    input = 'E';
    getDirection(input, nextRow, nextCol);
    input = 'Q';
    getDirection(input, nextRow, nextCol);

    cout<<endl<<"[START] getDirection() invalid char"<<endl;
    input = 'p';
    getDirection(input, nextRow, nextCol);
    input = 'P';
    getDirection(input, nextRow, nextCol);
    input = 0;
    getDirection(input, nextRow, nextCol);
    input = '-';
    getDirection(input, nextRow, nextCol);
    
    
/*
{
    if (input != '\0') {
        cout << " OK : input is not nullptr" << endl;
        if (input == 'w') {
            cout << " OK : input is w" << endl;
            nextRow--;
        }
        else if (input == 'a') {
            cout << " OK : input is a" << endl;
            nextCol--;
        } 
        else if (input == 's') {
            cout << " OK : input is s" << endl;
            nextRow++;
        } 
        else if (input == 'd') {
            cout << " OK : input is d" << endl;
            nextCol++;
        } 
        else if (input == 'e') {
            cout << " OK : input is e" << endl;
        }
        else if (input == 'q') {
            cout << " OK : input is q" << endl;
        }
        else {
            cout << "FAIL: input is invalid" << endl;
        }
    } else {
        cout << "FAIL: input is invalid" << endl;
    }
    if (nextRow < 0) {
        cout << "FAIL: cannot move to a negative row" << endl;
    }
    if (nextCol < 0) {
        cout << "FAIL: cannot move to a negative column" << endl;
    }
}
*/
    cout<<endl<<"-------deleteMap-------"<<endl<<endl;

    cout<<endl<<"[START] deleteMap() happy path"<<endl;
    char** map = loadLevel("example.txt", maxRow, maxCol, player);
    deleteMap(map, maxRow);
    cout<<endl<<"[START] deleteMap() nullptr map"<<endl;
    map = loadLevel("deleteMap_1.txt", maxRow, maxCol, player);
    deleteMap(map, maxRow);


    cout<<endl<<"-------resizeMap-------"<<endl<<endl;

    cout<<endl<<"[START] resizeMap() happy path"<<endl;
    
    char** mapmap = loadLevel("example.txt", maxRow, maxCol, player);
    cout<<endl<<"BEFORE: maxRow="<<maxRow<<" & maxCol="<<maxCol<<endl;
    char** mapResize = resizeMap(mapmap, maxRow, maxCol);
    cout<<endl<<"AFTER: maxRow="<<maxRow<<" & maxCol="<<maxCol<<endl;
    deleteMap(mapResize, maxRow);
    ////////////////////
    // this is required to prevent memory leaks on part 1 (test first)
    /*
    if (mapmap) {
        for (int row = 0; row < maxRow; row++) {
            delete[] mapmap[row];
        }
        delete[] mapmap;
    }
    
    if (mapResize) {
        for (int row = 0; row < maxRow; row++) {
            delete[] mapResize[row];
        }
        delete[] mapResize;
    }
    */
    ////////////////////
    
    cout<<endl<<"[START] resizeMap() neg row"<<endl;
    mapmap = loadLevel("resizeMap_1.txt", maxRow, maxCol, player);
    cout<<endl<<"BEFORE: maxRow="<<maxRow<<" & maxCol="<<maxCol<<endl;
    mapResize = resizeMap(mapmap, maxRow, maxCol);
    cout<<endl<<"AFTER: maxRow="<<maxRow<<" & maxCol="<<maxCol<<endl;

    cout<<endl<<"[START] resizeMap() neg col"<<endl;
    mapmap = loadLevel("resizeMap_2.txt", maxRow, maxCol, player);
    cout<<endl<<"BEFORE: maxRow="<<maxRow<<" & maxCol="<<maxCol<<endl;
    mapResize = resizeMap(mapmap, maxRow, maxCol);
    cout<<endl<<"AFTER: maxRow="<<maxRow<<" & maxCol="<<maxCol<<endl;

    cout<<endl<<"[START] resizeMap() both neg"<<endl;
    mapmap = loadLevel("resizeMap_4.txt", maxRow, maxCol, player);
    cout<<endl<<"BEFORE: maxRow="<<maxRow<<" & maxCol="<<maxCol<<endl;
    mapResize = resizeMap(mapmap, maxRow, maxCol);
    cout<<endl<<"AFTER: maxRow="<<maxRow<<" & maxCol="<<maxCol<<endl;

    cout<<endl<<"[START] resizeMap() nullptr map ('i')"<<endl;
    mapmap = loadLevel("resizeMap_3.txt", maxRow, maxCol, player);
    cout<<endl<<"BEFORE: maxRow="<<maxRow<<" & maxCol="<<maxCol<<endl;
    mapResize = resizeMap(mapmap, maxRow, maxCol);
    cout<<endl<<"AFTER: maxRow="<<maxRow<<" & maxCol="<<maxCol<<endl;


    

    cout<<endl<<"-------doPlayerMove-------"<<endl<<endl;

    cout<<endl<<"[START] doPlayerMove() happy path"<<endl;
    //same as example.txt
    map = loadLevel("doPlayerMove_1.txt", maxRow, maxCol, player);
    //maxRow = 5, maxCol = 3;
    cout<<endl<<endl<<"[START] doPlayerMove() col=1"<<endl;
    nextCol = 1;

    cout<<endl<<"                             row=1"<<endl;
    nextRow = 1;
/*1*/doPlayerMove(map, maxRow, maxCol, player, nextRow, nextCol);

    cout<<endl<<"                             row=0"<<endl;
    nextRow = 0;
/*2*/doPlayerMove(map, maxRow, maxCol, player, nextRow, nextCol);
    
    cout<<endl<<"                             row=-1"<<endl;
    nextRow = -1;
/*3*/doPlayerMove(map, maxRow, maxCol, player, nextRow, nextCol);
    
    cout<<endl<<"                             row=10"<<endl;
    nextRow = 10;
/*4*/doPlayerMove(map, maxRow, maxCol, player, nextRow, nextCol);
    //nextRow = 2147483647;
//"5"
    

    cout<<endl<<endl<<"[START] doPlayerMove() row=1"<<endl;
    nextRow = 1;

//"6"

    nextCol = 1;
    cout<<endl<<"                             col=1"<<endl;
    doPlayerMove(map, maxRow, maxCol, player, nextRow, nextCol);

    cout<<endl<<"                             col=0"<<endl;
    nextCol = 0;


/*5*/doPlayerMove(map, maxRow, maxCol, player, nextRow, nextCol);

    cout<<endl<<"                             col=-1"<<endl;
    nextCol = -1;
/*6*/doPlayerMove(map, maxRow, maxCol, player, nextRow, nextCol);
    
    cout<<endl<<"                             col=10"<<endl;
    nextCol = 10;
/*7*/doPlayerMove(map, maxRow, maxCol, player, nextRow, nextCol);
//"10"
    cout<<endl<<endl<<"[START] doPlayerMove() row=0 & col=0"<<endl;
    nextRow = 0;
    nextCol = 0;
/*8*/doPlayerMove(map, maxRow, maxCol, player, nextRow, nextCol);

    cout<<endl<<endl<<"[START] doPlayerMove() row=2 & col=2"<<endl;
    nextRow = 2;
    nextCol = 2;
/*9*/doPlayerMove(map, maxRow, maxCol, player, nextRow, nextCol);

    cout<<endl<<endl<<"[START] doPlayerMove() at door with treasure"<<endl;
    player.treasure = STATUS_TREASURE;
    doPlayerMove(map, maxRow, maxCol, player, nextRow, nextCol);

    cout<<endl<<endl<<"[START] doPlayerMove() row=4 & col=0"<<endl;
    nextRow = 4;
    nextCol = 0;
/*10*/doPlayerMove(map, maxRow, maxCol, player, nextRow, nextCol);

    cout<<endl<<endl<<"[START] doPlayerMove() row=4 & col=2"<<endl;
    nextRow = 4;
    nextCol = 2;
/*11*/doPlayerMove(map, maxRow, maxCol, player, nextRow, nextCol);

    /*
    cout<<endl<<endl<<"poop"<<endl;
    player.row=4;
    player.col=0;
    nextRow=5;
    nextCol=-1;
    doPlayerMove(map, maxRow, maxCol, player, nextRow, nextCol);
    player.row=0;
    player.col=2;
    nextRow=-1;
    nextCol=3;
    doPlayerMove(map, maxRow, maxCol, player, nextRow, nextCol);
    */

    ////////////////////
    // this is required to prevent memory leaks on part 1 (test first)
    if (map) {
        for (int row = 0; row < maxRow; row++) {
            delete[] map[row];
        }
        delete[] map;
    }
    ////////////////////

    /*
    {
        map = loadLevel("doMonsterAttack_1.txt", maxRow, maxCol, player);
        bool doesHeAttack = doMonsterAttack(map, maxRow, maxCol, player);
        ////////////////////
        // this is required to prevent memory leaks on part 1 (test first)
        if (map) {
            for (int row = 0; row < maxRow; row++) {
                delete[] map[row];
            }
            delete[] map;
        }
        ////////////////////
        map = loadLevel("doMonsterAttack_2.txt", maxRow, maxCol, player);
        doesHeAttack = doMonsterAttack(map, maxRow, maxCol, player);
        ////////////////////
        // this is required to prevent memory leaks on part 1 (test first)
        if (map) {
            for (int row = 0; row < maxRow; row++) {
                delete[] map[row];
            }
            delete[] map;
        }
        ////////////////////
        map = loadLevel("doMonsterAttack_3.txt", maxRow, maxCol, player);
        doesHeAttack = doMonsterAttack(map, maxRow, maxCol, player);
        ////////////////////
        // this is required to prevent memory leaks on part 1 (test first)
        if (map) {
            for (int row = 0; row < maxRow; row++) {
                delete[] map[row];
            }
            delete[] map;
        }
        ////////////////////
        map = loadLevel("doMonsterAttack_4.txt", maxRow, maxCol, player);
        doesHeAttack = doMonsterAttack(map, maxRow, maxCol, player);
        ////////////////////
        // this is required to prevent memory leaks on part 1 (test first)
        if (map) {
            for (int row = 0; row < maxRow; row++) {
                delete[] map[row];
            }
            delete[] map;
        }
        ////////////////////
        map = loadLevel("doMonsterAttack_5.txt", maxRow, maxCol, player);
        doesHeAttack = doMonsterAttack(map, maxRow, maxCol, player);
        ////////////////////
        // this is required to prevent memory leaks on part 1 (test first)
        if (map) {
            for (int row = 0; row < maxRow; row++) {
                delete[] map[row];
            }
            delete[] map;
        }
        ////////////////////
        map = loadLevel("doMonsterAttack_6.txt", maxRow, maxCol, player);
        doesHeAttack = doMonsterAttack(map, maxRow, maxCol, player);
        ////////////////////
        // this is required to prevent memory leaks on part 1 (test first)
        if (map) {
            for (int row = 0; row < maxRow; row++) {
                delete[] map[row];
            }
            delete[] map;
        }
        ////////////////////
        map = loadLevel("doMonsterAttack_7.txt", maxRow, maxCol, player);
        doesHeAttack = doMonsterAttack(map, maxRow, maxCol, player);
        ////////////////////
        // this is required to prevent memory leaks on part 1 (test first)
        if (map) {
            for (int row = 0; row < maxRow; row++) {
                delete[] map[row];
            }
            delete[] map;
        }
        ////////////////////
        map = loadLevel("doMonsterAttack_8.txt", maxRow, maxCol, player);
        doesHeAttack = doMonsterAttack(map, maxRow, maxCol, player);
        ////////////////////
        // this is required to prevent memory leaks on part 1 (test first)
        if (map) {
            for (int row = 0; row < maxRow; row++) {
                delete[] map[row];
            }
            delete[] map;
        }
        ////////////////////
        map = loadLevel("doMonsterAttack_9.txt", maxRow, maxCol, player);
        doesHeAttack = doMonsterAttack(map, maxRow, maxCol, player);
        ////////////////////
        // this is required to prevent memory leaks on part 1 (test first)
        if (map) {
            for (int row = 0; row < maxRow; row++) {
                delete[] map[row];
            }
            delete[] map;
        }
        ////////////////////
        
        if(doesHeAttack){
            int i = 0;
            i++;
        }
    }
    */

    cout<<endl<<"-------doPlayerMove-------"<<endl<<endl;

    cout<<endl<<"[START] doMonsterAttack() happy path, not eaten"<<endl;
    fetusDeletus("doMonsterAttack_1.txt");

    cout<<endl<<"[START] doMonsterAttack() up, not eaten"<<endl;
    fetusDeletus("doMonsterAttack_2.txt");
    cout<<endl<<"[START] doMonsterAttack() right, not eaten"<<endl;
    fetusDeletus("doMonsterAttack_3.txt");
    cout<<endl<<"[START] doMonsterAttack() down, not eaten"<<endl;
    fetusDeletus("doMonsterAttack_4.txt");
    cout<<endl<<"[START] doMonsterAttack() left, not eaten"<<endl;
    fetusDeletus("doMonsterAttack_5.txt");

    cout<<endl<<"[START] doMonsterAttack() up, eaten"<<endl;
    fetusDeletus("doMonsterAttack_6.txt");
    cout<<endl<<"[START] doMonsterAttack() right, eaten"<<endl;
    fetusDeletus("doMonsterAttack_7.txt");
    cout<<endl<<"[START] doMonsterAttack() down, eaten"<<endl;
    fetusDeletus("doMonsterAttack_8.txt");
    cout<<endl<<"[START] doMonsterAttack() left, eaten"<<endl;
    fetusDeletus("doMonsterAttack_9.txt");

    cout<<endl<<"[START] doMonsterAttack() up, not eaten, pillar"<<endl;
    fetusDeletus("doMonsterAttack_10.txt");
    cout<<endl<<"[START] doMonsterAttack() right, not eaten, pillar"<<endl;
    fetusDeletus("doMonsterAttack_11.txt");
    cout<<endl<<"[START] doMonsterAttack() down, not eaten, pillar"<<endl;
    fetusDeletus("doMonsterAttack_12.txt");
    cout<<endl<<"[START] doMonsterAttack() left, not eaten, pillar"<<endl;
    fetusDeletus("doMonsterAttack_13.txt");

    cout<<endl<<"[START] doMonsterAttack() monster and player same spot"<<endl;
    fetusDeletus("doMonsterAttack_14.txt");

    cout<<endl<<"[START] doMonsterAttack() player and money same spot"<<endl;
    fetusDeletus("doMonsterAttack_15.txt");
    cout<<endl<<"[START] doMonsterAttack() player and amulet same spot"<<endl;
    fetusDeletus("doMonsterAttack_16.txt");
    cout<<endl<<"[START] doMonsterAttack() player and door same spot"<<endl;
    fetusDeletus("doMonsterAttack_17.txt");
    
    fetusDeletus("doMonsterAttack_18.txt");
    fetusDeletus("doMonsterAttack_19.txt");
    fetusDeletus("doMonsterAttack_20.txt");
    

    return 0;
}
