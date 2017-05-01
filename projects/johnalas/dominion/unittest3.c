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

	//give player 1 hand
	G.handCount[0] = 1; //hand size 1
	G.hand[0][0] = 3; //position 1

	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(numPlayer, k, seed, &G); // initialize a new game

	printf("\nTesting playCard():\n");

	G.numActions = 0; //no actions
	if (playCard(0, 0, 0, 0, &G) == 0) {
		printf("Test actions=%d failed.\n", G.numActions);
	}
	else printf("Test actions=%d successful.\n", G.numActions);
	
	G.numActions = 1; //enough actions, not an action card
	if (playCard(0, 0, 0, 0, &G) == 0) {
		printf("Test non-action card failed.\n");
	}
	else printf("Test non-action card successful.\n");

	G.hand[0][0] = 8; //council room into hand
	if (playCard(0, 0, 0, 0, &G) == -1 || G.numActions != 0) {
		printf("Test play card failed.\n");
	}
	else printf("Test play card successful.\n");

	return 0;
}