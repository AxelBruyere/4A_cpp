# Compte Rendu du TP 4 
###### par Philippe CHARRAT, le 05/02/2021 

### Partie 1 : Gestion des utilisateurs et des groupes
- Question 1 : Pour créer  un groupe, il faut utiliser la commande : groupadd dev avec dev qui est le nom du groupe crée. 
- Question 2 : Pour créer un compte utilisateur, la commande est useradd alice --create-home --shell /bin/bash avec deux options : 
  - alice : le nom de l'utilisateur crée.
  - create-home : création du dossier personel associé à l'utilisateur.
  - shell : sélection du shell pour exécuter les commandes du terminal utilisateur. Dans notre cas, nous avons choisie /bin/bash qui est un shell relativement complet.  
- Question 3 : Pour ajouter un utilisateur dans un groupe, la commande est adduser alice dev avec : 
  - alice : le nom de l'utilisateur à ajouter.
  - dev : le nom du groupe destination. 
- Question 4 : La première méthode est la commande getent group infra, avec getent une commande pour les bases de données (issue de l'article : [suivant](linuxize.com/post/how-to-list-groups-in-linux)). group correspond à la base de données appelée et infra, le mot clé recherché. </br> La seconde méthode est composée de deux instructions : 
  - cut -d : -f1,4 /etc/group : Les lignes dans /etc/group sont composés d'éléments séparés par ':'. cut va scinder le fichier en colonnes. L'option -d : indique que le séparateur est le charactère ':'. -f 1,4 indique la récupération des colonnes 1 et 4. 
  - grep infra : grep permet de filtrer les résultats et d'afficher ceux contenant le mot clé attendu (dans notre cas : infra ou dev).
  - Remarque : pour le groupe dev, on a plusieurs groupes qui contienne *dev donc la sortie donne plusieurs lignes.* 
  - Commande complète : cut -d : -f1,4 /etc/group | grep infra 
  - Résultat avec le groupe infra pour la seconde méthode : infra:dave,bob,charlie
- Question 5 : Pour modifier le propriétaire ou le groupe, la commande est chown -R alice:infra /home/alice avec les options : 
  - -R : Modifie les réperoirtes et leurs contenus de manière récursive. 
  - alice:infra : le nouveau propriétaire (alice) et le nouveau groupe (infra).
  - /home/alice : le répertoire concerné. 
- Question 6 : Pour changer de groupe intial d'un utilisateur, la commande est usermod -g dev alice avec les options : 
  - -g : paramètre pour indiquer la modification du groupe *initial*.
  - nomdugroupe : nouveau groupe assigné, dans notre cas dev.
  - user : nom de l'utilisateurs affecté, dans notre cas alice.
- Question 7 : Pour créer un dossier partagé entre tous les membres d'un groupe (exemple : infra). La commande est composée de trois parties :
  - mkdir /home/infra : création d'un dossier nommé infra dans le répertoire /home.
  - chown -R root:infra /home/infra : la commande chown réalise la modification de propriété d'un élements. Le -R indique que le changement sera appliqué de manière récursive sur les sous-dossiers et contenues du répertoire. root:infra dit que le nouveau propriétaire est root et le nouveau groupe propriétaire est infra. /home/infra indique le dossier concerné par les changements. 
  - chmod 770 /home/infra : chmod permet un changement des propriétés sur un éléments. 770 indique que le propriétaire et membres du groupe propriétaire auront toutes les permissions sur ce dossier, les autres aucune. /home/infra indique le dossiers concerné. 
  - La commande complète : mkdir /home/infra |chown -R root:infra /home/infra | chmod 770 /home/infra
- Question 8 : Dans le dossier partagé, seul les propriétaires puissent être renommer ou supprimer le fichier. La commande est chmod g+t /home/infra. Le t est le sticky bit, il s'agit d'une permission spéciale pour que seul le propriétaire puisse supprimer ou renommer son fichier. Le g pour modifier les permissions du groupe. 
- Question 9 : Nous ne pouvons pas nous connecter sur les comptes créer (alice, charlie, ...), il est nécessaire d'avoir un mot de passe configurer pour l'utilisateur.   
- Question 10: Pour configurer le mot de passe d'un compte, il faut appliquer la commande : passwd alice. Cela va demander de saisir deux fois le mot de passe. Une fois cette manipulation effectuée, le compte est utilisable.
- Question 11: Pour connaitres l'id utilisateur (UID), la commande est id -u alice et l'on obtient l'id suivant : `1001'. 
- Question 12: Pour connaitre le nom de l'utilisateur à partir de son UID. La commande`id -nu 1003` retourne charlie. 
- Question 13: Pour connaitre l'id d'un groupe en fonction de son nom. Nous allons utiliser les trois instructions suivantes : 
  - cat /etc/group : Affiche le fichier /etc/group.   
  - grep infra :  Affiche les lignes avec infra (nom du groupe).
  - awk -F : '{print $ 3}' : Affiche la troisième colonne donc le GID ( à l'aide de la doc : [ici](http://doc.ubuntu-fr.org/tutoriel/gestion_utilisateurs_et_groupes_en_ligne_de_commande))
  - Commande complète : `cat /etc/group |grep infra |awk -F : '{print $ 3}' 
  - Remarque : pour le groupe dev, on a plusieurs groupes qui contienne *dev donc la sortie donne plusieurs lignes.* 
  - La réponse pour alice, est l'id 1001. 
- Question 14: Pour connaitre le nom d'un groupe en fonction de identifiant. Nous allons utiliser les trois instructions suivantes : 
  - cat /etc/group : Affiche le fichier /etc/group.   
  - grep 1003 :  Affiche les lignes avec 1003 (id du groupe).
  - awk -F : '{print $ 1}' : Affiche la première colonne à savoir le nom ( à l'aide de la doc : [ici](http://doc.ubuntu-fr.org/tutoriel/gestion_utilisateurs_et_groupes_en_ligne_de_commande))
  - Commande complète : cat /etc/group |grep 1003 |awk -F : '{print $ 1}'
  - La réponse pour le GUID 1003 est charlie. 
- Question 15: La commande gpasswd --delete charlie infra va retirer le membre charlie du groupe infra. A l'aide de cat /etc/group, nous pouvons observer que charlie a été retiré du groupe infra. Avec id charlie, le groupe initial reste infra. Nous pouvons en déduire que l'utilisateur "reste" dans le groupe tant qu'un nouveau ne lui ai pas attibué mais n'est plus référencé dans celui-ci. 
- Question 16: Pour faire expirer un compte à une date précise, nous utilisons la commande usermod -e 2021/06/01 dave. L'option e est pour indiquer la présence de la date d'expiration (au format AAAA/MM/DD). Pour la configuration du mot de passe, le commande est chage -m 5 -M 90 -W 14 -I 30 dave avec les otpions suivantes :
  - -m X: Le mot de passe ne peut être modifier tous les X jours, avec 5 jours dans notre cas.
  - -M X: Le mot de passe est expiré s'il n'est pas modifié avant X jours, 90 dans notre cas.
  - -W X: Si la date d'expiration du mdp est dans X (14) jours, l'utilisateurs reçoit un message d'alerte. 
  - -I X: Le compte est bloqué si le mot de passe est expiré depuis X (30) jours.
- Question 17: Pour connaitre le shell utilisé par un utilisateur, la commande est composée de 3 parties :
  - cat /etc/passwd : Affichage du fichier /etc/passwd qui contient tous les utilisateurs enregistré sur la machine.
  - grep root : Trie et récupération des lignes contenant le mot clé root
  - awk -F : '{print $ 7}' : Affichage de la 7ième colonne, le shell de l'utilisateur. 
  - *Remarque : Plusieurs utilisateurs ou groupe se nomme *root**
  - Commande complète : cat /etc/passwd | grep root | awk -F : '{print $ 7}' 
  - Sortie : /bin/bash /usr/sbin/nologin, on en déduit que /bin/bash est le shell du root. Après modification de la ligne (en affichant la première colonne), il apparait que  /usr/sbin/nologin est le shell de l'utilisateur nm-openvpn.
- Question 18: Avec la commande cat /etc/passwd | grep nobody, la sortie est : nobody:x:65534:65534:nobody:/nonexistent:/usr/sbin/nologin. Cet utilisateur a pour unique fonction d'éxecuter des programme. C'est une sécurité de Linux qui va faire un utilisateur avec un minimum de permission. En exécutant des scripts, s'il se fait corrompre par une attaque alors aucun fichier ne sera impacté.
- Question 19: Quand la commande sudo est utilisée, la session va mémoriser pendant 15 minutes le mot de passe administrateur. Pendant ce laps de temps, l'utilisateur peut exécuter sudo sans demande de mot de passe. Pour finir la session, il faut appliquer la commande sudo -k avec le paramètre -k pour remettre à zéro la session de temps.

### Partie 2 : Gestion de permissions

- Question 1 : Après la création du dossier avec la commande mkdir et du fichier avec touch. La commande ls -ll . va lister les fichiers, leurs propriétaires et permissions. Le . indique le fichier courant. Les sorties sont :
  -`drwxrwxr-x 2 philippe philippe 4096 Feb  5 16:22 test` : Pour le répertoire test, le propriétaire (philippe) à les droits de lecture/ecriture/execution. Le groupe philippe et les "autres" ont des droits de lecture/exécution.
  -`-rw-rw-r-- 1 philippe philippe 78 Feb 5 16:22 fichier` :  Pour le répertoire fichier, le propriétaire (philippe) et le groupe philippe ont les droits de lecture/ecriture. Les "autres" ont le droit de lecture.
- Question 2 : Si l'on supprime tous les droits avec la commande : chmod 000 fichier. 000 indique aucune permission aux propriétaire, groupe et autres. Avec la commande vim fichier (vim est un éditeur de texte), deux possibilités : 
  - utilisateur philippe : permission refusé.
  - utilisateur root : possibilité de modifier/supprimer le fichier. Le super utilisateur root n'est pas impacté par les permissions sur le fichier. 
- Question 3 : La commande echo "Hello World" > fichier, deux cas de figures possibles : 
  - utilisateur philippe ou du groupe philippe, le contenue de fichier est remplacé par "Hello World".
  - autre (exemple : utilisateur alice), la permission est refusée. Cela est cohérent car cela est une écriture sur fichier. Or à l'aide de la question 1, il a été établit que les autres utilisateurs n'ont pas de droit d'écriture sur fichier. 
- Question 4 : Pour la commande ./fichier, deux cas de figure : 
  -utilisateur philippe ou du groupe philippe ou autre : Permission denied. Les permissions montre que x n'est pas autoriser par défaut. 
  -`root` : exécution du fichier, mais erreur car le fichier n'est pas un script. Comme pour la question 2, root n'est pas impacté par les permissions du fichier donc peut l'exécuter.  
- Question 5 :  Avec la commande chmod 330, les permissions de lecture sont retirés. Les commandes suivantes : 
  - ls -ll test : ls: cannot open directory 'test': Permission denied. Il n'est plus possible de lister les contenues du fichier.
  - mkdir test_test : Possibilité de créer un répertoire ou fichier. 
  - vim test/fichier : Possibilité de modifier un fichier. 
- Question 6 : Si les permission du dossier test  sont Exécution/Lecture (chmod 550 test), il est possible de modifier fichiers existant. Mais les actions de créer ou supprimer un fichier (exemple : commande touch nomdufichier) sont interdite. Pour le fichier nouveau, sans la permission d'écriture, il est dans un état de lecture seul (exemple : vim fichier). 
- Question 7 :Avec la commande chmod 660, les permissions d'exécution sont retirés. Le résultat des commandes suivantes : 
  - ls -ll test : ls: cannot open directory 'test': Permission denied. Il n'est plus possible de lister les contenues du fichier.
  - mkdir test_test : Il n'est plus possible de créer un fichier/réperoire. 
  - vim test/fichier : Il n'est plus possible de modifier un fichier.  
  - cd test/ : Il n'est plus possible de modifier un fichier.  
- Question 8 : on ne pas créer/modifier/supprimer un fichier, ni lister le contenue, ni aller dans les sous-répertoires. Mais on peut faire cd .. car il s'agit des permissions du dossiers parents. 
Question 9 : chmod 740 fichier
Question 10: umask 077 -> réponse : drwx------ 2 alice dev 4096 Feb  5 17:16 se
Question 11: umask 022 -> réponse : drwxr-xr-x 2 alice dev 4096 Feb  5 17:18 tre | fichier : -rw-r--r-- 1 alice dev    0 Feb  5 17:19 gyu
Question 12: umak 027 -> réponse : drwxr-x--- 2 alice dev 4096 Feb  5 17:18 tres | fichier : -rw-r----- 1 alice dev    0 Feb  5 17:19 trees
Question 13: - 534 | * 603 |  rw-r-x-wx | 
Question 14: ls -ll /etc | grep passwd -> réponse : -rw-r--r--  1 root root       3066 Feb  5 15:02 passwd. Ce fichier est une BDD qui contient les infos sur les users qui peuvent se connecter aux système. Un utilisateurs classique peut être amener à consulter cette liste mais il ne doit pas pouvoir la modifier (ce serait très dangereux). Root qui va créer/modifier/ supprimer des utilisateurs doient avoir les accès en lecture/ecriture. Comme ce n'est pas un script, on n'a pas la permission d'exécution.
