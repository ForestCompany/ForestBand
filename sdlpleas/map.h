#pragma once
#include "tile.h"
#include "stdlib.h"
#include<stdio.h>

typedef struct map {
	Tile** map;
	 int width;
	 int height;
}Map;

void InitMap(Map* mp);

void ShowMap(Map* mp);

void DestroyMap(Map* mp);















