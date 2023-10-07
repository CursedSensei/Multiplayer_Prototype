#pragma once

typedef struct {
	char name[100];
	unsigned int highest_score;

	unsigned int color;
} player_metadata;

typedef struct {
	unsigned int color;
	unsigned int score = 0;
} snake_data;