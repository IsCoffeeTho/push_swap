# Push Swap
### Techincal juice
This implementation uses:
* BubbleSort (for small sets)
* RadixSort [*`see example`*](#algorithm)
* LinkedLists *`see libft`*
* Doxygen
	*(when using vscode you can see documentation on function hover)*

## Algorithm
[*`see psuedo-code`*](#psuedo-code)
First we initialize each array (or list)
```
A: [-7 5 -1 8 3 4 -5 -6 1 -2 -4 0 -8 7 6 2 -3]
B: [empty]
```
we will do some checks to see what we need to do to the stack  
we need to find out:
* the lowest negative number if any (0 default)
* the highest positive number if any (0 default)
```
A: [-7 5 -1 8 3 4 -5 -6 1 -2 -4 0 -8 7 6 2 -3]

 low: -8
high: 8
```
we then make the maximum the bigger one of the two considering both are positive  
*Notice we need to invert the negative lowest for this step*
```
max: 8
```
we then consider the highest bit of that number to be the biggest radix
```
8 is 00001000 in binary
         ^^^^
	     4 bits including the highest

highestRadix = 4
```
we then get the first bit of each item of A
then if its a 1 we push it to B
```
A: [8 4 -6 -2 -4 0 -8 6 2]
B: [-3 7 1 -5 3 -1 5 -7]
(every odd number is in B now (number with the first bit on))
```
*Notice that Stack B is in reverse order*

We then push all those numbers back on top of the A stack  
*Also Notice that they got pushed in reverse order again*
```
A: [-7 5 -1 3 -5 1 7 -3 8 4 -6 -2 -4 0 -8 6 2]
B: [empty]
```
we then look at the next bit and do the same process
```
A: [-7 5 1 -3 8 4 -4 0 -8]
B: [2 6 -2 -6 7 -5 3 -1]
```
```
A: [-1 3 -5 7 -6 -2 6 2 -7 5 1 -3 8 4 -4 0 -8]
B: [empty]
```
*Always be aware of the push being reversed*  
The then increase the radix bit and do it again:  
	the next examples will be done automatically
```
A: [3 -5 -6 2 -7 1 8 0 -8] (bit 3)
B: [-4 4 -3 5 6 -2 7 -1]
```
```
A: [-1 7 -2 6 5 -3 4 -4 3 -5 -6 2 -7 1 8 0 -8]
B: [empty]
```
```
A: [7 6 5 4 3 2 1 0] (bit 4 (our highestRadix))
B: [-8 8 -7 -6 -5 -4 -3 -2 -1]
```
```
A: [-1 -2 -3 -4 -5 -6 -7 8 -8 7 6 5 4 3 2 1 0]
B: [empty]
```
*The next steps will only run if there are negative numbers*  
*If your stack begins with only positive numbers you are complete here*  
Now we get to a point that all the negative numbers are in the position of the stack  
so we need to extract them and a good way to do that is to understand that

negative numbers are the positive number with all the bits inverted and +1
```
example:
given an 8 bit word (consider bit 8 to mean the sign)

+3 is 00000011
to take the negative
we invert
      11111100
then add 1
-3 is 11111101

This is called the Two's Compliment (2s Comp)
```
we extend the above example to 32 bits (`sizeof(int) * 8`)
```
a simple constant to check for the last bit:
0x80000000
meaning:
1000 0000 ... 0000
for 32 bits
```
We push all the negative numbers from A into B  
but for each item that gets pushed we rotate B  
to cancel that reversing push symptom
```
A: [8 7 6 5 4 3 2 1 0]
B: [-1 -2 -3 -4 -5 -6 -7 -8]
```
We then push the items in B back into A but rotating A each time  
so we end up with the negative number at the end of the stack in order
```
A: [8 7 6 5 4 3 2 1 0 -1 -2 -3 -4 -5 -6 -7 -8]
B: [empty]
```
Because the subject requires us to have the stack in  
ascending order, we then reverse stack A to get the final stacks
```
A: [-8 -7 -6 -5 -4 -3 -2 -1 0 1 2 3 4 5 6 7 8]
B: [empty]
```
### Psuedo-Code
```
A = [...Get Elements...]
B = [empty]

func RadixSort( A and B )

	variable 'radix' used for what position to check

	loop through items to search for highest and lowest number from 0

	if the lowest number is further away from 0 than the higher is
		make the maximum the negative of the lowest number
	else
		make the maximum the highest number
	
	get the highest bit that is on in the highest number

	make that the highestRadix

	while Radix < highestRadix
		for every item in A
			see if item has 1 at Radix
			yes?:
				push item to B
			no?:
				rotate A
		push items from B to A
		increment radix
	end while

	if there is a negative number
		while Radix < highestRadix
			for every item in A
				see if item is negative
				yes?:
					push item to B
					rotate B
				no?:
					rotate A
			push items from B and rotate A each time
		end while

	reverse stack A order

	finished!

end func
```