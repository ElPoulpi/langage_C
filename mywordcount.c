#include<stdio.h>
#define DEDANS 1
#define DEHORS 0

int main(){
	int c, nl, nm, nc, etat;

	etat = DEHORS;
	nl = nm = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n'){
			++nl;
		}
		if (c == ' ' || c == '\n' || c == '\t') {
			etat = DEHORS;
		}
		else if (etat == DEHORS) {
			etat = DEDANS;
			++nm;
		}
	}
	printf("%d %d %d\n", nl, nm, nc);
}

