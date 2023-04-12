/* JOGNA2 – Jogo 2º Semestre - A linha do Trem

CAIO GUIMARÃES SA SILVA 
MARCO AURÉLIO SODRÉ 
SAMIRA DE BARROS CAVALCANTE 
TAIGUARA TALES DA SILVA VITORINO
*/


#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

#define LEFT   	75
#define RIGHT  	77
#define UP     	72
#define DOWN   	80
#define ESC    	27
#define SPACE   32




#define qntm 13 // andar inimigo
#define qntp 10  //portal
#define qnta 14  // ataque inimigo
#define qntand 9 // andar direito
#define qntande 9 // andar esquerdo



#define qntpulo 18 // pulo personagem
#define qntpuloe 18 // pulo personagem esquerdo




//structs
struct Obj {int xi, yi, x, y, lar, alt,CamT,CamX,CamV, ligado,velx,vely;}; //largura imagem, altura imagem, posição x, posição y, largura, altura

  	
struct Obj 
    Vidap[3]= {{90,90,0,10,90,90,300,0,1,0}, {90,90,0,10,90,90,300,0,1,0},{90,90,0,10,90,90,300,0,1,0}},
	Player = {150, 150, 100, 250, 150, 150,300,0,1,0,3,0},
	car = {90,90,0,10,90,90,300,0,1,0},
	port = {1500,150,600,470,150,150,300,0,1,0},
	gar [3] = {{80,80,600,500,80,80,300,0,1,0,2,0}, {80,80,1200,500,80,80,300,0,1,0,2,0}, {80,80,2000,500,80,80,300,0,1,0,2,0}},
	ban [7] = {{80,80,1000,500,80,80,300,0,1,0,2,0},{80,80,2500,500,80,80,300,0,1,0,2,0},{80,80,3700,500,80,80,300,0,1,0,2,0},{80,80,5000,500,80,80,300,0,1,0,2,0},{80,80,5600,500,80,80,300,0,1,0,2,0},{80,80,6100,500,80,80,300,0,1,0,2,0},{80,80,6350,500,80,80,300,0,1,0,2,0}},
	Fundo = {12800, 600, 0, 0, 800, 600,300,0,1,0},
	Inimigo[10] = {{250, 250,rand()%100+250,430, 250, 250,300,0,1,0,3,10}, {250, 250,rand()%100+1250,430, 250, 250,300,0,1,0,3,10}, {250, 250,rand()%100+1650,430, 250, 250,300,0,1,0,3,10}, {250, 250,rand()%100+2050,430, 250, 250,300,0,1,0,3,10}, {250, 250,rand()%100+2450,430, 250, 250,300,0,1,0,3,10}, {250, 250,rand()%100+2850,430, 250, 250,300,0,1,0,3,10}, {250, 250,rand()%100+3250,430, 250, 250,300,0,1,0,3,10}, {250, 250,rand()%100+3650,430, 250, 250,300,0,1,0,3,10},{250, 250,rand()%100+4050,430, 250, 250,300,0,1,0,3,10}, {250, 250,rand()%100+4450,430, 250, 250,300,0,1,0,3,10}};
	
	
;
	
//variáveis globais
int LarTela = 800, AltTela = 600;
  char s[50];
  	void *Vida;
  	void *Vidam;// esta variável é um vetor dinâmico que contém a máscara
  	void *Clover[qntand];  // personagem direito
  	void *CloverM [qntand];
  	void *Cloveer[qntande];  // personagem esquerdo
  	void *ClovereM [qntande];
  	void *Cloverp[qntpulo]; // personagem pulo
  	void *Cloverpm[qntpulo];
  	void *Cloverpe[qntpuloe]; // personagem pulo esquerdo
  	void *Cloverpem[qntpuloe];
  	
  	void *fundo;
  	void *Enemie[qntm], *EnemieM[qntm];   // andar inimigo

  	void *portal[qntp], *portalm[qntp];
  	void *Cara;
  	void *caram;
  	void *garrafa;
  	void *garrafam;
  	void *bandage;
  	void *bandagem;
  	int pLimit = 0, initroca = 0,initrocai = 0, initrocaii = 0, i = 0;
  	char Score[33], mortes[33], highscore[33];
	int c=0, k=0, m=0;
	int contp=0,contm=0;;
	bool anda = false, caindo = true, troca = false, jump = false,frente=false, posicao1=false, gameover=false, vitoria=false,vai=false, direita=false, esquerda=false, parado=false,pulo=false,corre=false,ataque=false,ataqueinimigo=false,andarini=false;
	
	bool dano=false, morteinimigo=false, mortep=false, correrdireito=false, correresquerdo=false;
	int GlbLar, GlbAlt;
    int GlbBtnLar, GlbBtnAlt;
  	char tecla = 0;
	int h = 0;
	int mata = 0;
	int tamI;
	int perdavida=0;
	int iportal = 0;
	int iandar=0;
	int iandare=0;
	int ipulo=0;
	int ipuloe=0; 
	int icorre=0;
	int icorree=0;
	int iataque=0;
	int iataquee=0;
	int iniataque=0;
	int idano=0;
	int idanoe=0;
	int inimorte=0;
	int imortep=0;
	int imortepe=0;
	int ivitoria=0;
	int ivitoriae=0;
	
	

/* funções usadas neste programa */
void TelaInicial();
void Menu();
void Creditos();
void Jogo();
void Tutorial();
int inimigo();
bool colisao(Obj Ax, Obj Bx);
int text();
int recuperarvida();
void Gameover();
void Vitoria();


int main()  { 


  GlbLar = 800;
  GlbAlt = 600;
  GlbBtnLar = 250;
  GlbBtnAlt = 80;

  /* inicia área gráfica */
  initwindow(GlbLar, GlbAlt, "A Linha do Trem", 10, 10);
  /* transfere execução para a função TelaInicial() */
  TelaInicial();
  Menu();
  /* finaliza área gráfica */
  closegraph();
  return(0);
 

}

