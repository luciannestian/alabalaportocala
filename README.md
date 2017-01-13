# alabalaportocala

----------------------------------------------System Tool--------------------------------------------------------




Realizat de Dodoloi Laurentiu & Nestian Lucian [I1B7]


Lucru minimal cu fisiere: copierea / gasirea / mutarea / concatenarea fisierelor.



Ruleaza atat pe Linux, cat si pe Windows datorita librariei <dirent.h>.





----------------------------------------------System Tool--------------------------------------------------------

System Tool (2 perosană) (notă maximă: 12 puncte)
Modela
ț
i un utilitar pentru 
lucrul cu fi
ș
iere - similar celor din Linux -  cu (minimal) următoarele
func
ț
ionalită
ț
i:
-
copierea unui fişier 
într-o altă / nouă locaţie sau sub un alt nume – 
​
cp
-
mutarea sau reden
umirea unui fi
ș
ier (dintr-o sursă într-o destinaţie) sub un alt nume
– 
​
mv
-
căutarea în cadru
l fişierelor (la nivel de linie) a unui şir de caractere – 
​
grep
​
 – cu
op
ț
iunile:
1.
-n 
​
- se afişe
ază şi numărul liniei în care apare şirul
2.
-y 
​
- nu se f
ace deosebire între literă mare şi literă mică
3.
-l  
​
-  se afişe
ază doar numele fişierelor ce conţin şirul precizat
-
concatenarea conţ
inutului mai multor fişiere de tip text şi afişarea la consolă a
fişierului rezultat –
​
cat
-
selectarea anumit
or por
ț
iuni dintr-un fi
ș
ier - 
​
cut
-
Cautarea unui fisie
r, după un anumit pattern de nume, intr-un folder - 
​
find
​
, cu
următoarele op
ț
iuni:
1.
-r 
​
- recurs
iv, se va căuta fi
ș
ierul 
ș
i în subfoldere.
2.
-d:X 
​
- adâncimea maximă la care să se coboare în foldere, în nivele, unde X
este nivelu
l maxim.
3.
Pattern-ul d
e nume poate fi în urmatoarele formate:
a.
Nume complet. Ex: find ana.txt
b.
Nume prefixat de wildcard. Ex: find *.txt (cauta toate fisierele .txt)
c.
Nume postfixat de wildcard. Ex: find ana.* (cauta toate fisierele ana,
indiferent de extensie).
-
calcularea spa
ț
iului ocupat de un fi
ș
ier.
Programul trebuie să poat
ă fi compilat atât pe Linux cât 
ș
i pe Windows.
