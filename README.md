# Projets ISN terminale
ta daronne elle boit du sprite

Pour faire marcher le prog :

- Sous Linux : `git clone https://github.com/blacklennon/isn.git nomdossier` => `make` => `./sudoku`
Si rien ne se passe c'est bon. Pour resoudre une grille il faut passer chaque ligne du sudoku en argument avec des points pour les cases vides.
Ex : `./sudoku ".4.1....." "..35...19" ".....6..3" "..7..5..8" ".81...96." "9..2..7.." "6..9....." "81...24.." ".....4.9."`

- Sous windaube : https://openclassrooms.com/forum/sujet/compiler-en-c-c-avec-gcc-sous-windows-12536
Si `make` marche pas go `gcc` avec tous les fichiers .c comme dans le tuto (au lieu d'en mettre qu'un faut tous les mettres a la suite). Mais le mieux c'est de voir si dans l'installation ca parle pas de Makefile a un moment si ya les lib juste go `make` tout va bien se compiler.
