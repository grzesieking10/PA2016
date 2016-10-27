//Przykładowa implementacja funkcji parsującej liczbę całkowitą z tekstu.
//Po konwersji wskaźnik znakowy jest przesunięty za liczbę.
//Zwracane jest 0 = OK, inna wartość gdy błąd.


int getint(char * &s, int &n)  
{
	int sign = 1; //domyślnie liczba dodatnia (gdy nie ma + ani - z przodu)
	if(*s==‘+’) s++; //+ nic nie zmienia, pomijamy
  else
	if(*s==‘-’) { sign = -1; s++; } //zmiana znaku liczby na ujemny
  
  if(!is_digit(*s)) return -666; //to w ogóle nie jest liczba!
	n = 0; //nasza liczba - najpierw zerujemy
	while(is_digit(*s))
  {
		n = n*10 + (*s++) - ’0’;
  }
	n *= sign;
	return 0; //OK - brak błędów konwersji
}
 
