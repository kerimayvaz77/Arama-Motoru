#include <iostream>
#include <bits/stdc++.h> 
#include <string>
#include <cstring>
#include <fstream>
using namespace std; 
#define d 256
void aramatameslesen(string pat, string txt, int q)  
{  
    int M = pat.size();  //d��ardan girilen kelimenin uzunlu�u
    int N = txt.size();  //dosyada okunan kelimenin uzunlu�u  
    int i,j;  //j ve i tan�mlad�m
    int p = 0; //p 0 tan�mlad�m
    int t = 0;   //t 0 tan�mlad�m
    int h = 1;  //h 1 tan�mlad�m
 
    for (i = 0; i < M - 1; i++)   //h � girilen kelimenin uzunlu�u kadar hesapl�yor 
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
            		if(M==N){
					//tam eslesme ��kma yeri
            			fstream dosya_guncelle("deneme.txt",ios::app|ios::in|ios::out);
            			dosya_guncelle<<"|************----Tam Eslesme----************|"<<endl;
            			dosya_guncelle<<"|************-------------------************|"<<endl;
            			dosya_guncelle<<"|************-------------------************|"<<endl;
            			dosya_guncelle<<"|************-------------------************|"<<endl;
            			dosya_guncelle<<"|************-------------------************|"<<endl;
            			dosya_guncelle<<"|************-------------------************|"<<endl;
            			dosya_guncelle<<"-----------------"<<txt<<"-----------------"<<endl;
            			dosya_guncelle<<"|************-------------------************|"<<endl;
            			dosya_guncelle<<"|************-------------------************|"<<endl;
            			dosya_guncelle<<"|************-------------------************|"<<endl;
            			dosya_guncelle<<"|************-------------------************|"<<endl;
            			dosya_guncelle<<"|************-------------------************|"<<endl;
            			dosya_guncelle<<"|************-------------------************|"<<endl;
            			dosya_guncelle.close();
            			remove("SONUC.txt");
    rename("deneme.txt","SONUC.txt");
    system("SONUC.txt");
            			
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
void tameslesendosyalama(string girilen,string dosyadaokunan,int q)
{
	ifstream dosyaoku("kelimeler1.txt");//kelimeler1.txt a��yor
    while(!dosyaoku.eof()){
    	getline(dosyaoku,dosyadaokunan);//kelimeler1.txt' nin ilk sat�r�ndan ba�lay�p okuyor ve dosyadaokunana e�itliyor
		aramatameslesen(girilen, dosyadaokunan, q);//kelimeler1.txt deki �ekilen kelimeyi algoritmaya g�nderiyor		
	}
	dosyaoku.close();
	
	fstream dosya2("kelimeler2.docx",ios::app|ios::out|ios::in);//kelimeler2.docx a��yor
	while(!dosya2.eof()){
    	getline(dosya2,dosyadaokunan);//kelimeler2.docx' nin ilk sat�r�ndan ba�lay�p okuyor ve dosyadaokunana e�itliyor
    	aramatameslesen(girilen, dosyadaokunan, q);//kelimeler2.docx deki �ekilen kelimeyi algoritmaya g�nderiyor
    	
	} 
	dosya2.close();
	fstream dosya1("kelimeler3.pdf",ios::app|ios::out|ios::in);//kelimeler3.pdf a��yor
	while(!dosya1.eof()){
    	getline(dosya1,dosyadaokunan);//kelimeler3.pdf' nin ilk sat�r�ndan ba�lay�p okuyor ve dosyadaokunana e�itliyor
    	aramatameslesen(girilen, dosyadaokunan,q);//kelimeler3.pdf'deki �ekilen kelimeyi algoritmaya g�nderiyor
    	
	}
	dosya1.close();
	fstream dosya3("kelimeler4.html",ios::app|ios::out|ios::in);//kelimeler4.html a��yor
	while(!dosya3.eof()){
    	getline(dosya3,dosyadaokunan);//kelimeler4.html' nin ilk sat�r�ndan ba�lay�p okuyor ve dosyadaokunana e�itliyor
    	aramatameslesen(girilen, dosyadaokunan, q);//kelimeler4.html'deki �ekilen kelimeyi algoritmaya g�nderiyor
    	
	} 
	dosya3.close();
}
void yakinindayakini(string pat,string txt,int q)
{
	int M = pat.size(); //d��ardan girilen kelimenin uzunlu�u 
    int N = txt.size();	//dosyada okunan kelimenin uzunlu�u  
    int j;  //j tan�mlad�m
    int z=0;// z tan�mlay�p 0'a e�itledim
    	for(j=0;txt[j];j++){//dosyada okunan kadar �al��mas� i�in bi for yapt�m
    		if(txt[j]==pat[j]){//e�er d��ardan girilenin j. indisi ile okunan�n j. indisi e�le�iyorsa z 1 art�yor
    			z++;
			}
			else if(txt[j]==pat[j+1]){//e�er d��ardan girilenin j+1. indisi ile okunan�n j. indisi e�le�iyorsa z 1 art�yor
				z++;
			}
			else if(txt[j]==pat[j-1]){//e�er d��ardan girilenin j. indisi ile okunan�n j-1. indisi e�le�iyorsa z 1 art�yor
				z++;
			}
		}
		if((z>=N-1)&&(txt[0]==pat[0])&&(N==M||N-1==M||N+1==M)&&txt!=pat)
		/* 1)e�er �stteki for d�ng�s�nden ��kan z, d��ardan girilen kelimenin uzunlu�undan b�y�k yada e�itse if'in ilki TRUE
		2)e�er txt 0. indisiyle pat�n 0. indisi birbirine e�itse TRUE
		3)e�er dosyadan okunan�n uzunlu�uyla girilen kelimenin uzunlu�u e�it veya
				dosyadan okunan�n uzunlu�unun bir eksi�inin  girilen kelimenin uzunlu�uyla e�itse veya
				dosyadan okunan�n uzunlu�unun bir fazlas�n�n  girilen kelimenin uzunlu�uyla e�itse TRUE
		4)dosyadan okunan ile d��ardan girilen e�it de�ilse TRUE(Bunu yapmam�n sebebi e�it olursa tam e�le�meyi de yazd��� i�in
		ama ben bu algoritmay� yak�n e�le�me i�in yazd���mdan e�it olmamal�*/
				
		{
			
		
				fstream dosya_guncelle3("SONUC.txt",ios::app|ios::in|ios::out);//sonucu a�t�m
				dosya_guncelle3<<endl<<"---- "<<txt<< " ----"<<endl;//dosyaya yaz�yor
					dosya_guncelle3.close();//dosyay� kapat�yor
		}		
}
void yakinindayakinidosyalama(string girilen,string dosyadaokunan,int q)
{
		ifstream dosyaoku("kelimeler1.txt");//kelimeler1.txt a��yor
    while(!dosyaoku.eof()){
    	getline(dosyaoku,dosyadaokunan);//kelimeler1.txt' nin ilk sat�r�ndan ba�lay�p okuyor ve dosyadaokunana e�itliyor
		yakinindayakini(girilen, dosyadaokunan, q);//kelimeler1.txt deki �ekilen kelimeyi algoritmaya g�nderiyor		
	}
	dosyaoku.close();
	
	fstream dosya2("kelimeler2.docx",ios::app|ios::out|ios::in);//kelimeler2.docx a��yor
	while(!dosya2.eof()){
    	getline(dosya2,dosyadaokunan);//kelimeler2.docx' nin ilk sat�r�ndan ba�lay�p okuyor ve dosyadaokunana e�itliyor
    	yakinindayakini(girilen, dosyadaokunan, q);//kelimeler2.docx deki �ekilen kelimeyi algoritmaya g�nderiyor
    	
	} 
	dosya2.close();
	fstream dosya1("kelimeler3.pdf",ios::app|ios::out|ios::in);//kelimeler3.pdf a��yor
	while(!dosya1.eof()){
    	getline(dosya1,dosyadaokunan);//kelimeler3.pdf' nin ilk sat�r�ndan ba�lay�p okuyor ve dosyadaokunana e�itliyor
    	yakinindayakini(girilen, dosyadaokunan,q);//kelimeler3.pdf'deki �ekilen kelimeyi algoritmaya g�nderiyor
    	
	}
	dosya1.close();
	fstream dosya3("kelimeler4.html",ios::app|ios::out|ios::in);//kelimeler4.html a��yor
	while(!dosya3.eof()){
    	getline(dosya3,dosyadaokunan);//kelimeler4.html' nin ilk sat�r�ndan ba�lay�p okuyor ve dosyadaokunana e�itliyor
    	yakinindayakini(girilen, dosyadaokunan, q);//kelimeler4.html'deki �ekilen kelimeyi algoritmaya g�nderiyor
    	
	} 
	dosya3.close();
	
}
void aramaenyakin1(string pat, string txt, int q)  
{  
    int M = pat.size();  //d��ardan girilen kelimenin uzunlu�u
    int N = txt.size();  //dosyada okunan kelimenin uzunlu�u
    int i,j;  //j ve i tan�mlad�m
    int p = 0; //p 0 tan�mlad�m
    int t = 0;  // t 0 tan�mlad�m
    int h = 1; // h 1 tan�mlad�m
 
    for (i = 0; i < M - 1; i++) //h � girilen kelimenin uzunlu�u kadar hesapl�yor 
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
					if(N-M<=2&&M!=N){//2 eksi�i yada benzerli�i var m� diye bak�yor
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
void enyakin1dosyalama(string girilen,string dosyadaokunan,int q)
{
		ifstream dosyaoku("kelimeler1.txt");//kelimeler1.txt a��yor
    while(!dosyaoku.eof()){
    	getline(dosyaoku,dosyadaokunan);//kelimeler1.txt' nin ilk sat�r�ndan ba�lay�p okuyor ve dosyadaokunana e�itliyor
		aramaenyakin1(girilen, dosyadaokunan, q);//kelimeler1.txt deki �ekilen kelimeyi algoritmaya g�nderiyor		
	}
	dosyaoku.close();
	
	fstream dosya2("kelimeler2.docx",ios::app|ios::out|ios::in);//kelimeler2.docx a��yor
	while(!dosya2.eof()){
    	getline(dosya2,dosyadaokunan);//kelimeler2.docx' nin ilk sat�r�ndan ba�lay�p okuyor ve dosyadaokunana e�itliyor
    	aramaenyakin1(girilen, dosyadaokunan, q);//kelimeler2.docx deki �ekilen kelimeyi algoritmaya g�nderiyor
    	
	} 
	dosya2.close();
	fstream dosya1("kelimeler3.pdf",ios::app|ios::out|ios::in);//kelimeler3.pdf a��yor
	while(!dosya1.eof()){
    	getline(dosya1,dosyadaokunan);//kelimeler3.pdf' nin ilk sat�r�ndan ba�lay�p okuyor ve dosyadaokunana e�itliyor
    	aramaenyakin1(girilen, dosyadaokunan,q);//kelimeler3.pdf'deki �ekilen kelimeyi algoritmaya g�nderiyor
    	
	}
	dosya1.close();
	fstream dosya3("kelimeler4.html",ios::app|ios::out|ios::in);//kelimeler4.html a��yor
	while(!dosya3.eof()){
    	getline(dosya3,dosyadaokunan);//kelimeler4.html' nin ilk sat�r�ndan ba�lay�p okuyor ve dosyadaokunana e�itliyor
    	aramaenyakin1(girilen, dosyadaokunan, q);//kelimeler4.html'deki �ekilen kelimeyi algoritmaya g�nderiyor
    	
	} 
	dosya3.close();
	
}
void aramaazyakin(string pat, string txt, int q)  
{  
    int M = pat.size();  //d��ardan girilen kelimenin uzunlu�u
    int N = txt.size();  //dosyada okunan kelimenin uzunlu�u
    int i,j;  //j ve i tan�mlad�m
    int p = 0; 
    int t = 0;   
    int h = 1;  
  	int sayac=0;//sayac tan�mlay�pp 0'a e�itledim
 
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
				fstream dosya_guncelle3("SONUC.txt",ios::app|ios::in|ios::out);//sonucu a�t�m
				/* burda bunu yapmam�n sebebi bu en uzak e�le�meden ��kan sonucun �nceki algoritmalardan ��kan sonu�larla e�le�iyor mu diye bakmas� i�in
				e�er e�le�irse birdaha yaz�cak birdaha yazmamas� i�in sorgu yapt�m*/
					dosya_guncelle3<<endl<<"---- "<<txt<< " ----"<<endl;//dosyaya yaz�yor
				dosya_guncelle3.close();//dosyay� kapat�yor
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
void azyakindosyalama(string girilen,string dosyadaokunan,int q)
{
		ifstream dosyaoku("kelimeler1.txt");//kelimeler1.txt a��yor
    while(!dosyaoku.eof()){
    	getline(dosyaoku,dosyadaokunan);//kelimeler1.txt' nin ilk sat�r�ndan ba�lay�p okuyor ve dosyadaokunana e�itliyor
		aramaazyakin(girilen, dosyadaokunan, q);//kelimeler1.txt deki �ekilen kelimeyi algoritmaya g�nderiyor		
	}
	dosyaoku.close();
	
	fstream dosya2("kelimeler2.docx",ios::app|ios::out|ios::in);//kelimeler2.docx a��yor
	while(!dosya2.eof()){
    	getline(dosya2,dosyadaokunan);//kelimeler2.docx' nin ilk sat�r�ndan ba�lay�p okuyor ve dosyadaokunana e�itliyor
    	aramaazyakin(girilen, dosyadaokunan, q);//kelimeler2.docx deki �ekilen kelimeyi algoritmaya g�nderiyor
    	
	} 
	dosya2.close();
	fstream dosya1("kelimeler3.pdf",ios::app|ios::out|ios::in);//kelimeler3.pdf a��yor
	while(!dosya1.eof()){
    	getline(dosya1,dosyadaokunan);//kelimeler3.pdf' nin ilk sat�r�ndan ba�lay�p okuyor ve dosyadaokunana e�itliyor
    	aramaazyakin(girilen, dosyadaokunan,q);//kelimeler3.pdf'deki �ekilen kelimeyi algoritmaya g�nderiyor
    	
	}
	dosya1.close();
	fstream dosya3("kelimeler4.html",ios::app|ios::out|ios::in);//kelimeler4.html a��yor
	while(!dosya3.eof()){
    	getline(dosya3,dosyadaokunan);//kelimeler4.html' nin ilk sat�r�ndan ba�lay�p okuyor ve dosyadaokunana e�itliyor
    	aramaazyakin(girilen, dosyadaokunan, q);//kelimeler4.html'deki �ekilen kelimeyi algoritmaya g�nderiyor
    	
	} 
	dosya3.close();
	
}	
void aramaenuzak(string pat, string txt, int q)  
{  
int kelimevar=0;// kelime kontrol�
    int M = pat.size();  //d��ardan girilen kelimenin uzunlu�u
    int N = txt.size();  //dosyada okunan kelimenin uzunlu�u
    int i,j;  //j ve i tan�mlad�m
    int sayac=0;//sayac tan�mlay�pp 0'a e�itledim
    	for(j=0;txt[j];j++){//dosyada okunan kadar �al��mas� i�in bi for yapt�m
    		if(txt[j]==pat[j]){//e�er d��ardan girilenin j. indisi ile okunan�n j. indisi e�le�iyorsa sayac� 2 art�yor
    			sayac=sayac+2;//bunu yapmam�n sebebi e�er e�itseler daha yak�n oldu�unu g�sterebilmek i�in
			}
			else if(txt[j+1]==pat[j]){//e�er d��ardan girilenin j. indisi ile okunan�n j+1. indisi e�le�iyorsa saya� 1 art�yor
				sayac++;
			}
			else if(txt[j]==pat[j+1]){//e�er d��ardan girilenin j+1. indisi ile okunan�n j. indisi e�le�iyorsa saya� 1 art�yor
				sayac++;
			}
			else if(txt[j]==pat[j-1]){//e�er d��ardan girilenin j-1. indisi ile okunan�n j. indisi e�le�iyorsa saya� 1 art�yor
				sayac++;
			}
			else if(txt[j-1]==pat[j])//e�er d��ardan girilenin j. indisi ile okunan�n j-1. indisi e�le�iyorsa saya� 1 art�yor
    		{
    			sayac++;
			}
			
		}
		 if(sayac>N+1&&(N==M||N-1==M||N+1==M))
		 /*1)sayac e�er dosyada okunan uzunlu�undan bir fazlas�ndan b�y�kse TRUE
		   2)e�er dosyadan okunan�n uzunlu�uyla girilen kelimenin uzunlu�u e�it veya
				dosyadan okunan�n uzunlu�unun bir eksi�inin  girilen kelimenin uzunlu�uyla e�itse veya
				dosyadan okunan�n uzunlu�unun bir fazlas�n�n  girilen kelimenin uzunlu�uyla e�itse TRUE
				bu ise en uzak e�le�me */
		 {

				fstream dosya_guncelle3("SONUC.txt",ios::app|ios::in|ios::out);//sonucu a�t�m
					dosya_guncelle3<<endl<<"---- "<<txt<< " ----"<<endl;//dosyaya yaz�yor
		dosya_guncelle3.close();//dosyay� kapat�yor
					
				}
				
				
	}
	
	
void enuzakdosyalama(string girilen,string dosyadaokunan,int q)
{
		ifstream dosyaoku("kelimeler1.txt");//kelimeler1.txt a��yor
    while(!dosyaoku.eof()){
    	getline(dosyaoku,dosyadaokunan);//kelimeler1.txt' nin ilk sat�r�ndan ba�lay�p okuyor ve dosyadaokunana e�itliyor
		aramaenuzak(girilen, dosyadaokunan, q);	//kelimeler1.txt deki �ekilen kelimeyi algoritmaya g�nderiyor	
	}
	dosyaoku.close();
	
	fstream dosya2("kelimeler2.docx",ios::app|ios::out|ios::in);//kelimeler2.docx a��yor
	while(!dosya2.eof()){
    	getline(dosya2,dosyadaokunan);//kelimeler2.docx' nin ilk sat�r�ndan ba�lay�p okuyor ve dosyadaokunana e�itliyor
    	aramaenuzak(girilen, dosyadaokunan, q);//kelimeler2.docx deki �ekilen kelimeyi algoritmaya g�nderiyor
    	
	} 
	dosya2.close();
	fstream dosya1("kelimeler3.pdf",ios::app|ios::out|ios::in);//kelimeler3.pdf a��yor
	while(!dosya1.eof()){
    	getline(dosya1,dosyadaokunan);//kelimeler3.pdf' nin ilk sat�r�ndan ba�lay�p okuyor ve dosyadaokunana e�itliyor
    	aramaenuzak(girilen, dosyadaokunan,q);//kelimeler3.pdf'deki �ekilen kelimeyi algoritmaya g�nderiyor
    	
	}
	dosya1.close();
	fstream dosya3("kelimeler4.html",ios::app|ios::out|ios::in);//kelimeler4.html a��yor
	while(!dosya3.eof()){
    	getline(dosya3,dosyadaokunan);//kelimeler4.html' nin ilk sat�r�ndan ba�lay�p okuyor ve dosyadaokunana e�itliyor
    	aramaenuzak(girilen, dosyadaokunan, q);//kelimeler4.html'deki �ekilen kelimeyi algoritmaya g�nderiyor
    	
	} 
	dosya3.close();
	
	
}
void baslama()
{
//tam e�le�me yeni bi dosya a��l�yormu� gibi �zerine yaz�yor tam e�le�me �al���yor sonras�nda ise bu �al���yor.
//tam e�le�meyi ��kartt�ktan sonra dosyan�n �zerine sadece (---- BUNU'MU DEMEK ISTED�N�Z? ----) yaz�yor
	fstream dosya_guncelle32("deneme.txt",ios::app|ios::in|ios::out);//deneme diye bi dosya a��yorum
						dosya_guncelle32<<"(---- BUNU'MU DEMEK ISTED�N�Z? ----)";//i�ine (---- BUNU'MU DEMEK ISTED�N�Z? ----) yaz�yorum
						dosya_guncelle32.close();//dosyay� kapat�yorum
						remove("SONUC.txt");//sonucu siliyorum
    rename("deneme.txt","SONUC.txt");//deneme isimli dosyan�n ismini de�i�tirip sonuc.txt yap�yorum
    //bu i�lem sonucunda SONUC.txt nin i�ine (---- BUNU'MU DEMEK ISTED�N�Z? ----) yaz�yor.
}
void resetlemecalistirma(){
	fstream dosya_guncelle12332("arasonuc12.txt",ios::app|ios::in|ios::out);//arasonuc diye bi dosya a��yor
	dosya_guncelle12332<<"!!!!ARADIGINIZ SONUC BULUNAMADI!!!!"<<endl;//i�ine !!!!ARADIGINIZ SONUC BULUNAMADI!!!! yaz�yor
	dosya_guncelle12332.close();//dosyay� kapat�yor
	remove("SONUC.txt");//sonucu siliyor
    rename("arasonuc12.txt","SONUC.txt");//arasonuc12 nin yeni ismini sonuc yap�yor yani bi nevi sonucun �zerine yaz�yor
}
void resetleme(){
	/* e�er okudu�u sonuc dosyas�nda hi�bir sonuc bulamazsa en son yazd�lan �eyin son karakterine bak�yor 
	o karakter e�er ) e�it ise demekki i�ine hi�bir sonu� yaz�lmam�� oluyor. yani bu ne demek;
	tam e�le�me de olmam��,yak�n e�le�mesi de yok.
	bunu bulursa e�er �st�ne sonu� bulunamad� yaz�yor*/
	ifstream dosyaoku("SONUC.txt");//sonuc dosyas�n� a��yor
	char karakter;
		while(dosyaoku.get(karakter)){//bu karakter karakter okuma.
		//burda karakter karakter okuyor sonuna kadar
		}
		dosyaoku.close();
		if(karakter==')'){// e�er en son okudu�u karakter ) e�it ise sonuc dosyas�n�n �zerine bulunamad� yaz�yor 
			resetlemecalistirma();//yazd�g�m fonksiyon �al���yor
		}
}
void main1(){
	system("color F4");	
	string dosyadaokunan;  //dosyada okunan kelime
    string girilen;//d��ardan kullan�c�n�n girdi�i kelime 
    clock_t t1, t2; //zamanlay�c� i�in olu�turulan t1 ve t2 yi tan�mlad�m.
    cout<<"Aramak Istediginiz Kelimeyi Giriniz = ";getline(cin,girilen);  //kullan�c� kelimeyi giriyor
    int q = 101;// asal say�
    t1 = clock(); //o an ki zaman� elde tutuyor
   tameslesendosyalama(girilen,dosyadaokunan,q);//algoritmalar �al���yor
    baslama();
    enyakin1dosyalama(girilen,dosyadaokunan,q);
   yakinindayakinidosyalama(girilen,dosyadaokunan,q);
	azyakindosyalama(girilen,dosyadaokunan,q);
	enuzakdosyalama(girilen,dosyadaokunan,q);
	t2 = clock(); // yine o a ki zaman� elinde tutuyor
	float diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;   //en son tuttu�u zamandan ilk tuttu�u zaman� float olarak ��kar�p ms �l�ekli float bi de�ere e�itliyor
	cout<<"ARAMA ISLEMINI "<<diff<<" SANIYEDE'DE YAPMISTIR."<<endl;//burda zaman� yaz�yor
resetleme();	//resetleme fonksiyonu
system("SONUC.txt");//SONUC.txt dosyas�n� a��yor

}
int main()  
{  
main1();//ana program�n �al��t��� yer
return 0;  
}

