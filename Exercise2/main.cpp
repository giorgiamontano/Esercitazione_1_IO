#include <fstream>
#include <iostream>
#include <vector>

double map(double value)
{
	return((value * 0.75)-1.75);
}	


int main()
{
	std::ifstream file_input("./data.txt");
	if (file_input.fail())
	{
		std::cerr <<"Non è stato possibile aprire il file"<< std::endl;
		return 1;
	}
	
	std::vector<double> list_num; //inizializzo un vettore vuoto (che conterrà elementi di tipo double) in cui andrò a inserire i numeri del file di input già mappati
	
	double num; //inizializzo una variabile che chiamo num in cui andrò a memorizzare man mano i vari numeri presenti nel file di input
	
	while (file_input >> num)
	{
		list_num.push_back(map(num)); //mappo i numeri e li inserisco nel mio vettore
	}	
	
	std::ofstream file_output("./result.txt");
	if (file_output.fail())
	{
		std::cerr <<"Non è stato possibile creare il file di output"<< std::endl;
		return 2;
	}

	file_output << "# N Mean\n"; //scrivo la prima riga del file 
	
	int N = list_num.size();
	double sum = 0;
	
	for (int i=0; i<N; i++)
	{
		sum = sum + list_num[i];
		file_output << i+1 << " " << sum/(i+1) << "\n";
	}	
	
	file_input.close();
	file_output.close();
	
    return 0;
}