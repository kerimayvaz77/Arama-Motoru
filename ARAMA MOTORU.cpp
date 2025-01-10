#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include <algorithm>
#include <locale>

#ifdef _WIN32
    #include <windows.h>
#endif

using namespace std;
#define d 256

// İşletim sistemine göre dosya açma
void dosyaAc() {
    #ifdef _WIN32
        system("SONUC.txt");
    #else
        system("open SONUC.txt");
    #endif
}

// Konsol rengini ayarlama (sadece Windows'ta çalışır)
void konsolRengiAyarla() {
    #ifdef _WIN32
        system("color F4");
    #endif
}

// Boşlukları temizleyen yardımcı fonksiyon
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, (last - first + 1));
}

void baslama() {
    ofstream dosya_guncelle32("SONUC.txt");
    dosya_guncelle32 << "(---- BUNU'MU DEMEK ISTEDNIZ? ----)" << endl;
    dosya_guncelle32.close();
}

void aramatameslesen(string pat, string txt, int q)  
{  
    // Girilen ve okunan kelimelerdeki boşlukları temizle
    pat = trim(pat);
    txt = trim(txt);
    
    // Büyük/küçük harf duyarlılığını kaldır
    transform(pat.begin(), pat.end(), pat.begin(), ::tolower);
    transform(txt.begin(), txt.end(), txt.begin(), ::tolower);
    
    if (pat == txt) {
        ofstream dosya_guncelle("SONUC.txt");  // Dosyayı sıfırdan aç
        dosya_guncelle << "|************----Tam Eslesme----************|" << endl;
        dosya_guncelle << "|************-------------------************|" << endl;
        dosya_guncelle << "|************-------------------************|" << endl;
        dosya_guncelle << "|************-------------------************|" << endl;
        dosya_guncelle << "|************-------------------************|" << endl;
        dosya_guncelle << "|************-------------------************|" << endl;
        dosya_guncelle << "-----------------" << txt << "-----------------" << endl;
        dosya_guncelle << "|************-------------------************|" << endl;
        dosya_guncelle << "|************-------------------************|" << endl;
        dosya_guncelle << "|************-------------------************|" << endl;
        dosya_guncelle << "|************-------------------************|" << endl;
        dosya_guncelle << "|************-------------------************|" << endl;
        dosya_guncelle << "|************-------------------************|" << endl;
        dosya_guncelle.close();
    }
}
void tameslesendosyalama(string girilen, string dosyadaokunan, int q) {
    ifstream dosyaoku("kelimeler1.txt");
    if (!dosyaoku.is_open()) {
        cout << "kelimeler1.txt dosyası açılamadı!" << endl;
        return;
    }
    
    bool tamEslesmeVar = false;
    while (getline(dosyaoku, dosyadaokunan)) {
        if (!dosyadaokunan.empty()) {
            // Boşlukları temizle
            dosyadaokunan = trim(dosyadaokunan);
            string girilenTemp = trim(girilen);
            
            // Büyük/küçük harf duyarlılığını kaldır
            transform(dosyadaokunan.begin(), dosyadaokunan.end(), dosyadaokunan.begin(), ::tolower);
            transform(girilenTemp.begin(), girilenTemp.end(), girilenTemp.begin(), ::tolower);
            
            if (girilenTemp == dosyadaokunan) {
                tamEslesmeVar = true;
                aramatameslesen(girilen, dosyadaokunan, q);
                break;
            }
        }
    }
    dosyaoku.close();
    
    if (!tamEslesmeVar) {
        baslama();  // Eğer tam eşleşme yoksa benzer kelimeleri göster
    }
}
void yakinindayakini(string pat,string txt,int q)
{
	int M = pat.size(); //dardan girilen kelimenin uzunluu 
    int N = txt.size();	//dosyada okunan kelimenin uzunluu  
    int j;  //j tanmladm
    int z=0;// z tanmlaypp 0'a eitliyor
    	for(j=0;txt[j];j++){//dosyada okunan kadar almas iin bi for yaptm
    		if(txt[j]==pat[j]){//eer dardan girilenin j. indisi ile okunann j. indisi eitiyorsa z 1 artyyor
    			z++;
			}
			else if(txt[j]==pat[j+1]){//eer dardan girilenin j+1. indisi ile okunann j. indisi eitiyorsa z 1 artyyor
				z++;
			}
			else if(txt[j]==pat[j-1]){//eer dardan girilenin j. indisi ile okunann j-1. indisi eitiyorsa z 1 artyyor
				z++;
			}
		}
		if((z>=N-1)&&(txt[0]==pat[0])&&(N==M||N-1==M||N+1==M)&&txt!=pat)
		/* 1)eer stteki for dngsnden kana z, dardan girilen kelimenin uzunluundan byk yada eitse if'in ilki TRUE
		2)eer txt 0. indisiyle patn 0. indisi birbirine eitse TRUE
		3)eer dosyadan okunannzunluuyla girilen kelimenin uzunluu eit veya
				dosyadan okunannzunluunun bir eksiinin  girilen kelimenin uzunluuyla eitse veya
				dosyadan okunannzunluunun bir fazlasnn  girilen kelimenin uzunluuyla eitse TRUE
		4)dosyadan okunan ile dardan girilen eit deilse TRUE(Bunu yapmamnz sebebi eit olursa tam elemeyi de yazdym
		ama ben bu algoritmay yakn eleme iin yazdymdan eit olmamal)*/
				
		{
			
		
				fstream dosya_guncelle3("SONUC.txt",ios::app|ios::in|ios::out);//sonucu atm
				dosya_guncelle3<<endl<<"---- "<<txt<< " ----"<<endl;//dosyaya yazyor
					dosya_guncelle3.close();//dosyay kapatyor
		}		
}
void yakinindayakinidosyalama(string girilen, string dosyadaokunan, int q) {
    ifstream dosyaoku("kelimeler1.txt", ios::in);
    if (!dosyaoku.is_open()) {
        return;
    }
    while (getline(dosyaoku, dosyadaokunan)) {
        if (!dosyadaokunan.empty()) {
            yakinindayakini(girilen, dosyadaokunan, q);
        }
    }
    dosyaoku.close();
}
void aramaenyakin1(string pat, string txt, int q)  
{  
    int M = pat.size();  //dardan girilen kelimenin uzunluu
    int N = txt.size();  //dosyada okunan kelimenin uzunluu
    int i,j;  //j ve i tanmladm
    int p = 0; //p 0 tanmladm
    int t = 0;  // t 0 tanmladm
    int h = 1; // h 1 tanmladm
 
    for (i = 0; i < M - 1; i++) //h girilen kelimenin uzunluu kadar hesaplyor 
        h = (h * d) % q;  
  
    
    for (i = 0; i < M; i++)  
    {  
        p = (d * p + pat[i]) % q;  
        t = (d * t + txt[i]) % q;  
    }  
  
 
    for (i = 0; i <= N - M; i++)  
    {  
  
        
        if ( p == t )  
        {  
           
            for (j = 0; j < M; j++)  
            {  
                if (txt[i+j] != pat[j])  
                    break;  
               
            }  
  
            
            if (j == M){
            	if(i==0){
					if(N-M<=2&&M!=N){//2 eksiisi yada benzerlii var m diye bakyor
						ofstream dosya_guncelle3("SONUC.txt",ios::app);
						dosya_guncelle3<<endl<<"---- "<<txt<< " ----"<<endl;
						dosya_guncelle3.close();
							}
							
						
								
				}
						
			}
     
	   }
	   
        
		 
        if ( i < N-M )  
        {  
            t = (d*(t - txt[i]*h) + txt[i+M])%q;  
  
             
            if (t < 0)  
            t = (t + q);  
        }
        
							
		  
  			  }
	}
