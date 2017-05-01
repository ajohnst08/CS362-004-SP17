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


	printf("\nTesting smithy():\n");
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(numPlayer, k, seed, &G); // initialize a new game
	//start with hand, player 1 has 2 cards
	G.handCount[0] = 2;
	G.hand[0][0] = 13; //set smithy card as handpos 0
	G.hand[0][1] = 12;

	int s = smithy_fct(0, &G, 0); //+3 cards, discard smithy
	//player 1 should have 4 cards
	if (G.handCount[0] == 4) {
		printf("Test draw 3 successful.\n");
	}
	else printf("Test draw 3 fail.\n");

	return 0;
}