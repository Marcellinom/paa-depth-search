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
```cpp
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) cin >> matrix[i][j];
	}
```

2. mulai dari vertex s masukin child nya:
```py
    // masukin vertex yang terkoneksi dengan vertex s kedalam stack
	for (int j = 0; j < n; j++) if (matrix[s][j] == 1) st.push(j);
	matrix[s][s] = 1;
```
![image](https://user-images.githubusercontent.com/74979139/170640203-588dc0ce-e39f-417e-bb8f-0640c02c5c99.png)

3. nge loop per isi stack buat cari anak-anak dari anak nya sampai semua vertex yang connected sudah dikunjungi:
```py
	while (!st.empty())
	{
		int a = st.top();
        st.pop();
```

4. bila vertex dari stack tersebut belum dikunjungi:
```py
		if (matrix[a][a] != 1) // berarti vertex ke-a belung dikunjungi
		{
            // masukin vertex yang terkoneksi dengan vertex ke node kedalam stack
			for (int j = 0; j < n; j++) if (matrix[a][j] == 1) st.push(j);
			counter++;
			matrix[a][a] = 1;
		}
```
![image](https://user-images.githubusercontent.com/74979139/170640368-4c0a76c4-cafd-4f8d-bec7-5ad39a2e1d98.png)

vertex 1 tidak dimasukan kedalam stack karena sudah pernah dikunjungi

5. lanjut examine isi stack:

![image](https://user-images.githubusercontent.com/74979139/170640608-a5fbeb8f-82c3-4fb1-8742-83f724fc6867.png)


## output:
![image](https://user-images.githubusercontent.com/74979139/170643357-ec7416b0-a58f-4964-a75a-f7e9cccc590a.png)

## OnlineJudge
![image](https://user-images.githubusercontent.com/74979139/170643417-d6afcadd-f6af-4023-aa8d-ac2d316ef720.png)
