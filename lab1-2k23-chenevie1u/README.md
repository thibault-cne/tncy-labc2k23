# Lab #1 - Introduction à la programmation C

## Objectifs

- Mettre à jour son environnement de travail
- Savoir compiler/exécuter un programme C
- Connaître la syntaxe de base du langage C et 
  - variables, types primitifs
- savoir utiliser les structures de contrôle classique
  - boucles, conditionnelles, etc.
- Définitions et appels de fonctions
- Définition, initialisation et utilisations de tableaux à taille fixe
- Gestion élémentaire des entrées/sorties
- Programmation modulaire et compilation séparée
  - écriture d'un `makefile` et utilisation de la commande `make`


## Préliminaires

Vous réaliserez ce travail dans un dépôt Git local. Il vous est demandé de commiter **régulièrement** vos contributions et de *pousser* celles-ci sur la plateforme GitLab (https://gitlab.telecomnancy.univ-lorraine.fr) de l'école.
Veillez à organiser votre dépôt de la manière suivante :
- un répertoire `src/` dans lequel vous placerez le code source de votre travail
- ne committez que le code source `.c` et non les versions compilées de vos programmes. Pour cela ajouter le nécessaire dans le fichier `.gitignore` pour ignorer les fichiers `.o` notamment.


## Rendu

Ce travail est à rendre au plus tard le **lundi 6 février 2023 à 13:00** sur la plateforme GitLab de l'école.


### Pré-requis

Pour l'ensemble du module, nous utiliserons l'environnement de développement intégré Visual Studio Code (https://code.visualstudio.com/). Cet environnement est normalement déjà installé dans la machine virtuelle.

Sinon, vous devrez :

- Téléchargez et installez celui-ci si ce n'est pas déjà fait (https://code.visualstudio.com/).

Vous devez maintenant, si ce n'est pas déjà fait, cloner le dépôt du TP, vous placer dans le répertoire ainsi créer. Plus tard, vous devrez ouvrir ce répertoire dans Visual Studio Code (en utilisant la commande `code .` par exemple).
```sh
# en SSH
git clone git@gitlab.telecomnancy.univ-lorraine.fr:c2k23/lab1-oster7.git
# ou en HTTPS (ici on insére l'adresse email dans l'URL lors du "clonage" afin de ne pas avoir à la re-saisir plus tard -- à chaque "push")
git clone https://gerald.oster%40telecomnancy.eu@gitlab.telecomnancy.univ-lorraine.fr/c2k23/lab1-oster7.git

cd lab1-oster7.git
```

**C'est parti !**




## Environnement de développement

Cette section est dédiée à la configuration de votre environnement de développement. Les explications sont dédiées à être réalisée sur la machine virtuelle (VirtualBox) fournie par l'école. Elles peuvent être facilement adaptées pour un autre environnement GNU/Linux ou pour macOS.

Cette année, dans le module de C, nous utiliserons exclusivement le compilateur Clang (https://clang.llvm.org/) et l'environnement de développement intégré Visual Studio Code (https://code.visualstudio.com/).


### Configuration de Visual Studio Code

Dans cette section, vous trouverez les deux extensions à installer


#### C/C++ Extension pack `ms-vscode.cpptools-extension-pack`
https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack

**Sources:**
- https://code.visualstudio.com/docs/cpp/config-linux
- https://code.visualstudio.com/docs/cpp/config-clang-mac

Dans un terminal, vous pouvez simplement exécuter la commande suivante :
```sh
code --install-extension ms-vscode.cpptools-extension-pack
```


#### Makefile Tools `ms-vscode.makefile-tools`
https://marketplace.visualstudio.com/items?itemName=ms-vscode.makefile-tools 

**Sources:**
- https://devblogs.microsoft.com/cppblog/now-announcing-makefile-support-in-visual-studio-code/


Dans un terminal, vous pouvez simplement exécuter la commande suivante :
```sh
code --install-extension ms-vscode.makefile-tools 
```


### Validation

Une fois que vous avez réalisé toutes les étapes précédentes, exécuter le script `report.sh`.

```sh
./report.sh
```



## Exercices

Ouvrez dans Visual Studio Code le répertoire de votre dépôt. Vous pouvez par exemple utiliser la commande suivante :

```bash 
cd lab1-oster7 # si ce n'est déjà fait
code . # pour ouvrir (en tant que projet) le répertoire courant
```

### Exercice 1 : Hello world

1. Dans un fichier `helloworld.c`, écrivez un programme permettant d'afficher le message `Hello, World!` sur la sortie standard.

   Si vous avez besoin d'aide concernant une fonction de la librairie C, nous vous invitons à consulter la page `man` dédiée à cette fonction (i.e. pour obtenir la documentation de la fonction `printf` vous pouvez utiliser la commande `man 3 printf`).

2. Compilez et exécutez ce programme.

	Pour rappel, les lignes de commande à utiliser sont (si vous avez des questions à ce sujet, n'hésitez pas à interpeller votre chargé(e) de TD/TP) :
	```bash
	clang -c -Wall -Wextra -pedantic -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls helloworld.c
	clang -Wall -Wextra -pedantic -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls  helloworld.o -o helloworld
	```


### Tests unitaires

Dans votre dépôt git, vous disposez d'une branche `tests` contenant un certain nombre de scripts `bash` et de programmes `.c` permettant de tester votre code.

Nous exécuterons de manière automatisée (en utilisant le serveur d'intégration continue de la plateforme GitLab) ces tests sur votre code afin de connaître l'état de votre rendu. Vous pouvez consulter ces tests (sans y être obligé) de différentes manières :
- en consultant le contenu de la branche `tests` par l'interface web de la plateforme GitLab
- en consultant le contenu de la branche `tests` par l'intermédiaire de la commande `git checkout` (ou `git switch`)
- en fusionnant la branche `tests` dans votre branche `master` par l'intermédiaire de la commande `git merge`



### Exercice 2 : Entrées/sorties et fonctions

1. Dans un fichier `max3.c`, écrivez un programme qui calcule le maximum de 3 valeurs entières. 
    
    Les trois valeurs à comparer seront précisées dans des variables `a`, `b` et `c` que vous définirez dans votre programme. Il fera ensuite appel à une fonction `max3` que vous définirez. Le résultat renvoyé par cette fonction sera affiché sur la sortie standard.

	Pour répondre à cette question, vous aurez sûrement besoin de consulter un peu de documentation sur les chaînes de format. Vous devriez avoir lu à ce sujet dans le Chapitre 1 "Les bases de la programmation en C" (page 30) du polycopié fourni sur Arche.


2. Compilez et exécutez votre programme. 

    Quels sont les jeux de tests (les valeurs à passer en paramètre) que vous devez envisager pour s'assurer de la correction de votre programme ? Documentez ces jeux de tests dans un fichier texte `max3_tests.txt` où chaque ligne correspond à une entrée (3 valeurs entières séparées par un espace) à passer en paramètre pour une exécution de votre programme.

3. Dans un fichier `max3_stdin.c`, écrivez un programme qui calcule le maximum de 3 valeurs entières. 

   Cette fois-ci, le programme demandera à l'utilisateur de saisir les 3 valeurs entières sur l'entrée standard (une valeur par ligne).

   **Remarque :** Vous pourrez être amené à utiliser la fonction `scanf` de la librairie standard pour lire une valeur entière depuis l'entrée standard. Vous pouvez vous référer au chapitre 1 du polycopié (page 31) ou à la page man de la fonction `man 3 scanf`.
 
4. Dans un fichier `max3_args.c`, écrivez un programme qui calcule le maximum de 3 valeurs entières.

   Cette fois-ci, le programme demandera à l'utilisateur de passer les 3 valeurs entières en paramètre sur la ligne de commande.

   **Remarque :** Vous serez amené à utiliser la fonction `atoi` de la librairie standard pour convertir une chaîne de caractères en une valeur entière. Là encore, vous devriez consulter la page man associée (`man 3 atoi`).


### Exercice 3 : Entrées/sorties et tableaux

Il est possible d'identifier le signe astrologique d'une personne en fonction de sa date de naissance. Pour cela, il suffit de consulter le tableau ci-dessous :

| Signe | Dates | | Signe | Dates |
|:------|:------|-|:------|:------|
| Bélier     | 21/3 au 19/4 | | Balance    | 23/9 au 22/10 |
| Taureau    | 20/4 au 20/5 | | Scorpion   | 23/10 au 21/11 |
| Gémeaux    | 21/5 au 20/6 | | Sagittaire  | 22/11 au 21/12 |
| Cancer     | 21/6 au 21/7 | | Capricorne | 22/12 au 19/1 |
| Lion       | 22/7 au 22/8 | | Verseau    | 20/1 au 18/2 |
| Vierge     | 23/8 au 22/9 | | Poisson    | 19/2 au 20/3 |


1. Écrivez un programme `zodiac.c` prenant en paramètre (en argument de la ligne de commande) la date de naissance d'un utilisateur (au format jour/mois/an) et qui affiche en retour son signe astrologique. On imposera que l'année de la date saisie soit positive et non nulle. Si la date saisie n'est pas valide, affichez un message d'erreur et quitter le programme avec un code de retour non nul.

   Vous découperez votre programme en plusieurs sous fonctions (validation de la date, calcul du signe astrologique, etc.)

   Vous proposerez un algorithme reposant sur des tableaux qui mémorisent les signes astrologiques et leurs dates d'effet pour réaliser ce programme. (Il ne s'agit pas ici de faire un énorme `if... else... else if...` ni d'utiliser une construction du type `switch... case...`, mais plutôt une variante d'une boucle de recherche).

   **Rappel :** On rappelle que les tableaux en C sont des tableaux à taille fixe.

   **Remarque :** Vous pourrez être amené à utiliser la fonction `sscanf` de la librairie standard pour analyser une chaîne de caractères.


### Exercice 4 : Entrées/sorties et fonctions

1. Écrivez un programme `dayofbirth.c` qui indique le jour de la semaine de naissance de l'utilisateur. Ce jour peut être calculé en utilisant la formule de Zeller (1885) :
> ω = j + ⌊2.6 × t - 0.2⌋ + d  + ⌊d / 4⌋ + ⌊c / 4⌋ + 5 × c
>
>où : 
>   - j : numéro du jour dans le mois,
>   - m : numéro du mois dans l'année,
>   - a : numéro de l'année,
>   - la notation ⌊x⌋ correspond à la partie entière de x, 
>   - t = m - 2 si m > 2 sinon m + 10
>   - b = a si m > 2 sinon a - 1
>   - c = ⌊b / 100⌋
>   - d = b - 100 × c
>
>   ω ≡ 0 (mod 7) si le jour est un dimanche, à 1 (mod 7) si le jour est un lundi, etc.

   L'utilisateur devra saisir son prénom ainsi que sa date de naissance sur la ligne de commande (ie. `./dayofbirth "Black Adder" 15/06/1983`). Le résultat sera affiché sur la sortie standard (ie. `Black Adder est né(e) un Mercredi`).

2. Écrivez un deuxième programme `dayofbirth_stdin.c` qui effectue les mêmes calculs, mais cette fois demande à l'utilisateur de saisir son nom et sa date de naissance sur l'entrée standard (vous pourriez être amené à utiliser les fonctions `fgets` et `strnlen`).

   ```bash
   rlyeh:c2k23-lab1.git cthulhu$ ./dayofbirth_stdin
   Gerald O.
   19/03/1978
   Gerald O. est né(e) un Dimanche
   rlyeh:c2k23-lab1.git cthulhu$
   ```

### Exercice 4 : Programmation modulaire et compilation séparée

L'objectif de cet exercice est de re-découper le code source de l'exercice précédent en plusieurs fichiers sources (`.c`) et d'entêtes (`.h`) contenant les prototypes des fonctions.

Les fichiers attendus sont :
- `astrological.h`, un fichier d'entêtes contenant les prototypes des fonctions de calcul (signe astrologique et jour de naissance).
- `astrological.c`, un fichier de code source contenant le code des fonctions de calcul.
- `astrological_main.c`, un fichier de code source principal faisant appel aux fonctions définies dans le fichier `astrological.c`. Ce programme lit ces entrées sur la ligne de commande.
- `astrological_main_stdin.c`, un fichier de code source principal faisant appel aux fonctions définies dans le fichier `astrological.c`. Ce programme lit les valeurs saisies sur l'entrée standard.

1. Écrivez les différents fichiers d'entêtes et de code source.

   Les fonctions à définir devront respecter les indications suivantes :
   - la fonction `compute_zodiac` qui prend en paramètre 2 valeurs entières de type `int` (le jour et le mois) et qui retourne le signe astrologique sous la forme d'une chaîne de caractères (`char*`)
   - la fonction `validate_date` qui prend en paramètre 3 valeurs entières de type `int` (le jour et le mois et l'année) et qui retourne une valeur booléenne (type `char` valant 1 si vrai, sinon une valeur nulle). 
   - la fonction `zeller` qui prend en paramètre 3 valeurs entières de type `int` (le jour, le mois et l'année) et qui retourne une valeur entière (type `int`) correspondant au numéro du jour dans la semaine (0 pour dimanche, 1 pour lundi, etc.).
   - la fonction `day_of_week` qui prend en paramètre 3 valeurs entières de type `int` (le jour, le mois et l'année) et qui retourne une chaîne de caractères (type `char*`) indiquant le jour de la semaine correspondant à la date donnée en paramètre.

2. Compilez de manière séparée vos programmes. 
   Vous compilerez :
   1. d'abord et uniquement `astrological.c`, 
   2. puis uniquement `astrological_main.c` (respectivement `astrological_main_stdin.c`) 
   3. et enfin vous assemblerez `astrological.o` avec `astrological_main.o` (respectivement `astrological_main_stdin.o`) pour générer l'exécutable `astrological_main` (respectivement `astrological_main_stdin`)


### Exercice 5 : Makefile

Dans cet exercice, nous vous demandons d'écrire un fichier `makefile` permettant de compiler/re-compiler le code de l'exercice précédent.
Pour connaître la syntaxe spécifique à un fichier `makefile`, nous vous invitons à revoir la partie du CM et également à lire la section 7.3 (page 93) du chapitre 7 du polycopié.



### Exercice 6 : Transformations de chaînes de caractères

1. Dans des fichiers `stringtools.h` et `stringtools.c`, écrivez une fonction `char min2maj(char c)` qui convertit un caractère minuscule passé en paramètre en sa majuscule associée.

   **Indice :** La documentation retournée par la commande `man 7 ascii` devrait vous permettre de trouver une solution simple à ce problème.

2. Complétez les fichiers `stringtools.c` et `stringtools.h`, en écrivant une fonction `char maj2min(char c)` qui convertit un caractère majuscule passé en paramètre en sa minuscule associée.

3. Écrivez un programme `stringtools_main.c` qui prend en paramètre sur la ligne de commande une chaîne de caractères et qui transforme chaque caractère minuscule en majuscule et inversement. Le résultat sera affiché sur la sortie standard. Votre programme fera usage des fonctions définies dans les questions précédentes.


### Exercice 7 : Occurrences d'un caractère dans un mot

1. Dans des fichiers `occurrences.h`et `occurrences.c`, écrivez les fonctions suivantes :
   - la fonction `int first_occurrence(char c, char str[])` qui renvoie le rang de la première occurrence du caractère `c` dans la chaîne `str` si celui-ci est présent sinon elle retourne la valeur -1.
   - la fonction `int last_occurrence(char c, char str[])` qui renvoie le rang de la dernière occurrence du caractère `c` dans la chaîne `str` si celui-ci est présent sinon elle retourne la valeur -1.

   **Remarque :** Vous pourrez être amené à utiliser la fonction `strlen` de la librairie standard.


2.  Écrivez dans un fichier `occurrences_main.c` un programme qui trouve la première et la dernière occurrence d'un caractère dans un mot. Le mot et le caractère seront lus à partir de l'entrée standard (caractère recherché sur la première ligne, mot sur la seconde, affichage des résultats sur la sortie standard séparés par un espace).

    ```bash
    rlyeh:c2k23-lab1.git cthulhu$ ./occurrences_main
    a
    abcdefga
    0 7
    ```

3. Généralisez votre programme (dans un fichier `occurrences_main_loop.c`) à une suite de mots entrée au clavier, la saisie du mot `exit` provoquant la terminaison du programme.
