git submodule init
git submodule update
git submodule foreach git pull origin master

# FT LS

Approche

Flags a prendre en compte:

- l	: use a long listing format
- R	: Recursive.
- a	: Affiche aussi les entité commencant par ".".
- r	: Reverse
- t	: Sort by modification time, newest first

On verifie si le path recu est un dossier, si oui, appel vers la
fonction recursive de folder. Sinon, on apple le listeur de fichier
directement avec le patch. Selon ce principe, il y aura donc

main

## Stucture

t_ls
	
	lflag	bool (int)
	recflag	bool (int)
	aflag	bool (int)
	revflag	bool (int)
	tflag	bool (int)

### ft_ls_core (Main)

- Recois le call
- Init / free la structure de donnees
- Popule les flags
- Appel selon le path recu

### ft_ls_folders

- Fonction récursive si le flag -R est présent
- Reverse si -r est présent
- By time 

// clang -Wall -Wextra -Werror -L -c main.c -o main.o libft/libft.a -I libft/includes