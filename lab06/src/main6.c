#define SIZE 3

int main()
{
    	int matrix[SIZE][SIZE] = {{1, 2, 3},
                            	  {4, 5, 6},
                            	  {7, 8, 8,}};
    	int result_matrix[SIZE][SIZE] = {0};
    	for (int i = 0; i < SIZE; i++){
        	for (int j = 0; j < SIZE; j++){
           		for (int l = 0; l < SIZE; l++) {
                		result_matrix[i][j] += matrix[i][l] * matrix[l][j];
            		}
        	}
    	}
    	return 0;
}
