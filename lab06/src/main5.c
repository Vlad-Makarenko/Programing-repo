#define N 4

int main()
{
    	int array[N][N] = {{1, 2, 3, 4},
                   	   {5, 6, 7, 8},
                   	   {9, 10, 11, 12},
                   	   {13, 14, 15, 16}};
    	int reserve = array[0][0];
    	for (int i = 0; i < N * N; i++) {
        	array[0][i] = array[0][i + 1];
    	}
    	array[N - 1][N - 1] = reserve;
    	return 0;
}
