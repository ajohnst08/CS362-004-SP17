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
	int drawntreasure = 0;
	int temphand[MAX_HAND];
	int temphandCounter = 0;
	int *bonus;

	printf("\nTesting adventurer():\n");
	memset(&G, 23, sizeof(struct gameState));   // clear the game state
	initializeGame(numPlayer, k, seed, &G); // initialize a new game
	int firsthand = G.handCount[0];
	adventurer_fct(drawntreasure, 0, temphand, temphandCounter, &G, 0, bonus);
	//check if handcount increased
	if (G.handCount[0]==(firsthand+2)) {
		printf("Test card draw successful.\n");
	}
	else printf("Test card draw fail.\n");
	//check if recent draws are treasures
	if (G.hand[0][6] == 4 || G.hand[0][6] == 5 || G.hand[0][6] == 6) {
		printf("Test teasure card successful.\n");
	}
	else printf("Test treasure card fail at position %d.\n",G.handCount[0]);

	return 0;
}