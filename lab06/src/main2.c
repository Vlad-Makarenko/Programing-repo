#define SIZE 55

int main()
{
    	int Prime_numbers[SIZE];
    	int first_number = 2;
        for ( int i = 0 ; i < SIZE; i++ ){
            	for ( int j = first_number; j < 99999; j++){
                	int prime = 1;  // Число простое
                	for ( int num = 2; num <= j/2; num++){
                    		if ( j % num == 0){
                            		prime = 0; // Число составное
                            		break; 
                    		} 
                	}                         
                	if ( prime == 1){
                   		Prime_numbers[i] = j;
                    		first_number = j + 1;
                    		break;
                	}  
            	}
        }   
     	return 0;
}