void enyakin1dosyalama(string girilen, string dosyadaokunan, int q) {
    ifstream dosyaoku("kelimeler1.txt", ios::in);
    if (!dosyaoku.is_open()) {
        return;
    }
    while (getline(dosyaoku, dosyadaokunan)) {
        if (!dosyadaokunan.empty()) {
            aramaenyakin1(girilen, dosyadaokunan, q);
        }
    }
    dosyaoku.close();
}
void aramaazyakin(string pat, string txt, int q)  
{  
    int M = pat.size();  //dardan girilen kelimenin uzunluu
    int N = txt.size();  //dosyada okunan kelimenin uzunluu
    int i,j;  //j ve i tanmladm
    int p = 0; 
    int t = 0;   
    int h = 1;  
  	int sayac=0;//sayac tanmlaypp 0'a eitliyor
 
    for (i = 0; i < M - 1; i++)  
        h = (h * d) % q;  
  
    
    for (i = 0; i < M; i++)  
    {  
        p = (d * p + pat[i]) % q;  
        t = (d * t + txt[i]) % q;  
    }  
  
 
    for (i = 0; i <= N - M; i++)  
    {  
  
        
        if ( p == t )  
        {  
           
            for (j = 0; j < M; j++)  
            {  
                if (txt[i+j] != pat[j])  
                    break;  
               
            }  
  
            
            if (j == M){
				if(i==1){
				fstream dosya_guncelle3("SONUC.txt",ios::app|ios::in|ios::out);//sonucu atm
				/* burda bunu yapmamnz sebebi bu en uzak elemeden kana sonucun nceki algoritmalardan kana sonuularmla eitiyor mu diye bakmas iin
				eer eitirse birdaha yazcy birdaha yazmamas iin sorgu yaptm*/
					dosya_guncelle3<<endl<<"---- "<<txt<< " ----"<<endl;//dosyaya yazyor
				dosya_guncelle3.close();//dosyay kapatyor
				}
				}
						
			}
     
	   }
        
		 
        if ( i < N-M )  
        {  
            t = (d*(t - txt[i]*h) + txt[i+M])%q;  
  
             
            if (t < 0)  
            t = (t + q);  
        }
        
							
		  
    	
}
void azyakindosyalama(string girilen, string dosyadaokunan, int q) {
    ifstream dosyaoku("kelimeler1.txt", ios::in);
    if (!dosyaoku.is_open()) {
        return;
    }
    while (getline(dosyaoku, dosyadaokunan)) {
        if (!dosyadaokunan.empty()) {
            aramaazyakin(girilen, dosyadaokunan, q);
        }
    }
    dosyaoku.close();
}
void aramaenuzak(string pat, string txt, int q)  
{  
int kelimevar=0;// kelime kontrol
    int M = pat.size();  //dardan girilen kelimenin uzunluu
    int N = txt.size();  //dosyada okunan kelimenin uzunluu
    int i,j;  //j ve i tanmladm
    int sayac=0;//sayac tanmlaypp 0'a eitliyor
    	for(j=0;txt[j];j++){//dosyada okunan kadar almas iin bi for yaptm
    		if(txt[j]==pat[j]){//eer dardan girilenin j. indisi ile okunann j. indisi eitiyorsa sayac 2 artyyor
    			sayac=sayac+2;//bunu yapmamnz sebebi eer eitlerse daha yakn olduunu gsterebilmek iin
			}
			else if(txt[j+1]==pat[j]){//eer dardan girilenin j. indisi ile okunann j+1. indisi eitiyorsa saya 1 artyyor
				sayac++;
			}
			else if(txt[j]==pat[j+1]){//eer dardan girilenin j+1. indisi ile okunann j. indisi eitiyorsa saya 1 artyyor
				sayac++;
			}
			else if(txt[j]==pat[j-1]){//eer dardan girilenin j-1. indisi ile okunann j. indisi eitiyorsa saya 1 artyyor
				sayac++;
			}
			else if(txt[j-1]==pat[j])//eer dardan girilenin j. indisi ile okunann j-1. indisi eitiyorsa saya 1 artyyor
    		{
    			sayac++;
			}
			
		}
		 if(sayac>N+1&&(N==M||N-1==M||N+1==M))
		 /*1)sayac eer dosyada okunan uzunluundan bir fazlasndan bykse TRUE
		   2)eer dosyadan okunann uzunluuyla girilen kelimenin uzunluu eit veya
				dosyadan okunann uzunluunun bir eksiinin  girilen kelimenin uzunluuyla eitse veya
				dosyadan okunann uzunluunun bir fazlasnn  girilen kelimenin uzunluuyla eitse TRUE
				bu ise en uzak eleme */
		 {

				fstream dosya_guncelle3("SONUC.txt",ios::app|ios::in|ios::out);//sonucu atm
					dosya_guncelle3<<endl<<"---- "<<txt<< " ----"<<endl;//dosyaya yazyor
		dosya_guncelle3.close();//dosyay kapatyor
					
				}
				
				
	}
	
	
