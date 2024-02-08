# TP1

## Exercice 2

### Complexité

La compléxité de l'agorithm tri_insertion est O(n^2)

### Explication

Selon le code en C et les notions théoriques on a:

```c
void tri_ins(int *tab, int n)
{
  int key, index; //O(1)
  for (int i = 1; i < n; i++) //n x (O(1)+O(1)+O(n))
  {
    key = tab[i]; //O(1)
    index = i - 1; //O(1)
    while (index >= 0 && tab[index] > key) //n x O(1)
    {
      tab[index + 1] = tab[index]; //O(1)
      index--; //O(1)
    }
    tab[index + 1] = key; //O(1)
  }
} 
// => (n x O(n)) + O(1) = O(n^2)
```

## Exercise 3

### Complexité

La compléxité de l'algorithm tri_fusion est O(n log(n))

### Explication

L’algorithme de tri fusion utilise une stratégie classique dite « diviser pour régner ». Elle consiste en découper un gros problème en plus petits problèmes, résoudre récursivement les problèmes, puis combiner les résultats pour obtenir une solution au problème initial.

En ce qui concerne l'analyse de complexité on observe ci-dessous l'arbre des appels recursifs:![1707390297121](image/README/1707390297121.png)

Le coût d’un nœud est simplement le coût de la séparation et de la fusion. Si l'on regarde les coûts par niveau, on se rend compte que le premier niveau est O(n), le deuxième deux fois 0(n/2), le troisième quatre fois O(n/4), etc. Chaque niveau coûte donc O(n), où n est la taille de la séquence initiale, jusqu'au dernier niveau, où il y a 2k feuilles représentant le coût de « trier» des sous-séquences de taille 1, i.e., O(1), et 2k = n.

Au total, la complexité de l'algorithme du tri_fusion est O(n) x le nombre de niveaux, c'est-à-dire la hauteur de l'arbre. Comme pour la recherche binaire, on trouve que cette hauteur est exactement le nombre de fois qu'il faut diviser n par 2 pour atteindre 1, soit k = log n. La complexité du tri fusion est donc en O(n log(n)).

### Selon le théorème de maitre

Considérons la relation de récurrence qui viens de théorème de maitre:

![1707390989745](image/README/1707390989745.png)

où a, b et c sont des réels positifs, avec a > 1 et b > 1. Alors :

1. Si c < logb a : C(n) = Θ(n^logb(a))
2. Si c > logb a : C(n) = Θ(n^c)
3. Si c = logb a : C(n) = Θ(n^(logb(a)) * log(n))

Dans notre cas:

`T(n) = 2T(n/2) + O(n)` selon tri_fusion_bis. Alors, a = 2, b = 2 et *f* (n) = O(n). On remarque qu'on est dans le cas numéro 2. Ainsi n^log b(a)  <=> O(n) et n^1 <=> O(n), dès lors T(n) = O(n log(n)).

## Exercise 4 

On a crée deux differents versions de la même base d'algorithm d'énumeration. L'un utilise le min et le max du tableau passé (tri_enum_v2) en argument et l'autre utilise un traitment lineaire (tri_enum) selon le numero de fois qu'on element etait trouvé sur le tableau original, tout en calculant la nouvelle position via:

```c
for (int i = n - 1; i >= 0; i--) // We start from the end and we go back to the beginning
  {
    int position = counts[tab[i]] - 1;
    sorted[position] = tab[i]; // placing the element on the final position that was found beforehand
    counts[tab[i]]--;          // in case that we have more times the same item in the table, we need to increment
    // the number_of_times that we saw it in order to be placed on the correct position (otherwise we
    // would place it always on the same position and that would have no effect on sorting)
  }
```

### Complexité

#### tri_enum

La compléxité de l'algorithm tri_base est O(n + c) => O(n)

#### tri_enum_v2

La compléxité de l'algorithm tri_base est O(n + c) => O(n^2)

### Explication

#### tri_enum

```c
void tri_enum(int *tab, int n)
{
  int key = tab[0]; //O(1)
  get_max(tab, n, &key); //O(n)

  int counts[key + 1]; //O(1)
  for (int i = 0; i <= key; i++) //key x O(1) => O(key)
  {
    counts[i] = 0; // O(1)
  }

  for (int i = 0; i < n; i++) //n x O(1) => O(n)
  {
    counts[tab[i]]++; //O(1)
  }

 
  for (int i = 1; i <= key; i++) //key x O(1) => O(key)
  {
    counts[i] += counts[i - 1]; // O(1)
  }

  int sorted[n]; //O(1)
  for (int i = n - 1; i >= 0; i--) // n x 3 x O(1) => O(n)
  {
    int position = counts[tab[i]] - 1; //O(1)
    sorted[position] = tab[i]; // O(1)
    counts[tab[i]]--;          // O(1)
  }

  for (int i = 0; i < n; i++) //n x O(1) => O(n)
  {
    tab[i] = sorted[i]; //O(1)
  }
}
```

Donc au total on a `O(1) + O(n) + O(1) + O(key) + O(n) + O(key) + O(1) + O(1) + O(n) + o(n) => O(n + key)`

#### tri_enum_v2

Si Bmax et Bmin sont des constantes, c'est-à-dire que la différence entre ces deux valeurs ne change pas et ne dépend pas de la taille du tableau n, la complexité de l'algorithme de tri par énumération change de manière significative. Dans notre algorithme:

* `get_min_max` a une complexité de O(n)
* On a deux boucles imbriques (un pour et un tant que) du coup ils ont une complexite de O(n^2)

Donc au total on a `O(n) + O(n^2) => O(n^2)`

## Exercise 5

### Complexité

### Explication

## Exercise 6

Voici les résultats du jeu:
