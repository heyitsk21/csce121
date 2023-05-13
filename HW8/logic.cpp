#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "logic.h"

using std::cout, std::endl, std::ifstream, std::string;

/**
 * TODO: Student implement this function
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  pointer to 2D dynamic array representation of dungeon map with player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */
char** loadLevel(const string& fileName, int& maxRow, int& maxCol, Player& player) {
    //open the file
	//ifstream myFile;//NOT: ifstream myFile(file);
    ifstream input_file(fileName);
	//myFile.open(fileName);

	//throw exception if file doesn't open correctly
	if(!input_file.is_open()){
        return nullptr;
		//throw std::invalid_argument("Cannot open file");
	}

    // int lineNumber = 0;
    // string currLine;

    // std::istringstream input_string;


    input_file >> maxRow;
    if(input_file.fail() || maxRow < 1 || maxRow >= INT32_MAX){
        return nullptr;
    }
    input_file >> maxCol;
    if(input_file.fail() || maxCol <  1 || maxCol >= INT32_MAX){
        return nullptr;
    }
    if(INT32_MAX/maxCol <= maxRow || INT32_MAX/maxRow <= maxCol){
        return nullptr;
    }
    

    input_file >> player.row;
    if(input_file.fail() || player.row < 0 || player.row >= maxRow){
        return nullptr;
    }
    input_file >> player.col;
    if(input_file.fail() || player.col < 0 || player.col >= maxCol){
        return nullptr;
    }

    char** map = createMap(maxRow, maxCol);
    if (map == nullptr){
        deleteMap(map, maxRow);
        return nullptr;
    } 

    int numTiles = 0;

    for (int b = 0; b < maxRow; b++){
        for (int c = 0; c < maxCol; c++){
            input_file >> map[b][c];
            if(input_file.fail()){
                return nullptr;
            }
            if (b == player.row){
                if (c == player.col){
                    map[b][c] = TILE_PLAYER;
                }
            } else if (map[b][c] == '-'){
                map[b][c] = TILE_OPEN;
            } else if (map[b][c] == '$'){
                map[b][c] = TILE_TREASURE;
            } else if (map[b][c] == '@'){
                map[b][c] = TILE_AMULET;
            } else if (map[b][c] == 'M'){
                map[b][c] = TILE_MONSTER;
            } else if (map[b][c] == '+'){
                map[b][c] = TILE_PILLAR;
            } else if (map[b][c] == '?'){
                map[b][c] = TILE_DOOR;
            } else if (map[b][c] == '!'){
                map[b][c] = TILE_EXIT;
            } else {
                return nullptr;
            }
            numTiles++;
        }
    }

    if (numTiles < maxRow*maxCol || numTiles > maxRow*maxCol) {
        return nullptr;
    }
    char temp;
    if (input_file >> temp){
        return nullptr;
    }

    bool hasDoor = false;
    for (int x = 0; x < maxRow; x++){
        for (int y = 0; y < maxCol; y++){
            if(map[x][y] == TILE_DOOR || map[x][y] == TILE_EXIT){
                hasDoor = true;
            }
        }
    }
    if(!hasDoor){
        return nullptr;
    }

    return map;
}

/**
 * TODO: Student implement this function
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * @param   input       Character input by the user which translates to a direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 */
void getDirection(char input, int& nextRow, int& nextCol) {
    if (input != '\0') {
        //cout << " OK : input is not nullptr" << endl;
        if (input == 'w') {
            //cout << " OK : input is w" << endl;
            input = MOVE_UP;
            nextRow--;
        }
        else if (input == 'a') {
            //cout << " OK : input is a" << endl;
            input = MOVE_LEFT;
            nextCol--;
        } 
        else if (input == 's') {
            //cout << " OK : input is s" << endl;
            input = MOVE_DOWN;
            nextRow++;
        } 
        else if (input == 'd') {
            //cout << " OK : input is d" << endl;
            input = MOVE_RIGHT;
            nextCol++;
        } 
        else if (input == 'e') {
            //cout << " OK : input is e" << endl;
            input = INPUT_STAY;
        }
        else if (input == 'q') {
            //cout << " OK : input is q" << endl;
            input = INPUT_QUIT;
        }
        else {
            //cout << "FAIL: input is invalid" << endl;
            input = INPUT_STAY;
        }
    } else {
        //cout << "FAIL: input is invalid" << endl;
    }
}

