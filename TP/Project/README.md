# Projet Vasileios Skarleas et Yanis Sadoun

## Question 1

Si on considere que pour cette premiere etape qu'il est possible de colorier une ligne en respectant une sequence, alors la condition necesaire est que T(M-1, k) = TRUE et T(M-2, k) = FALSE pour l'unicité avec k entre 1 et l.

Vue qu'on connait deja tous les solution de T(j,l_bizare) du sujet, on regarder pour la nombre maximale des indices de colognes et sellon chaque sequence disponible pour une ligne (au moins un), si tous les cases de la ligen sont blanc [condition suffisante]. De plus, pour la meme sequence que l condition suffisante est verifié, alors pour une indice avant l'indice maximale des colones, on regarde qu'il faut avoir comme reponse egale à False parce que normallement il n'y a pas de cases suffisantes.

## Question 2

Selon les conditions du sujet/jeu:

* Case 1
  * Il faut retourner TRUE car c'est la case de base et en fait ca veut dire qu'il n'y a pas de sequence en question alors il y a tous le spossibilités seront colorées un moment pendan tl'evolution du jeu.
* Case 2
  * Option a
    * Il va retourner FALSE car on ne peut pas rendre toute la sequence demandé pour l'indice en question
  * Option b
    * Il va retourner TRUE si on est à s1 parce que on sait forcement qu'il n'y a pas uen autre sequence à traiter. Par contre pour sl, si l > 1, alors on peut pas etre sur si la prochaine sequence pourrait etre traité d edebut à la fin.

## Question 3

Soit j' < j et l' <= l. On propose la recurence suivante:

* Si (i, j) est blanc alors T(j, l) = T(j - 1, l)
* Si (i, j) est noir alors T(j - sl -1, l - 1)

On applique tous ceux notions sur le pseudocode proposé ci-dessous pour la question 4.

## Question 4

```
bool verifier(l, j, tab, seq)
switch (l)
	cas (0):
		retourner TRUE
		break
	cas (>= 1):
		switch(j)
			cas (< seq[1, l] -1)
				retourner FALSE
				break
			cas (= seq[1, l] - 1)
				si (l =1)
					retourner TRUE
				sinon
					retiruner FALSE
				break
			cas (j > seq[l] - 1)
						if (verfier(l, j-1, tab, seq)  || verifier(l-1, j - seq[l] - 1, tab, seq))
							retourner TRUE
						else
							retourner FALSE
		fin_switch
		break
fin_switch
```

## Question 5

On propose les modifications suivantes:

```
bool verifier(l, j, tab, seq, decision_code)
NOTA: pour decision_code = 1 c'est qu'on a bien une conclusion positive (TRUE), si decision_code = 2 on a deux conclusion negative (FALSE), et enfin si decision_code = 3 on ne peut mas decider.
switch (l)
	cas (0):
		retourner TRUE
		decision_code = 1
		break
	cas (>= 1):
		switch(j)
			cas (< seq[1, l] -1)
				decision_code = 2
				retourner FALSE
				break
			cas (= seq[1, l] - 1)
				si (l =1)
					decision_code = 1
					retourner TRUE
				sinon
					decision_code = 2
					retiruner FALSE
				fin_si
				break
			cas (j > seq[l] - 1)
						if (verfier(l, j-1, tab, seq)  || verifier(l-1, j - seq[l] - 1, tab, seq))
							if (verfier(l, j-1, tab, seq)) alors
								tab[1, j] = BLANC
								retourner TRUE
							else
								if (verifier(l-1, j - seq[l] - 1, tab, seq))
									tab[1, j] = NOIR
									retourner TRUE
								else
									decision_code = 3
									retourner FALSE
								fin_si
							fin_si
						else
							retourner FALSE
							decision_code = 3
						fin_si
		fin_switch
		break
fin_switch
```

Comme j'utilise decision_code ????
