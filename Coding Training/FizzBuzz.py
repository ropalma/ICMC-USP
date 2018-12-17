count = 100
number = 1
while count:
	if number % 5 == 0 and number % 3 == 0:
		print(' FizzBuzz', end='')
	elif number % 5 == 0:
		print(' Buzz', end='')
	elif number % 3 == 0:
		print(' Fizz', end='')
	else:
		print(" {}".format(number), end='')
	# print(" ")
	number+=1
	count -= 1