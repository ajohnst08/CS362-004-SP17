#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define PRINTOUT 1 //set to 1 for test printout

int main() {


	//game initialization declarations
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	int seed = 1000;
	struct gameState G;
	int numPlayer = 2;


	printf("\nTesting isGameOver():\n");
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(numPlayer, k, seed, &G); // initialize a new game
	//set pile of province cards
	G.supplyCount[3] = 0;
	int check = isGameOver(&G);
	if (check == 1) {
		printf("Province empty test successful.\n");
	}
	else printf("Province empty test FAIL.\n");

	//reset provinces
	G.supplyCount[3] = 0;
	//set 3 piles of cards to 0
	G.supplyCount[17] = 0;
	G.supplyCount[19] = 0;
	G.supplyCount[21] = 0;
	check = isGameOver(&G);
	if (check == 1) {
		printf("3 pile empty test successful.\n");
	}
	else printf("3 pile empty test FAIL.\n");

	return 0;
}