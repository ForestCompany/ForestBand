#include "map.h"

void InitMap(Map* mp)
{
	
	mp->height = 600/20;
	mp->width = 800/20;
	mp->map = (Tile**)malloc(mp->height * sizeof(Tile*));
	for (int i = 0; i < mp->height; ++i) {
		mp->map[i] = (Tile*)malloc(mp->width * sizeof(Tile));
	}
	for (int i = 0; i < mp->height; ++i) {
		for (int j = 0; j < mp->width; ++j) {
			mp->map[i][j].path = "../images/tile.png";
			mp->map[i][j].y = i;
			mp->map[i][j].x = j;
		}
	}
	
}


void ShowMap(Map* mp) {
	for (int i = 0; i < mp->height; ++i) {
		for (int j = 0; j < mp->width; ++j) {
			if (mp->map[i][j].path == "../images/tile.png") {
				printf('o');
			}
		}
		printf('\n');
	}
}


void DestroyMap(Map* mp)
{
	for (int i = 0; i < mp->height; ++i) {
		free(mp->map[i]);
	}
	free(mp->map);
}
