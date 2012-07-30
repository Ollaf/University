#include "..\include\Fight.h"


Fight::Fight(int n){// n- число армий

    vector<string> name;
    ifstream InF("ArmyName.txt");
    string s;

	while(!InF.eof()){
        InF >> s;
        name.push_back(s);
    }
    InF.close();
    srand(time(NULL));

    for(int i=0; i<n; i++){
        F.push_back( Army(name[i],				//Название армии
					(rand()%39)+1,				//Число солдат в армии
					(rand()%n)+1));				//Сторона армии
    }
    SetAgr();
    system("pause");
    name.clear();
}

Fight::~Fight(){
    F.clear();
}

void Fight::SetAgr(){
    for(int i=0; i<F.size(); i++){
    	Agr[i]=new int [F.size()];
        for(int j=0; j<F.size(); j++){
        	if(F[i].GetSide()==F[j].GetSide())	Agr[i][j]=0;
        	else								Agr[i][j]=(rand()%F.size());
			cout << Agr[i][j] << " ";
		}	cout << endl;
    }
}

int Fight::GetAgr(int idx, int &pos){
	int max = Agr[idx][0];
    for(int j=1; j<F.size(); j++){
		if(Agr[idx][j]>max) {max=Agr[idx][j]; pos=j;}
	}
	return max;
}

void Fight::AddArmy(Army &A){
    F.push_back(A);
}

bool f(Soldier S){ return S.GetHp()<1; }

void Fight::ChAgr(){
	for(int i=0; i<F.size(); i++){
		if(F[i].GetArmy().size()==0){
			for(int j=0; j<F.size(); j++){
				Agr[i][j]=0;
				Agr[j][i]=0;
			}
		}
	}
}

void Fight::Atack(int pos, int &pw){
	list<Soldier>::iterator AIter;
	list<Soldier>& Ar=F[pos].GetArmy();
	do{
		for(AIter=Ar.begin();AIter!=Ar.end();AIter++){
			int dmg = rand()%(Ar.size()+1);
			if(AIter->GetHp()>0){
				AIter->GetHp()-=dmg;
				pw-=dmg;
			}
			if(pw<1) {pw=0; break;}
		}
		Ar.remove_if(f);
		if(F[pos].GetArmy().size()==0) pw=0;
	}while(pw>0);
}

bool Fight::Battle(){
	int tmp=0;
	for(int i=0; i<F.size(); i++){
		for(int j=0; j<F.size(); j++) tmp+=Agr[i][j];
    }
    return tmp>0;
}

void Fight::Print(int i_1, int size_1, int i_2, int size_2){
	vector<string> color;
	ifstream InF("color.txt");
	for(int i=0;i<7;i++){
		string c;
		InF >> c;
		color.push_back(c);
	}
	InF.close();
	ofstream OutF;
	OutF.open("Result.html",ios_base::app);
	OutF << "<FONT COLOR=" << color[F[i_1].GetSide()] << ">";
	OutF << F[i_1].GetName() << "(" << size_1 << ")";
	OutF << " --> ";
	OutF << F[i_1].GetName() << "(" << F[i_1].GetArmy().size() << ")";
	OutF << "</FONT>";
	OutF << " \t атакует \t";
	OutF << "<FONT COLOR=" << color[F[i_2].GetSide()] << ">";
	OutF << F[i_2].GetName() << "(" << size_2 << ")";
	OutF << " --> ";
	OutF << F[i_2].GetName() << "(" << F[i_2].GetArmy().size() << ")";
	OutF << "</FONT>";
	OutF << "<br>" << endl;
	OutF.close();
	color.clear();
	Sleep(999);
}

int Fight::Start(){

    int PW=0;
	ofstream OutHtm("Result.html");

	OutHtm << "<html>" << endl;
	OutHtm << "\t <head>" << endl;
	OutHtm << "\t <META CONTENT='1;URL=Result.html'HTTP-EQUIV=Refresh>" << endl;
	OutHtm << "\t </head>" << endl;
	OutHtm << "<body>" << endl;

	OutHtm.close();
	system("start Result.html");
	delete OutHtm;

	OutHtm.open("Result.html", ios_base::app);
	int raund=1;

do{
// 1 - раунд
	OutHtm << "Раунд " << raund << "<br>" << endl;
    for(int i=0; i<F.size(); i++){     // Берем каждую армию из массива армий
    	int k=0;
    	if(GetAgr(i,k)){
    		Agr[i][k]-=1;
    		int Asize1=F[i].GetArmy().size();
    		int Asize2=F[k].GetArmy().size();

			PW=F[i].ArmyPw();
			Atack(k,PW);

			PW=F[k].ArmyPw();
			Atack(i,PW);

			ChAgr();

			Print(i, Asize1, k, Asize2);
		}
    }
    raund++;
}while(Battle());
	OutHtm.close();
	//OutF.close();
    return 0;
}
