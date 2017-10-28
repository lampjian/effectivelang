Tile file format:
<number of transactions in data> <number of attributes in data>
<number of 1s in tile 1>
<number of transactions in tile 1> <transaction id 1> <transaction id 2>
<number of items in tile 1> <item id 1> <item id 2>
<number of 1s in tile 2>
<number of transactions in tile 2> <transaction id 1> <transaction id 2>
<number of items in tile 2> <item id 1> <item id 2>
.
.
.


Computing distances:

./tiva <tile file 1> <tile file 2> -b <background file 1> -b <background file 2> ...

Redescription:

./tire <target file> <source file> -b <background file 1> -b <background file 2>
