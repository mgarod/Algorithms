/*************************************************
README.txt for PHP_Quicksort
Author: Michael Garod
Date Created: 6/11/15
Description: A simple program to demonstrate the quicksort algorithm in PHP
Dependencies: none
*************************************************/
I. Bugs Encountered
	- Object oriented programming is strange in PHP. Once inside a method for an object, it seems the method no longer has access to any field or method within the object. The quicksortHelper() needed to be nested within quicksort() in order for quicksort() to have access to it.

II. Run Instructions
	- php quicksort.php

III. I/O Files
	- None