void TelaInicial() {
  char tecla = 0;
  int tam;
  void *Fundo;
  bool Fim = false, som=true;
  int pg = 1;

  tam = imagesize(0, 0, GlbLar-1, GlbAlt-1);
  Fundo = malloc(tam);
  readimagefile(".\\imagens\\telainicialjogo.bmp", 0, 0, GlbLar-1, GlbAlt-1);
  getimage(0, 0, GlbLar-1, GlbAlt-1, Fundo);
  
    int Opc = 9, i;

  // Carrega os arquivos mp3
  mciSendString("open .\\sons\\tela_inicial.mp3 type MPEGVideo alias repetido", NULL, 0, 0); 
  mciSendString("open .\\sons\\estacao.mp3 type MPEGVideo alias fundo", NULL, 0, 0);   
  mciSendString("open .\\sons\\my.mp3 type MPEGVideo alias fundo2", NULL, 0, 0); 
  mciSendString("open .\\sons\\cidade.mp3 type MPEGVideo alias fundo3", NULL, 0, 0);
  mciSendString("open .\\sons\\game_over.mp3 type MPEGVideo alias gameover", NULL, 0, 0);
  mciSendString("open .\\sons\\clover_dano.mp3 type MPEGVideo alias dano", NULL, 0, 0);
  mciSendString("open .\\sons\\clover_caminhada.mp3 type MPEGVideo alias andar", NULL, 0, 0);
  mciSendString("open .\\sons\\clover_corrida.mp3 type MPEGVideo alias correr", NULL, 0, 0);
  mciSendString("open .\\sons\\criatura_caminhada.mp3 type MPEGVideo alias caminhadaini", NULL, 0, 0);
  mciSendString("open .\\sons\\criatura_morte1.mp3 type MPEGVideo alias criaturamorte", NULL, 0, 0);
  mciSendString("open .\\sons\\clover_morte.mp3 type MPEGVideo alias clovermor", NULL, 0, 0);

  
  
  //  som tela inicial
    waveOutSetVolume(0,0xFFFFFFFF);
    mciSendString("play repetido repeat", NULL, 0, 0);
   


  while (!Fim) {
    if (pg == 1) pg = 2; else pg = 1;
    setactivepage(pg);
    putimage(0, 0, Fundo, COPY_PUT);
    setvisualpage(pg);
    if (kbhit()){
      tecla = getch();
      if (tecla == 32)
        Fim = true;
        
       
  }
}
}