/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 */
char** createMap(int maxRow, int maxCol) {
    if (maxRow < 0 || maxCol < 0){
        return nullptr;
    }

    char** map = new char*[maxRow];
    for (int a = 0; a < maxRow; a++){
        map[a] = new char[maxCol];
        for (int b = 0; b < maxCol; b++){
            map[a][b] = TILE_OPEN;
        }
    }

    return map;
}

/**
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @return None
 * @update map, maxRow
 */
void deleteMap(char**& map, int& maxRow) {
    ////////////////////
    // this is required to prevent memory leaks on part 1 (test first)
    if (map) {
        for (int row = 0; row < maxRow; row++) {
            delete[] map[row];
        }
        delete[] map;
    }
    ////////////////////
    map = nullptr;
    maxRow = 0;
}

/**
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 */
char** resizeMap(char** map, int& maxRow, int& maxCol) {
    if (maxRow < 1 || maxCol < 1){
        return nullptr;
    }
    if (map == nullptr){
        return nullptr;
    }

    char** newMap = createMap(maxRow*2,maxCol*2);
    int c = 0; //old row
    int d = 0; //old col
    for (int a = 0; a < maxRow*2; a++){
        for (int b = 0; b < maxCol*2; b++){
            if (a<maxRow && b<maxCol){ // A
                c = a;
                d = b;
            }
            else if (a>=maxRow && b<maxCol) { // B
                c = a - maxRow;
                d = b;
            }
            else if (a<maxRow && b>=maxCol) { // C
                c = a;
                d = b - maxCol;
            }
            else if (a>=maxRow && b>=maxCol) { // D
                c = a - maxRow;
                d = b - maxCol;
            }
            //cout<<"c"<<c<<endl<<"d"<<d<<endl;

            if (map[c][d] == TILE_PLAYER && (a>=maxRow || b>=maxCol)){
                newMap[a][b] = TILE_OPEN;
            }
            // else if (map[c][d] == TILE_DOOR){
            //     newMap[a][b] = TILE_OPEN;
            // }
            else {
                newMap[a][b] = map[c][d];
            }
            // if (map[c][d] == TILE_PLAYER){
            //     newMap[c][d] == TILE_OPEN;
            // }

            /*

            //quadrant A
            if (a<maxRow && b<maxCol){
                newMap[a][b] = map[a][b];
            }
            // if (a<maxRow && b<maxCol){
            //     if (map[a][b] == TILE_PLAYER){
            //         newMap[a][b] = TILE_OPEN;
            //     } else {
            //         newMap[a][b] = map[a][b];
            //     }
            // } 
            //quadrant B
            else if (a>=maxRow && b<maxCol) {
                if (map[a-maxRow][b] == TILE_PLAYER){
                    newMap[a][b] = TILE_OPEN;
                } else {
                    newMap[a][b] = map[a-maxRow][b];
                }
            } 
            //quadrant C
            else if (a<maxRow && b>=maxCol) {
                if (map[a][b-maxCol] == TILE_PLAYER){
                    newMap[a][b] = TILE_OPEN;
                } else {
                    newMap[a][b] = map[a][b-maxCol];
                }
            }
            //quadrant D
            else if (a>=maxRow && b>=maxCol) {
                if (map[a-maxRow][b-maxCol] == TILE_PLAYER){
                    newMap[a][b] = TILE_OPEN;
                } else {
                    newMap[a][b] = map[a-maxRow][b-maxCol];
                }
            }
            */
        }
    }
    int tempRow = maxRow;
    deleteMap(map,maxRow); //sets maxRow to 0!
    //cout<<"row"<<maxRow<<endl<<"col"<<maxCol<<endl;
    maxRow = tempRow*2;
    maxCol *= 2;
    //cout<<"row"<<maxRow<<endl<<"col"<<maxCol<<endl;
    return newMap;
}

