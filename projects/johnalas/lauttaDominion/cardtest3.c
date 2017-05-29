#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>


int main() {


	//game initialization declarations
	int k[10] = { adventurer, council_room, feast, gardens, mine
		, remodel, smithy, village, baron, great_hall };
	int seed = 1000;
	struct gameState G;
	int numPlayer = 2;


	printf("\nTesting great_hall():\n");
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(numPlayer, k, seed, &G); // initialize a new game
	int hsize = G.handCount[0]; //hand count before fct
	int asize = G.numActions;
	//put great hall in hand
	G.hand[0][0] = 16;
	playGreat_Hall(0, &G, 0);


	if (G.handCount[0]==hsize) {
		printf("Test draw 1 successful.\n");
	}
	else printf("Test draw 1 fail.\n");

	if (G.numActions == (asize + 1)) {
		printf("Test actions +1 successful.\n");
	}
	else printf("Test actions +1 fail.\n");

	return 0;
}