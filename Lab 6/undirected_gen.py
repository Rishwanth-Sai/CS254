import networkx as nx 

def generate_random_graph(num_nodes, num_edges): 
    G = nx.gnm_random_graph(num_nodes,num_edges) 
    return G 

num_nodes = 50000
num_edges = 120000
file_path = "test_cases_Q5.txt" 
t = 5
file = open(file_path, 'w')
file.write(f"{t}\n")
while(t > 0):
    t-= 1
    random_dag = generate_random_graph(num_nodes, num_edges) 
    all_edges = list(random_dag.edges())
    file.write(f"{num_nodes} {len(all_edges)}\n")
    for edge in all_edges:
        file.write(f"{edge[0] + 1} {edge[1] + 1}\n")

