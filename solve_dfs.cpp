#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int n, s, counter = 1;
	cin >> n >> s;
	s--;
	int matrix[n][n];
	stack<int> st;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) cin >> matrix[i][j];
	}
    // masukin vertex yang terkoneksi dengan vertex s kedalam stack
	for (int j = 0; j < n; j++) if (matrix[s][j] == 1) st.push(j);
	matrix[s][s] = 1;
	while (!st.empty())
	{
		int a = st.top();
        st.pop();
		if (matrix[a][a] != 1) // berarti vertex ke-node belung dikunjungi
		{
            // masukin vertex yang terkoneksi dengan vertex ke node kedalam stack
			for (int j = 0; j < n; j++) if (matrix[a][j] == 1) st.push(j);
			counter++;
			matrix[a][a] = 1;
		}
	}
	cout << counter << endl;
	return 0;
}
