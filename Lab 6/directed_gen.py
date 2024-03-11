import networkx as nx 
import random

def generate_random_dag(num_nodes, num_edges, v): 
    G = nx.gnm_random_graph(num_nodes,num_edges,directed=True) 
    # comment below line to generate cycles
    if(v == 1):
        G = nx.DiGraph([(u, v) for (u, v) in G.edges() if u < v])
    return G 

num_nodes = 50000
num_edges = 120000 
file_path = "test_cases_Q4.txt" 
t = 5
file = open(file_path, 'w')
file.write(f"{t}\n")
while(t > 0):
    t -= 1;
    random_dag = generate_random_dag(num_nodes, num_edges, random.randint(0, 1)) 
    all_edges = list(random_dag.edges())
    permutation = (list(range(num_nodes)))
    random.shuffle(permutation)
    file.write(f"{num_nodes} {len(all_edges)}\n")
    for edge in all_edges:
        file.write(f"{permutation[edge[0]] + 1} {permutation[edge[1]] + 1}\n")

