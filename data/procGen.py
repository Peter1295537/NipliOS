import random

num=input("Enter number of processes: ")
int(num)
for x in range (0,num):
	process=open("process%d"%(x), "w")
	process.write("%d\n"%(random.randint(100,1000)))
	for y in range (0, random.randint(10, 25)):
		dice=random.randint(0,6)
		if dice<2:
			process.write("CALCULATE %d\n"%(random.randint(100,400)))
		if dice==2:
			process.write("IO\n")
		if dice==3:
			process.write("YIELD\n")
		if dice==4:
			process.write("**CRITSTART**\n")
			for z in range (1,random.randint(1,4)):
				if z<3:
					process.write("CALCULATE %d\n"%(random.randint(100,400)))
				if z==4:
					process.write("IO \n")
			process.write("**CRITEND**\n")
		if dice==5:
			process.write("OUT\n")
		if dice==6:
			process.write("CALCULATE %d\n"%(random.randint(100,400)))
