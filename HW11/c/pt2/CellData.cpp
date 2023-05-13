/*
 * CellData.h
 *
 *  Created on: Nov 9, 2021
 *      Author: student
 */

#include <iostream>
#include <string>
#include "CellData.h"

using std::cout;
using std::string;

CellData::CellData():id("-1"), fov(-1), volume(-1), center_x(-1), center_y(-1), min_x(-1), max_x(-1), min_y(-1), max_y(-1) {} //initialize everything

CellData::CellData(std::string id, int fov, double volume, double center_x, double center_y, double min_x, double max_x, double min_y, double max_y):
id(id), fov(fov), volume(volume), center_x(center_x), center_y(center_y), min_x(min_x), max_x(max_x), min_y(min_y), max_y(max_y) {} //initialize everything


CellData::~CellData() {} // You should not need to implement this

bool CellData::operator<(const CellData& b) {
    //order by fov num
    //then by id
    bool overload = true;
    if(fov > b.fov){
        overload = false;
    }
    else if(fov < b.fov){
        overload = true;
    }
    else if (fov == b.fov){

        if(id < b.id){
            overload = true;
        }
        else if(id >= b.id){

            overload = false;
        }
    }
    return overload;
}

bool CellData::operator==(const CellData& b)
{
    //returns true if and only if two objects are memberwise identical
    bool same = true;
    if(id != b.id){same = false;}
    if(fov != b.fov){same = false;}
    if(volume != b.volume){same = false;}
    if(center_x != b.center_x){same = false;}
    if(center_y != b.center_y){same = false;}
    if(min_x != b.min_x){same = false;}
    if(max_x != b.max_x){same = false;}
    if(min_y != b.min_y){same = false;}
    if(max_y != b.max_y){same = false;}
    
    return same;
}

