#pragma once

typedef struct pData{
	char name[100];
	unsigned int highest_score;

	unsigned int color;
} player_metadata;

typedef struct sData{
	unsigned int color;
	unsigned int score = 0;
} snake_data;