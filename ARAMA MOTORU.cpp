#include <iostream>
#include <bits/stdc++.h> 
#include <string>
#include <cstring>
#include <fstream>
using namespace std; 
#define d 256
void aramatameslesen(string pat, string txt, int q)  
{  
    int M = pat.size();  //dýþardan girilen kelimenin uzunluðu
    int N = txt.size();  //dosyada okunan kelimenin uzunluðu  
    int i,j;  //j ve i tanýmladým
    int p = 0; //p 0 tanýmladým
    int t = 0;   //t 0 tanýmladým
    int h = 1;  //h 1 tanýmladým
 
    for (i = 0; i < M - 1; i++)   //h ý girilen kelimenin uzunluðu kadar hesaplýyor 
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
					//tam eslesme çýkma yeri
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
	ifstream dosyaoku("kelimeler1.txt");//kelimeler1.txt açýyor
    while(!dosyaoku.eof()){
    	getline(dosyaoku,dosyadaokunan);//kelimeler1.txt' nin ilk satýrýndan baþlayýp okuyor ve dosyadaokunana eþitliyor
		aramatameslesen(girilen, dosyadaokunan, q);//kelimeler1.txt deki çekilen kelimeyi algoritmaya gönderiyor		
	}
	dosyaoku.close();
	
	fstream dosya2("kelimeler2.docx",ios::app|ios::out|ios::in);//kelimeler2.docx açýyor
	while(!dosya2.eof()){
    	getline(dosya2,dosyadaokunan);//kelimeler2.docx' nin ilk satýrýndan baþlayýp okuyor ve dosyadaokunana eþitliyor
    	aramatameslesen(girilen, dosyadaokunan, q);//kelimeler2.docx deki çekilen kelimeyi algoritmaya gönderiyor
    	
	} 
	dosya2.close();
	fstream dosya1("kelimeler3.pdf",ios::app|ios::out|ios::in);//kelimeler3.pdf açýyor
	while(!dosya1.eof()){
    	getline(dosya1,dosyadaokunan);//kelimeler3.pdf' nin ilk satýrýndan baþlayýp okuyor ve dosyadaokunana eþitliyor
    	aramatameslesen(girilen, dosyadaokunan,q);//kelimeler3.pdf'deki çekilen kelimeyi algoritmaya gönderiyor
    	
	}
	dosya1.close();
	fstream dosya3("kelimeler4.html",ios::app|ios::out|ios::in);//kelimeler4.html açýyor
	while(!dosya3.eof()){
    	getline(dosya3,dosyadaokunan);//kelimeler4.html' nin ilk satýrýndan baþlayýp okuyor ve dosyadaokunana eþitliyor
    	aramatameslesen(girilen, dosyadaokunan, q);//kelimeler4.html'deki çekilen kelimeyi algoritmaya gönderiyor
    	
	} 
	dosya3.close();
}
void yakinindayakini(string pat,string txt,int q)
{
	int M = pat.size(); //dýþardan girilen kelimenin uzunluðu 
    int N = txt.size();	//dosyada okunan kelimenin uzunluðu  
    int j;  //j tanýmladým
    int z=0;// z tanýmlayýp 0'a eþitledim
    	for(j=0;txt[j];j++){//dosyada okunan kadar çalýþmasý için bi for yaptým
    		if(txt[j]==pat[j]){//eðer dýþardan girilenin j. indisi ile okunanýn j. indisi eþleþiyorsa z 1 artýyor
    			z++;
			}
			else if(txt[j]==pat[j+1]){//eðer dýþardan girilenin j+1. indisi ile okunanýn j. indisi eþleþiyorsa z 1 artýyor
				z++;
			}
			else if(txt[j]==pat[j-1]){//eðer dýþardan girilenin j. indisi ile okunanýn j-1. indisi eþleþiyorsa z 1 artýyor
				z++;
			}
		}
		if((z>=N-1)&&(txt[0]==pat[0])&&(N==M||N-1==M||N+1==M)&&txt!=pat)
		/* 1)eðer üstteki for döngüsünden çýkan z, dýþardan girilen kelimenin uzunluðundan büyük yada eþitse if'in ilki TRUE
		2)eðer txt 0. indisiyle patýn 0. indisi birbirine eþitse TRUE
		3)eðer dosyadan okunanýn uzunluðuyla girilen kelimenin uzunluðu eþit veya
				dosyadan okunanýn uzunluðunun bir eksiðinin  girilen kelimenin uzunluðuyla eþitse veya
				dosyadan okunanýn uzunluðunun bir fazlasýnýn  girilen kelimenin uzunluðuyla eþitse TRUE
		4)dosyadan okunan ile dýþardan girilen eþit deðilse TRUE(Bunu yapmamýn sebebi eþit olursa tam eþleþmeyi de yazdýðý için
		ama ben bu algoritmayý yakýn eþleþme için yazdýðýmdan eþit olmamalý*/
				
		{
			
		
				fstream dosya_guncelle3("SONUC.txt",ios::app|ios::in|ios::out);//sonucu açtým
				dosya_guncelle3<<endl<<"---- "<<txt<< " ----"<<endl;//dosyaya yazýyor
					dosya_guncelle3.close();//dosyayý kapatýyor
		}		
}
void yakinindayakinidosyalama(string girilen,string dosyadaokunan,int q)
{
		ifstream dosyaoku("kelimeler1.txt");//kelimeler1.txt açýyor
    while(!dosyaoku.eof()){
    	getline(dosyaoku,dosyadaokunan);//kelimeler1.txt' nin ilk satýrýndan baþlayýp okuyor ve dosyadaokunana eþitliyor
		yakinindayakini(girilen, dosyadaokunan, q);//kelimeler1.txt deki çekilen kelimeyi algoritmaya gönderiyor		
	}
	dosyaoku.close();
	
	fstream dosya2("kelimeler2.docx",ios::app|ios::out|ios::in);//kelimeler2.docx açýyor
	while(!dosya2.eof()){
    	getline(dosya2,dosyadaokunan);//kelimeler2.docx' nin ilk satýrýndan baþlayýp okuyor ve dosyadaokunana eþitliyor
    	yakinindayakini(girilen, dosyadaokunan, q);//kelimeler2.docx deki çekilen kelimeyi algoritmaya gönderiyor
    	
	} 
	dosya2.close();
	fstream dosya1("kelimeler3.pdf",ios::app|ios::out|ios::in);//kelimeler3.pdf açýyor
	while(!dosya1.eof()){
    	getline(dosya1,dosyadaokunan);//kelimeler3.pdf' nin ilk satýrýndan baþlayýp okuyor ve dosyadaokunana eþitliyor
    	yakinindayakini(girilen, dosyadaokunan,q);//kelimeler3.pdf'deki çekilen kelimeyi algoritmaya gönderiyor
    	
	}
	dosya1.close();
	fstream dosya3("kelimeler4.html",ios::app|ios::out|ios::in);//kelimeler4.html açýyor
	while(!dosya3.eof()){
    	getline(dosya3,dosyadaokunan);//kelimeler4.html' nin ilk satýrýndan baþlayýp okuyor ve dosyadaokunana eþitliyor
    	yakinindayakini(girilen, dosyadaokunan, q);//kelimeler4.html'deki çekilen kelimeyi algoritmaya gönderiyor
    	
	} 
	dosya3.close();
	
}
void aramaenyakin1(string pat, string txt, int q)  
{  
    int M = pat.size();  //dýþardan girilen kelimenin uzunluðu
    int N = txt.size();  //dosyada okunan kelimenin uzunluðu
    int i,j;  //j ve i tanýmladým
    int p = 0; //p 0 tanýmladým
    int t = 0;  // t 0 tanýmladým
    int h = 1; // h 1 tanýmladým
 
    for (i = 0; i < M - 1; i++) //h ý girilen kelimenin uzunluðu kadar hesaplýyor 
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
					if(N-M<=2&&M!=N){//2 eksiði yada benzerliði var mý diye bakýyor
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
		ifstream dosyaoku("kelimeler1.txt");//kelimeler1.txt açýyor
    while(!dosyaoku.eof()){
    	getline(dosyaoku,dosyadaokunan);//kelimeler1.txt' nin ilk satýrýndan baþlayýp okuyor ve dosyadaokunana eþitliyor
		aramaenyakin1(girilen, dosyadaokunan, q);//kelimeler1.txt deki çekilen kelimeyi algoritmaya gönderiyor		
	}
	dosyaoku.close();
	
	fstream dosya2("kelimeler2.docx",ios::app|ios::out|ios::in);//kelimeler2.docx açýyor
	while(!dosya2.eof()){
    	getline(dosya2,dosyadaokunan);//kelimeler2.docx' nin ilk satýrýndan baþlayýp okuyor ve dosyadaokunana eþitliyor
    	aramaenyakin1(girilen, dosyadaokunan, q);//kelimeler2.docx deki çekilen kelimeyi algoritmaya gönderiyor
    	
	} 
	dosya2.close();
	fstream dosya1("kelimeler3.pdf",ios::app|ios::out|ios::in);//kelimeler3.pdf açýyor
	while(!dosya1.eof()){
    	getline(dosya1,dosyadaokunan);//kelimeler3.pdf' nin ilk satýrýndan baþlayýp okuyor ve dosyadaokunana eþitliyor
    	aramaenyakin1(girilen, dosyadaokunan,q);//kelimeler3.pdf'deki çekilen kelimeyi algoritmaya gönderiyor
    	
	}
	dosya1.close();
	fstream dosya3("kelimeler4.html",ios::app|ios::out|ios::in);//kelimeler4.html açýyor
	while(!dosya3.eof()){
    	getline(dosya3,dosyadaokunan);//kelimeler4.html' nin ilk satýrýndan baþlayýp okuyor ve dosyadaokunana eþitliyor
    	aramaenyakin1(girilen, dosyadaokunan, q);//kelimeler4.html'deki çekilen kelimeyi algoritmaya gönderiyor
    	
	} 
	dosya3.close();
	
}
void aramaazyakin(string pat, string txt, int q)  
{  
    int M = pat.size();  //dýþardan girilen kelimenin uzunluðu
    int N = txt.size();  //dosyada okunan kelimenin uzunluðu
    int i,j;  //j ve i tanýmladým
    int p = 0; 
    int t = 0;   
    int h = 1;  
  	int sayac=0;//sayac tanýmlayýpp 0'a eþitledim
 
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
				fstream dosya_guncelle3("SONUC.txt",ios::app|ios::in|ios::out);//sonucu açtým
				/* burda bunu yapmamýn sebebi bu en uzak eþleþmeden çýkan sonucun önceki algoritmalardan çýkan sonuçlarla eþleþiyor mu diye bakmasý için
				eðer eþleþirse birdaha yazýcak birdaha yazmamasý için sorgu yaptým*/
					dosya_guncelle3<<endl<<"---- "<<txt<< " ----"<<endl;//dosyaya yazýyor
				dosya_guncelle3.close();//dosyayý kapatýyor
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
		ifstream dosyaoku("kelimeler1.txt");//kelimeler1.txt açýyor
    while(!dosyaoku.eof()){
    	getline(dosyaoku,dosyadaokunan);//kelimeler1.txt' nin ilk satýrýndan baþlayýp okuyor ve dosyadaokunana eþitliyor
		aramaazyakin(girilen, dosyadaokunan, q);//kelimeler1.txt deki çekilen kelimeyi algoritmaya gönderiyor		
	}
	dosyaoku.close();
	
	fstream dosya2("kelimeler2.docx",ios::app|ios::out|ios::in);//kelimeler2.docx açýyor
	while(!dosya2.eof()){
    	getline(dosya2,dosyadaokunan);//kelimeler2.docx' nin ilk satýrýndan baþlayýp okuyor ve dosyadaokunana eþitliyor
    	aramaazyakin(girilen, dosyadaokunan, q);//kelimeler2.docx deki çekilen kelimeyi algoritmaya gönderiyor
    	
	} 
	dosya2.close();
	fstream dosya1("kelimeler3.pdf",ios::app|ios::out|ios::in);//kelimeler3.pdf açýyor
	while(!dosya1.eof()){
    	getline(dosya1,dosyadaokunan);//kelimeler3.pdf' nin ilk satýrýndan baþlayýp okuyor ve dosyadaokunana eþitliyor
    	aramaazyakin(girilen, dosyadaokunan,q);//kelimeler3.pdf'deki çekilen kelimeyi algoritmaya gönderiyor
    	
	}
	dosya1.close();
	fstream dosya3("kelimeler4.html",ios::app|ios::out|ios::in);//kelimeler4.html açýyor
	while(!dosya3.eof()){
    	getline(dosya3,dosyadaokunan);//kelimeler4.html' nin ilk satýrýndan baþlayýp okuyor ve dosyadaokunana eþitliyor
    	aramaazyakin(girilen, dosyadaokunan, q);//kelimeler4.html'deki çekilen kelimeyi algoritmaya gönderiyor
    	
	} 
	dosya3.close();
	
}	
void aramaenuzak(string pat, string txt, int q)  
{  
int kelimevar=0;// kelime kontrolü
    int M = pat.size();  //dýþardan girilen kelimenin uzunluðu
    int N = txt.size();  //dosyada okunan kelimenin uzunluðu
    int i,j;  //j ve i tanýmladým
    int sayac=0;//sayac tanýmlayýpp 0'a eþitledim
    	for(j=0;txt[j];j++){//dosyada okunan kadar çalýþmasý için bi for yaptým
    		if(txt[j]==pat[j]){//eðer dýþardan girilenin j. indisi ile okunanýn j. indisi eþleþiyorsa sayacý 2 artýyor
    			sayac=sayac+2;//bunu yapmamýn sebebi eðer eþitseler daha yakýn olduðunu gösterebilmek için
			}
			else if(txt[j+1]==pat[j]){//eðer dýþardan girilenin j. indisi ile okunanýn j+1. indisi eþleþiyorsa sayaç 1 artýyor
				sayac++;
			}
			else if(txt[j]==pat[j+1]){//eðer dýþardan girilenin j+1. indisi ile okunanýn j. indisi eþleþiyorsa sayaç 1 artýyor
				sayac++;
			}
			else if(txt[j]==pat[j-1]){//eðer dýþardan girilenin j-1. indisi ile okunanýn j. indisi eþleþiyorsa sayaç 1 artýyor
				sayac++;
			}
			else if(txt[j-1]==pat[j])//eðer dýþardan girilenin j. indisi ile okunanýn j-1. indisi eþleþiyorsa sayaç 1 artýyor
    		{
    			sayac++;
			}
			
		}
		 if(sayac>N+1&&(N==M||N-1==M||N+1==M))
		 /*1)sayac eðer dosyada okunan uzunluðundan bir fazlasýndan büyükse TRUE
		   2)eðer dosyadan okunanýn uzunluðuyla girilen kelimenin uzunluðu eþit veya
				dosyadan okunanýn uzunluðunun bir eksiðinin  girilen kelimenin uzunluðuyla eþitse veya
				dosyadan okunanýn uzunluðunun bir fazlasýnýn  girilen kelimenin uzunluðuyla eþitse TRUE
				bu ise en uzak eþleþme */
		 {

				fstream dosya_guncelle3("SONUC.txt",ios::app|ios::in|ios::out);//sonucu açtým
					dosya_guncelle3<<endl<<"---- "<<txt<< " ----"<<endl;//dosyaya yazýyor
		dosya_guncelle3.close();//dosyayý kapatýyor
					
				}
				
				
	}
	
	
void enuzakdosyalama(string girilen,string dosyadaokunan,int q)
{
		ifstream dosyaoku("kelimeler1.txt");//kelimeler1.txt açýyor
    while(!dosyaoku.eof()){
    	getline(dosyaoku,dosyadaokunan);//kelimeler1.txt' nin ilk satýrýndan baþlayýp okuyor ve dosyadaokunana eþitliyor
		aramaenuzak(girilen, dosyadaokunan, q);	//kelimeler1.txt deki çekilen kelimeyi algoritmaya gönderiyor	
	}
	dosyaoku.close();
	
	fstream dosya2("kelimeler2.docx",ios::app|ios::out|ios::in);//kelimeler2.docx açýyor
	while(!dosya2.eof()){
    	getline(dosya2,dosyadaokunan);//kelimeler2.docx' nin ilk satýrýndan baþlayýp okuyor ve dosyadaokunana eþitliyor
    	aramaenuzak(girilen, dosyadaokunan, q);//kelimeler2.docx deki çekilen kelimeyi algoritmaya gönderiyor
    	
	} 
	dosya2.close();
	fstream dosya1("kelimeler3.pdf",ios::app|ios::out|ios::in);//kelimeler3.pdf açýyor
	while(!dosya1.eof()){
    	getline(dosya1,dosyadaokunan);//kelimeler3.pdf' nin ilk satýrýndan baþlayýp okuyor ve dosyadaokunana eþitliyor
    	aramaenuzak(girilen, dosyadaokunan,q);//kelimeler3.pdf'deki çekilen kelimeyi algoritmaya gönderiyor
    	
	}
	dosya1.close();
	fstream dosya3("kelimeler4.html",ios::app|ios::out|ios::in);//kelimeler4.html açýyor
	while(!dosya3.eof()){
    	getline(dosya3,dosyadaokunan);//kelimeler4.html' nin ilk satýrýndan baþlayýp okuyor ve dosyadaokunana eþitliyor
    	aramaenuzak(girilen, dosyadaokunan, q);//kelimeler4.html'deki çekilen kelimeyi algoritmaya gönderiyor
    	
	} 
	dosya3.close();
	
	
}
void baslama()
{
//tam eþleþme yeni bi dosya açýlýyormuþ gibi üzerine yazýyor tam eþleþme çalýþýyor sonrasýnda ise bu çalýþýyor.
//tam eþleþmeyi çýkarttýktan sonra dosyanýn üzerine sadece (---- BUNU'MU DEMEK ISTEDÝNÝZ? ----) yazýyor
	fstream dosya_guncelle32("deneme.txt",ios::app|ios::in|ios::out);//deneme diye bi dosya açýyorum
						dosya_guncelle32<<"(---- BUNU'MU DEMEK ISTEDÝNÝZ? ----)";//içine (---- BUNU'MU DEMEK ISTEDÝNÝZ? ----) yazýyorum
						dosya_guncelle32.close();//dosyayý kapatýyorum
						remove("SONUC.txt");//sonucu siliyorum
    rename("deneme.txt","SONUC.txt");//deneme isimli dosyanýn ismini deðiþtirip sonuc.txt yapýyorum
    //bu iþlem sonucunda SONUC.txt nin içine (---- BUNU'MU DEMEK ISTEDÝNÝZ? ----) yazýyor.
}
void resetlemecalistirma(){
	fstream dosya_guncelle12332("arasonuc12.txt",ios::app|ios::in|ios::out);//arasonuc diye bi dosya açýyor
	dosya_guncelle12332<<"!!!!ARADIGINIZ SONUC BULUNAMADI!!!!"<<endl;//içine !!!!ARADIGINIZ SONUC BULUNAMADI!!!! yazýyor
	dosya_guncelle12332.close();//dosyayý kapatýyor
	remove("SONUC.txt");//sonucu siliyor
    rename("arasonuc12.txt","SONUC.txt");//arasonuc12 nin yeni ismini sonuc yapýyor yani bi nevi sonucun üzerine yazýyor
}
void resetleme(){
	/* eðer okuduðu sonuc dosyasýnda hiçbir sonuc bulamazsa en son yazdýlan þeyin son karakterine bakýyor 
	o karakter eðer ) eþit ise demekki içine hiçbir sonuç yazýlmamýþ oluyor. yani bu ne demek;
	tam eþleþme de olmamýþ,yakýn eþleþmesi de yok.
	bunu bulursa eðer üstüne sonuç bulunamadý yazýyor*/
	ifstream dosyaoku("SONUC.txt");//sonuc dosyasýný açýyor
	char karakter;
		while(dosyaoku.get(karakter)){//bu karakter karakter okuma.
		//burda karakter karakter okuyor sonuna kadar
		}
		dosyaoku.close();
		if(karakter==')'){// eðer en son okuduðu karakter ) eþit ise sonuc dosyasýnýn üzerine bulunamadý yazýyor 
			resetlemecalistirma();//yazdýgým fonksiyon çalýþýyor
		}
}
void main1(){
	system("color F4");	
	string dosyadaokunan;  //dosyada okunan kelime
    string girilen;//dýþardan kullanýcýnýn girdiði kelime 
    clock_t t1, t2; //zamanlayýcý için oluþturulan t1 ve t2 yi tanýmladým.
    cout<<"Aramak Istediginiz Kelimeyi Giriniz = ";getline(cin,girilen);  //kullanýcý kelimeyi giriyor
    int q = 101;// asal sayý
    t1 = clock(); //o an ki zamaný elde tutuyor
   tameslesendosyalama(girilen,dosyadaokunan,q);//algoritmalar çalýþýyor
    baslama();
    enyakin1dosyalama(girilen,dosyadaokunan,q);
   yakinindayakinidosyalama(girilen,dosyadaokunan,q);
	azyakindosyalama(girilen,dosyadaokunan,q);
	enuzakdosyalama(girilen,dosyadaokunan,q);
	t2 = clock(); // yine o a ki zamaný elinde tutuyor
	float diff = (((float)t2 - (float)t1) / 1000000.0F ) * 1000;   //en son tuttuðu zamandan ilk tuttuðu zamaný float olarak çýkarýp ms ölçekli float bi deðere eþitliyor
	cout<<"ARAMA ISLEMINI "<<diff<<" SANIYEDE'DE YAPMISTIR."<<endl;//burda zamaný yazýyor
resetleme();	//resetleme fonksiyonu
system("SONUC.txt");//SONUC.txt dosyasýný açýyor

}
int main()  
{  
main1();//ana programýn çalýþtýðý yer
return 0;  
}

