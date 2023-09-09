//#include <iostream>
//#include <vector>
//int busquedaIter(std::vector<int>, int);
//int busquedaRecur(std::vector<int>, int);
//
//
//int main() {
//	std::vector<int> aux = { 7,10,12,13,18,20,25,29,31,35 };
//
//
//	std::cout << busquedaIter(aux, 10) << std::endl;
//	return 0;
//}
//
//int busquedaIter(std::vector<int> vec , int buscado)
//{
//	int min = 0;
//	int max = vec.size() - 1;
//	int mitad = max / 2;
//
//	while (min <= max) {
//		if (vec.at(mitad) == buscado) return mitad;
//		else {
//			if (vec.at(mitad) > buscado) {
//				min = mitad;
//				mitad = (min + max) / 2;
//			}
//			else {
//				max = mitad;
//				mitad = (min + max) / 2;
//			}
//		}
//	}
//
//
//
//	return -1;
//}
//
//int busquedaRecur(int vec[], int buscado)
//{
//	return 0;
//}
//




#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#define CANTIDAD	20
#define NUM_MIN		1
#define NUM_MAX		100

int aleatorio();
void imprimir(const std::vector<int>&);
int binaria_iterativa(const std::vector<int>&, int);
int binaria_recursiva(const std::vector<int>&, int);
int binaria_recursiva(const std::vector<int>&, int, std::size_t, std::size_t);

// Generación de números pseudoaleatorios
static std::random_device rd;
static std::mt19937 rng{rd()};

int main()
{
	std::vector<int> vec;

	for (int i = 0; i < CANTIDAD; i++) {
		vec.push_back(aleatorio());
	}

	std::sort(vec.begin(), vec.end());

	imprimir(vec);

	std::cout << binaria_iterativa(vec, 1) << '\n';
	std::cout << binaria_recursiva(vec, 11) << '\n';

	return 0;
}

int aleatorio()
{
	static std::uniform_int_distribution<int> uid(NUM_MIN, NUM_MAX); // random dice
	return uid(rng); // use rng as a generator
}

void imprimir(const std::vector<int>& v)
{
	std::vector<int>::const_iterator iter;
	for (iter = v.cbegin(); iter != v.cend(); iter++) {
		std::cout << *iter << " ";
	}
	std::cout << '\n';
}

int binaria_iterativa(const std::vector<int>& v, int x) // Por que no se encuentra la primera posicion?
{
	std::size_t mitad, min, max;

	min = 0;
	max = v.size() - 1;

	while (min < max) {
		mitad = min + ((max - min) / 2);

		if (v[mitad] == x) {
			return v[mitad];
		}
		else if (v[mitad] > x) {
			max = mitad - 1;
		}
		else {
			min = mitad + 1;
		}
	}
	// No se encontró
	return -1;
}

int binaria_recursiva(const std::vector<int>& v, int x)
{
	return binaria_recursiva(v, x, 0, v.size() - 1);
}

int binaria_recursiva(const std::vector<int>& v, int x, std::size_t min, std::size_t max) // Por que crashea?
{
	// Si el limite inferior es mayor al límite mayor terminamos
	if (min > max) {
		return -1;
	}

	std::size_t mitad = min + ((max - min) / 2);

	if (v[mitad] == x) {
		return v[mitad];
	}
	else if (v[mitad] > x)
	{
		return binaria_recursiva(v, x, min, mitad - 1);
	}

	return binaria_recursiva(v, x, mitad + 1, max);
}


