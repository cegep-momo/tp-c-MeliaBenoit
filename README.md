```
Projet de Mélia Benoit
DA: 20 21 33 252
```

# Construire le projet
Vous pouvez utiliser un dev container de base C++ de VScode.
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

# Répertoire data

Il contient 2 fichiers `books.txt`et `users.txt` que vous pouvez utilisez pour tester votre code.
Pour ca il suffit de les copiers dans le repertoire `build` avec l'application `bibliotheque`

# === VEILLE TECHNOLOGIQUE ===
# Question 1: C++
Fonctionnalité: lecture/écriture d'un fichier texte.
Fichier: filemanager.cpp/.h

`Lecture`
Pour lire le fichier contenant les données sur les livres, la fonction "FileManager::loadBooksFromFile(Library &library)" est utilisée. 
Tout d'abord, dans cette fonction, il y a une vérification du fichier afin de s'assurer qu'il y a des données existantes. 
Si c'est le cas, alors on déclare un itérateur (int count = 0;) et un string (string line;) qui servira à contenir une ligne du fichier texte. Ensuite, tant et aussi longtemps qu'il reste des lignes dans le fichier, la ITERATORème ligne est enregistrée dans un string (while(getline(file, line))).
Si ce string n'est pas vide (if (!line.empty())), alors on convertit les informations (chaque champs est séparé par |) en un objet Book (à l'aide d'une fonction dédiée), puis on ajoute ce livre dans un array contenant tous les livres (library.addBook(book);).
Finalement, on ferme le fichier texte (file.close();).

`Écriture`
Pour écrire les données sur les livres dans un fichier texte, la fonction "FileManager::saveBooksToFile(Library &library)" est utilisée
Tout d'abord, dans cette fonction, on vérifie si il est possible d'ouvrir le fichier dédié (if(!file.open())).
Si c'est possible, alors pour chaque livres (objet Book) contenus dans "library" (un array de livres), on va:
    1. Prendre chaque champs et les séparer par | à l'aide d'une fonction dédiée (book->toFileFormat()).
    2. Écrire la ligne obtenue dans le fichier, puis ajouter un saut de ligne (file << "Le texte à écrire";)
Finalement, ne pas oublier de fermer le fichier (file.close();).

# Question 2: Options de développement possible
Utiliser un fichier texte pour enregistrer des millions de livres (et autres informations) n'est pas une bonne pratique. Il serait mieux d'utiliser une base de données, par exemple MySQL. Donc, au lieu d'utiliser un fichier texte et d'avoir à lire lignes par lignes les millions de donées, il suffirait simplement d'enregistrer les informations dans une BD MySQL et d'accéder aux informations à partir de requêtes. La clé primaire de la table "Books" serait l'ISBN. Le champs "borrowerName" serait désormais "borrowerID" et serait une clé étrangère référençant l'ID de la table "Users".