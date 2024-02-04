output_file = "test_cases_Q2.txt"
file=open(output_file, "w")
file.write(str(5)+"\n")
import random

for i in range (5):
    n = random.randint(0,200000)
    m = random.randint(0,200000)
    file.write(str(n)+" " +str(m)+"\n")
    a = []
    b = []
    for i in range(n):
        a.append(random.randint(-10000000,10000000))
    for i in range(m):
        b.append(random.randint(-10000000,10000000))
    a.sort()
    b.sort()
    for i in range(n):
        file.write(f"{a[i]} ")
    file.write("\n")
    for i in range(m):
        file.write(f"{b[i]} ")
    file.write("\n")
file.close()