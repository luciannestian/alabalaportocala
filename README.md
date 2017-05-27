##System tools

Un utilitar scris C++ pentru lucrul cu fișiere - similar celor din Linux - cu (minimal) următoarele
funcționalități:
##- cd
-schimbarea directorului curent

##- ls
-listarea fișierelor din directorul curent

##– cp
- copierea unui fişier într-o altă / nouă locaţie sau sub un alt nume

##– mv
- mutarea sau redenumirea unui fișier (dintr-o sursă într-o destinaţie) sub un alt nume

##– grep
-  căutarea în cadrul directorului curent (la nivel de linie) a unui şir de caractere – cu
opțiunile:
 * -n  se afişează şi numărul liniei în care apare şirul
 * -y - nu se face deosebire între literă mare şi literă mică

##– cat
- concatenarea conţinutului mai multor fişiere de tip text 

##- find

- Cautarea unui fisier, după un anumit pattern de nume, intr-un folder ​, cu
următoarele opțiuni:
 * -r - recursiv, se va căuta fișierul și în subfoldere.
 * -d X - adâncimea maximă la care să se coboare în foldere, în nivele, unde X
este nivelul maxim.

 Pattern-ul de nume poate fi în urmatoarele formate:
 * a. Nume complet. Ex: find ana.txt
 * b. Nume prefixat de wildcard. Ex: find *.txt (cauta toate fisierele .txt)
 * c. Nume postfixat de wildcard. Ex: find ana.* (cauta toate fisierele ana,
    indiferent de extensie).

##-filesize
- calcularea spațiului ocupat de un fișier.

##Contributors
**Dodoloi Laurentiu** & **Nestian Lucian** [IB7]
