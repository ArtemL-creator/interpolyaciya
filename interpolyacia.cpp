// interpolyacia.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

using namespace std;

#include <iostream>

bool error = false;


template <typename T>
T inter(T xt, T*arrXt, T *arrYt, size_t n)
{
	T res;
	int i = 0;
	if (xt < arrXt[0]) { error = true; return 0; }
	if (xt > arrXt[n - 1]) { error = true; return 0; }

	while (arrXt[i] <= xt)
	{
		i++;
		if (xt == arrXt[i])
		{
			i++;
			break;
		}
	}
	i--;
	res = arrYt[i] + (((arrYt[i + 1] - arrYt[i]) / (arrXt[i + 1] - arrXt[i])) * (xt - arrXt[i]));
	return res;
}

int main()
{
	float x, res;
	size_t n;
	cout << "Vvedite razmernost: \n";
	cin >> n;
	if (n < 2) { cout << "Razmernost ochen mala."; return 0; }
	float* arrX = new float[n], * arrY = new float[n];

	cout << "Vvedite znachenia\nx y: \n";
	for (size_t i = 0; i < n; i++) { cin >> arrX[i] >> arrY[i]; }

	//////////////////////////////////////////////////////////////////
	//for (size_t i = 0; i < n; i++) { cout << arrX[i] << "\t"; }// << arrY[i] << endl; }
	////////////////////////////////////////////////////////////////////
	//cout << endl;
	//for (size_t i = 0; i < n; i++) { cout << arrY[i] << "\t"; }
	//cout << endl;
	//////////////////////////////////////////////////////////////////
	
	cout << "Vvedite x: \n";
	cin >> x;

	res = inter(x, arrX, arrY, n);
	if (error == true) cout<< "Otsutstvuet na otrezke.";
	else cout << "Rezultat = " << res;
	return 0;
}