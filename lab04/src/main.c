int main () 
{	
    const float PI = 3.14;
    const float R = 4;
    char command = 's';
    float result;
    if (command == 'v'){
    	result = (4 * PI * R * R) / 3; 
    }
    else if (command == 's'){
    	result = PI * R * R;
    }
    else if (command == 'l'){
    	result = 2 * PI * R;
    }
    return 0;
}
