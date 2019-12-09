# Pathfinder

Pathfinder is a prject I made as a part of a [Ucode](https://unit.ua/en/) study programme.

## Description

Pathfinder is a program that finds all shortest paths between all vertices of a graph.
Based on Dijkstra's algorithm, so negative edge weight is not supported. If there are differents shortest paths between two vertices, Pathfinder outputs them all.

Allowed functions:
```malloc, malloc_size, free, open, read, write, close, exit```

Includes the libmx library with various analogues of standard C functions.

**Usage:**
Requires a file as an input. First line of a file must be the number of vertices, remaining lines contain distances between vertices, in the format shown below.

```bash
cat -e example.txt
4$
Greenland-Bananal,8$
Fraser-Greenland,10$
Bananal-Fraser,3$
Java-Fraser,5$

./pathfinder example.txt | cat -e
========================================$
Path: Greenland -> Bananal$
Route: Greenland -> Bananal$
Distance: 8$
========================================$
========================================$
Path: Greenland -> Fraser$
Route: Greenland -> Fraser$
Distance: 10$
========================================$
========================================$
Path: Greenland -> Java$
Route: Greenland -> Fraser -> Java$
Distance: 10 + 5 = 15$
========================================$
========================================$
Path: Bananal -> Fraser$
Route: Bananal -> Fraser$
Distance: 3$
========================================$
========================================$
Path: Bananal -> Java$
Route: Bananal -> Fraser -> Java$
Distance: 3 + 5 = 8$
========================================$
========================================$
Path: Fraser -> Java$
Route: Fraser -> Java$
Distance: 5$
========================================$

./pathfinder
usage: ./pathfinder [filename]

cat -e islands
cat: islands: No such file or directory
./pathfinder islands | cat -e
error: file islands does not exist

cat -e empty
./pathfinder empty | cat -e
error: file empty is empty

cat -e invalid1
4f$
Greenland-Bananal,8$
Fraser-Greenland,10$
Bananal-Fraser,3$
Java-Fraser,5$
./pathfinder invalid1 | cat -e
error: line 1 is not valid

cat -e invalid2
4$
Greenland-Bananal,8$
Fraser--Greenland,10$  # invalid line 3
Bananal-Fraser,$  # invalid line 4
Java-Java,5$  # invalid line 5
./pathfinder invalid2 | cat -e
error: line 3 is not valid

cat -e invalid3
3$
Greenland-Bananal,8$
Fraser-Greenland,10$
Bananal-Fraser,3$
Java-Fraser,5$
./pathfinder invalid3 | cat -e
error: invalid number of islands
```

**Installation:** Clone and  ```make```. Written and tested on MacOS Mojave.

