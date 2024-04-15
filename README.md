# Projet LIFAPCD
12202838 LUCAS DUCHAMP

12209697 DJESSY-ALBERTO KITA

12209838 COME KOUAME


# L'Antagoniste
## DESCRIPTION : 
L'Antagoniste est un jeu de type RPG avec des combats en tour par tour. 
Vous incarnez un personnage qui se surnomme "L'Antagoniste", comme son nom l'indique il est antipathique, malveillant et très mal élevé.
Au cours de votre aventure vous allez rencontrer des PNJs, avec qui l'on peut interagir, des coffres pour y trouver des objets
qui pourront être utilisés pour se battre avec des ennemis. 

## Utilisation :
Exécuter la commande 'make' sur Linux puis './bin/mainAff' pour la version graphique, './bin/mainTxt' pour la version de la démo mi_parcours dans le terminal ou bien ./bin/testCombat pour avoir une démonstration du déroulé d'un combat.

### Dans bin/mainAff et bin/mainTxt 
Pour se déplacer : Format Z,Q,S,D (respectivement Avancer,Gauche,Reculer,Droite)

### Dans bin/mainAff 
Pour interagir avec l'environnement (PNJs, Coffres) : "F"
Pour quitter le jeu : Echap ou la croix de la fenêtre en haut à droite.

### Dans bin/mainTxt 
Pour quitter le jeu : "P" ou la fermeture du terminal.

### Dans bin/testCombat
Le combat commence dès que le fichier est exécuté. On utilise le clavier numérique :

Sur le menu principal : <br>
1 -> attaque de base <br>
2 -> garde <br>
3 -> compétences <br>
4 -> inventaire <br>
5 -> retraite <br>

Sur la sélection d'ennemi : <br>
1,2 ou 3 selon l'ennemi qu'on veut attaquer.

Sur le menu de compétences : <br>
1 -> attaque mono-cible (attaque un ennemi) <br>
2 -> attaque multi-cible (attaque tous les ennemis) <br>
3 -> soin (augmente la vie du personnage) <br>

Sur l'inventaire : <br>
Tous les chiffres de 0 à 9 selon l'objet voulu.

## Organisation de l'archive
bin -> Les fichiers exécutables. <br>
data -> Les images des cartes, des dialogues et du héros. <br>
doc -> La documentation des modules, la présentation en PDF, le diagramme de Gantt et le diagramme des classes UML. <br>
obj -> Les fichiers objets. <br>
src -> Les fichiers .cpp et .h contenant les classes du projet et leur code.

##  Documentation du code

Avoir doxygen installé pour générer la documentation.
Exécuter la commande firefox doc/html/index.html pour la voir.