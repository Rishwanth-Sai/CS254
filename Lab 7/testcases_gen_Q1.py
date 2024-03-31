output_file = "test_cases_Q1.txt"
file=open(output_file, "w")
file.write(str(10)+"\n")
import random

for i in range (10):
    n = random.randint(1,5000)
    max_weight = random.randint(1,5000)
    file.write(str(n)+" "+str(max_weight)+"\n")
    for i in range(n):
        file.write(f"{random.randint(1,10000)} ")
    file.write("\n")
    for i in range(n):
        file.write(f"{random.randint(1,1000000)} ")
file.close()