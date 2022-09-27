# Push Swap
### Techincal juice
This implementation uses:
* RadixSort [*`see example`*](#algorithm)
* LinkedLists *`see libft`*
* Doxygen
	*(when using vscode you can see documentation on function hover)*

## Algorithm
[*`see psuedo-code`*](#psuedo-code)
First we initialize each array (or list)
```
A: [16 1 13 19 15 12 21 10 11 7 17 6 3 5 9 18 20 8 2 4 14]
B: [empty]
```
we then get the first bit of each item
then if its on we push it to B
```
eg:
21 is 0010101 in binary
            ^ this is the first bit
			meaning that it gets pushed to B
```
after looking at each item the stacks will look like this
```
A: [16 12 10 6 18 20 8 2 4 14]
B: [9 5 3 17 7 11 21 15 19 13 1]
(every odd number is in B now (number with the first bit on))
```
we then push all those numbers back on top of the A stack
```
A: [1 13 19 15 21 11 7 17 3 5 9 16 12 10 6 18 20 8 2 4 14]
B: [empty]
```
we then look at the next bit and do the same process
```
A: [16 12 20 8 4 1 13 21 17 5 9]
B: [10 6 18 2 14 19 15 11 7 3]
```
```
A: [16 12 20 8 4 1 13 21 17 5 9 10 6 18 2 14 19 15 11 7 3]
B: [empty]
```
the rest of the examples finish the algorithm section off
```
A: [16 8 1 17 9 10 18 2 19 11 3] (bit 3)
B: [12 20 4 13 21 5 6 14 15 7]
```
```
A: [16 8 1 17 9 10 18 2 19 11 3 12 20 4 13 21 5 6 14 15 7]
B: [empty]
```
```
A: [16 1 17 18 2 19 3 20 4 21 5 6 7] (bit 4)
B: [8 9 10 11 12 13 14 15]
```
```
A: [16 1 17 18 2 19 3 20 4 21 5 6 7 8 9 10 11 12 13 14 15]
B: [empty]
```
```
A: [1 2 3 4 5 6 7 8 9 10 11 12 13 14 15] (bit 5)
B: [21 20 19 18 17 16]
```
```
A: [1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21]
B: [empty]
```
### Psuedo-Code
```
A = [...Get Elements...]
B = [empty]

func RadixSort( A and B )

	variable 'radix' used for what position to check

	while radix < highestRadix

		for every item in A
			see if item has 1 at Radix
			yes?:
				push item to B
			no?:
				rotate A

		push items from B to A

		increment radix

	end while

	reverse stack A order

end func
```