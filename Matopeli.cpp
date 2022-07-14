

#include <iostream>
#include <conio.h> //tarvitaan matopelin ohjaukseen, mahdollistaa konsoli input/output komennot.
#include <windows.h> //tarvitaan sleep()-funktioon, muuten mato liikkuu liian nopeasti
#include<time.h> //tarvitaan ett‰ hedelm‰ tulostaa aina satunnaisesti, ottaa joka kerta eri seedin k‰ytt‰en tietokoneen sis‰ist‰ kelloa. 
using namespace std;
//---------------------------------------------------------

char outputbuf[1300];
char uudestaan = 'y';
bool peliOhi;
bool startscreen = true;
//Pelikent‰n koko
const int korkeus = 20;
const int leveys = 35;
//Peliss‰ k‰ytett‰vi‰ muuttujia
int matoX, matoY, hedelm‰X, hedelm‰Y, pisteet, vastaus; 
int tailX[100], tailY[100];
int nTail;
//Intro
class intro {
public:
    void introTeksti() {
        cout << "###################################\n";
        cout << "# Matopeli Averko c++ kesa 2022   #\n";
        cout << "# Peetu Puikkonen                 #\n";
        cout << "###################################\n";
        cout << "# Matoa ohjataan nappaimilla WASD #\n";
        cout << "# Valitse toiminto                #\n";
        cout << "###################################\n";
        cout << endl;
        cout << "1. Pelaa\n2. Lopeta ";
        cout << endl;
    }
};
//eSuunta-muuttujan avulla seurataan madon suuntaa
enum eSuunta {STOP = 0, VASEN, OIKEA, YLOS, ALAS};
//T‰ll‰ pidet‰‰n valittu suunta lukittuna
eSuunta suunta;


//Peliss‰ k‰ytett‰v‰t funktiot.

void menu()
{
   // cout << "Matopeli 2022\n";
   // cout << "Peetu Puikkonen\n";
  //  cout << "Valitse toiminto\n";
   // cout << endl;
  //  cout << "1. Pelaa\n2. Lopeta ";
  //  cout << endl;
    intro introObject;
    introObject.introTeksti();
    int valinta;
    cin >> valinta;

    switch (valinta)
    {
    case 1:
        startscreen = false;
        break;
    case 2:
        peliOhi = true;
        
    }
}
  


void Asetukset()
{
    
    peliOhi = false;
    suunta = STOP; //pelin alussa suunta on stop, eli mato ei l‰hde liikkeelle kun vasta pelaajan k‰skyst‰
    //Madon aloituskohta keskell‰ kartalla
    matoX = leveys / 2;
    matoY = korkeus / 2;
    
    //Hedelm‰n paikka asettuu satunnaisesti kartalle
    hedelm‰X = rand() % leveys;
    hedelm‰Y = rand() % korkeus;
    pisteet = 0;
    cout.rdbuf()->pubsetbuf(outputbuf, sizeof(outputbuf)); //bufferointi poistaa ylim‰‰r‰isen v‰lkynn‰n mik‰ johtui kent‰n tulostuksen jatkuvasta putsauksesta.
    ios::sync_with_stdio(false);

}
void grafiikanPiirto()
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 }); //"putsaa" pelikent‰n jatkuvalla syklill‰
    //system("cls");
    for (int i = 0; i < leveys + 2; i++)
        cout << "#"; //tulostaa kent‰n yl‰reunan
    cout << "\n";

    for (int i = 0; i < korkeus; i++)
    {
        for (int j = 0; j < leveys; j++)
        {
            if (j == 0)
                cout << "|"; //tulostaa kent‰n vasemman reunan
            if (i == matoY && j == matoX)
                cout << "O";
            else if (i == hedelm‰Y && j == hedelm‰X)
                cout << "@";
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        cout << "o";
                        print = true;
                    }
                   
                }
                if (!print)
                    cout << " ";
           }
            

            if (j == leveys -1)
                cout << "|"; //tulostaa kent‰n oikean reunan
        }
        cout << endl;
    }
    for (int i = 0; i < leveys + 2; i++)
        cout << "#";//tulostaa kent‰n alareunan
    cout << "\n";
    cout << "Pisteet:" << pisteet << endl;

    if (peliOhi != false)
        cout << "HAVISIT PELIN! Sait " << pisteet << " pistetta!\n";
    

    
   
}
void Ohjaus()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            if (suunta != OIKEA) suunta = VASEN;
            break;
        case 'd':
            if(suunta != VASEN) suunta = OIKEA;
            break;
        case 'w':
            if(suunta != ALAS) suunta = YLOS;
            break;
        case 's':
            if(suunta != YLOS) suunta = ALAS;
            break;
        case 'x':
                peliOhi = true;
                break;
                
                
        } 
       
        
    }
}
void Logiikka()
{   //prevXY muuttujia tarvitaan jotta peli muistaa h‰ntien paikan kartalla
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = matoX;
    tailY[0] = matoY;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (suunta)
    {
    case VASEN:
        matoX--;
        break;
    case OIKEA:
        matoX++;
        break;
    case YLOS:
        matoY--;
        break;
    case ALAS:
        matoY++;
        break;
    default:
        break;
    }
    //if (x > leveys || x < 0 || y > korkeus || y < 0)
       //peliOhi = true;

    //

    if (matoX >= leveys) matoX = 0; else if (matoX < 0) matoX = leveys - 1;
    if (matoY >= korkeus) matoY = 0; else if (matoY < 0) matoY = korkeus - 1;
     for ( int i = 0; i < nTail; i++)
         if (tailX[i] == matoX && tailY[i] == matoY)
          peliOhi = true;
            
    if (matoX == hedelm‰X && matoY == hedelm‰Y)
    {

        pisteet += 10;
        hedelm‰X = rand() % leveys;
        hedelm‰Y = rand() % korkeus;
        nTail++;
        //Alla olevalla for if -lauseella estet‰‰n hedelm‰n spawnaus h‰nn‰n sis‰lle // jos hedelm‰n paikka on h‰nn‰n sis‰ll‰, se spawnataan uuteen kohteeseen.
        for (int i = 0; i < nTail; i++)
        {
            if (hedelm‰X == tailX[i] && hedelm‰Y == tailY[i])
            {
                hedelm‰X = rand() % leveys;
                hedelm‰Y = rand() % korkeus;
            }
        }
    }

}
//--------------------------------------------------

int main()
{
    while (uudestaan == 'y')
    {
        
        system("cls");
        srand(time(NULL)); //luo joka pelikerralla uuden seedin k‰ytt‰en tietokoneen sis‰ist‰ kelloa, mahdollistaa t‰ysin satunnaiset hedelmien paikat.
        Asetukset();
        if (startscreen == true)
        {
            menu();
        }

        while (peliOhi == false)
        {

            Ohjaus();
            Logiikka();
            grafiikanPiirto();
            Sleep(70); //sleepin arvo m‰‰r‰‰ pelin nopeuden, mit‰ korkeampi arvo, sit‰ hitaanpi mato.

        }
        //cout << "uudestaan?" << endl;
        break;
        
        
        
    }
      
        
    
    
        cout << "Peli on ohi! Peli sulkeutuu pian." << endl;
        Sleep(5000); //Peli sulkeutuu 5s h‰viˆn j‰lkeen.
        
    
        }

        
        

