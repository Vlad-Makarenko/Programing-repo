int main()
{
	char word[] = "Vlad   Makarenko    is  Vlad       Makarenko";
	int sum = 1;
	for (int i = 0; i <= word; i++) {
		if (word[i] == '\0') {
			break;
		}
		if (word[i + 1] == ' ') { 
			continue;
		}else if ( word[i] == ' ') {
	        	sum += 1;
	        } 
	}
    return 0;
}