void enuzakdosyalama(string girilen, string dosyadaokunan, int q) {
    ifstream dosyaoku("kelimeler1.txt", ios::in);
    if (!dosyaoku.is_open()) {
        return;
    }
    while (getline(dosyaoku, dosyadaokunan)) {
        if (!dosyadaokunan.empty()) {
            aramaenuzak(girilen, dosyadaokunan, q);
        }
    }
    dosyaoku.close();
}
void resetlemecalistirma(){
	fstream dosya_guncelle12332("arasonuc12.txt",ios::app|ios::in|ios::out);//arasonuc diye bi dosya akyor
	dosya_guncelle12332<<"!!!!ARADIGINIZ SONUC BULUNAMADI!!!!"<<endl;//iine !!!!ARADIGINIZ SONUC BULUNAMADI!!!! yazyor
	dosya_guncelle12332.close();//dosyay kapatyor
	remove("SONUC.txt");//sonucu siliyor
    rename("arasonuc12.txt","SONUC.txt");//arasonuc12 nin yeni ismini sonuc yapyor yani bi nevi sonucun zerine yazyor
}
void resetleme(){
	/* eer okuduun sonuc dosyasnda hi bir sonuc bulamazsa en son yazdlan eyin son karakterine bakyor 
	o karakter eer ) eit ise demekki iine hi bir sonu yazlmam oluyor. yani bu ne demek;
	tam eleme de olmam,yakn elemesi de yok.
	bunu bulursa eer stne sonu bulunamad yazyor*/
	ifstream dosyaoku("SONUC.txt");//sonuc dosyasn akyor
	char karakter;
		while(dosyaoku.get(karakter)){//bu karakter karakter okuma.
		//burda karakter karakter okuyor sonuna kadar
		}
		dosyaoku.close();
		if(karakter==')'){// eer en son okuduun karakter ) eit ise sonuc dosyasnnz zerine bulunamad yazyor 
			resetlemecalistirma();//yazygy fonksiyon alcyyor
		}
}
void main1(){
    #ifdef _WIN32
        SetConsoleOutputCP(65001); // Windows'ta Türkçe karakter desteği
    #else
        setlocale(LC_ALL, "Turkish"); // MacOS/Linux'ta Türkçe karakter desteği
    #endif

    konsolRengiAyarla();
    
    string dosyadaokunan;
    string girilen;
    clock_t t1, t2;
    
    cout << "Aramak Istediginiz Kelimeyi Giriniz = ";
    getline(cin, girilen);
    
    if (girilen.empty()) {
        cout << "Boş kelime girdiniz!" << endl;
        return;
    }
    
    int q = 101;
    t1 = clock();
    
    // Dosya varlığını kontrol et
    ifstream test("kelimeler1.txt");
    if (!test.is_open()) {
        cout << "kelimeler1.txt dosyası bulunamadı!" << endl;
        return;
    }
    test.close();
    
    // Önce tam eşleşme kontrolü yap
    tameslesendosyalama(girilen, dosyadaokunan, q);
    
    // Eğer tam eşleşme yoksa benzer kelimeleri ara
    enyakin1dosyalama(girilen, dosyadaokunan, q);
    yakinindayakinidosyalama(girilen, dosyadaokunan, q);
    azyakindosyalama(girilen, dosyadaokunan, q);
    enuzakdosyalama(girilen, dosyadaokunan, q);
    
    t2 = clock();
    float diff = (((float)t2 - (float)t1) / 1000000.0F) * 1000;
    cout << "ARAMA ISLEMINI " << diff << " SANIYEDE TAMAMLANDI." << endl;
    
    resetleme();
    dosyaAc();
}
int main()  
{  
main1();//ana programnalt yer
return 0;  
}

