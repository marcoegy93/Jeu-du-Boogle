:: La grille à jouer est dans grille.txt
:: Les listes de mots des 3 joueurs sont dans coup-j1.txt, coup-j2.txt et coup-j3.txt
:: Le script qui suit affiche les points remportés par chaque joueur

@echo off

:: ----------------------------  A ADAPTER selon votre organisation ---------------------------
:: Chemin vers les exécutables exo1, exo2, ..., exo6
set cheminexe=..\test
:: Chemin vers le dictionnaire ods4.txt
set chemindico=..\test
:: --------------------------------------------------------------------------------------------

:: calculer les mots présents dans au moins deux des listes des joueurs
(type coup-j1.txt & type coup-j2.txt & type coup-j3.txt & echo *) | %cheminexe%\exo5 > commun.txt

:: supprimer ces mots de chacune de ces listes en en profitant pour supprimer les mots répétés

(type commun.txt & type coup-j1.txt) | %cheminexe%\exo3 | %cheminexe%\exo2 > tmp-j1.txt
(type commun.txt & type coup-j2.txt) | %cheminexe%\exo3 | %cheminexe%\exo2 > tmp-j2.txt
(type commun.txt & type coup-j3.txt) | %cheminexe%\exo3 | %cheminexe%\exo2 > tmp-j3.txt

del commun.txt

:: supprimer de ces listes les mots n'apparaissant pas dans le dictionnaire

(type %chemindico%\ods4.txt & echo * & type tmp-j1.txt) | %cheminexe%\exo4 > tmp.txt
copy /Y tmp.txt tmp-j1.txt > NUL
(type %chemindico%\ods4.txt & echo * & type tmp-j2.txt) | %cheminexe%\exo4 > tmp.txt
copy /Y tmp.txt tmp-j2.txt > NUL
(type %chemindico%\ods4.txt & echo * & type tmp-j3.txt) | %cheminexe%\exo4 > tmp.txt
copy /Y tmp.txt tmp-j3.txt > NUL

del tmp.txt

:: supprimer de ces listes les mots n'apparaissant pas dans la grille et afficher le nombre de points

(type grille.txt & type tmp-j1.txt) | %cheminexe%\exo6 | %cheminexe%\exo1 & echo ^ point(s) pour le joueur 1
(type grille.txt & type tmp-j2.txt) | %cheminexe%\exo6 | %cheminexe%\exo1 & echo ^ point(s) pour le joueur 2
(type grille.txt & type tmp-j3.txt) | %cheminexe%\exo6 | %cheminexe%\exo1 & echo ^ point(s) pour le joueur 3

:: faire le peu de ménage restant

del tmp-j?.txt

:: afficher le nombre maximal de points qui était possible pour cette grille

echo ----------
(type grille.txt & type %chemindico%\ods4.txt & echo *) | %cheminexe%\exo6 | %cheminexe%\exo1 & echo ^ point(s) au maximum possible

 