void Menu() {
  bool Fim = false;
  int pg = 1;
  POINT P;
  HWND janela;
  
  bool btnJogarSelecionado = false; 
  bool btnTutorialSelecionado = false;
  bool btnCreditosSelecionado = false; 
  bool btnSairSelecionado = false;
  
  int tam;
  void *Fundo;
  void *btnJogar, *btnJogarSel;
  void *btnTutorial, *btnTutorialSel;
  void *btnCreditos, *btnCreditosSel;
  void *btnSair, *btnSairSel;
  
  setactivepage(1);
  setvisualpage(1);
  setactivepage(2);
  
  
  /* carga da imagem de fundo */
  tam = imagesize(0, 0, GlbLar-1, GlbAlt-1);
  Fundo = malloc(tam);
  readimagefile(".\\imagens\\telamenu.bmp", 0, 0, GlbLar-1, GlbAlt-1);
  getimage(0, 0, GlbLar-1, GlbAlt-1, Fundo);
  /* carga da imagem dos botões */
  cleardevice();
  tam = imagesize(0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  btnJogar = malloc(tam);
  readimagefile(".\\imagens\\jogarsemtracinho.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnJogar);
  btnJogarSel = malloc(tam);
  readimagefile(".\\imagens\\jogarcomtracinho.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnJogarSel);
  btnTutorial = malloc(tam);
  readimagefile(".\\imagens\\tutorialsemtracinho.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnTutorial);
  btnTutorialSel = malloc(tam);
  readimagefile(".\\imagens\\tutorialcomtracinho.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnTutorialSel);
  btnCreditos = malloc(tam);
  readimagefile(".\\imagens\\creditossemtracinho.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnCreditos);
  btnCreditosSel = malloc(tam);
  readimagefile(".\\imagens\\creditoscomtracinho.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnCreditosSel);
  btnSair = malloc(tam);
  readimagefile(".\\imagens\\sairsemtracinho.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnSair);
  btnSairSel = malloc(tam);
  readimagefile(".\\imagens\\saircomtracinho.bmp", 0, 0, GlbBtnLar-1, GlbBtnAlt-1);
  getimage(0, 0, GlbBtnLar-1, GlbBtnAlt-1, btnSairSel);
  
  janela = GetForegroundWindow(); // Obtém o Handle da janela gráfica
  while (!Fim) {
    if (pg == 1) pg = 2; else pg = 1;
    setactivepage(pg);
    putimage(0, 0, Fundo, COPY_PUT);
    if (btnJogarSelecionado)
      putimage(100, 150, btnJogarSel, COPY_PUT); // retângulo do botão 900, 400, 900+GlbBtnLar-1, 400+GlbBtnAlt-1
    else
      putimage(100, 150, btnJogar, COPY_PUT);
        if (btnTutorialSelecionado)
      putimage(100, 250, btnTutorialSel, COPY_PUT); // retângulo do botão 900, 400, 900+GlbBtnLar-1, 400+GlbBtnAlt-1
    else
      putimage(100, 250, btnTutorial, COPY_PUT);
    if (btnCreditosSelecionado)
      putimage(100, 350, btnCreditosSel, COPY_PUT);
    else
      putimage(100, 350, btnCreditos, COPY_PUT);
    if (btnSairSelecionado)
      putimage(100, 450, btnSairSel, COPY_PUT);
    else
      putimage(100, 450, btnSair, COPY_PUT);
    setvisualpage(pg);
    /* Verifica movimento do mouse independente de haver clique */
    if (GetCursorPos(&P)) // captura a posição do mouse. A variável P é carregada com coordenadas físicas de tela
      if (ScreenToClient(janela, &P)) { // Converte as coordenadas físicas de tela para as coordenadas 
  
        /* configura a troca da imagem do botão quando o mouse está sobre ele */
        btnJogarSelecionado = false; // botão jogar
        if (100 <= P.x && P.x <= 100+GlbBtnLar-1 && 150 <= P.y && P.y <= 150+GlbBtnAlt-1) 
          btnJogarSelecionado = true;
          
        btnTutorialSelecionado = false; // botão tutorial
        if (100 <= P.x && P.x <= 100+GlbBtnLar-1 && 250 <= P.y && P.y <= 250+GlbBtnAlt-1) 
          btnTutorialSelecionado = true;
      
        btnCreditosSelecionado = false; // botão créditos
        if (100 <= P.x && P.x <= 100+GlbBtnLar-1 && 350 <= P.y && P.y <= 350+GlbBtnAlt-1)
          btnCreditosSelecionado = true;
           
        btnSairSelecionado = false; // botão sair
        if (100 <= P.x && P.x <= 100+GlbBtnLar-1 && 450 <= P.y && P.y <= 450+GlbBtnAlt-1)
          btnSairSelecionado = true;
           

        /* verifica se o mouse foi pressionado na área de algum botão */          
        if(GetKeyState(VK_LBUTTON)&0x80) {
          // botão jogar
          if (100 <= P.x && P.x <= 100+GlbBtnLar-1 && 150 <= P.y && P.y <= 150+GlbBtnAlt-1){
          	mciSendString("stop repetido", NULL, 0, 0);
          	Jogo();
		  }
          
             
            
		 // botão tutorial
          if (100 <= P.x && P.x <= 100+GlbBtnLar-1 && 250 <= P.y && P.y <= 250+GlbBtnAlt-1)

            Tutorial();    
            
          // botão créditos
          else if (100 <= P.x && P.x <= 100+GlbBtnLar-1 && 350 <= P.y && P.y <= 350+GlbBtnAlt-1)
      
            Creditos();
           
          // botão sair
          else if (100 <= P.x && P.x <= 100+GlbBtnLar-1 && 450 <= P.y && P.y <= 450+GlbBtnAlt-1)
     
            Fim = true;
           
            

            
        }
      }
  }  
}

void Creditos() {
  char tecla = 0;
  int tam;
  void *Fundo;
  bool Fim = false;
  int pg = 1;

  tam = imagesize(0, 0, GlbLar-1, GlbAlt-1);
  Fundo = malloc(tam);
  readimagefile(".\\imagens\\telacreditosjogo.bmp", 0, 0, GlbLar-1, GlbAlt-1);
  getimage(0, 0, GlbLar-1, GlbAlt-1, Fundo);

  while (!Fim) {
    if (pg == 1) pg = 2; else pg = 1;
    setactivepage(pg);
    putimage(0, 0, Fundo, COPY_PUT);
    setvisualpage(pg);
    if (kbhit()){
      tecla = getch();
      if (tecla == ESC)
        Fim = true;
        

        
        
    }
  }
}


void Tutorial() {
  char tecla = 0;
  int tam;
  void *Fundo;
  bool Fim = false;
  int pg = 1;

  tam = imagesize(0, 0, GlbLar-1, GlbAlt-1);
  Fundo = malloc(tam);
  readimagefile(".\\imagens\\TeladeTUTORIAL.bmp", 0, 0, GlbLar-1, GlbAlt-1);
  getimage(0, 0, GlbLar-1, GlbAlt-1, Fundo);

  while (!Fim) {
    if (pg == 1) pg = 2; else pg = 1;
    setactivepage(pg);
    putimage(0, 0, Fundo, COPY_PUT);
    setvisualpage(pg);
    if (kbhit()){
      tecla = getch();
      if (tecla == ESC)
        Fim = true;
    }
  }
}

void Jogo() {
 

	int pg = 2;
  	int tamC, tamN, tamN2, tamC2, tamI, tamV,tamc3,tamp,tamC4;

  	srand(time(NULL));
  	
  	int FPS;
	FPS = 60;
	int passoX = 8; 
	
  
  
	int gravidade = 10, velocidadey = 0;
 	int vup = 30;
 	int pLimit = 0;
	int b = 0;
	int i = 0;
	int j=0;
	int itroca = 0;
	unsigned long long gt1, gt2;
	int cont=0;
	int vida, vidam, carinha;

	
	
		

	

    gt1 = GetTickCount();
  	gt2 = gt1 + 1200;
  	

  	
  	initwindow(12800, AltTela, "A Linha do Trem");
  	
  
  		
	setactivepage(1);
	setvisualpage(1);
	setactivepage(2);	
  	
  	
  	
  		//lê inimigo e máscara
  	tamI = imagesize(0, 0, Inimigo[0].lar, Inimigo[0].alt);
  	for(i = 0; i<= qntm; i++){
  		Enemie[i] = malloc(tamI);
  		EnemieM[i] = malloc(tamI);
	}
	
	
	
  	
  	//Inimigo
  	readimagefile(".\\imagens\\peranda.bmp", 0, 0, 3250, Inimigo[0].yi-1);
  	for(i = 0; i <= qntm; i++){
  		getimage(Inimigo[0].lar*i, 5, Inimigo[0].lar-1+Inimigo[0].lar*i, Inimigo[0].alt-1, Enemie[i]);
  		
  	
	 }
  	
  	readimagefile(".\\imagens\\perandam.bmp", 0, 0, 3250, Inimigo[0].yi-1);
  	for(i = 0; i <= qntm; i++){
  		getimage(Inimigo[0].lar*i, 5, Inimigo[0].lar-1+Inimigo[0].lar*i, Inimigo[0].alt-1, EnemieM[i]);
  		
  	
	 }
	 
	 

	
  	
  
  	
  	
  	
  	
  	
  		//lê inimigo e máscara
  	tamI = imagesize(0, 0, port.lar, port.alt);
  	for(i = 0; i<= qntp; i++){
  		portal[i] = malloc(tamI);
  		portalm[i] = malloc(tamI);
  	
	}
	
  	
  	
  	//portal
  	readimagefile(".\\imagens\\portal.bmp", 0, 0, 1500, port.yi-1);
  	for(i = 0; i <= qntp; i++){
  		getimage(port.lar*i, 0, port.lar-1+port.lar*i, port.alt-1, portal[i]);
  		
  	
	 }
  	
  	readimagefile(".\\imagens\\portalm.bmp", 0, 0, 1500, port.yi-1);
  	for(i = 0; i <= qntp; i++){
  		getimage(port.lar*i, 0, port.lar-1+port.lar*i, port.alt-1, portalm[i]);
  		
  	
	 }
	 
	 	// andar direito
	 
	tamC2 = imagesize(0, 0, Player.lar-1, Player.alt-1);
  	for(i = 0; i <= qntand; i++) {
    	Clover[i] = malloc(tamC2);
    	CloverM[i] = malloc(tamC2);
  	}

  	
  	// Player
 	readimagefile(".\\imagens\\andardireito.bmp", 0, 0, 1350, Player.yi-1);
  	for(i = 0; i <= qntand; i++) {
    	getimage(Player.lar*i, 0, Player.lar-1+ Player.lar*i, Player.alt-1, Clover[i]);
 	}
  	
  	// Player mask
  		
  	readimagefile(".\\imagens\\andardireitom.bmp", 0, 0, 1350, Player.alt-1);
  	for(i = 0; i <= qntand; i++) {
  	getimage(Player.lar*i,0, Player.lar-1+ Player.lar*i, Player.alt-1, CloverM[i]);
  	
}


	 	// andar esquerdo
	 
	tamC4 = imagesize(0, 0, Player.lar-1, Player.alt-1);
  	for(i = 0; i <= qntande; i++) {
    	Cloveer[i] = malloc(tamC4);
    	ClovereM[i] = malloc(tamC4);
  	}

  	
  	// Player
 	readimagefile(".\\imagens\\andaresquerdo.bmp", 0, 0, 1350, Player.yi-1);
  	for(i = 0; i <= qntande; i++) {
    	getimage(Player.lar*i, 0, Player.lar-1+ Player.lar*i, Player.alt-1, Cloveer[i]);
 	}
  	
  	// Player mask
  		
  	readimagefile(".\\imagens\\andaresquerdom.bmp", 0, 0, 1350, Player.alt-1);
  	for(i = 0; i <= qntande; i++) {
  	getimage(Player.lar*i,0, Player.lar-1+ Player.lar*i, Player.alt-1, ClovereM[i]);
  	
}


// pulo direito

	 
	tamC4 = imagesize(0, 0, Player.lar-1, Player.alt-1);
  	for(i = 0; i <= qntpulo; i++) {
    	Cloverp[i] = malloc(tamC4);
    	Cloverpm[i] = malloc(tamC4);
  	}

  	
  	// Player
 	readimagefile(".\\imagens\\pulardireito.bmp", 0, 0, 2700, Player.yi-1);
  	for(i = 0; i <= qntpulo; i++) {
    	getimage(Player.lar*i, 0, Player.lar-1+ Player.lar*i, Player.alt-1, Cloverp[i]);
 	}
  	
  	// Player mask
  		
  	readimagefile(".\\imagens\\pulardireitom.bmp", 0, 0, 2700, Player.alt-1);
  	for(i = 0; i <= qntpulo; i++) {
  	getimage(Player.lar*i,0, Player.lar-1+ Player.lar*i, Player.alt-1, Cloverpm[i]);
  	
}


// pulo esquerdo

	 
	tamC4 = imagesize(0, 0, Player.lar-1, Player.alt-1);
  	for(i = 0; i <= qntpuloe; i++) {
    	Cloverpe[i] = malloc(tamC4);
    	Cloverpem[i] = malloc(tamC4);
  	}

  	
  	// Player
 	readimagefile(".\\imagens\\pularesquerdo.bmp", 0, 0, 2700, Player.yi-1);
  	for(i = 0; i <= qntpuloe; i++) {
    	getimage(Player.lar*i, 0, Player.lar-1+ Player.lar*i, Player.alt-1, Cloverpe[i]);
 	}
  	
  	// Player mask
  		
  	readimagefile(".\\imagens\\pularesquerdom.bmp", 0, 0, 2700, Player.alt-1);
  	for(i = 0; i <= qntpuloe; i++) {
  	getimage(Player.lar*i,0, Player.lar-1+ Player.lar*i, Player.alt-1, Cloverpem[i]);
  	
}








	tamN = imagesize(0, 0, Fundo.xi, Fundo.yi-1);
  	fundo = malloc(tamN);
  	readimagefile(".\\imagens\\cenariocompleto.bmp", 0, 0, Fundo.xi, Fundo.yi-1);
  	getimage(0, 0, Fundo.xi, Fundo.yi-1, fundo);

  	
   	closegraph();
  	initwindow(LarTela, AltTela, "A Linha do Trem");
  	
  	
  	setactivepage(1);
	setvisualpage(1);
	setactivepage(2);

	
  	/////// vidas
  	
  	vida = imagesize(0, 0, Vidap[0].lar-1, Vidap[0].alt-1);
  	
    Vida = malloc(vida);
    
    tamV= imagesize(0, 0, Vidap[0].lar-1, Vidap[0].alt-1);
    
    Vidam=malloc(tamV);
 
  	
  	readimagefile(".\\imagens\\coracao.bmp", 0, 0,  Vidap[0].xi,  Vidap[0].yi-1);
 	getimage( 0, 0,  Vidap[0].lar-1,  Vidap[0].alt-1, Vida);

  	readimagefile(".\\imagens\\coracaom.bmp", 0, 0, Vidap[0].lar-1, Vidap[0].alt-1);
  	getimage(0, 0, Vidap[0].lar-1, Vidap[0].alt-1, Vidam);
  	
  	/// emoticon personagem
  	
  	carinha = imagesize(0, 0, car.lar-1, car.alt-1);
  	
    Cara = malloc(carinha);
    
    tamp= imagesize(0, 0, car.lar-1, car.alt-1);
    
    caram=malloc(tamp);
  	
  	
  	
  	readimagefile(".\\imagens\\Rostopersonagem.bmp", 0, 0,  car.xi,  car.yi-1);
 	getimage( 0, 0,  car.lar-1,  car.alt-1, Cara);

  	readimagefile(".\\imagens\\Rostopersonagemm.bmp", 0, 0, car.lar-1, car.alt-1);
  	getimage(0, 0, car.lar-1, car.alt-1, caram);
  	
  		int garrafinha, bandaginha,tamg,tamb;
  	
  	
    // garrafa de agua
  	
  	garrafinha = imagesize(0, 0, gar[0].lar-1, gar[0].alt-1);
  	
    garrafa = malloc(garrafinha);
    
    tamg= imagesize(0, 0, gar[0].lar-1, gar[0].alt-1);
    
    garrafam=malloc(tamg);
  	
  	
  	readimagefile(".\\imagens\\GarrafadeAgua.bmp", 0, 0,  gar[0].xi,  gar[0].yi-1);
 	getimage( 0, 0,  gar[0].lar-1,  gar[0].alt-1, garrafa);

  	readimagefile(".\\imagens\\GarrafadeAguam.bmp", 0, 0,gar[0].lar-1, gar[0].alt-1);
  	getimage(0, 0, gar[0].lar-1, gar[0].alt-1, garrafam);
  	
 
 
  	
  	readimagefile(".\\imagens\\coracao.bmp", 0, 0,  Vidap[0].xi,  Vidap[0].yi-1);
 	getimage( 0, 0,  Vidap[0].lar-1,  Vidap[0].alt-1, Vida);

  	readimagefile(".\\imagens\\coracaom.bmp", 0, 0, Vidap[0].lar-1, Vidap[0].alt-1);
  	getimage(0, 0, Vidap[0].lar-1, Vidap[0].alt-1, Vidam);
  	
  	
  	    // bandagem
  	
  	bandaginha = imagesize(0, 0, ban[0].lar-1, ban[0].alt-1);
  	
    bandage = malloc(bandaginha);
    
    tamb= imagesize(0, 0, ban[0].lar-1, ban[0].alt-1);
    
    bandagem=malloc(tamb);
  	
  	
  	
  	readimagefile(".\\imagens\\Bandagem.bmp", 0, 0,  ban[0].xi,  ban[0].yi-1);
 	getimage( 0, 0,  ban[0].lar-1,  ban[0].alt-1, bandage);

  	readimagefile(".\\imagens\\Bandagemm.bmp", 0, 0, ban[0].lar-1, ban[0].alt-1);
  	getimage(0, 0, ban[0].lar-1, ban[0].alt-1, bandagem);
  	
  	
         
         
    waveOutSetVolume(0,0xFFFFFFFF);
  	mciSendString("play fundo repeat", NULL, 0, 0);
  
  	

  	
  	while(tecla != ESC) {
  		
  		if(!gameover){
  		
  		gt2 = GetTickCount();
  		if (gt2 - gt1 > 1000/FPS) { /* este if garante que o programa só desenhará no momento certo */
      		gt1 = gt2;
  		
  		
    	if (pg == 1) pg = 2; else pg=1;
    	setactivepage(pg);
    	
    	cleardevice();
    	
  
		  	
  		putimage(Fundo.CamX,Fundo.y, fundo, COPY_PUT);
  		
  		frente =true;
  		
  		if (frente ==true && esquerda==false&& direita==false&& pulo==false)
  		{
		  
   		putimage(Player.x, Player.y, CloverM[0], AND_PUT);
        putimage(Player.x, Player.y, Clover[0], OR_PUT);
}
   	

    	
    	
    	putimage(car.x, car.y, caram, AND_PUT);
    	putimage(car.x, car.y, Cara, OR_PUT);
    	
    	if (direita == true)
    	{
    
    		putimage(Player.x, Player.y, CloverM[iandar], AND_PUT);
    		putimage(Player.x, Player.y, Clover[iandar], OR_PUT);
    		
}



	if (esquerda == true)
    	{
    		
    		putimage(Player.x, Player.y, ClovereM[iandare], AND_PUT);
    		putimage(Player.x, Player.y, Cloveer[iandare], OR_PUT);
    		
}

	if ( pulo == true && frente ==true )
    	{
    		
    		direita=false;
    		esquerda=false;
    		putimage(Player.x, Player.y, Cloverpm[ipulo], AND_PUT);
    		putimage(Player.x, Player.y, Cloverp[ipulo], OR_PUT);
    		
}

    
	if ( pulo == true && esquerda ==true && frente ==false)
    	{
    		direita=false;
    		putimage(Player.x, Player.y, Cloverpem[ipuloe], AND_PUT);
    		putimage(Player.x, Player.y, Cloverpe[ipuloe], OR_PUT);
    		
}






    	inimigo();
    	
    	recuperarvida();
    	
    	text();
    	
   
    		
    		
    	for(i=0; i<3; i++){
    		if(Vidap[i].ligado == 0){
    			putimage(Vidap[0].x+100, Vidap[0].y, Vidam, AND_PUT);
    			putimage(Vidap[0].x+100, Vidap[0].y, Vida, OR_PUT);
    
    			putimage(Vidap[1].x+210, Vidap[1].y, Vidam, AND_PUT);
    			putimage(Vidap[1].x+210, Vidap[1].y, Vida, OR_PUT);
    
    			putimage(Vidap[2].x+320, Vidap[2].y, Vidam, AND_PUT);
    			putimage(Vidap[2].x+320, Vidap[2].y, Vida, OR_PUT);
			}
		}
  		
      
    
  	i++;
    if (i > 3) 
     i = 0;
    
    	
		if (anda == true){
		  Fundo.CamT=770;
		  Fundo.CamV=0;
		  	putimage(port.x, port.y, portalm[iportal], AND_PUT);
    		putimage(port.x, port.y, portal[iportal], OR_PUT);
			iportal++;
			if(iportal >= qntp){
			iportal = 0;
			}
		 	
		}
		
		
		
	setvisualpage(pg);
	

		
	if (b >= 1190){
			
		anda=true;
			
			
		}
	
	
	
	
	    if (troca == true ){
	    		
		itroca ++;
	
		if (itroca >= qntand){
			itroca = 0;
		}	
	}
		
		
			
    	if (Player.x > Fundo.CamT  ){  
			Player.x = Fundo.CamT-1; // = 300
			Fundo.CamX -= Fundo.CamV * 10; // Movimentação da Camera	(direita)
			b ++;
		
		
		if (b==10)
		{
			posicao1 = true;
		}
	
			
}

		if (b>=610)  // 2º som do cenario
			{
					
				mciSendString("stop fundo", NULL, 0, 0);
         
        		waveOutSetVolume(0,0xFFFFFFFF);
  				mciSendString("play fundo3 repeat", NULL, 0, 0);
			}
		
		//mata personagem
		if(mata == 3){
		
			mciSendString("play clovermor ", NULL, 0, 0);
			
		    Player.y=100;
			gameover= true;
			Gameover();
		}
		
		
		
		// definindo a colisão com o chão
	if (Player.y >= Fundo.alt-151) {
			caindo = false;
			Player.y = 450;
		}
		
		//colisão teto

		if (Player.y <= Fundo.y){
			Player.y = Fundo.y;
			pLimit += 600;
		}

		
		//colisão esquerda
		if (Player.x <= Fundo.x){
			Player.x = Fundo.x;
		}
		

		
		
			//animação andar
		if (caindo == false && troca == true){
			itroca ++;
			if (itroca >= qntand){
				itroca = 0;
			}	
		}
		
		else if(caindo == false && troca == false){
			itroca = 0;
		}

		troca = false;
		
		
		//pulo, gravidade e animação pulo
		if (jump == true && Player.y > pLimit-100  ){
			Player.y += velocidadey;
			velocidadey = -vup;
			caindo = true;
			itroca = 2;
			pulo=true;
			
	
		}
		else if (caindo == true){
			jump = false;
			velocidadey += gravidade;
			Player.y += velocidadey;
	
	       
	
		}
		else {
			jump = false;
		
			velocidadey = 0;
		
		}
					ipulo=0;
		
		if(vai){
			mciSendString("play andar repeat", NULL, 0, 0);	
		}
		else{
			mciSendString("stop andar", NULL, 0, 0);
			mciSendString("seek andar to start", NULL, 0, 0);
		}
	
		gt2 = GetTickCount();
		fflush(stdin);
		if(GetKeyState(VK_LEFT)&0x80)  {
		
		
		vai = true;
		esquerda=true;
		direita=false;

		
		Player.x = Player.x - passoX*2;	
			troca = true;
			
			iandare++;
			if(iandare >= qntande){
			iandare = 0;
		}
		
		}
		else{
		 vai = false;
	
		}
		


			
	   if(GetKeyState(VK_RIGHT)&0x80) 
	
		{
			
		vai=true;	
		direita=true;
		esquerda=false;
		Player.x = Player.x + passoX*2;
	   	troca = true;	
	   	iandar++;
			if(iandar >= qntand){
			iandar = 0;
	    	
		}
	}
		else{
			vai = false;

		}
		
	    	    
		if(GetKeyState(VK_SHIFT)&0x80){
			passoX = 15;
			vai = false;
			pulo=false;
	
			mciSendString("play correr repeat", NULL, 0, 0);
			if (Player.x > Fundo.CamT ){  
				Player.x = Fundo.CamT-1; // = 300
				Fundo.CamX -= Fundo.CamV * 30;
				b+=3;
				
			}	
				
			if (b >= 1190){	
				anda=true;
				
			
			
			}
			
			if (b>=610)  // 2º som do cenario
			{
					
				mciSendString("stop fundo", NULL, 0, 0);
         
        		waveOutSetVolume(0,0xFFFFFFFF);
  				mciSendString("play fundo3 repeat", NULL, 0, 0);
			}
		
			if (b==10)
			{
				posicao1 = true;
			}
		
		}
		else{
			passoX = 8;
			tecla = 0;
			mciSendString("stop correr", NULL, 0, 0);
			mciSendString("seek correr to start", NULL, 0, 0);
		}

	    if (GetKeyState(VK_SPACE)&0x80&& !jump && !velocidadey){
				pLimit = Player.y;
				jump = true;
				tecla = 0;
				sndPlaySound(".\\sons\\clover_pulo.wav", SND_ASYNC);
				
			ipulo++;
			if(ipulo >= qntpulo && frente== true){
			ipulo = 0;
		}
		
		ipulo++;
			if(ipulo >= qntpulo && frente== false && correrdireito==true){
			ipulo = 0;
		}
		ipuloe++;
			if(ipuloe >= qntpuloe && correresquerdo== true && frente==false){
			ipuloe = 0;
		}
				
    	if (kbhit()){
    		tecla = getch();
			}

		}
      
  }
 
}

}
}

bool colisao(Obj A, Obj B){

bool colidiu = false;
float distancia;

distancia = sqrt(pow((A.x- B.x),2) + pow((A.y - B.y), 2));

if (distancia < B.lar)
{
	colidiu = true;
}
return colidiu;

}

int inimigo(){
    	
    		 for(i=0; i<10; i++){
		if(Inimigo[i].ligado == 0){
    		putimage(Inimigo[0].x , Inimigo[0].y-30, EnemieM[initroca], AND_PUT);
    		putimage(Inimigo[0].x, Inimigo[0].y-30, Enemie[initroca], OR_PUT);
    		putimage(Inimigo[1].x , Inimigo[1].y-30, EnemieM[initroca], AND_PUT);
    		putimage(Inimigo[1].x, Inimigo[1].y-30, Enemie[initroca], OR_PUT);
    		putimage(Inimigo[2].x , Inimigo[2].y-30, EnemieM[initroca], AND_PUT);
    		putimage(Inimigo[2].x, Inimigo[2].y-30, Enemie[initroca], OR_PUT);
    		putimage(Inimigo[3].x , Inimigo[3].y-30, EnemieM[initroca], AND_PUT);
    		putimage(Inimigo[3].x, Inimigo[3].y-30, Enemie[initroca], OR_PUT);
    		putimage(Inimigo[4].x , Inimigo[4].y-30, EnemieM[initroca], AND_PUT);
    		putimage(Inimigo[4].x, Inimigo[4].y-30, Enemie[initroca], OR_PUT);
    	    putimage(Inimigo[5].x , Inimigo[5].y-30, EnemieM[initroca], AND_PUT);
    		putimage(Inimigo[5].x, Inimigo[5].y-30, Enemie[initroca], OR_PUT);
    		putimage(Inimigo[6].x , Inimigo[6].y-30, EnemieM[initroca], AND_PUT);
    		putimage(Inimigo[6].x, Inimigo[6].y-30, Enemie[initroca], OR_PUT);
    		putimage(Inimigo[7].x , Inimigo[7].y-30, EnemieM[initroca], AND_PUT);
    		putimage(Inimigo[7].x, Inimigo[7].y-30, Enemie[initroca], OR_PUT);
    		putimage(Inimigo[8].x , Inimigo[8].y-30, EnemieM[initroca], AND_PUT);
    		putimage(Inimigo[8].x, Inimigo[8].y-30, Enemie[initroca], OR_PUT);
    		putimage(Inimigo[9].x , Inimigo[9].y-30, EnemieM[initroca], AND_PUT);
    		putimage(Inimigo[9].x, Inimigo[9].y-30, Enemie[initroca], OR_PUT);
    		
    		Inimigo[i].x-= Inimigo[i].velx;
    	}
    	
    	if (Inimigo[i].x + Inimigo[i].lar <=0)
    	{
    		Inimigo[i].x=Fundo.xi;
    	
    
		}
		

		
			//colisão inimigos
	if(colisao(Player, Inimigo[i])){
		if (Player.x+Player.lar>= Inimigo[i].x+200 && Player.x+Player.lar<= Inimigo[i].x+Inimigo[i].lar)
		{
		
		h++;
		
		initroca++;
		
		if (initroca >= qntm) initroca = 0;	
		if(GetKeyState(0x58)&0x80 || GetKeyState(0x78)&0x80){  ///tecla x - ataque
			
			initrocaii = 0;
			Inimigo[i].velx = 0;
			Inimigo[i].y = - 610;	
			Inimigo[i].x = -300;
			
			sndPlaySound(".\\sons\\clover_ataque.wav", SND_ASYNC);	
			c+=5;
			contp=c;
			k+=1;
			contm=k;
			
			
			
}
			
		
			
		
		tecla = 0;
	

		
		if(h == 10){
			
			
			
			
			
		
	
			Vidap[2].y = -100;
			mata++;
			perdavida++;
			mciSendString("seek dano to start", NULL, 0, 0);
			mciSendString("play dano", NULL, 0, 0);
			sndPlaySound(".\\sons\\criatura_ataque.wav", SND_ASYNC);
			
		
			 
			
		}
		
		if(h==110){
		
			Vidap[1].y = -100;
			mata++;
			perdavida++;
			mciSendString("seek dano to start", NULL, 0, 0);
			mciSendString("play dano", NULL, 0, 0);
			sndPlaySound(".\\sons\\criatura_ataque.wav", SND_ASYNC);
		
			 
		}
	
		if(h==210){
			
		
			Vidap[0].y = -100;
			mata++;
			perdavida++;
			sndPlaySound(".\\sons\\criatura_ataque.wav", SND_ASYNC);
			mciSendString("seek dano to start", NULL, 0, 0);
		 	mciSendString("play dano", NULL, 0, 0);
		 	
		}
	  
		
}


		//movimentação dos inimigos
	if (Inimigo[i].velx != 0){
		
		initroca++;

		if (initroca >= qntm) initroca = 0;	
	}
	
}
	
}
}




int text(){


  	setbkcolor(RGB(0,0,0));
  	setcolor(RGB(255,255,255));
  	settextstyle(10,0,5);
  	sprintf(Score,"Score: %d", c);
  	outtextxy(500,7,Score);
  	sprintf(highscore,"High Score: %d", m);
  	outtextxy(450,50,highscore);
  	sprintf(mortes,"Mortes: %d", k);
  	outtextxy(500,93,mortes);
  	
  	if (c> m)
  	{
  		m=c;
	  }
  	
  }
  
  int recuperarvida()
  
  {
  	

  	
  	
  	   for(i=0; i<3; i++){
		if(gar[i].ligado == 0){
  	
  	
  		putimage(gar[0].x , gar[0].y, garrafam, AND_PUT);
    	putimage(gar[0].x, gar[0].y, garrafa, OR_PUT);
    	putimage(gar[1].x , gar[1].y, garrafam, AND_PUT);
    	putimage(gar[1].x, gar[1].y, garrafa, OR_PUT);
    	putimage(gar[2].x , gar[2].y, garrafam, AND_PUT);
    	putimage(gar[2].x, gar[2].y, garrafa, OR_PUT);
    	
    	gar[i].x-= gar[i].velx;
    	
    }
    	
    	 //	colisão garrafas
	if(colisao(Player, gar[i])){
		if (Player.x+20>= gar[i].x && Player.x+Player.lar-20 && Player.x+Player.lar>= gar[i].x)
		{
		
		 
		
			
		
		
	if (perdavida==2 && Vidap[1].y <= -100 && Vidap[2].y <= -100)
  		{
  		 
			perdavida = 0;
			mata = 0;
			h = 0;
			   Vidap[1].y = 10;
			Vidap[2].y = 10;
				gar[i].velx=0;
		gar[i].x=-600;
		gar[i].y=-600;
		sndPlaySound(".\\sons\\coleta_outros.wav", SND_ASYNC);
  	
  		}
  
  		if (perdavida==1 && Vidap[2].y <= -100)
  		{
  		
  			perdavida = 0;
  			mata = 0;
  			h = 0;
  			Vidap[2].y = 10;
  				gar[i].velx=0;
		gar[i].x=-600;
		gar[i].y=-600;
		sndPlaySound(".\\sons\\coleta_outros.wav", SND_ASYNC);
  		}	

}
}

    
    	for(i=0; i<6; i++){
	if(ban[i].ligado == 0){
			
			
    	putimage(ban[0].x , ban[0].y, bandagem, AND_PUT);
    	putimage(ban[0].x, ban[0].y, bandage, OR_PUT);
    	putimage(ban[1].x , ban[1].y, bandagem, AND_PUT);
    	putimage(ban[1].x, ban[1].y, bandage, OR_PUT);
    	putimage(ban[2].x , ban[2].y, bandagem, AND_PUT);
    	putimage(ban[2].x, ban[2].y, bandage, OR_PUT);
    	putimage(ban[3].x , ban[3].y, bandagem, AND_PUT);
    	putimage(ban[3].x, ban[3].y, bandage, OR_PUT);
    	putimage(ban[4].x , ban[4].y, bandagem, AND_PUT);
    	putimage(ban[4].x, ban[4].y, bandage, OR_PUT);
    	putimage(ban[5].x , ban[5].y, bandagem, AND_PUT);
    	putimage(ban[5].x, ban[5].y, bandage, OR_PUT);
    	putimage(ban[6].x , ban[6].y, bandagem, AND_PUT);
    	putimage(ban[6].x, ban[6].y, bandage, OR_PUT);
    	
    	ban[i].x-= ban[i].velx;
    	
    }
    	  	 	//colisão bandagens
	if(colisao(Player, ban[i])){
		if (Player.x+20>= ban[i].x && Player.x+Player.lar-20 && Player.x+Player.lar>= ban[i].x)
		{
	if (perdavida==2 && Vidap[1].y <= -100 && Vidap[2].y <= -100)
  		{
  		 
			perdavida = 0;
			mata = 0;
			h = 0;
			   Vidap[1].y = 10;
				ban[i].velx=0;
		ban[i].x=-600;
		ban[i].y=-600;
		sndPlaySound(".\\sons\\coleta_outros.wav", SND_ASYNC);
  	
  		}
  
  		if (perdavida==1 && Vidap[2].y <= -100)
  		{
  		
  			perdavida = 0;
  			mata = 0;
  			h = 0;
  			Vidap[2].y = 10;
  				ban[i].velx=0;
		ban[i].x=-600;
		ban[i].y=-600;
		sndPlaySound(".\\sons\\coleta_outros.wav", SND_ASYNC);
		
		
  		}	

}
}
}
}


	if(colisao(Player, port)){
		if (Player.x+Player.lar >= port.x+150)
		{
		
			vitoria=true;
			Vitoria();
		}
		
	
		
			
}
}



  void Gameover()
  {
  	if (gameover == true)
  	{
  char tecla = 0;
  int tam;
  void *Fund;
  bool Fim = false;
  int pg = 1;

  tam = imagesize(0, 0, GlbLar-1, GlbAlt-1);
  Fund = malloc(tam);
  readimagefile(".\\imagens\\gameover.bmp", 0, 0, GlbLar-1, GlbAlt-1);
  getimage(0, 0, GlbLar-1, GlbAlt-1, Fund);
  
  
  mciSendString("stop fundo3", NULL, 0, 0);
  mciSendString("stop fundo", NULL, 0, 0);
  
  
   mciSendString("play gameover repeat", NULL, 0, 0);

  while (!Fim) {
    if (pg == 1) pg = 2; else pg = 1;
    setactivepage(pg);
    putimage(0, 0, Fund, COPY_PUT);
    
    if (kbhit()){
      tecla = getch();
      if (tecla == ESC)
        Fim = true;
        
        
         if (tecla == 82 || tecla ==114){   // TECLA R
        	
        	cleardevice();
        	gameover=false;
        	mata=0;
        	c=0;
        	k=0;
        	h=0;
        	Player.x = 100;
        	Inimigo[0].x=850;
        	Inimigo[1].x=1250;
        	Inimigo[2].x=1650;
        	Inimigo[3].x=2050;
        	Inimigo[4].x=2450;
        	Inimigo[5].x=2850;
        	Inimigo[6].x=3250;
        	Inimigo[7].x=3650;
        	Inimigo[8].x=4050;
        	Inimigo[9].x=4450;
        	ban[0].x=1000;
        	ban[1].x= 2500;
        	ban[2].x= 3700;
        	ban[3].x= 5000;
        	ban[4].x= 5600;
			ban[5].x= 6100;
        	ban[6].x= 6350;
        	gar[0].x=600;
        	gar[1].x=1200;
        	gar[2].x=2000;
        	
        	
        	for(i=0; i<10; i++){
        		Inimigo[i].y=430;
        		Inimigo[i].ligado = 0;
        		Inimigo[i].velx = 3;
		}
			
			for(i=0; i<3; i++){
        		gar[i].y=500;
        		gar[i].ligado = 0;
        		gar[i].velx = 2;
			}
			
			for(i=0; i<7; i++){
        		ban[i].y=500;
        		ban[i].ligado = 0;
        		ban[i].velx = 2;
			}

        	Fundo.CamX= 0;
        	Vidap[0].y = 10;
        	Vidap[1].y = 10;
			Vidap[2].y = 10;

			
			mciSendString("stop gameover", NULL, 0, 0);
			mciSendString("seek fundo3 to start", NULL, 0, 0);
			mciSendString("seek fundo to start", NULL, 0, 0);
			mciSendString("seek gameover to start", NULL, 0, 0);
			mciSendString("stop andar", NULL, 0, 0);
			mciSendString("seek andar to start", NULL, 0, 0);
			mciSendString("stop correr", NULL, 0, 0);
			mciSendString("seek correr to start", NULL, 0, 0);
			vai = false;

        	
        
        	Jogo();
        	
            setvisualpage(pg);
        
    
	}
}
	}
	
	}}
	
	
	void Vitoria(){

 	if (vitoria == true)
  	{
  char tecla = 0;
  int tam;
  void *Fund;
  bool Fim = false;
  int pg = 1;
  vai = false;

  tam = imagesize(0, 0, GlbLar-1, GlbAlt-1);
  Fund = malloc(tam);
  
   mciSendString("stop fundo3", NULL, 0, 0);
   mciSendString("stop andar", NULL, 0, 0);
   mciSendString("seek andar to start", NULL, 0, 0);
   mciSendString("stop correr", NULL, 0, 0);
   mciSendString("seek correr to start", NULL, 0, 0);
  
  	sndPlaySound(".\\sons\\tela_de_vitória.wav", SND_ASYNC);
  	
  	
  readimagefile(".\\imagens\\telavocevenceu.bmp", 0, 0, GlbLar-1, GlbAlt-1);
  getimage(0, 0, GlbLar-1, GlbAlt-1, Fund);
  
   
  	
  	
		


  while (!Fim) {
    if (pg == 1) pg = 2; else pg = 1;
    setactivepage(pg);
    putimage(0, 0, Fund, COPY_PUT);
    
    if (kbhit()){
      tecla = getch();
      if (tecla == ESC)
        Fim = true;
 
  }
  }
  }
  }
  


	  


