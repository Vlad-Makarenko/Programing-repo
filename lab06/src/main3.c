int main()
{
    	int number = 2212;
    	char result[4][15];
    	for (int i = 0; i < 15; i++) {
		result[i][i] = ' ';
	}
        
    	char thousands[9][20] = {" one thousand ", " two thousands ", " three thousands ", " four thousands ", " five thousands", " six thousands ", " seven thousands ", " eight thousands ", " nine thousands "};
    	char hundreds[9][20] = {" one hundred ", " two hundreds ", " three hundreds ", " four hundreds ", " five hundreds ", " six hundreds ", " seven hundreds ", " eight hundreds ", " nine hundreds "};
    	char cardinal[9][20] = {" ten ", " eleven ", " twelve ", " thirteen ", " fourteen ", " fifteen ", " sixteen ", " seventeen ", " eighteen ", " nineteen "}; 
    	char dozens[9][15] = {" twenty ", " thirty ", " fourty ", " fifty ", " sixty ", " seventy ", " eighty ", " ninety "};
    	char units[9][15] = {" one ", " two ", " three ", " four ", " five ", " six ", " seven ", " eight ", " nine "};

    	for (int i = 0; i < 15; i++) {
        	result[0][i] = thousands[number / 1000 - 1][i];
        	result[1][i] = hundreds[number % 1000 / 100 - 1][i];
        	if (number % 100 >= 10 && number % 100 < 20) {
            		result[2][i] = cardinal[number % 100 - 10][i];
        	}else{
            		result[2][i] = dozens[number % 100 / 10 - 2 ][i];
            		result[3][i] = units[number % 10 - 1][i];
        	}
    	}
    	return 0;
}
