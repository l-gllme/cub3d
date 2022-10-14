## Cub3d

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
