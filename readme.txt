CSS 343 Program 4 Winter 2023

1. -Program successfully reads in book, patron, and command data
   -successfully displays information with neat format
   -uses open closed design principle with use of factories rather than switches
   -successfully implements hashtable
   -items able to be stored in bintrees, patrons stored in hashtable
   -commands properly read and executed
   -each object created for is accounted for and properly deleted

2. -Wrote hashtables in HashTable class, ActionFactory, and ItemFactory.
   -hashtable storing patrons found in HashTable class
   -hashtable stored within ActionFactory and ItemFactory classes
   -patron HashTable used to store patrons
   -ActionFactory and ItemFactory used to create action and item objects

3. -To read the books, I have readItems() in Library class. This is called in 
   my main file. The file is read, item factory creates item object with
   createIt(), data set with setData(), and item stored in item container
   using addItem().

4. -To read the patrons, I have readUsers() in Library class. This is called in 
   my main file. The file is read, patron object created and data set with 
   setData(), and item stored in patron HashTable with addItem().
