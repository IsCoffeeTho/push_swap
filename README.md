# Push Swap
### Techincal juice
This implementation uses:
* BubbleSort (for indexing)
* RadixSort [*`see example`*](#algorithm)
* LinkedLists *`see libft bonus`*
* Doxygen
	*(when using vscode you can see documentation on function hover)*

## Algorithm
[*`see psuedo-code`*](#psuedo-code)
Assuming that the list isn't already sorted
First we initialize each array (or list)
```
A: [-7 5 -1 8 3 4 -5 -6 1 -2 -4 0 -8 7 6 2 -3]
B: [empty]
```
We then normalize the array to a list of in what order they should appear
```
A: [1 13 7 16 11 12 3 2 9 6 4 8 0 15 14 10 5]
B: [empty]
```
we will do some checks to see what we need to do to the stack  
we need to find out the highest positive number
```
A: [1 13 7 16 11 12 3 2 9 6 4 8 0 15 14 10 5]

max: 16
```
We then consider the highest bit of that number to be the biggest radix
```
16 is 00010000 in binary
         ^^^^^
	     5 bits including the highest
highestRadix = 5
```
we then get the first bit of each item of A
then if its a 1 we push it to B
```
A: [16 12 2 6 4 8 0 14 10]
B: [5 15 9 3 11 7 13 1]
(every odd number is in B now (number with the first bit on))
```
*Notice that Stack B is in reverse order*

We then push all those numbers back on top of the A stack  
*Also Notice that they got pushed in reverse order again*
```
A: [1 13 7 11 3 9 15 5 16 12 2 6 4 8 0 14 10]
B: [empty]
```
we then look at the next bit and do the same process
```
A: [1 13 9 5 16 12 4 8 0]
B: [10 14 6 2 15 3 11 7]
```
```
A: [7 11 3 15 2 6 14 10 1 13 9 5 16 12 4 8 0]
B: [empty]
```
*Always be aware of the push being reversed*  
The then increase the radix bit and do it again:  
	the next examples will be done automatically
```
A: [11 3 2 10 1 9 16 8 0] (bit 3)
B: [4 12 5 13 14 6 15 7]
```
```
A: [7 15 6 14 13 5 12 4 11 3 2 10 1 9 16 8 0]
B: [empty]
```
```
A: [7 6 5 4 3 2 1 16 0] (bit 4)
B: [8 9 10 11 12 13 14 15]
```
```
A: [15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 16 0]
B: [empty]
```
```
A: [15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0] (bit 5 (the highestRadix))
B: [16]
```
```
A: [16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0]
B: [empty]
```
We then reverse the stack to get it in ascending order
```
A: [0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16]
B: [empty]
```
### Psuedo-Code
```
A = [...Get Elements...]
B = [empty]

func RadixSort( A and B )

	normalize 

	variable 'radix' used for what position to check

	loop through items to search for highest number from 0
	
	get the highest bit that is on in the highest number
		make that the highestRadix

	while Radix < highestRadix
		for every item in A
			see if item has 1 at Radix
			yes?:
				pb()
			no?:
				ra()
		for each item in B
			pa()
		increment radix
	end while

	reverse stack A order
end func
```