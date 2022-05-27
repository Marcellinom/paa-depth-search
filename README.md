# paa-depth-search-problem
link: https://www.eolymp.com/en/problems/4000

## case:
![image](https://user-images.githubusercontent.com/74979139/170638511-e135b2c9-ad47-46a6-a444-4eb62c36fb0e.png)

## visualisasi graph:
![image](https://user-images.githubusercontent.com/74979139/170638574-cff9b0b0-5e7e-46dd-9cd3-4e87479b2e99.png)

## expected output:
![image](https://user-images.githubusercontent.com/74979139/170638612-3867e2c7-cde2-4e4e-8b53-18fee4e285c9.png)

## workflow:
1. input graph kedalam adjency list
```py
    graph = []
    a, b = map(int, input().split())
    for i in range(a): graph.append(list(map(int, input().split())))
    print(dfs(graph, a, b))
```

2. mulai dari vertex b masukin child nya:
```py
    st = []
    # masukin vertex yang terkoneksi dengan vertex ke b kedalam stack
    for i in range(0,a): st.append(i) if graph[b][i] == 1 else None
    graph[b][b] = 1
```
![image](https://user-images.githubusercontent.com/74979139/170640203-588dc0ce-e39f-417e-bb8f-0640c02c5c99.png)

3. nge loop per isi stack buat cari anak-anak dari anak nya sampai semua vertex yang connected sudah dikunjungi:
```py
    while len(st):
        node = st.pop()
```

4. bila vertex dari stack tersebut belum dikunjungi:
```py
        if (graph[node][node] != 1): # berarti vertex ke-node belung dikunjungi
            
            # masukin vertex yang terkoneksi dengan vertex ke node kedalam stack
            for i in range(0,a): st.append(i) if graph[node][i] == 1 else None 
            
            count += 1 # increment nilai count setiap ada vertex yang terhubung dari vertex b
            graph[node][node] = 1
```
![image](https://user-images.githubusercontent.com/74979139/170640368-4c0a76c4-cafd-4f8d-bec7-5ad39a2e1d98.png)

vertex 1 tidak dimasukan kedalam stack karena sudah pernah dikunjungi

5. lanjut examine isi stack:

![image](https://user-images.githubusercontent.com/74979139/170640608-a5fbeb8f-82c3-4fb1-8742-83f724fc6867.png)


## output:
![image](https://user-images.githubusercontent.com/74979139/170640753-43763a03-d81f-4eba-bb40-1c63f935ad64.png)
