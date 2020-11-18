# Word_count program (based on K&R program)

Ce programme est une version réduite au plus simple de la commande ``wc`` (Word Count) implémenté dans les systèmes UNIX.

```c
#define DEDANS 1
#define DEHORS 0
```
Je définis au départ du programme les états DEDANS et DEHORS afin de signaler au programme quand nous sommes sur un mot ou non (espaces, tabulations, retour à la ligne)

```c
int main(){
	int c, nl, nm, nc, etat;

/* j'init les variables:
      [c] caractere,
      [nl] nombre de ligne,
      [nm] nombre de mot,
      [nc] nombre de caractere,
      [etat] etat du curseur (DEHORS ou DEDANS)
*/

	etat = DEHORS;
	nl = nm = nc = 0;

  while ((c = getchar()) != EOF) {
/* J'utilise une boucle while pour lire tout les caractères jusqu'à EOF
   soit via une fichier contenant les caractères, soit en utilisant ^D pour signifier le EOF
*/
  	++nc; // J'incrémente pour chaques caractères
		if (c == '\n'){
			++nl; // J'incrémente pour chaques lignes
		}
		if (c == ' ' || c == '\n' || c == '\t') {
			etat = DEHORS;
		}
		else if (etat == DEHORS) {
			etat = DEDANS;
			++nm; // J'incrémente pour chaques mots
		}
	}
	printf("%d ligne(s)\n %d mot(s)\n %d caractère(s)\n", nl, nm, nc); // J'affiche tous les types de caractères
}
```

Pour vérifier le fonctionnement du programme, j'utilise le fichier `fichierwc`

```
Bonjour ceci est un fichier
un ficher contenant des mots, des espaces et des retours à la ligne.

enf of file
```
