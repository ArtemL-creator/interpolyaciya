
using namespace std;

#include <iostream>


int fact(int n) 
{
	if (n != 0)
		return (n * fact(n - 1));
	else
		return 1;
}


template<typename T>
T DeltaY(T* arr, int n, int deg, int i)
{
	int it = i, p = deg;
	T *arrTMP = new T[n];
	int count = 1;
	for (int j = 0; j < n; j++) {
		arrTMP[j] = arr[j];
	}
	do {
		for (int j = 0; j < n - 1; j++) {
			arrTMP[j] = arrTMP[j + 1] - arrTMP[j];
		}
		if (count == deg) {
			return arrTMP[it];
		}
		count++;
		p--; n--;
	} while (p > 0);
}

template <typename T>
int getX0(T* arr, int n, int x)
{
	int ind;
	for (auto i = 0; i < n; i++)
	{
		if (arr[i] > x) ind = (i - 1);
	}
	return ind;
}

template <typename T>
T Q(T x, T *arr, int ind, T h)
{
	return ((x - arr[ind]) / h);
}

template <typename T>
int GaussMult1(T q, int n)
{
	if (n = 0)
		return ((q - n + 1) * (q + n - 1)*(GaussMult1(q,n-1)));
	else return ((q+1)*(q-1));
}

template <typename T>
int GaussMult2(T q, int n)
{
	if (n = 0)
		return ((q - n + 1) * (q + n - 1)*(q-n) * (GaussMult2(q, n - 1)));
	else return ((q+1)*(q - 1)*q);
}

template <typename T>
T summ(T* arrY, int n, int yt, T q)
{
	
}

template <typename T>
T inter(T* arrX, T* arrY, int n, T h, T x)
{
	T p;
	int ind0 = getX0(arrX, n, x);
	T q = Q(x, arrX, ind0, h);

	p = arrY[ind0] + (q * DeltaY(arrY, 1, ind0 - 1)) + ((q * ((q - 1) / 2)) * DeltaY(arrY, 2, ind0 - 2));
	ind0 = ind0 - 2;
	int yt = 2;
	for(int ix = 3; ind0 >= 0; ix++)
	{
		ind0 = ind0 - ix;
		yt = yt + 1;
		p = p + summ(arrY, ind0, yt, q);
	}
}

int main()
{
	float x, res;
	size_t n;
	cout << "Vvedite razmernost: ";
	cin >> n;
	if (n < 2) { cout << "Razmernost ochen mala."; return 0; }
	float* arrX = new float[n], * arrY = new float[n];
	float h;
	cout << "Vvedite shag: ";
	cin >> h;

	cout << "Vvedite znachenie\nx = ";
	cin >> arrX[0];
	for (size_t i = 0; i < n; i++) {
		arrY[i] = 1 / arrX[i];
		cout << "y = " << arrY[i] << endl << endl;
		arrX[i + 1] = arrX[i] + h;
		if (i != n-1) cout << "x = " << arrX[i+1] << endl;
	}
	cout << endl;


	cout << "Vvedite x: \n";
	cin >> x;

	//res = inter(x, arrX, arrY, n, h);

	return 0;
}