/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure. 
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 */
int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol) {
    int playerStatus;
    if (nextRow < 0 || nextRow >= maxRow) {
        //cout << "FAIL: cannot move to a negative row" << endl;
        //cout << "FAIL: cannot move below maxRow bounds" << endl;
        playerStatus = STATUS_STAY;
        nextRow = player.row;
        nextCol = player.col;
        return playerStatus;
    }
    if (nextCol < 0 || nextCol >= maxCol) {
        //cout << "FAIL: cannot move to a negative column" << endl;
        //cout << "FAIL: cannot move further than maxCol bounds" << endl;
        playerStatus = STATUS_STAY;
        nextRow = player.row;
        nextCol = player.col;
        return playerStatus;
    }
    if (map[nextRow][nextCol] == TILE_PILLAR || map[nextRow][nextCol] == TILE_MONSTER) {
        playerStatus = STATUS_STAY;
        nextRow = player.row;
        nextCol = player.col;
        return playerStatus;
    }
    if (map[nextRow][nextCol] == TILE_TREASURE) {
        playerStatus = STATUS_TREASURE;
        player.treasure++;
    }
    if (map[nextRow][nextCol] == TILE_AMULET) {
        playerStatus = STATUS_AMULET;
    }
    if (map[nextRow][nextCol] == TILE_DOOR) {
        playerStatus = STATUS_LEAVE;
    }
    if (map[nextRow][nextCol] == TILE_EXIT) {
        if (player.treasure > 0){
            playerStatus = STATUS_ESCAPE;
        } else {
            playerStatus = STATUS_STAY;
            nextRow = player.row;
            nextCol = player.col;
            return playerStatus;
        }
    }
    if (map[nextRow][nextCol] == TILE_OPEN) {
        playerStatus = STATUS_MOVE;
    }
    map[player.row][player.col] = TILE_OPEN;
    player.row = nextRow;
    player.col = nextCol;
    map[nextRow][nextCol] = TILE_PLAYER;

    return playerStatus;
}

/**
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the player, false if not.
 * @update map contents
 */
bool doMonsterAttack(char** map, int maxRow, int maxCol, const Player& player) {
    //cout<<"player row="<<player.row<<endl<<"player col="<<player.col<<endl<<"maxRow="<<maxRow<<endl<<"maxCol="<<maxCol<<endl;

    //up --> player.row decreases til 0 (start one above though)
    for (int row = player.row -1; row >= 0; row--) {
        //cout<<"this is line 243 (up)"<<endl;
        if (map[row][player.col] == TILE_PILLAR) {
            //return false;
            break;
        }
        if (map[row][player.col] == TILE_MONSTER) {
            //cout<<"there is a monster (up)"<<endl;
            map[row+1][player.col] = TILE_MONSTER;
            map[row][player.col] = TILE_OPEN;
            //return true;
        }
    }
    //down --> row increases to maxRow
    for (int row = player.row +1; row < maxRow; row++) {
        //cout<<"this is line 255 (down)"<<endl;
        if (map[row][player.col] == TILE_PILLAR) {
            //return false;
            break;
        }
        if (map[row][player.col] == TILE_MONSTER) {
            //cout<<"there is a monster (down)"<<endl;
            map[row-1][player.col] = TILE_MONSTER;
            map[row][player.col] = TILE_OPEN;
            //return true;
        }
    }
    //left --> col decreases til zero
    for (int col = player.col -1; col >= 0; col--) {
        //cout<<"this is line 267 (left)"<<endl;
        if (map[player.row][col] == TILE_PILLAR) {
            //return false;
            break;
        }
        if (map[player.row][col] == TILE_MONSTER) {
            //cout<<"there is a monster (left)"<<endl;
            map[player.row][col+1] = TILE_MONSTER;
            map[player.row][col] = TILE_OPEN;
            //return true;
        }
    }
    //right --> col increases to maxCol
    for (int col = player.col +1; col < maxCol; col++) {
        //cout<<"this is line 279 (right)"<<endl;
        if (map[player.row][col] == TILE_PILLAR) {
            //return false;
            break;
        }
        if (map[player.row][col] == TILE_MONSTER) {
            //cout<<"there is a monster (right)"<<endl;
            map[player.row][col-1] = TILE_MONSTER;
            map[player.row][col] = TILE_OPEN;
            //return true;
        }
        
    }
    if (map[player.row][player.col] == TILE_MONSTER){
        return true;
    } else {
        return false;
    }
    return false;
}
