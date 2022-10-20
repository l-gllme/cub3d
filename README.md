## Cub3d

![image](https://user-images.githubusercontent.com/94530285/197015108-50058177-dac4-4494-ad0b-a7bba2ca912d.png)

### Parsing

Fichier .cub -> proteger l'extension + open en directory

1 pour les murs
0 pour un espace vide
N, S, E, W position de depart avec orientation (un seul ?)

Map fermee mais espaces acceptee et lignes de taille diferentes

Les elements (et la map) peuvent etre separes par plusieur lignes vides 

La map est en dernier mais l'orde des elements n'est pas important

Elements dans le fichier de la map

Texture des murs avec identifieur plus chemin relatif
NO ./path
SO ./path
WE ./path
EA ./path

F 100,100,0 (RGB)
C 100,100,0 (RGB)

Proteger les textures !

### Raycasting

Determiner en fonction de l'orientation et de la position du joueur sur la map,
la distance en ce dernier et le mur, faire ca pour tous les rayons compris dans le FOV.

Calculer la hauteur du mur en fonction de la distance du joueur.

Afficher en fonction de la hauteur calculer le ciel puis le mur et le sol.
