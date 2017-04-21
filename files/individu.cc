#include "individu.hh"

/* Constants */
const char *ERI1 = "error";
const char *ERI2 = "no tiene padre";
const char *ERI3 = "no tiene madre";


individu::individu(){
	amb_mare = amb_pare = false;
	sex1 = 'X';
}

individu::individu(especie esp){
	amb_mare = amb_pare = false;
	sex1 = 'X';
	EspInd = esp;
}

individu::~individu(){}

string individu::consultar_NOM() const
{
	return NOM;
}

string individu::consultar_SEXE() const
{
	return SEXE;
}

bool individu::te_pare() const
{
	return amb_pare;
}

individu individu::consultar_PARE() const
{
	if (not amb_pare) throw Excepcio(ERI2);
	return *PARE;
}

bool individu::te_mare() const
{
	return amb_mare;
}

individu individu::consultar_MARE() const
{
	if (not amb_mare) throw Excepcio(ERI3);
	return *MARE;
}



void individu::afegir_especie(const especie& esp)
{
	EspInd = esp;
}

void individu::llegir()
{

	COD_GEN = vector<pair<vector<int>, vector<int>>> (EspInd.consultar_numero_parells()+1);

	int d = EspInd.consultar_longitud_x();

	cin >> NOM;
	cin >> sex2;

	if (sex2=='X') SEXE = "femeni";

	else if (sex2=='Y')
	{
		SEXE = "masculi";
		d = EspInd.consultar_longitud_y();
	}

	// nom i sexe
	int x;
	for (int i = 0; i < EspInd.consultar_longitud_x(); ++i)
	{
		cin >> x;
		COD_GEN[0].first.push_back(x);

	}
	for (int i = 0; i < d; ++i)
	{
		cin >> x;
		COD_GEN[0].second.push_back(x);

	}

	for (int i = 1; i <= EspInd.consultar_numero_parells(); ++i) // accedim a cada pair
	{
		for (int j = 0; j < EspInd.consultar_longitud_i(i); ++j)
		{
			cin >> x;
			COD_GEN[i].first.push_back(x);
		}
		for (int j = 0; j < EspInd.consultar_longitud_i(i); ++j)
		{
			cin >> x;
			COD_GEN[i].second.push_back(x);
		}
	}


}


void individu::escriure() const
{
	cout << NOM << ' ' << sex1 << sex2 << " (";
	if (not te_pare()) cout << "$";
	else cout << PARE->consultar_NOM();
	cout << ',';
	if (not te_mare()) cout << "$";
	else cout << MARE->consultar_NOM();
	cout << ')';
	cout << endl;
}

void individu::escriure_particular() const
{
	int d = EspInd.consultar_longitud_y();
	if (sex2=='X') d = EspInd.consultar_longitud_x();
	cout << "escribir_genotipo " << NOM << endl;

	// nom
	cout << sex1 << ": ";
	for (int i = 0; i < EspInd.consultar_longitud_x(); ++i) cout << COD_GEN[0].first[i] << ' ';
	cout << endl;
	cout << sex2 << ": ";
	for (int i = 0; i < d; ++i) cout << COD_GEN[0].second[i] << ' ';
	cout << endl;
	for (int i = 1; i < COD_GEN.size(); ++i) // accedim a cada pair
	{
		cout << i << ".1: ";
		for (int j = 0; j < EspInd.consultar_longitud_i(i); ++j) cout << COD_GEN[i].first[j] << ' ';
		cout << endl;
		cout << i << ".2: ";
		for (int j = 0; j < EspInd.consultar_longitud_i(i); ++j) cout << COD_GEN[i].second[j] << ' ';
		cout << endl;
	}
}



















