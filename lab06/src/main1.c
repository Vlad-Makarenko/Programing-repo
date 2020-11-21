int main()
{
    	int N = 15;
	char filler = '_';
    	char line[] = "Ivanov        ";
    	int sum = 0;
    	for (int i = 0; line[i] != ' '; i++) {
        	sum += 1;
    	}
    	char copy[N];
    	for (int i = 0; i < N; i++) {
        	copy[i] = line[i];
    	}
    	int X = (N - sum - 1) / 2;
    	for (int j = 0; j < X; j++) {
        	line[j] = filler;
    	}
    	int j = 0;
    	for (int k = X; k <= X + sum; k++){
        	line[k] = copy[j];
        	j += 1;
    	}
    	int Y = sum + X;
    	for (int n = Y; n < N - 1; n++) {
        	line[n] = filler; 
    	}
    	return 0;
}
