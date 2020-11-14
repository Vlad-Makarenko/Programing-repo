int main ()
{
    int num = 3;
    float Square_root = 0.0001;
    while (Square_root * Square_root <= num) {
        Square_root += 0.0001;
    }
    
  return 0;
}
