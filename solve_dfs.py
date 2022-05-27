def dfs(graph, a, b):
    count = 1
    st = []
    # masukin vertex yang terkoneksi dengan vertex ke b kedalam stack
    for i in range(0,a): st.append(i) if graph[b][i] == 1 else None
    graph[b][b] = 1
    while len(st):
        node = st.pop()
        if (graph[node][node] != 1): # berarti vertex ke-node belung dikunjungi
            
            # masukin vertex yang terkoneksi dengan vertex ke node kedalam stack
            for i in range(0,a): st.append(i) if graph[node][i] == 1 else None 
            
            count += 1 # increment nilai count setiap ada vertex yang terhubung dari vertex b
            graph[node][node] = 1
    return count

graph = []
a, b = map(int, input().split())
for i in range(a): graph.append(list(map(int, input().split())))
print(dfs(graph, a, b))
