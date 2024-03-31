output_file = "test_cases_Q2.txt"
file=open(output_file, "w")
file.write(str(10)+"\n")
import random

for i in range (10):
    n = random.randint(1,100000)
    file.write(str(n)+"\n")
    for i in range(n):
        file.write(f"{random.randint(1,1000000)} {random.randint(1,1000000)}\n")
file.close()