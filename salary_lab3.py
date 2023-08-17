x=str(input("Enter the grade of the user to calculate the gross salary : "))

basicA = 10000
basicB = 4567
basicC = 3000
#asumed the grade C basic because it is not given

t = 1;

if(x=="A"):
	salary = basicA + (0.20*basicA) + (0.50*basicA) + 1700 - (0.11*basicA)
elif(x=="B"):
	salary = basicB + (0.20*basicB) + (0.50*basicB) + 1500 - (0.11*basicB)
elif(x=="C"):
	salary = basicC + (0.20*basicC) + (0.50*basicC) + 1300 - (0.11*basicC)
else:
	print("The input is invalid")
	t=0

if(t):
	print("The gross salary of the user",x,"would be",salary)


