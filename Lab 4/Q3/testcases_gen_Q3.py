output_file = "test_cases_Q3.txt"
file=open(output_file, "w")
file.write(str(10)+"\n")
import random

for i in range (10):
    n = random.randint(1,1000000)
    k = random.randint(1,n)
    file.write(str(n)+" "+str(k)+"\n")
    for i in range(n):
        file.write(f"{random.randint(-10000000,10000000)} ")
    file.write("\n")
file.close()